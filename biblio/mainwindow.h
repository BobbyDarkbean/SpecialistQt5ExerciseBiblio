#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
namespace Biblio {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

protected slots:
    void newItem();

private:
    Q_DISABLE_COPY(MainWindow)

    QAction *actNewItem;
};

} // namespace Biblio

#endif // MAINWINDOW_H
