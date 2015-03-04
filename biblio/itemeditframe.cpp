#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QBoxLayout>
#include "helpers.h"

#include "itemeditframe.h"

namespace Biblio {

ItemEditFrame::ItemEditFrame(QWidget *parent) :
    QFrame(parent)
{
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QBoxLayout *l = new QVBoxLayout(this);
    setup_item_type(l);
    setup_author(l);
    setup_title(l);
    setup_subtitle(l);
    {
     QBoxLayout *l1 = new QHBoxLayout;
     l1->setMargin(0);
     l->addLayout(l1);

     setup_location(l1);
     setup_publisher(l1);
     setup_year(l1);
     setup_total_pages(l1);
    }{
     QBoxLayout *l1 = new QHBoxLayout;
     l1->setMargin(0);
     l->addLayout(l1);

     setup_journal(l1);
     setup_volume(l1);
     setup_issue(l1);
     setup_page(l1);
    }
    setup_comment(l);
}

ItemEditFrame::~ItemEditFrame() { }

void ItemEditFrame::setup_item_type(QBoxLayout *l)
{
    QBoxLayout *l1 = new QHBoxLayout;
    l->addLayout(l1);

    QSpacerItem *sp = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    l1->addItem(sp);

    QComboBox *cbx = new QComboBox(this);
    l1->addWidget(cbx);
}

void ItemEditFrame::setup_author(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Author"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_title(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Title"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_subtitle(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Subtitle"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_location(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Location"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_publisher(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Publisher"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_year(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Year"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_total_pages(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Total pages"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
//    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_journal(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Journal"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_volume(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Volume"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_issue(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Issue"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_page(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Page"));
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_comment(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Comment"));
    l1->addWidget(lbl);

    QTextEdit *txt = new QTextEdit(this);
    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    l1->addWidget(txt);
}

}
