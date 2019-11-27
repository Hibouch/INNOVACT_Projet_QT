#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{  public:
    Client() ;
    Client(int ,QString ,QString,QString, int);
    int get_CIN();
    int get_num();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    void setNom(QString);
    void setPrenom(QString);
    void setCIN(int);
    void setNum(int);
    void setEmail(QString);
    bool ajouter(Client c);
    bool modifier (Client c);
    bool supprimer(int cinn);
    QSqlQueryModel * afficher();
    QSqlQueryModel *recherchernomclient(QString );
    QSqlQueryModel *tri();

    private:
    int CIN ;
    int numero ;

    QString nom , prenom , email ;
};

#endif // CLIENT_H
