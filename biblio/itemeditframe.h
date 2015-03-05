#ifndef ITEMEDITFRAME_H
#define ITEMEDITFRAME_H

#include <QFrame>

class QLabel;
class QLineEdit;
class QComboBox;
class QBoxLayout;
namespace Biblio {

class ItemEditFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ItemEditFrame(QWidget *parent = 0);
    virtual ~ItemEditFrame();

protected slots:
    void itemTypeSelected(int index);

private:
    Q_DISABLE_COPY(ItemEditFrame)

    QComboBox   *cbxItemType;
    void setup_item_type(QBoxLayout *);

    void setup_author(QBoxLayout *);
    void setup_title(QBoxLayout *);
    void setup_subtitle(QBoxLayout *);

    void setup_location(QBoxLayout *);
    void setup_publisher(QBoxLayout *);
    void setup_year(QBoxLayout *);
    QLabel      *lblTotalPages;
    QLineEdit   *edtTotalPages;
    void setup_total_pages(QBoxLayout *);

    QLabel      *lblJournal;
    QLineEdit   *edtJournal;
    void setup_journal(QBoxLayout *);
    QLabel      *lblVolume;
    QLineEdit   *edtVolume;
    void setup_volume(QBoxLayout *);
    QLabel      *lblIssue;
    QLineEdit   *edtIssue;
    void setup_issue(QBoxLayout *);
    QLabel      *lblPage;
    QLineEdit   *edtPage;
    void setup_page(QBoxLayout *);

    void setup_comment(QBoxLayout *);
};

}

#endif // ITEMEDITFRAME_H
