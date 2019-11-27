#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ticket
{  public:
    ticket() ;
    ticket(int,int,QString,int,QString,int,int,int);
    int get_RefArticle () { return Ref; }
    int get_quantiteArticle() {return Quantite ;}
    int get_prixArticle() {return Prix ;}
    int get_prixTotal() {return Total;}
    int get_numticket(){return Ticket;}
    int get_numcaisse(){return Numcaisse;}
    QString get_nomArticle(){return Nom ;}
    QString get_agent(){return Agent ;}
    void setNomarticle(QString);
    void setagent (QString);
    void setRefArticle(int);
    void setquantite(int);
    void setprixArticle(int);
    void setprixTotal(int);
    void setnumTicket (int);
    void setnumcaisse (int);
    bool ajouterTicket(ticket t);

    bool modifierTicket (ticket t);
    bool supprimerTicket(int );
    QSqlQueryModel * afficherTicket();

    QSqlQueryModel *rechercherTicket(QString );
    QSqlQueryModel *tri();

    private:
    int Numcaisse ;
    QString Agent ;
    int Ticket;
    int Ref ;
    QString Nom;
    int Quantite ;
    int Prix ;
    int Total ;


};

#endif // TICKET_H
