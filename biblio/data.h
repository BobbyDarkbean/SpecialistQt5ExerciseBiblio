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

    virtual ~Object();
};

Object::~Object() { }

struct Book : public Object
{
    int totalPages;
};

struct Article : public Object
{
    QString journal;
    QString volume;
    QString issue;
    QString page;
};

} // namespace Data
} // namespace Biblio

#endif // DATA_H
