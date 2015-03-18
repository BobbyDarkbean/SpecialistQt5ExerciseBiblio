#include <QAction>
#include "application.h"
#include "bibliomodel.h"
#include "itemeditdialog.h"
#include "data.h"

#include "table.h"

namespace Biblio {

Table::Table(QWidget *parent) :
    QTableView(parent)
{
    setProperty("modeName", "Table");

    setModel(bblApp->model());
    setContextMenuPolicy(Qt::ActionsContextMenu);

    {
        QAction *a = actNew = new QAction(this);
        a->setText(tr("New"));
        connect(a, SIGNAL(triggered()), this, SLOT(itemCreateNew()));
        addAction(a);
    }{
        QAction *a = actEdit = new QAction(this);
        a->setText(tr("Edit"));
        connect(a, SIGNAL(triggered()), this, SLOT(itemEditCurrent()));
        addAction(a);
    }{
        QAction *a = actDelete = new QAction(this);
        a->setText(tr("Delete"));
        connect(a, SIGNAL(triggered()), this, SLOT(itemDeleteCurrent()));
        addAction(a);
    }
}

Table::~Table() { }

void Table::itemCreateNew()
{

}

void Table::itemEditCurrent()
{
    QModelIndex mi = currentIndex();
    if (!mi.isValid())
        return;

    Data::Object *o = bblApp->model()->at(mi.row());
//    o->author = model()->data(mi).toString();

    ItemEditDialog dialog(this);
    dialog.attach(o);

    dialog.exec();
}

void Table::itemDeleteCurrent()
{

}

} // namespace Biblio
