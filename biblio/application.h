#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class QTranslator;

namespace Biblio {

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int argc, char *argv[]);
    virtual ~Application();

protected slots:
    void setupLanguage(const QString &lcode);

private:
    Application();
    Q_DISABLE_COPY(Application)

    QTranslator *t;
};

}

#endif // APPLICATION_H
