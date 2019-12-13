#ifndef MAIL_H
#define MAIL_H

#include <QDialog>

namespace Ui {
class Mail;
}

class Mail : public QDialog
{
    Q_OBJECT

public:
    explicit Mail(QWidget *parent = nullptr);
    ~Mail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Mail *ui;
};

#endif // MAIL_H
