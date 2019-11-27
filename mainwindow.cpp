#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "ticket.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabclient->setModel(tmpclient.afficher());
ui->tableTicket->setModel(tmpticket.afficherTicket());
//ui->tableView_2->setModel(tmpticket.afficherTicket());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int CIN=ui->lineEdit_CIN->text().toInt();
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
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_supprimer_clicked()
{
int CIN = ui->lineEdit_CIN->text().toInt();
bool test=tmpclient.supprimer(CIN);
if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Client supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pushButton_clicked()
{
    int CIN = ui->CIN2->text().toInt();
    QString nom= ui->lineEdit_nom_1->text();
    QString prenom= ui->lineEdit_prenom_->text();
    QString email=ui->lineEdit_email_1->text();
    int numero=ui->lineEdit_num_1->text().toInt();

Client C (CIN,nom,prenom,email,numero);


 bool test=C.modifier(C);

 if (test)
 {
 QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                   QObject::tr(" client modifié .\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_2_clicked()
{
    QString nomc =ui->lineEdit_nomC->text();  /*->currentText();*/

    ui->tabclient_3->setModel(tmpclient.recherchernomclient(nomc));

    bool test=tmpclient.recherchernomclient(nomc);
    if (test=1)
    {
    QMessageBox::information(nullptr, QObject::tr("Rechercher un client"),
                      QObject::tr(" Client n'existe pas .\n"
                                  "Try again."), QMessageBox::Retry);
   }

}

void MainWindow::on_pushButton_3_clicked()
{   Client cc;
    QSqlQueryModel * p=cc.tri();
    ui->tableView ->setModel(tmpclient.tri());
    ui->tableView->setModel(p);

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

        int Numcaisse=ui->lineEdit_caisse->text().toInt();
        QString Agent= ui->lineEdit_agent->text();
        int NumTicket = ui->lineEdit_num->text().toInt();
        int Ref= ui->Ref->text().toInt();
        QString Nom = ui->Nomp->text();
        int Quantite = ui->quantite->text().toInt();
        int Prix = ui->quantite->text().toInt();
        int Total = ui->lineEdit_total->text().toInt();

        ticket t (Numcaisse,NumTicket,Agent,Ref,Nom,Quantite,Prix,Total);


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
    int Numcaisse=ui->lineEdit_caisse->text().toInt();
    QString Agent= ui->lineEdit_agent->text();
    int NumTicket = ui->lineEdit_num->text().toInt();
    int Ref= ui->Ref->text().toInt();
    QString Nom = ui->Nomp->text();
    int Quantite = ui->quantite->text().toInt();
    int Prix = ui->quantite->text().toInt();
    int Total = ui->lineEdit_total->text().toInt();

    ticket t (Numcaisse,NumTicket,Agent,Ref,Nom,Quantite,Prix,Total);
    bool test=t.modifierTicket(t);

    if (test)
    {
    QMessageBox::information(nullptr, QObject::tr("modifier un ticket"),
                      QObject::tr(" ticket modifié .\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
   }
}


void MainWindow::on_pushButton_9_clicked()
{int Caisse = ui->lineEdit_9->text().toInt();
    bool test=tmpticket.supprimerTicket(Caisse);
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
{   QString caissee=ui->lineEdit_10->text();  /*->currentText();*/

    ui->tableView_4->setModel(tmpticket.rechercherTicket(caissee));

    bool test=tmpticket.rechercherTicket(caissee);
    if (test=1)
    {
    QMessageBox::information(nullptr, QObject::tr("Rechercher une ticket "),
                      QObject::tr(" Ticket n'existe pas .\n"
                                  "Try again."), QMessageBox::Retry);
   }

}
