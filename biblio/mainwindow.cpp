#include <QTextEdit>
#include <QMenuBar>
#include "edit.h"
#include "table.h"
#include "itemeditdialog.h"

#include "mainwindow.h"

namespace Biblio {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QActionGroup *agModes = new QActionGroup(this);
    agModes->setExclusive(true);
    {
     QAction *a = actNewItem = new QAction(this);
     a->setText(tr("Item"));
     connect(a, SIGNAL(triggered()), this, SLOT(newItem()));
    }{
     QAction *a = actEditMode = new QAction(this);
     a->setText(tr("Edit mode"));
     a->setCheckable(true);
     agModes->addAction(a);
     connect(a, SIGNAL(triggered()), this, SLOT(editMode()));
    }{
     QAction *a = actTableMode = new QAction(this);
     a->setText(tr("Table mode"));
     a->setCheckable(true);
     agModes->addAction(a);
     connect(a, SIGNAL(triggered()), this, SLOT(tableMode()));
    }

    QMenu *menuItem = menuBar()->addMenu(tr("Item"));
    menuItem->addAction(actNewItem);

    QTextEdit *t = new QTextEdit(this);
    setCentralWidget(t);


}

MainWindow::~MainWindow() { }

void MainWindow::newItem()
{
    ItemEditDialog dialog(this);
    dialog.exec();
}

void MainWindow::editMode()
{
    // проверим, можно ли выключить старый режим
    bool ok = true;
    cancelMode(&ok);
    if (!ok)
        return;

    // переключаем режим
    QWidget *w = centralWidget();
    if (dynamic_cast<Edit *>(w))
        return;
    setCentralWidget(0);    // снимаем центральный виджет
    delete w;

    w = new Edit(this);
//    w->setProperty("modeAction", actEditMode);
    setCentralWidget(w);    // ставим новый центральный виджет
//    connect(this, SIGNAL(cancelMode(bool *)), w, SLOT(onCancelMode(bool *)));
    actEditMode->setChecked(true);
}

void MainWindow::tableMode()
{
    // проверим, можно ли выключить старый режим
    bool ok = true;
    cancelMode(&ok);
    if (!ok)
        return;

    // переключаем режим
    QWidget *w = centralWidget();
    if (dynamic_cast<Table *>(w))
        return;
    setCentralWidget(0);    // снимаем центральный виджет
    delete w;

    w = new Table(this);
    setCentralWidget(w);    // ставим новый центральный виджет
    actTableMode->setChecked(true);
}

} // namespace Biblio
