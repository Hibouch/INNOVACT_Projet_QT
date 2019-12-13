#include "employee.h"
#include <QDebug>
#include <QDate>
 Employee:: Employee()

{
id="";
nom="";
prenom="";
}
 Employee::  Employee (QString id,QString nom,QString prenom , QString ds)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this -> ds = ds ;
}
QString  Employee::get_nom(){return  nom;}
QString  Employee::get_prenom(){return prenom;}
QString  Employee::get_ds(){return ds;}
QString Employee::get_id(){return  id;}
void  Employee::set_ds(QString de){ds=de;}
void  Employee::set_nom(QString ne){nom=ne;}
void  Employee::set_prenom(QString pe){prenom=pe;}
void  Employee::set_id(QString ie){id=ie;}

bool Employee::ajouter()
{
QSqlQuery query;
//QString res= QString::number(id);
query.prepare("INSERT INTO employee (ID, NOM, PRENOM,ds) "
                    "VALUES (:id, :nom, :prenom, :ds)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":ds", ds);

return    query.exec();
}

QSqlQueryModel *  Employee::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  employee");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ds"));
    return model;
}

bool Employee::supprimer (QString idd)
{
QSqlQuery query;
//QString res= QString::number(idd);
query.prepare("Delete from  employee where ID = :id ");
query.bindValue(":id", idd);
return    query.exec();
}


QSqlQueryModel * Employee ::recherche(QString nomc)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from  employee where nom like '"+nomc+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("ds"));
return model;
}

QSqlQueryModel * Employee::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM  employee ORDER BY nom ");
q->exec();
model->setQuery(*q);
return model;
}

bool  Employee::modifier( Employee e)
{
    QSqlQuery query;

       query.prepare("UPDATE  employee SET NOM =:nom, PRENOM =:prenom ,DS=:ds WHERE ID=:id");
       query.bindValue(":id", e.get_id());
       query.bindValue(":nom", e.get_nom());
       query.bindValue(":prenom",e.get_prenom());
       query.bindValue(":ds", e.get_ds());

    return query.exec();
}
