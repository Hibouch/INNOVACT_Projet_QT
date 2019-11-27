#ifndef CNX_H
#define CNX_H
#include <QSqlDatabase>

class Cnx
{
private:
    QSqlDatabase db;
public:
    Cnx();
    bool ouvrirConnexion();
    void fermerConnexion();
};

#endif // CNX_H
