#include "mail.h"
#include "ui_mail.h"
#include <src/SmtpMime>
#include <mainwindow.h>
Mail::Mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mail)
{
    ui->setupUi(this);
}

Mail::~Mail()
{
    delete ui;
}
void MainWindow::on_pushButton_17_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
       smtp.setUser("hiba.sboui@esprit.tn");
       smtp.setPassword("hibasboui11");
       MimeMessage message;
       message.setSender(new EmailAddress("hiba.sboui@esprit.tn", "hiba"));
       message.addRecipient(new EmailAddress(ui->email->text(), "Recipient's Name"));
       message.setSubject(ui->objet->text());
       MimeText text;
       text.setText(ui->lineEdit_3->text());
       message.addPart(&text);
       smtp.connectToHost();
       smtp.login();
       smtp.sendMail(message);
       smtp.quit();
}
