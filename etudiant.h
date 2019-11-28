#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateEdit>
class Etudiant
{public:
    Etudiant();
    Etudiant(int,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_ds() ;
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *recherche(QString) ;
    QSqlQueryModel *tri() ;
      bool modifier(Etudiant E) ;
private:
    QString nom,prenom,ds;
    //QDate datee;
    int id;
};

#endif // ETUDIANT_H
