#include <QBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QSpacerItem>
#include "itemeditdialog.h"

namespace Biblio {

namespace ItemEditDialog_Helper {

    Buttons::Buttons(QDialog *parent) :
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
        }
        {
         QPushButton *b = cancelButton = new QPushButton(this);
         l->addWidget(b);
         b->setText(tr("Cancel"));
         connect(b, SIGNAL(clicked()), this, SIGNAL(rejecting()));
        }
    }

    Buttons::~Buttons() { }

} // namespace ItemEditDialog_Helper

ItemEditDialog::ItemEditDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("Editing a reference"));

    QVBoxLayout *l0 = new QVBoxLayout(this);
    {
     QFrame *f = new QFrame(this);
     f->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
     f->setSizePolicy(QSizePolicy::Expanding,
                      QSizePolicy::Expanding);
     l0->addWidget(f);
    }
    {
     btn = new ItemEditDialog_Helper::Buttons(this);
     connect(btn, SIGNAL(accepting()), this, SLOT(accept()));
     connect(btn, SIGNAL(rejecting()), this, SLOT(reject()));
     l0->addWidget(btn);
    }

}

ItemEditDialog::~ItemEditDialog() { }

} // namespace Biblio
