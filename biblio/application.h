#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class QTranslator;

namespace Biblio {

class BiblioModel;

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int argc, char *argv[]);
    virtual ~Application();

    BiblioModel *model() const;

protected slots:
    void setupLanguage(const QString &lcode);

private:
    Application();
    Q_DISABLE_COPY(Application)

    BiblioModel *mdl;
    QTranslator *t;
};

}

#define bblApp qobject_cast< ::Biblio::Application *>(qApp)

#endif // APPLICATION_H
