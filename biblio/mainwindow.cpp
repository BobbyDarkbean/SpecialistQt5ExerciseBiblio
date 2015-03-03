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

    QMenu *menuItem = menuBar()->addMenu(tr("Item"));
    menuItem->addAction(actNewItem);

//    actNewItem->setEnabled(false);
}

MainWindow::~MainWindow() { }

void MainWindow::newItem()
{
    ItemEditDialog dialog(this);
    dialog.exec();
}

} // namespace Biblio
