#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Facture
{
public:
    Facture();
    Facture(int,QString,QString,QString ,QString ,QString ,QString,QString  );
    void set_nom_fournisseur(QString n);
    void set_prenom_fournisseur(QString p);
    void set_adresse(QString a);
    void set_courriel(QString c);
     void set_codepostal(QString p);
    void set_telephone(QString t);
    void set_date(QString d);
    void set_Nfacture(int f);
    QString get_nom_fournisseur();
    QString get_prenom_fournisseur();
    QString get_adresse();
    QString get_courriel();
    QString get_codepostal();
    QString get_telephone();
     QString get_date();
    int get_Nfacture();
    bool ajouter( );
    bool modifier_facture();
    QSqlQueryModel* afficher();
     QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel* recherche(int valeur,int etat);
    bool supprimer(int );
private:
    QString nom_fournisseur,prenom_fournisseur,adresse,courriel,codepostal,telephone,date;
    int Nfacture;

};

#endif // FACTURE_H
