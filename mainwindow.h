#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <future>


    void waitAndNotify();
    void paulDone();
    void foop();
    void mouseTracking(int x, int y);
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
    void eyeMov(double x,double y);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
