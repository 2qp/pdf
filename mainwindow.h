#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "extractor.h"
#include <QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLoad_triggered();

    void on_actionRead_triggered();

    void ischecked(bool checked);

    void on_actionDuplicates_triggered();

    void on_actionClear_triggered();

    void on_actionSave_triggered();

    void on_actionSave_Sliced_Output_triggered();

private:
    Ui::MainWindow *ui;
    extractor extract;

};
#endif // MAINWINDOW_H
