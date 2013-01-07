#include "include/menu/NewGameDialog.h"
#include "include/menu/MainDialog.h"
#include "ui_NewGameDialog.h"
#include "include/enum/Enum.h"
#include "include/engine/GameEngine.h"

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


    GameEngine *ge = new GameEngine(gameMode, duration, player1, player2, difficulty, this);
    md->setGameEngine(ge);
    connect(ge, SIGNAL(endGame()), md, SLOT(endGame()));
    close();
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
