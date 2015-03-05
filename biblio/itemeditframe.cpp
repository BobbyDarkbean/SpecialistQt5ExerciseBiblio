#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QBoxLayout>
#include "items.h"
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

    emit cbxItemType->currentIndexChanged(Unknown);
}

ItemEditFrame::~ItemEditFrame() { }

void ItemEditFrame::itemTypeSelected(int index)
{
    QComboBox *c = dynamic_cast<QComboBox *>(sender());
    if (!c) {
        /// @TODO Написать сообщение в лог
        return;
    }

    bool ok = false;
    ItemType t = ItemType(c->itemData(index).toInt(&ok));
    if (!ok) {
        /// @TODO Написать сообщение в лог
        return;
    }

    switch (t) {
    case Unknown:
        lblTotalPages->setVisible(true);
        lblTotalPages->setEnabled(false);
        edtTotalPages->setVisible(true);
        edtTotalPages->setEnabled(false);

        lblJournal->setVisible(true);
        lblJournal->setEnabled(false);
        edtJournal->setVisible(true);
        edtJournal->setEnabled(false);
        lblVolume->setVisible(true);
        lblVolume->setEnabled(false);
        edtVolume->setVisible(true);
        edtVolume->setEnabled(false);
        lblIssue->setVisible(true);
        lblIssue->setEnabled(false);
        edtIssue->setVisible(true);
        edtIssue->setEnabled(false);
        lblPage->setVisible(true);
        lblPage->setEnabled(false);
        edtPage->setVisible(true);
        edtPage->setEnabled(false);

        break;
    case Book:
        lblTotalPages->setVisible(true);
        lblTotalPages->setEnabled(true);
        edtTotalPages->setVisible(true);
        edtTotalPages->setEnabled(true);

        lblJournal->setVisible(false);
        lblJournal->setEnabled(false);
        edtJournal->setVisible(false);
        edtJournal->setEnabled(false);
        lblVolume->setVisible(false);
        lblVolume->setEnabled(false);
        edtVolume->setVisible(false);
        edtVolume->setEnabled(false);
        lblIssue->setVisible(false);
        lblIssue->setEnabled(false);
        edtIssue->setVisible(false);
        edtIssue->setEnabled(false);
        lblPage->setVisible(false);
        lblPage->setEnabled(false);
        edtPage->setVisible(false);
        edtPage->setEnabled(false);

        break;
    case Article:
        lblTotalPages->setVisible(false);
        lblTotalPages->setEnabled(false);
        edtTotalPages->setVisible(false);
        edtTotalPages->setEnabled(false);

        lblJournal->setVisible(true);
        lblJournal->setEnabled(true);
        edtJournal->setVisible(true);
        edtJournal->setEnabled(true);
        lblVolume->setVisible(true);
        lblVolume->setEnabled(true);
        edtVolume->setVisible(true);
        edtVolume->setEnabled(true);
        lblIssue->setVisible(true);
        lblIssue->setEnabled(true);
        edtIssue->setVisible(true);
        edtIssue->setEnabled(true);
        lblPage->setVisible(true);
        lblPage->setEnabled(true);
        edtPage->setVisible(true);
        edtPage->setEnabled(true);

        break;
    default:
        /// @TODO Написать сообщение в лог
        return;
    }
}

void ItemEditFrame::setup_item_type(QBoxLayout *l)
{
    QBoxLayout *l1 = new QHBoxLayout;
    l->addLayout(l1);

    QSpacerItem *sp = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    l1->addItem(sp);

    QComboBox *cbx = cbxItemType = new QComboBox(this);
    cbx->addItem(tr("---"), Unknown);
    cbx->addItem(tr("Book"), Book);
    cbx->addItem(tr("Article"), Article);
    cbx->setCurrentIndex(Unknown);
    connect(cbx, SIGNAL(currentIndexChanged(int)), this, SLOT(itemTypeSelected(int)));

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
    l->addLayout(l1, 1);

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
    l->addLayout(l1, 2);

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
    Hlp::setWidth(lbl, 50);
    l1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    Hlp::setWidth(txt, 50);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_total_pages(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = lblTotalPages = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("total p."));
    Hlp::setWidth(lbl, 50);
    l1->addWidget(lbl);

    QLineEdit *txt = edtTotalPages = new QLineEdit(this);
    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    Hlp::setWidth(txt, 50);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_journal(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = lblJournal = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Journal title"));
    l1->addWidget(lbl);

    QLineEdit *txt = edtJournal = new QLineEdit(this);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_volume(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = lblVolume = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Vol."));
    Hlp::setWidth(lbl, 50);
    l1->addWidget(lbl);

    QLineEdit *txt = edtVolume = new QLineEdit(this);
    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    Hlp::setWidth(txt, 50);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_issue(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = lblIssue = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("Issue"));
    Hlp::setWidth(lbl, 50);
    l1->addWidget(lbl);

    QLineEdit *txt = edtIssue = new QLineEdit(this);
    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    Hlp::setWidth(txt, 50);
    l1->addWidget(txt);
}

void ItemEditFrame::setup_page(QBoxLayout *l)
{
    QBoxLayout *l1 = new QVBoxLayout;
    l1->setSpacing(2);
    l1->setMargin(0);
    l->addLayout(l1);

    QLabel *lbl = lblPage = new QLabel(this);
    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    lbl->setText(tr("p."));
    Hlp::setWidth(lbl, 50);
    l1->addWidget(lbl);

    QLineEdit *txt = edtPage = new QLineEdit(this);
    txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    Hlp::setWidth(txt, 50);
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
