#ifndef ITEMEDITDIALOG_H
#define ITEMEDITDIALOG_H

#include <QDialog>
#include <QFrame>

class QPushButton;

namespace Biblio {

namespace ItemEditDialog_Helper {
    class ButtonsFrame : public QFrame
    {
        Q_OBJECT

    public:
        explicit ButtonsFrame(QDialog *parent = 0);
        virtual ~ButtonsFrame();

    signals:
        void accepting();
        void rejecting();

    private:
        Q_DISABLE_COPY(ButtonsFrame)

        QPushButton *okButton;
        QPushButton *cancelButton;
    };
} // namespace ItemEditDialog_Helper

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

    ItemEditDialog_Helper::ButtonsFrame *btn;
};

} // namespace Biblio

#endif // ITEMEDITDIALOG_H
