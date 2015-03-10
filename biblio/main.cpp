#include "mainwindow.h"
#include "application.h"

int main(int argc, char *argv[])
{
    Biblio::Application app(argc, argv);

    Biblio::MainWindow w;
    QObject::connect(&w, SIGNAL(languageChanged(QString)), &app, SLOT(setupLanguage(QString)));

    w.show();

    return app.exec();
}
