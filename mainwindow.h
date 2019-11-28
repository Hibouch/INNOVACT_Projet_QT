#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "etudiant.h"
#include "direc.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_ajouter_2_clicked();
    void on_pb_supprimer_clicked();
     void    on_pb_supprimer_2_clicked();

     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Etudiant tmpetudiant;
    Direc tmpdirec ;
};

#endif // MAINWINDOW_H
