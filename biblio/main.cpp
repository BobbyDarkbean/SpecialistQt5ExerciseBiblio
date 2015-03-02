#include "mainwindow.h"
#include "application.h"

int main(int argc, char *argv[])
{
    Biblio::Application app(argc, argv);

    Biblio::MainWindow w;
    w.show();

    return app.exec();
}
