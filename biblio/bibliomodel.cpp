#include <qiterator.h>
#include "data.h"

#include "bibliomodel.h"

namespace Biblio {

BiblioModel::BiblioModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    // Temp
    Data::Book *x = new Data::Book;
    x->author = "John Smith";
    x->title = "Hello, world!";
    l.append(x);
}

#define iterate(ContainerType, Container) \
    ContainerType::iterator _e = Container.end(); \
    for (ContainerType::iterator i = Container.begin(); i != _e; ++i)

BiblioModel::~BiblioModel()
{
    // Java-style
    /*
    QListIterator<Data::Object *> i(l);
    while (i.hasNext()) {
        Data::Object *o = i.next();
        delete o;
    }*/

    // via macro
    /*
    foreach (Data::Object *o, l) {
        delete o;
    }*/

    // custom macro
    iterate (QList<Data::Object *>, l) {
        delete *i;
    }

    // STL-style
    /*
    for (QList<Data::Object *>::Iterator itr = l.begin(); itr != l.end(); ++itr) {
        delete *itr;
    }*/
}

int BiblioModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return l.size();
}

int BiblioModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;
}

QVariant BiblioModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(index);
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return l.at(index.row())->author;
        case 1:
            return l.at(index.row())->title;
        default:
            return QVariant();
        }
    } else {
        return QVariant();
    }
}

Data::Object *BiblioModel::at(int k)
{
    return l.at(k);
}

} // namespace Biblio
