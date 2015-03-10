#include <QTranslator>
#include "application.h"

namespace Biblio {

Application::Application(int argc, char *argv[]) :
    QApplication(argc, argv),
    t(0)
{
    t = new QTranslator(this);
    setupLanguage("rus");
}

Application::~Application() { }

void Application::setupLanguage(const QString &lcode)
{
    t->load("biblio_" + lcode);
    installTranslator(t);
}

}
