#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

namespace Biblio {

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int argc, char *argv[]);
    virtual ~Application();

private:
    Application();
    Q_DISABLE_COPY(Application)
};

}

#endif // APPLICATION_H
