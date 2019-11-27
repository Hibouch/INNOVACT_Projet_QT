#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include"ticket.h"
#include <QMainWindow>
#include <QComboBox>

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

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    //void on_pushButton_5_clicked();


   // void on_pushButton_5_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    Client tmpclient;
    ticket tmpticket;
};
#endif // MAINWINDOW_H
