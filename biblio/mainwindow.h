#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

class QAction;
namespace Biblio {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

signals:
    void cancelMode(bool *ok = 0);
    void languageChanged(const QString &);

protected slots:
    void newItem();

    void editMode();
    void tableMode();

private:
    Q_DISABLE_COPY(MainWindow)

    QAction *actNewItem;

    QMap<QString, QAction *> modeActions;
    QAction *actEditMode;
    QAction *actTableMode;
};

} // namespace Biblio

#endif // MAINWINDOW_H
