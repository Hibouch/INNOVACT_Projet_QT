#include "client.h"
#include <QDebug>
Client::Client()
{
CIN =0;
nom="";
prenom="";
email="";
numero=0;

}
Client::Client(int CIN,QString nom,QString prenom ,QString email , int numero)
{
  this->CIN=CIN;
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->numero=numero ;

}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return this->prenom;}
QString Client::get_email(){return email;}
int Client::get_CIN(){return  CIN;}
int Client::get_num(){return  numero;}

bool Client::ajouter(Client C)
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABCLIENT (CIN, NOM, PRENOM, EMAIL, NUMERO) "
                        "VALUES (:cin, :nom, :prenom, :email, :numero)");
    query.bindValue(":cin",C.get_CIN());
    query.bindValue(":nom",C.get_nom());
    query.bindValue(":prenom",C.get_prenom());
    query.bindValue("email",C.get_email());
    query.bindValue(":numero",C.get_num());
    return query.exec();
}


QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABCLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
    return model;
}

bool Client::supprimer(int cinn)
{
QSqlQuery query;
QString CIN= QString::number(cinn);
query.prepare("Delete from tabclient where CIN = :CIN ");
query.bindValue(":CIN", CIN);
return    query.exec();
}
bool Client::modifier(Client C)
{
    QSqlQuery query;

       query.prepare("UPDATE TABCLIENT SET NOM =:nom , PRENOM =:prenom , EMAIL =:email ,NUMERO =:numero WHERE CIN =:cin ");
       query.bindValue(":cin", C.get_CIN());
       query.bindValue(":nom", C.get_nom());
       query.bindValue(":prenom",C.get_prenom());
       query.bindValue(":email", C.get_email());
       query.bindValue(":email", C.get_num());
    return query.exec();
}
QSqlQueryModel *Client::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABCLIENT ORDER BY NOM");
q->exec();
model->setQuery(*q);
return model;
}


QSqlQueryModel *Client::recherchernomclient(QString nomc)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABCLIENT where NOM like '"+nomc+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
return model;
}
