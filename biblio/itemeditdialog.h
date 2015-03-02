#ifndef ITEMEDITDIALOG_H
#define ITEMEDITDIALOG_H

#include <QDialog>

namespace Biblio {

/**
 * @brief Редактирование данных об издании в отдельном окне.
 */
class ItemEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemEditDialog(QWidget *parent = 0);
    virtual ~ItemEditDialog();

private:
    Q_DISABLE_COPY(ItemEditDialog)
};

} // namespace Biblio

#endif // ITEMEDITDIALOG_H
