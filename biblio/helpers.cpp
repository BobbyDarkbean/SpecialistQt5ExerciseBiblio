#include <QWidget>
#include "helpers.h"

namespace Biblio {
namespace Hlp {

void setHPolicy(QWidget *w, QSizePolicy::Policy policy)
{
    QSizePolicy p = w->sizePolicy();
    p.setHorizontalPolicy(policy);
    w->setSizePolicy(p);
}

void setVPolicy(QWidget *w, QSizePolicy::Policy policy)
{
    QSizePolicy p = w->sizePolicy();
    p.setVerticalPolicy(policy);
    w->setSizePolicy(p);
}

void setWidth(QWidget *w, int width)
{
    QSize s = w->maximumSize();
    s.setWidth(width);
    w->setMaximumSize(s);
}

} // namespace Hlp
} // namespace Biblio
