#include "include/menu/OptionsDialog.h"
#include "include/utils/Settings.h"
#include "ui_OptionsDialog.h"
#include <QMessageBox>
#include "include/enum/Enum.h"
#include "include/menu/SetKeyDialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);

    inSetting = -1;

    btgKeys = new QButtonGroup(this);
    btgKeys->addButton(ui->btnP1Up, Top1);
    btgKeys->addButton(ui->btnP2Up, Top2);
    btgKeys->addButton(ui->btnP1Down, Bottom1);
    btgKeys->addButton(ui->btnP2Down, Bottom2);
    btgKeys->addButton(ui->btnP1Fire, Shoot1);
    btgKeys->addButton(ui->btnP2Fire, Shoot2);

    Settings& s = Settings::getGlobalSettings();
    ui->ledP1name->setText(s.playerOneName());
    ui->ledP2name->setText(s.playerTwoName());

    ui->sliderMusicVolume->setValue(s.musicVolume());
    ui->sliderSoundEffectsVolume->setValue(s.soundEffectsVolume());

    controls = new QMap<Action, Qt::Key>(s.playersControls());

    showKeys();

    connect(btgKeys, SIGNAL(buttonClicked(int)), this, SLOT(keyChange(int)));
}

OptionsDialog::~OptionsDialog()
{
    delete controls;
    delete ui;
}

void OptionsDialog::keyChange(int iKey)
{
    Action key = (Action)iKey;
    inSetting = key;

    SetKeyDialog *skd = new SetKeyDialog(this);
    connect(skd, SIGNAL(keySelected(Qt::Key)), this, SLOT(setKey(Qt::Key)));
    skd->exec();
}

void OptionsDialog::on_btnBack_clicked()
{
    this->close();
}

void OptionsDialog::on_btnSave_clicked()
{
    Settings& s = Settings::getGlobalSettings();

    s.setPlayerOneName(ui->ledP1name->text());
    s.setPlayerTwoName(ui->ledP2name->text());

    s.setMusicVolume(ui->sliderMusicVolume->value());
    s.setSoundEffectsVolume(ui->sliderSoundEffectsVolume->value());

    s.setPlayersControls(*controls);

    QMessageBox::information(this, tr("Saved"), tr("The settings were successfully saved"));
    this->close();
}

void OptionsDialog::showKeys()
{
        ui->btnP1Up->setText((QString)QKeySequence(controls->value(Top1)));
        ui->btnP2Up->setText((QString)QKeySequence(controls->value(Top2)));
        ui->btnP1Down->setText((QString)QKeySequence(controls->value(Bottom1)));
        ui->btnP2Down->setText((QString)QKeySequence(controls->value(Bottom2)));
        ui->btnP1Fire->setText((QString)QKeySequence(controls->value(Shoot1)));
        ui->btnP2Fire->setText((QString)QKeySequence(controls->value(Shoot2)));
}

void OptionsDialog::setKey(Qt::Key key)
{
    controls->insert((Action)inSetting, key);
    inSetting = -1;
    showKeys();
}
