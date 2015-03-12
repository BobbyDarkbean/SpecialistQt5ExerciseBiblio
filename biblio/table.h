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

protected slots:
    void itemCreateNew();
    void itemEditCurrent();
    void itemDeleteCurrent();

private:
    Q_DISABLE_COPY(Table)

    QAction *actNew;
    QAction *actEdit;
    QAction *actDelete;
};

} // namespace Biblio

#endif // TABLE_H
