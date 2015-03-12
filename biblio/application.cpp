#include <QTranslator>
#include "bibliomodel.h"

#include "application.h"

namespace Biblio {

Application::Application(int argc, char *argv[]) :
    QApplication(argc, argv),
    mdl(0),
    t(0)
{
    t = new QTranslator(this);
    setupLanguage("rus");

    mdl = new BiblioModel(this);
}

Application::~Application() { }

BiblioModel *Application::model() const { return mdl; }

void Application::setupLanguage(const QString &lcode)
{
    t->load(":/lang/" + lcode);
    installTranslator(t);
//    setLayoutDirection(Qt::RightToLeft);
}

}
