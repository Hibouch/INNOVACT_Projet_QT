#include "fournisseur.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

Fournisseur::Fournisseur()
{

        cin=0;
        nom_fournisseur="";
        prenom_fournisseur="";
        courriel="";
        telephone="";

}

Fournisseur::Fournisseur(int cin,QString nom_fournisseur,QString prenom_fournisseur,QString courriel,QString telephone){
    this->cin=cin;
    this->nom_fournisseur=nom_fournisseur;
    this->prenom_fournisseur=prenom_fournisseur;
     this->courriel=courriel;
    this->telephone=telephone;


}

void Fournisseur::set_cin(int CIN){
    cin=CIN;
}

void Fournisseur::set_nom_fournisseur(QString n){
    nom_fournisseur=n;
}

void Fournisseur::set_prenom_fournisseur(QString p){
    prenom_fournisseur=p;
}

void Fournisseur::set_telephone(QString t){
    telephone=t;
}
void Fournisseur::set_courriel(QString c){
    courriel=c;
}

int Fournisseur::get_cin(){
    return cin;
}
QString Fournisseur::get_nom_fournisseur(){
    return nom_fournisseur;
}

QString Fournisseur::get_prenom_fournisseur(){
    return prenom_fournisseur;
}
QString Fournisseur::get_telephone(){
    return telephone;
}
QString Fournisseur::get_courriel(){
    return courriel;
}

bool Fournisseur::ajouter_fournisseur()
{

QSqlQuery query;

 QString res=QString::number(cin);

query.prepare("INSERT INTO FOURNISSEUR (CIN,NOM,PRENOM,TELEPHONE,COURRIEL) ""VALUES (:CIN, :NOM, :PRENOM,:TELEPHONE,:COURRIEL)");
query.bindValue(":CIN", res);
 qDebug()<<"num"<<cin;
query.bindValue(":NOM", nom_fournisseur);
 query.bindValue(":PRENOM", prenom_fournisseur);
query.bindValue(":TELEPHONE", telephone);
query.bindValue(":COURRIEL", courriel);

 return    query.exec();

}


QSqlQueryModel* Fournisseur::afficher_fournisseur(){

QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("courriel"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
return model;
}

bool Fournisseur::supprimer(int cin){
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("Delete from FOURNISSEUR where CIN = :CIN ");
    query.bindValue(":CIN",res);
    return query.exec();

}
bool Fournisseur::modifier_fournisseur(Fournisseur fo){
    QSqlQuery query;

   query.prepare("update FOURNISSEUR set CIN=:CIN,NOM=:NOM,PRENOM=:PRENOM,TELEPHONE=:TELEPHONE,COURRIEL=:COURRIEL where CIN=:CIN");
   query.bindValue(":CIN",fo.get_cin());
   query.bindValue(":NOM", fo.get_nom_fournisseur());
    query.bindValue(":PRENOM", fo.get_prenom_fournisseur());
    query.bindValue(":TELEPHONE", fo.get_telephone());
    query.bindValue(":COURRIEL", fo.get_courriel());

    return    query.exec();

}
