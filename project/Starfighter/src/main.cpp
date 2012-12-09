#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include "include/menu/MainDialog.h"
#include "include/engine/DisplayEngine.h"//
#include "include/engine/GameEngine.h"//
#include "include/game/Asteroid.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*QTranslator translator;
    if (translator.load(QLocale::system(), "starfighter", "_", ":/strings/", ".qm"))
    {
        app.installTranslator(&translator);
    }

    MainDialog md;
    md.show();*/
    GameEngine* ge = new GameEngine;
    //for(int i = 0;i<1;i++)
    //ge->displayEngine()->addAsteroide(new Asteroid(0,0,Other,0,0,ge,0));

    return app.exec();
}
