#include "include/menu/NewGameDialog.h"
#include "ui_NewGameDialog.h"
#include "include/enum/Enum.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);

    ui->cbbGametype->addItem(tr("Deathmatch"), DeathMatch);
    ui->cbbGametype->addItem(tr("Timer"), Timer);

    // TODO : Fill the player ships comboboxes
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::on_btnBack_clicked()
{
    close();
}

void NewGameDialog::on_btnStart_clicked()
{

}

void NewGameDialog::on_cbbGametype_currentIndexChanged(int index)
{
    if(ui->cbbGametype->itemData(index) == DeathMatch)
    {
        ui->teeDuration->setEnabled(false);
    }
    else if(ui->cbbGametype->itemData(index) == Timer)
    {
        ui->teeDuration->setEnabled(true);
    }
}
