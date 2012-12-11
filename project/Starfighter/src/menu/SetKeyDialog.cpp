#include "include/menu/SetKeyDialog.h"
#include <QKeyEvent>
#include <QLabel>

SetKeyDialog::SetKeyDialog(QWidget *parent) :
    QDialog(parent)
{
    new QLabel(tr("Please press the key now"), this);
}

void SetKeyDialog::keyPressEvent(QKeyEvent *event)
{
    Qt::Key key = (Qt::Key)event->key();
    if(key != Qt::Key_Escape && key != Qt::Key_F12)
    {
        emit keySelected(key);
        close();
    }
}
