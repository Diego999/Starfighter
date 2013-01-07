#ifndef MAINDIALOG_H
#define MAINDIALOG_H

class GameEngine;
class NewGameDialog;

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();
    void setGameEngine(GameEngine *);

public slots:
    void endGame();
    
private slots:
    void on_btnPlay_clicked();

    void on_btnOptions_clicked();

    void on_btnAbout_clicked();

private:
    Ui::MainDialog *ui;
    GameEngine *ge;
    NewGameDialog *ngd;
};

#endif // MAINDIALOG_H
