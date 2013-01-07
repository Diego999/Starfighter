#include "include/menu/MainDialog.h"
#include "include/menu/OptionsDialog.h"
#include "include/menu/NewGameDialog.h"
#include "include/menu/AboutDialog.h"
#include "ui_MainDialog.h"
#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    ge = 0;
    ngd = 0;
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_btnPlay_clicked()
{
    ngd = new NewGameDialog(this);
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

void MainDialog::setGameEngine(GameEngine *ge)
{
    if(ge != 0)
        this->ge = ge;
}

void MainDialog::endGame()
{
    ge->deleteLater();
    ngd->deleteLater();
    ngd=0;
    ge=0;
}
