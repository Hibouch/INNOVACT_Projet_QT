#ifndef DIREC_H
#define DIREC_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateEdit>
class Direc
{public:
    Direc();
    Direc(int,QString,QString,QString);
    QString get_nomc();
    QString get_prenomc();
    QString get_dsc() ;
    int get_idc();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nomc,prenomc,dsc;
    //QDate datee;
    int idc;
};

#endif // ETUDIANT_H
