#ifndef DATA_H
#define DATA_H

#include <QString>

namespace Biblio {
namespace Data {

struct Object
{
    QString author;
    QString title;
    QString subtitle;
    QString location;
    QString publisher;
    int year;

    virtual ~Object() { }
};

struct Book : public Object
{
    Book() : Object() { }

    int totalPages;

    virtual ~Book() { }
};

struct Article : public Object
{
    Article() : Object() { }

    QString journal;
    QString volume;
    QString issue;
    QString page;

    virtual ~Article() { }
};

} // namespace Data
} // namespace Biblio

#endif // DATA_H
