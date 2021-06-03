#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <future>


    void waitAndNotify();
    void paulDone();
    void foop();
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateKey(int key, int state);
    void debug();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
