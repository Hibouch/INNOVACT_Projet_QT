#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "direc.h"
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabetudiant->setModel(tmpetudiant.afficher());
ui->tabdirec->setModel (tmpdirec.afficher()) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QDate datee = ui->dateEdit -> date();
    QString ds=datee.toString() ;


  Etudiant e(id,nom,prenom,ds);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int idc = ui->lineEdit_idc->text().toInt();
    QString nomc= ui->lineEdit_nomc->text();
    QString prenomc= ui->lineEdit_prenomc->text();
    QDate dateee = ui->dateEditc -> date();
    QString dsc=dateee.toString() ;


  Direc eE(idc,nomc,prenomc,dsc);
  bool test=eE.ajouter();
  if(test)
{ui->tabdirec->setModel(tmpdirec.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un direc"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un direc "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpetudiant.supprimer(id);
if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_supprimer_2_clicked()
{
int id = ui->lineEdit_id_4->text().toInt();
bool test=tmpdirec.supprimer(id);
if(test)
{ui->tabdirec->setModel(tmpdirec.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un direc"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un direc"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pushButton_clicked()
{
    QString recherche= ui->lineEdit_recherche->text();
    ui->tabetudiant->setModel(tmpetudiant.recherche(recherche));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tabetudiant->setModel(tmpetudiant.tri());
}



void MainWindow::on_pushButton_3_clicked()
{

        int id = ui->id_1->text().toInt();
        QString nom= ui->lineEdit_nom_2->text();
        QString prenom= ui->lineEdit_prenom_2->text();
        QDate dateee = ui->dateEditc_2-> date();
        QString dsc=dateee.toString() ;

    Etudiant E (id, nom , prenom ,dsc );


     bool test=E.modifier(E);

     if (test)
     {
     QMessageBox::information(nullptr, QObject::tr("modifier"),
                       QObject::tr(" client modifié .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
