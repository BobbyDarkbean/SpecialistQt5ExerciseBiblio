#ifndef BIBLIOMODEL_H
#define BIBLIOMODEL_H

#include <QAbstractTableModel>

namespace Biblio {

namespace Data {
struct Object;
}

class BiblioModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BiblioModel(QObject *parent = 0);
    virtual ~BiblioModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Data::Object *at(int);

private:
    QList<Data::Object *> l;
};

} // namespace Biblio

#endif // BIBLIOMODEL_H
