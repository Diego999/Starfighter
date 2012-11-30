#include "include/menu/MainDialog.h"
#include "include/menu/OptionsDialog.h"
#include "include/menu/NewGameDialog.h"
#include "include/menu/AboutDialog.h"
#include "ui_MainDialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_btnPlay_clicked()
{
    NewGameDialog *ngd = new NewGameDialog(this);
    ngd->exec();
}

void MainDialog::on_btnOptions_clicked()
{
    OptionsDialog *od = new OptionsDialog(this);
    od->exec();
}

void MainDialog::on_btnAbout_clicked()
{
    AboutDialog *ad = new AboutDialog(this);
    ad->exec();
}
