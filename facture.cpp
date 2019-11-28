#include "facture.h"
#include <QDebug>
#include <QSqlError>

Facture::Facture()
{

    nom_fournisseur="";
    prenom_fournisseur="";
    Nfacture=0;
    adresse="";
    date="";
    courriel="";
    codepostal="";
    telephone="";
}


Facture::Facture(int Nfacture ,QString nom_fournisseur,QString prenom_fournisseur,QString adresse,QString date,QString courriel,QString codepostal,QString telephone){
    this->Nfacture=Nfacture;
    this->nom_fournisseur=nom_fournisseur;
    this->prenom_fournisseur=prenom_fournisseur;
    this->adresse=adresse;
    this->date=date;
    this->courriel=courriel;
    this->codepostal=codepostal;
    this->telephone=telephone;
}

void Facture::set_nom_fournisseur(QString n){
    nom_fournisseur=n;
}

void Facture::set_prenom_fournisseur(QString p){
    prenom_fournisseur=p;
}

void Facture::set_adresse(QString a){
    adresse=a;
}

void Facture::set_date(QString d){
     date=d;
}

void Facture::set_telephone(QString t){
    telephone=t;
}
void Facture::set_codepostal(QString p){
    codepostal=p;
}
void Facture::set_courriel(QString c){
    courriel=c;
}
void Facture::set_Nfacture(int f){
     Nfacture=f;
}

QString Facture::get_nom_fournisseur(){
    return nom_fournisseur;
}

QString Facture::get_prenom_fournisseur(){
    return prenom_fournisseur;
}

QString Facture::get_adresse(){
    return adresse;
}

QString Facture::get_date(){
    return date;
}

QString Facture::get_telephone(){
    return telephone;
}
QString Facture::get_codepostal(){
    return codepostal;
}
QString Facture::get_courriel(){
    return courriel;
}

int Facture::get_Nfacture(){return Nfacture;}

bool Facture::ajouter(){

QSqlQuery query;

 QString res=QString::number(Nfacture);

query.prepare("INSERT INTO FACTURE (NFACTURE, NOM, PRENOM,ADRESSE,TELEPHONE,CODEPOSTAL,COURRIEL) "
                     "VALUES (:NFACTURE, :NOM, :PRENOM,:ADRESSE,:TELEPHONE,:CODEPOSTAL,:COURRIEL)");
 query.bindValue(":NFACTURE", res);
 query.bindValue(":NOM", nom_fournisseur);
 query.bindValue(":PRENOM", prenom_fournisseur);
 query.bindValue(":ADRESSE", adresse);
 query.bindValue(":TELEPHONE", telephone);
 /*query.bindValue(":DATE", date);*/
  query.bindValue(":CODEPOSTAL", codepostal);
    query.bindValue(":COURRIEL", courriel);
    //qDebug()<<query.lastError().text()<<nom_fournisseur;
 return    query.exec();

}

bool Facture::modifier_facture(){

    QSqlQuery query;
     QString res=QString::number(Nfacture);

    query.prepare("update FACTURE set NFACTURE=:NFACTURE,NOM=:NOM,PRENOM=:PRENOM,ADRESSE=:ADRESSE,TELEPHONE=:TELEPHONE,CODEPOSTAL=:CODEPOSTAL,COURRIEL=:COURRIEL where NFACTURE=:NFACTURE");
    query.bindValue(":NFACTURE",res);
    query.bindValue(":NOM", nom_fournisseur);
    query.bindValue(":PRENOM", prenom_fournisseur);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":CODEPOSTAL", codepostal);
    query.bindValue(":COURRIEL", courriel);
        qDebug()<<query.lastError().text()<<nom_fournisseur;
    return    query.exec();
}

QSqlQueryModel* Facture::afficher(){

QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from FACTURE");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("Nfacture"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("codepostal"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("courriel"));
return model;
}

QSqlQueryModel * Facture::afficher_list(){

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select NFACTURE from FACTURE");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Nfacture"));

    return model;
}

void Facture::chercher(){
    QSqlQuery query1;
  //  QString res=QString::number(Nfacture);
    query1.prepare("SELECT  NOM,PRENOM,ADRESSE,TELEPHONE,CODEPOSTAL,COURRIEL FROM FACTURE WHERE Nfacture =:Nfacture");
     query1.bindValue(":Nfacture",Nfacture);
     query1.exec();
     while(query1.next())
          {
          Nfacture=query1.value(1).toInt();
          nom_fournisseur = query1.value(0).toString();
          prenom_fournisseur = query1.value(0).toString();
          telephone = query1.value(0).toString();
          courriel = query1.value(0).toString();
          adresse = query1.value(0).toString();
          }

}
QSqlQueryModel * Facture::recherche(int valeur,int etat){

    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM FACTURE WHERE NFACTURE LIKE :valeur order by NFACTURE");}
    else   { query.prepare("SELECT * FROM FACTURE WHERE NFACTURE LIKE :valeur order by NFACTURE desc");}
        /*valeur="%"+valeur+"%";*/
        query.bindValue(":valeur",valeur);
            query.exec();
            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nfacture"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("codepostal"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("courriel"));
            return model;

}
bool Facture::supprimer(int Nfacture){
    QSqlQuery query;
    QString res=QString::number(Nfacture);
    query.prepare("Delete from facture where Nfacture = :Nfacture ");
    query.bindValue(":Nfacture",res);
    return query.exec();
}
