#include <QTextEdit>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QFrame>
#include <QIcon>

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
     QIcon ic("application-text.svg");
     a->setText(tr("Edit mode"));
     a->setIcon(ic);
     a->setCheckable(true);
     agModes->addAction(a);
     modeActions.insert("Edit", a);
     connect(a, SIGNAL(triggered()), this, SLOT(editMode()));
    }{
     QAction *a = actTableMode = new QAction(this);
     QIcon ic("misc.svg");
     a->setText(tr("Table mode"));
     a->setIcon(ic);
     a->setCheckable(true);
     agModes->addAction(a);
     modeActions.insert("Table", a);
     connect(a, SIGNAL(triggered()), this, SLOT(tableMode()));
    }

    QMenu *menuItem = menuBar()->addMenu(tr("Item"));
    menuItem->addAction(actNewItem);

    QMenu *mModes = menuBar()->addMenu(tr("Modes"));
    mModes->addAction(actEditMode);
    mModes->addAction(actTableMode);

    QToolBar *tbModes = new QToolBar(this);
    tbModes->setWindowTitle(tr("Modes"));
    tbModes->addAction(actEditMode);
    tbModes->addAction(actTableMode);
    addToolBar(Qt::TopToolBarArea, tbModes);

    QMenu *mToolBars = menuBar()->addMenu(tr("Toolbars"));
    mToolBars->addAction(tbModes->toggleViewAction());

    editMode();

    QMenu *mWindows = menuBar()->addMenu(tr("Windows"));

    // Несколько тестовых припаркованных окон
    {
     QDockWidget *d1 = new QDockWidget(this);
     d1->setWindowTitle(tr("Yellow"));
     QFrame *f1 = new QFrame(this);
     f1->setStyleSheet("background: yellow;");
     d1->setWidget(f1);
     addDockWidget(Qt::LeftDockWidgetArea, d1);
     mWindows->addAction(d1->toggleViewAction());
    }
    {
     QDockWidget *d1 = new QDockWidget(this);
     d1->setWindowTitle(tr("Green"));
     QFrame *f1 = new QFrame(this);
     f1->setStyleSheet("background: green;");
     d1->setWidget(f1);
     addDockWidget(Qt::LeftDockWidgetArea, d1);
     mWindows->addAction(d1->toggleViewAction());
    }
    {
     QDockWidget *d1 = new QDockWidget(this);
     d1->setWindowTitle(tr("Red"));
     QFrame *f1 = new QFrame(this);
     f1->setStyleSheet("background: red;");
     d1->setWidget(f1);
     addDockWidget(Qt::LeftDockWidgetArea, d1);
     mWindows->addAction(d1->toggleViewAction());
    }


}

MainWindow::~MainWindow() { }

void MainWindow::newItem()
{
    ItemEditDialog dialog(this);
    dialog.exec();
}

void MainWindow::editMode()
{
    QWidget *w = centralWidget();
    // Проверяем, надо ли переключать режим
    if (dynamic_cast<Edit *>(w))
        return;

    // Если преобразование не сработало, но объект не ноль
    if (w) {
        // проверим, можно ли выключить старый режим
        bool ok = true;
        cancelMode(&ok);
        if (!ok) {
            QString modeName = w->property("modeName").toString();
            QAction *a = modeActions.value(modeName, 0);
            if (a)
                a->setChecked(true);

            return;
        }
        // выключаем старый режим
        setCentralWidget(0);    // снимаем центральный виджет
        delete w;
    }

    // переключаем режим
    w = new Edit(this);
//    w->setProperty("modeAction", actEditMode);
    setCentralWidget(w);    // ставим новый центральный виджет
    connect(this, SIGNAL(cancelMode(bool *)), w, SLOT(onCancelMode(bool *)));
    actEditMode->setChecked(true);
}

void MainWindow::tableMode()
{
    QWidget *w = centralWidget();
    // Проверяем, надо ли переключать режим
    if (dynamic_cast<Table *>(w))
        return;

    // Если преобразование не сработало, но объект не ноль
    if (w) {
        // проверим, можно ли выключить старый режим
        bool ok = true;
        cancelMode(&ok);
        if (!ok) {
            QString modeName = w->property("modeName").toString();
            QAction *a = modeActions.value(modeName, 0);
            if (a)
                a->setChecked(true);

            return;
        }
        // выключаем старый режим
        setCentralWidget(0);    // снимаем центральный виджет
        delete w;
    }

    // включаем новый режим
    w = new Table(this);
    setCentralWidget(w);    // ставим новый центральный виджет
    actTableMode->setChecked(true);
}

} // namespace Biblio
