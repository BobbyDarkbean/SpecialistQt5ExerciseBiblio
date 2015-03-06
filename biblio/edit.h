#ifndef EDIT_H
#define EDIT_H

#include <QTextEdit>

namespace Biblio {

class Edit : public QTextEdit
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = 0);
    virtual ~Edit();

signals:

public slots:
    void onCancelMode(bool *ok = 0);
};

} // namespace Biblio

#endif // EDIT_H
