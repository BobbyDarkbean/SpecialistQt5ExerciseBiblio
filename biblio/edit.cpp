#include "edit.h"

namespace Biblio {

Edit::Edit(QWidget *parent) :
    QTextEdit(parent)
{
    setProperty("modeName", "Edit");
}

Edit::~Edit() { }

void Edit::onCancelMode(bool *ok)
{
    QString s = toPlainText();
    if (ok)
        *ok = s.simplified().isEmpty();
}

} // namespace Biblio
