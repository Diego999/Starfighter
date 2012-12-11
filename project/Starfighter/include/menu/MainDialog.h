#ifndef MAINDIALOG_H
#define MAINDIALOG_H

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();
    
private slots:
    void on_btnPlay_clicked();

    void on_btnOptions_clicked();

    void on_btnAbout_clicked();

private:
    Ui::MainDialog *ui;
};

#endif // MAINDIALOG_H
