#include <QBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QSpacerItem>
#include "data.h"
#include "itemeditframe.h"

#include "itemeditdialog.h"

namespace Biblio {

namespace ItemEditDialog_Helper {

    ButtonsFrame::ButtonsFrame(QDialog *parent) :
        QFrame(parent)
    {
        setFrameStyle(StyledPanel | Sunken);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

        QHBoxLayout *l = new QHBoxLayout(this);
        l->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Maximum));
        {
            QPushButton *b = okButton = new QPushButton(this);
            l->addWidget(b);
            b->setText(tr("OK"));
            connect(b, SIGNAL(clicked()), this, SIGNAL(accepting()));
        }{
            QPushButton *b = cancelButton = new QPushButton(this);
            l->addWidget(b);
            b->setText(tr("Cancel"));
            connect(b, SIGNAL(clicked()), this, SIGNAL(rejecting()));
        }
    }

    ButtonsFrame::~ButtonsFrame() { }

} // namespace ItemEditDialog_Helper

ItemEditDialog::ItemEditDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("Editing a reference"));

    QVBoxLayout *l0 = new QVBoxLayout(this);
    {
        edt = new ItemEditFrame(this);
        l0->addWidget(edt);
    }{
        btn = new ItemEditDialog_Helper::ButtonsFrame(this);
        connect(btn, SIGNAL(accepting()), this, SLOT(accept()));
        connect(btn, SIGNAL(rejecting()), this, SLOT(reject()));
        l0->addWidget(btn);
    }

}

ItemEditDialog::~ItemEditDialog() { }

void ItemEditDialog::attach(Data::Object *o)
{
    edt->attach(o);
}

Data::Object *ItemEditDialog::acquire() const
{
    return edt->acquire();
}

void ItemEditDialog::done(int r)
{
    switch (r) {
    case Accepted:
        if (!edt->isValid() || !edt->acquire())
            return;
        // fall through
    case Rejected:
    default:
        QDialog::done(r);
    }
}

} // namespace Biblio
