#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();
    
private slots:
    void on_btnBack_clicked();

    void on_btnStart_clicked();

    void on_cbbGametype_currentIndexChanged(int index);

private:
    Ui::NewGameDialog *ui;
};

#endif // NEWGAMEDIALOG_H
