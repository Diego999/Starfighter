#include "include/menu/NewGameDialog.h"
#include "include/menu/MainDialog.h"
#include "ui_NewGameDialog.h"
#include "include/engine/GameEngine.h"
#include "include/config/Define.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    md = (MainDialog *)parent;

    ui->setupUi(this);

    ui->cbbGametype->addItem(tr("Deathmatch"), QVariant(DeathMatch));
    ui->cbbGametype->addItem(tr("Timer"), QVariant(Timer));

    ui->cbbP1ship->addItem(tr("Ship 1"), QVariant(SpaceshipType1));
    ui->cbbP1ship->addItem(tr("Ship 2"), QVariant(SpaceshipType2));
    ui->cbbP2ship->addItem(tr("Ship 1"), QVariant(SpaceshipType1));
    ui->cbbP2ship->addItem(tr("Ship 2"), QVariant(SpaceshipType2));
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::on_btnBack_clicked()
{
    close();
    delete this;
}

void NewGameDialog::on_btnStart_clicked()
{
    GameMode gameMode = (GameMode)(ui->cbbGametype->itemData(ui->cbbGametype->currentIndex()).toInt());
    int duration = ui->sbxDuration->value();
    SpaceshipType player1 = (SpaceshipType)(int)(ui->cbbP1ship->itemData(ui->cbbP1ship->currentIndex()).toInt());
    SpaceshipType player2 = (SpaceshipType)(int)(ui->cbbP2ship->itemData(ui->cbbP2ship->currentIndex()).toInt());
    int difficulty = 0;
    difficulty |= ((ui->cbxAlien->checkState() / Qt::Checked) * AlienMothership);
    difficulty |= ((ui->cbxAsteroid->checkState() / Qt::Checked) * Asteroids);
    difficulty |= ((ui->cbxSatellite->checkState() / Qt::Checked) * Satellites);
    difficulty |= ((ui->cbxSupernova->checkState() / Qt::Checked) * Supernovae);

    if(difficulty == Supernovae)
    {
        QMessageBox::warning(this, tr("Supernovae only"), tr("Sorry, you cannot play with supernovae only."));
    }
    else
    {
        GameEngine *ge = new GameEngine(gameMode, duration, player1, player2, difficulty, this);
        md->setGameEngine(ge);
        connect(ge, SIGNAL(endGame()), md, SLOT(endGame()));
        close();
    }
}

void NewGameDialog::on_cbbGametype_currentIndexChanged(int index)
{
    if(ui->cbbGametype->itemData(index) == DeathMatch)
    {
        ui->sbxDuration->setEnabled(false);
    }
    else if(ui->cbbGametype->itemData(index) == Timer)
    {
        ui->sbxDuration->setEnabled(true);
    }
}

void NewGameDialog::setPixmapForLabelWithSpaceshipType(SpaceshipType sType, QLabel *lbl)
{
    if(lbl == NULL)
        return;

    switch(sType)
    {
    case SpaceshipType1:
        lbl->setPixmap(QPixmap(PICTURE_SPACESHIP_1));
        break;
    case SpaceshipType2:
        lbl->setPixmap(QPixmap(PICTURE_SPACESHIP_2));
        break;
    }
}

void NewGameDialog::on_cbbP1ship_currentIndexChanged(int index)
{
    SpaceshipType player1 = (SpaceshipType)(int)(ui->cbbP1ship->itemData(ui->cbbP1ship->currentIndex()).toInt());
    setPixmapForLabelWithSpaceshipType(player1, ui->imgP1);
}

void NewGameDialog::on_cbbP2ship_currentIndexChanged(int index)
{
    SpaceshipType player2 = (SpaceshipType)(int)(ui->cbbP2ship->itemData(ui->cbbP2ship->currentIndex()).toInt());
    setPixmapForLabelWithSpaceshipType(player2, ui->imgP2);
}
