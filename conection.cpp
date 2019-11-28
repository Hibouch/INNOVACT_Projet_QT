#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
                            db.setDatabaseName("testfinal");
                            db.setUserName("yousseff");//inserer nom de l'utilisateur
                            db.setPassword("youssef");//inserer mot de passe de cet utilisateur
                            db.open();
}
bool Connection::ouvrirConnection(){
    bool test=false;



    if (db.isOpen())
        test=true;
    qDebug()<<db.lastError().text();
    return  t
}
