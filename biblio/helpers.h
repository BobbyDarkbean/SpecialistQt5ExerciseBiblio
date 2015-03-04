#ifndef HELPERS
#define HELPERS

#include <QSizePolicy>

namespace Biblio {
namespace Hlp {

void setHPolicy(QWidget *w, QSizePolicy::Policy policy);
void setVPolicy(QWidget *w, QSizePolicy::Policy policy);

void setWidth(QWidget *w, int width);

} // namespace Hlp
} // namespace Biblio

#endif // HELPERS
