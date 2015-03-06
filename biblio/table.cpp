#include "table.h"

namespace Biblio {

Table::Table(QWidget *parent) :
    QTableView(parent)
{
    setProperty("modeName", "Table");
}

Table::~Table() { }

} // namespace Biblio
