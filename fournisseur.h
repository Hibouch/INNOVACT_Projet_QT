#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QString,QString,QString);
         void set_cin(int cin);
        void set_nom_fournisseur(QString n);
        void set_prenom_fournisseur(QString p);
        void set_courriel(QString c);
        void set_telephone(QString t);
        QString get_nom_fournisseur();
        QString get_prenom_fournisseur();
        QString get_telephone();
        QString get_courriel();
        int get_cin();
        bool ajouter_fournisseur( );
        QSqlQueryModel* afficher_fournisseur();
        bool supprimer(int cin);
        bool modifier_fournisseur(Fournisseur fo);
private:
    QString nom_fournisseur,prenom_fournisseur,courriel,telephone;
    int cin;

};

#endif // FOURNISSEUR_H
