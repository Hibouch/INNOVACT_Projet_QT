#include "cnx.h"
#include <QSqlError>
#include <QDebug>
Cnx::Cnx(){
                      }
bool Cnx::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Source_Projet2A");
                           db.setUserName("Soumaya");//inserer nom de l'utilisateur
                           db.setPassword("exprit18");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

qDebug()<<db.lastError().text();
return  test;
}
void Cnx::fermerConnexion()
{db.close();}
