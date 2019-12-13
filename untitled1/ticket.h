#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QPainter"
#include"QPdfWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
class ticket
{  public:
    ticket() ;
    ticket(int,QString,QString,int,QString,int,int,int);
    int get_RefArticle () { return Ref; }
    int get_quantiteArticle() {return Quantite ;}
    int get_prixArticle() {return Prix ;}
    int get_prixTotal() {return Total;}
    QString get_numticket(){return Tickets;}
    int get_numcaisse(){return Numcaisse;}
    QString get_nomArticle(){return Nom ;}
    QString get_agent(){return Agent ;}
    void setNomarticle(QString);
    void setagent (QString);
    void setRefArticle(int);
    void setquantite(int);
    void setprixArticle(int);
    void setprixTotal(int);
    void setnumTicket (QString);
    void setnumcaisse (int);
    bool ajouterTicket(ticket t);
    bool modifierTicket (ticket t);
    bool supprimerTicket(QString );
    QSqlQueryModel * afficherTicket();

    QSqlQueryModel *rechercherTicket(QString );
    QSqlQueryModel *tri();

    private:
    int Numcaisse ;
    QString Agent ;
    QString Tickets;
    int Ref ;
    QString Nom;
    int Quantite ;
    int Prix ;
    int Total ;


};

#endif // TICKET_H
