#include "direc.h"
#include <QDebug>
#include <QDate>
Direc::Direc()

{
idc=0;
nomc="";
prenomc="";

}
Direc:: Direc(int idc,QString nomc,QString prenomc , QString dsc)
{
  this->idc=idc;
  this->nomc=nomc;
  this->prenomc=prenomc;
  this ->dsc= dsc ;
}
int Direc::get_idc(){return  idc;}
QString Direc::get_nomc(){return  nomc;}
QString Direc::get_prenomc(){return prenomc;}
QString Direc::get_dsc(){return dsc;}


bool Direc::ajouter()
{
QSqlQuery query;
QString ress= QString::number(idc);
query.prepare("INSERT INTO DIREC (IDC, NOMC, PRENOMC,DSC) "
                    "VALUES (:idc, :nomc, :prenomc, :dsc)");
query.bindValue(":idc", ress);
query.bindValue(":nomc", nomc);
query.bindValue(":prenomc", prenomc);
query.bindValue(":dsc", dsc);

return    query.exec();
}

QSqlQueryModel * Direc::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from DIREC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDC"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nomc "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénomc"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DSC"));
    return model;
}

bool Direc::supprimer(int iddd)
{
QSqlQuery query;
QString ress= QString::number(iddd);
query.prepare("Delete from DIREC where IDC = :iddd ");
query.bindValue(":iddd", ress);
return    query.exec();
}


