#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <future>


    void typeStatusDelay();
    void mouseTracking(int x, int y);
    void killAllChildren(); //Incredibly important function
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
    void audioTest();
    void closeEvent(QCloseEvent *event);
    bool keyMapState();
private:
    Ui::MainWindow *ui;
    void initKeyMap();
};

#endif // MAINWINDOW_H
