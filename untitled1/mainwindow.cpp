#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "ticket.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>
#include"QMessageBox"
#include<QPropertyAnimation>
#include<random>
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <src/SmtpMime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabclient->setModel(tmpclient.afficher());
ui->tableTicket->setModel(tmpticket.afficherTicket());}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_supprimer_clicked()
{
        //QString CIN = ui->comboBox_2->currentText();
       QString CIN= ui->CIN2->text();
        Client c;

              bool test=tmpclient.supprimer(CIN);
               // test=c.supprimer(CIN);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("client supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (!test)
           { QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }


}


void MainWindow::on_pushButton_clicked()
{
    QString CIN = ui->comboBox->currentText();
    QString nom= ui->lineEdit_nom_1->text();
    QString prenom= ui->lineEdit_prenom_->text();
    QString email=ui->lineEdit_email_1->text();
    int numero=ui->lineEdit_num_1->text().toInt();

Client C (CIN,nom,prenom,email,numero);


 bool test=C.modifier(C);

 if (test)
 { ui->tabclient->setModel(tmpclient.afficher());//refresh
 QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                   QObject::tr(" client modifié .\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}

/*void MainWindow::on_pushButton_2_clicked()
{
   QString cin =ui->lineEdit_nomC->text();

    //ui->tabclient_3->setModel(tmpclient.recherchernomclient(nomc));

    bool test=tmpclient.recherchernomclient(cin);
    if (test)
    {ui->tabclient_3->setModel(tmpclient.recherchernomclient(cin));
        QMessageBox::information(nullptr, QObject::tr("Rechercher un client"),
                          QObject::tr(" Client existe  .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
   }
    else

    QMessageBox::critical(nullptr, QObject::tr("Rechercher un client"),
                QObject::tr("Erreur !.\n"
                            "Try again"), QMessageBox::Retry);
}*/

void MainWindow::on_pushButton_3_clicked()
{   Client cc;
    QSqlQueryModel * p=cc.tri();
    ui->tabclient ->setModel(tmpclient.tri());
    ui->tabclient->setModel(p);

}
/*TICKET*/


void MainWindow::on_pushButton_5_clicked()
{
    QTableWidgetItem *Ref =new QTableWidgetItem();
    QTableWidgetItem *NomArticle =new QTableWidgetItem();
    QTableWidgetItem *QuantiteArticle =new QTableWidgetItem();
    QTableWidgetItem *PrixArticle =new QTableWidgetItem();
    Ref->setText(ui->Ref->text());
    NomArticle->setText(ui->Nomp->text());
    QuantiteArticle->setText(ui->quantite->text());
    PrixArticle->setText(ui->prix->text());
    int inserROW = ui->Monticket->rowCount();
    ui->Monticket->insertRow(inserROW);
    ui->Monticket->setItem(inserROW,0,Ref);
    ui->Monticket->setItem(inserROW,1,NomArticle);
    ui->Monticket->setItem(inserROW,2,QuantiteArticle);
    ui->Monticket->setItem(inserROW,3,PrixArticle);

}







void MainWindow::on_pushButton_4_clicked()
{

    const QString possibleCharacters("0123456789");
       const int randomStringLength = 4; // assuming you want random strings of 12 characters
       QString randomString;
       for(int i=2; i<randomStringLength; ++i)
       {
           int index = qrand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           randomString.append(nextChar);
       }
       QString  Tickets =randomString;

        int Caisse=ui->lineEdit_caisse->text().toInt();
        QString Agent= ui->lineEdit_agent->text();
        //QString Tickets = ui->lineEdit_ticket->text();
        int Ref= ui->Ref->text().toInt();
        QString Nom = ui->Nomp->text();
        int Quantite = ui->quantite->text().toInt();
        int Prix = ui->prix->text().toInt();
        int Total = ui->lineEdit_total->text().toInt();

        ticket t (Caisse,Tickets,Agent,Ref,Nom,Quantite,Prix,Total);


        bool test=t.ajouterTicket(t);
      if(test)
      {
    ui->tableTicket->setModel(tmpticket.afficherTicket());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un ticket"),
                      QObject::tr("ticket ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
         { QMessageBox::critical(nullptr, QObject::tr("Ajouter un ticket"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}



}





void MainWindow::on_pushButton_8_clicked()
{
    int Caisse=ui->lineEdit_5->text().toInt();
    QString Agent= ui->lineEdit_7->text();
    QString Tickets= ui->comboBox_2->currentText();
    int Ref= ui->Ref_2->text().toInt();
    QString Nom = ui->Nomp_2->text();
    int Quantite = ui->quantite_2->text().toInt();
    int Prix = ui->prix_2->text().toInt();
    int Total = ui->lineEdit_8->text().toInt();

    ticket t (Caisse,Tickets,Agent,Ref,Nom,Quantite,Prix,Total);
    bool test=t.modifierTicket(t);

    if(test)
    {   ui->tableTicket->setModel(tmpticket.afficherTicket());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                    QObject::tr("client modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("Modifier un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}


void MainWindow::on_pushButton_9_clicked()
{  QString Tickets = ui->lineEdit_9->text();
    bool test=tmpticket.supprimerTicket(Tickets);
    if(test)
    {  ui->tableTicket->setModel(tmpticket.afficherTicket());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Ticket supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_10_clicked()
{
    ui->Monticket->removeRow(ui->Monticket->currentRow());


}

void MainWindow::on_pushButton_6_clicked()
{
     QString Ref = ui->Ref->text();
     QString Nom = ui->Nomp->text();
     QString Quantite =ui->quantite->text();
     QString  prix = ui->prix->text();
     int currentRow = ui->Monticket->currentRow();
     ui->Monticket->item(currentRow,0)->setText(Ref);
     ui->Monticket->item(currentRow,1)->setText(Nom);
     ui->Monticket->item(currentRow,2)->setText(Quantite);
     ui->Monticket->item(currentRow,3)->setText(prix);
}


void MainWindow::on_pushButton_11_clicked()
{   QString tickett=ui->lineEdit_10->text();  /*->currentText();*/



    bool test=tmpticket.rechercherTicket(tickett);
    if (test)
    { ui->tableView_4->setModel(tmpticket.rechercherTicket(tickett));
    QMessageBox::information(nullptr, QObject::tr("Rechercher une ticket "),
                      QObject::tr("Ticket non trouvé "), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche une ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_12_clicked()
{

    QString CIN=ui->lineEdit_CIN->text();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString email= ui->lineEdit_email->text();
    int numero = ui->lineEdit_num->text().toInt();
    Client c(CIN,nom,prenom,email,numero);
    bool test= c.ajouter(c);
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_13_clicked()
{
      int i;
        ui->tabclient->setModel(c.afficher());
        qDebug()<<ui->tabclient->model()->rowCount();
        for (i=0;i<ui->tabclient->model()->rowCount();i++)
        {
        ui->comboBox->addItem(ui->tabclient->model()->index(i,0).data().toString());
        }

}



void MainWindow::on_pushButton_15_clicked()
{
    int i ;
    ui->tableTicket->setModel(t.afficherTicket());
    qDebug () <<ui->tableTicket->model()->rowCount();
    for (i=0;i<ui->tableTicket->model()->rowCount();i++)
    {
    ui->comboBox_2->addItem(ui->tableTicket->model()->index(i,0).data().toString());
    }
}



void MainWindow::on_pushButton_16_clicked()
{
    ticket tt;
        QSqlQueryModel * p=tt.tri();

        ui->tableTicket ->setModel(tmpticket.tri());
        ui->tableTicket->setModel(p);
}

void MainWindow::on_pushButton_7_clicked()
{
    QPrinter printer;

     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setOutputFileName("C:/Users/Asus/Documents.pdf");

    QPainter painter;
    painter.begin(&printer);
    QFont font;
    int Ref= ui->Ref->text().toInt();

    QString Nom =ui->Nomp->text();

    int Quantite = ui->quantite->text().toInt();

    int Prix = ui->prix->text().toInt();

    int Total = ui->lineEdit_total->text().toInt();
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);

    painter.drawText(100,300,"reference :");

    painter.drawText(100,400,"Nom :");

    painter.drawText(100,500,"quantite :");

    painter.drawText(100,600,"prix :");

    painter.drawText(100,700,"total :");

    font.setPixelSize(22);
    painter.setFont(font);
    painter.setPen(Qt::green);
    QString Reff= QString::number(Ref);
    QString Quantitee= QString::number(Quantite);
    QString Prixx= QString::number(Prix);
    QString Totall= QString::number(Total);
    painter.drawText(500,300,Reff);
    painter.drawText(500,400,Nom);
    painter.drawText(500,500,Quantitee);
    painter.drawText(500,600,Prixx);
    painter.drawText(500,700,Totall);
    painter.end();
}

void MainWindow::on_pushButton_17_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
       smtp.setUser("hibouba.sboui@gmail.com");
       smtp.setPassword("hibasboui11");
       MimeMessage message;
       message.setSender(new EmailAddress("hibouba.sboui@gmail.com", "Service client"));
       message.addRecipient(new EmailAddress(ui->email->text(), "Recipient's Name"));
       message.setSubject(ui->objet->text());
       MimeText text;
       text.setText(ui->lineEdit_3->text());
       message.addPart(&text);
       smtp.connectToHost();
       smtp.login();
       smtp.sendMail(message);
       smtp.quit();
}


void MainWindow::on_CIN2_2_textChanged()
{
    QString nom =ui->CIN2->text();

     ui->tabclient->setModel(tmpclient.recherchernomclient(nom));

}

void MainWindow::on_pushButton_2_clicked()
{
    QString nom =ui->CIN2_2->text();

     //ui->tabclient_3->setModel(tmpclient.recherchernomclient(nomc));

     bool test=tmpclient.recherchernomclient(nom);
     if (test)
     {ui->tabclient->setModel(tmpclient.recherchernomclient(nom));
         QMessageBox::information(nullptr, QObject::tr("Rechercher un client"),
                           QObject::tr(" Client existe  .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }
     else

     QMessageBox::critical(nullptr, QObject::tr("Rechercher un client"),
                 QObject::tr("Erreur !.\n"
                             "Try again"), QMessageBox::Retry);
}
