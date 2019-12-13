#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include "QMessageBox"
#include <QIntValidator>
#include <QDebug>
#include <QPixmap>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabfacture->setModel(tmpfacture.afficher());
    ui->lineEdit_telephone->setValidator( new QIntValidator(0, 99999999, this) );
    ui->setupUi(this);
    QPixmap pix1("C:/Users/Lenovo/Downloads/depositphotos");
        ui->label_fond_3->setPixmap(pix1);
     refresh();
     QMediaPlayer *music=new QMediaPlayer();
     music->setMedia(QUrl("qrc:/sound/minimalist-approach-ihsandincer-download-mp3-melody-loops-1.mp3"));
    music->play();
    show();
     /*connect(player, &QMediaPlayer::positionChanged,this,&MainWindow::on_duration_changed);
     connect(player, &QMediaPlayer::positionChanged,this,&MainWindow::on_position_changed);*/


}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::refresh(){
    ui->tabfacture->setModel(tmpfacture.afficher());
    ui->comboBox->setModel(tmpfacture.afficher_list());

}
void MainWindow::on_pushButton_ajouter_clicked()
{

    int Nfacture =ui->lineEdit_nfacture->text().toInt();

    QString nom_fournisseur=ui->lineEdit_name->text();
    QString prenom_fournisseur=ui->lineEdit_prenom->text();
     QString courriel=ui->lineEdit_courriel->text();
      QString telephone=ui->lineEdit_telephone->text();
       QString codepostal=ui->lineEdit_codepostal->text();
       QString adresse=ui->lineEdit_adresse->text();
       QString date=ui->dateEdit->text();
    Facture f(Nfacture,nom_fournisseur,prenom_fournisseur,date,telephone,adresse,courriel,codepostal);
      qDebug()<<"la valeur de num " << f.get_Nfacture();

    bool test=f.ajouter();
    QMessageBox msgBox;
   if(test){
        ui->tabfacture->setModel(tmpfacture.afficher());
      /*  QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                          QObject::tr("Etudiant ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);*/
        msgBox.setText("ajouter avec succées");
 msgBox.exec();

}
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int nfacture = ui->lineEdit_fact->text().toInt();
       bool test=tmpfacture.supprimer(nfacture);
       if(test)
      {
           ui->tabfacture->setModel(tmpfacture.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("Supprimer une facture"),
                       QObject::tr("Facture supprimé.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer  une facture"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_modifier_clicked()
{
 tmpfacture.set_nom_fournisseur(ui->lineEdit_name_2->text());
 tmpfacture.set_prenom_fournisseur(ui->lineEdit_prenom_2->text());
tmpfacture.set_codepostal(ui->lineEdit_codepostal_2->text());
tmpfacture.set_telephone(ui->lineEdit_adresse_2->text());
tmpfacture.set_courriel(ui->lineEdit_courriel->text());
tmpfacture.set_date(ui->dateEdit_2->text());
bool test=tmpfacture.modifier_facture();
if (test){
    refresh();
    QMessageBox::information(nullptr, QObject::tr("modifier une facture"),
            QObject::tr("Facture modifier.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

}


void MainWindow::on_comboBox_activated(const int &arg1)
{
    tmpfacture.set_Nfacture(arg1);
    tmpfacture.chercher();
    ui->lineEdit_name_2->setText(tmpfacture.get_nom_fournisseur());
    ui->lineEdit_prenom_2->setText(tmpfacture.get_prenom_fournisseur());
    ui->lineEdit_adresse_2->setText(tmpfacture.get_adresse());
    ui->lineEdit_courriel_2->setText(tmpfacture.get_courriel());
    ui->lineEdit_codepostal_2->setText(tmpfacture.get_codepostal());
    ui->lineEdit_telephone_2->setText(tmpfacture.get_telephone());
    refresh();

}



/*

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{  etat=arg1;
    ui->tabfacture->setModel(tmpfacture.recherche(valeur,etat));
    refresh();
    Facture f;
       qDebug()<<"la valeur de num "<< f.get_Nfacture();
}


void MainWindow::on_lineEdit_textChanged(const int &arg1)
{
    ui->tabfacture->setModel(tmpfacture.recherche(arg1,etat));
        valeur=arg1;
        refresh();
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
   player->setPosition(position);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
  player->setVolume(position);
}

void MainWindow::on_pushButton_4_clicked()
{
    player->setMedia(QUrl::fromLocalFile(":/sound/minimalist-approach-ihsandincer-download-mp3-melody-loops-1.mp3"));
    player->play();
    qDebug()<<player->errorString();
}

void MainWindow::on_pushButton_5_clicked()
{
    player->stop();
}

void MainWindow::on_duration_changed(int position)
{
    ui->horizontal->setValue(position);
}

void MainWindow::on_position_changed(int position)
{
ui->horizontalSlider_2->setMaximum(position);
}
*/
