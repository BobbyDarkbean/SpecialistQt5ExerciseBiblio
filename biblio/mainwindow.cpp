#include <QToolButton>
#include <QMenuBar>
#include "itemeditdialog.h"

#include "mainwindow.h"

namespace Biblio {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    {
        QAction *a = 0;
        a = actNewItem = new QAction(this);
        a->setText(tr("Item"));
        connect(a, SIGNAL(triggered()), this, SLOT(newItem()));
    }

    /*QMenu *menuItem = */menuBar()->addMenu(tr("Item"));

    QToolButton *b = new QToolButton(this);
    b->setText(tr("Item"));
    b->move(50, 50);
    b->setDefaultAction(actNewItem);
}

MainWindow::~MainWindow() { }

void MainWindow::newItem()
{
    ItemEditDialog dialog(this);
    dialog.exec();
}

} // namespace Biblio
