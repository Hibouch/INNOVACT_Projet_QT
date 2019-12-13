#include "ticket.h"
#include <QDebug>
#include "mainwindow.h"

ticket::ticket()
{    Numcaisse=0;
     Tickets="";
     Agent ="";
     Ref = 0 ;
     Nom ="";
     Quantite=0 ;
     Prix =0 ;
     Total =0 ;

}
  ticket::ticket(int numcaisse,QString tickets,QString agent ,int Ref,QString nom,int quantite,int prix,int Total)
{ this->Numcaisse=numcaisse;
  this->Tickets=tickets;
  this->Agent=agent ;
  this->Ref=Ref;
  this->Nom=nom;
  this->Quantite=quantite;
  this->Prix=prix ;
  this->Total=Total ;

}



bool ticket::ajouterTicket(ticket t)
{
    QSqlQuery query;

    query.prepare("INSERT INTO TABTICKET (CAISSE, TICKETS, AGENT, REFS, NOM, QUANTITE, PRIX, TOTAL) "
                        "VALUES (:caisse, :tickets, :agent, :refs, :nom, :quantite, :prix, :total)");
    query.bindValue(":caisse",t.get_numcaisse());
    query.bindValue(":tickets",t.get_numticket());
    query.bindValue(":agent",t.get_agent());
    query.bindValue(":refs",t.get_RefArticle());
    query.bindValue(":nom",t.get_nomArticle());
    query.bindValue(":quantite",t.get_quantiteArticle());
    query.bindValue(":prix",t.get_prixArticle());
    query.bindValue(":total",t.get_prixTotal());
    return query.exec();
}

QSqlQueryModel * ticket::afficherTicket()
{QSqlQueryModel * model1= new QSqlQueryModel();
model1->setQuery("select * from TABTICKET");
model1->setHeaderData(0, Qt::Horizontal, QObject::tr("caisse"));
model1->setHeaderData(1, Qt::Horizontal, QObject::tr("tickets"));
model1->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
model1->setHeaderData(3, Qt::Horizontal, QObject::tr("refs"));
model1->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
model1->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
model1->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));
model1->setHeaderData(7, Qt::Horizontal, QObject::tr("total"));
    return model1;
}


bool ticket::supprimerTicket(QString tickett)
{
QSqlQuery query;
//QString Tickets = QString::number(tickett);
query.prepare("Delete from TABTICKET where TICKETS =:tickets ");
query.bindValue(":tickets", tickett);
return    query.exec();
}
bool ticket::modifierTicket(ticket t)
{
    QSqlQuery query;

       query.prepare("UPDATE TABTICKET SET TICKETS=:tickets, AGENT=:agent, REFS=:refs, NOM=:nom , PRIX=:prix,TOTAL=:Total WHERE CAISSE=:caisse");
       query.bindValue(":caisse",t.get_numcaisse());
       query.bindValue(":tickets",t.get_numticket());
       query.bindValue(":agent",t.get_agent());
       query.bindValue(":refs",t.get_RefArticle());
       query.bindValue(":nom",t.get_nomArticle());
       query.bindValue(":quantite",t.get_quantiteArticle());
       query.bindValue(":prix",t.get_prixArticle());
       query.bindValue(":total",t.get_prixTotal());
    return query.exec();
}
QSqlQueryModel *ticket::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABTICKET ORDER BY TOTAL");
q->exec();
model->setQuery(*q);
return model;
}


QSqlQueryModel *ticket::rechercherTicket(QString tickett)
{
QSqlQueryModel * model1= new QSqlQueryModel();

model1->setQuery("select * from TABTICKET where TICKETS like '"+tickett+"' ");
model1->setHeaderData(0, Qt::Horizontal, QObject::tr("caisse"));
model1->setHeaderData(1, Qt::Horizontal, QObject::tr("tickets"));
model1->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
model1->setHeaderData(3, Qt::Horizontal, QObject::tr("refs"));
model1->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
model1->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));
model1->setHeaderData(6, Qt::Horizontal, QObject::tr("prix"));
model1->setHeaderData(7, Qt::Horizontal, QObject::tr("total"));
return model1;
}
