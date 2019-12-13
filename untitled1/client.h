#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{  public:
    Client() ;
    Client(QString ,QString ,QString,QString, int);
    QString get_CIN( ){return CIN ;}
    int get_num() {return numero ;}
    QString get_nom(){ return  nom;}
    QString get_prenom() {return prenom ;}
    QString get_email(){return  email ;}
    void setNom(QString);
    void setPrenom(QString);
    void setCIN(int);
    void setNum(int);
    void setEmail(QString);
    bool ajouter(Client c);
    bool modifier (Client c);
    bool supprimer(QString cinn);
    QSqlQueryModel * afficher();
    QSqlQueryModel *recherchernomclient(QString);
    QSqlQueryModel *tri();

    private:
    QString CIN ;
    int numero ;

    QString nom , prenom , email ;
};

#endif // CLIENT_H
