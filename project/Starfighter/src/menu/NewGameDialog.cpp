#include "include/menu/NewGameDialog.h"
#include "ui_NewGameDialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::on_btnBack_clicked()
{

}

void NewGameDialog::on_btnStart_clicked()
{

}
