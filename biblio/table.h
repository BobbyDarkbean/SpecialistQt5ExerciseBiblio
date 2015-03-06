#ifndef TABLE_H
#define TABLE_H

#include <QTableView>

namespace Biblio {

class Table : public QTableView
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    virtual ~Table();

signals:

public slots:
};

} // namespace Biblio

#endif // TABLE_H
