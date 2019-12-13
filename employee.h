#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateEdit>

class Employee
{
public:
    Employee();
   Employee(QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_ds() ;
    QString  get_id();
    void set_ds(QString) ;
    void set_prenom(QString) ;
    void set_nom(QString) ;
    void set_id(QString) ;
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel *recherche(QString) ;
    QSqlQueryModel *tri() ;
      bool modifier( Employee E) ;
private:
    QString nom,prenom,ds;
    //QDate datee;
    QString id;
};

#endif // EMPLOYEE_H
