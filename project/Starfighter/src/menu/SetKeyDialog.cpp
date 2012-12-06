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
    emit keySelected(key);
    close();
}
