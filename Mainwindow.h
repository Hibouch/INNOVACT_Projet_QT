#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "facture.h"
#include <QMainWindow>
#include <QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void refresh();
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_comboBox_activated(const int &arg1);



   // void on_checkBox_2_stateChanged(int arg1);

    /*void on_lineEdit_textChanged(const int &arg1);

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_duration_changed(int position);
    void on_position_changed(int position);*/
private:
    Ui::MainWindow *ui;
    Facture tmpfacture;
    int etat=0, valeur;
   // QMediaPlayer *player;
};
#endif // MAINWINDOW_H
