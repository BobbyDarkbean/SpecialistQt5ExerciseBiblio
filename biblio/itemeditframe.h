#ifndef ITEMEDITFRAME_H
#define ITEMEDITFRAME_H

#include <QFrame>

class QBoxLayout;
namespace Biblio {

class ItemEditFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ItemEditFrame(QWidget *parent = 0);
    virtual ~ItemEditFrame();

private:
    Q_DISABLE_COPY(ItemEditFrame)

    void setup_item_type(QBoxLayout *);

    void setup_author(QBoxLayout *);
    void setup_title(QBoxLayout *);
    void setup_subtitle(QBoxLayout *);

    void setup_location(QBoxLayout *);
    void setup_publisher(QBoxLayout *);
    void setup_year(QBoxLayout *);
    void setup_total_pages(QBoxLayout *);

    void setup_journal(QBoxLayout *);
    void setup_volume(QBoxLayout *);
    void setup_issue(QBoxLayout *);
    void setup_page(QBoxLayout *);

    void setup_comment(QBoxLayout *);
};

}

#endif // ITEMEDITFRAME_H
