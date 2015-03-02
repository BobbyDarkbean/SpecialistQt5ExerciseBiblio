#include "itemeditdialog.h"

namespace Biblio {

ItemEditDialog::ItemEditDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("Editing a reference"));

}

ItemEditDialog::~ItemEditDialog() { }

} // namespace Biblio
