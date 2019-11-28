#include "etudiant.h"
#include <QDebug>
#include <QDate>
Etudiant::Etudiant()

{
id=0;
nom="";
prenom="";
}
Etudiant:: Etudiant(int id,QString nom,QString prenom , QString ds)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this -> ds = ds ;
}
QString Etudiant::get_nom(){return  nom;}
QString Etudiant::get_prenom(){return prenom;}
QString Etudiant::get_ds(){return ds;}
int Etudiant::get_id(){return  id;}

bool Etudiant::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO etudiant (ID, NOM, PRENOM,ds) "
                    "VALUES (:id, :nom, :prenom, :ds)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":ds", ds);

return    query.exec();
}

QSqlQueryModel * Etudiant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ds"));
    return model;
}

bool Etudiant::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


QSqlQueryModel *Etudiant ::recherche(QString nomc)
{


QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Etudiant where nom like '"+nomc+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("ds"));
return model;
}

QSqlQueryModel *Etudiant::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM Etudiant ORDER BY nom ");
q->exec();
model->setQuery(*q);
return model;
}

bool Etudiant::modifier(Etudiant E)
{
    QSqlQuery query;

       query.prepare("UPDATE Etudiant SET NOM =:nom , PRENOM =:prenom ,DS=:ds WHERE ID =:id ");
       query.bindValue(":cin", E.get_id());
       query.bindValue(":nom", E.get_nom());
       query.bindValue(":prenom",E.get_prenom());
       query.bindValue(":email", E.get_ds());

    return query.exec();
}
