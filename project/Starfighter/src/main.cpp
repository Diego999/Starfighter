#include <QApplication>
#include "include/menu/MainDialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainDialog md;
    md.show();

    return app.exec();
}
