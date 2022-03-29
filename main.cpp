#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QChar>
#include <QDesktopWidget>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <ctime>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <QFile>
#include <math.h>
#include <QScreen>
#include <QAudioInput>


#define MOD_NOREPEAT 0x4000
#define MOD_ALT 0x0001

int foo;
char *poo[0];
QApplication a(foo, poo);//This is necessary for some reason
MainWindow w;

POINT pointer;

//QScreen *screen = QGuiApplication::primaryScreen();
QScreen *screen = w.screen();
QRect screenGeometry = screen->geometry();
const int screenH = screenGeometry.height();
const int screenW = screenGeometry.width();

HHOOK kHook = NULL;
HHOOK mHook = NULL;


clock_t startTime;
std::thread paul;
std::thread waiter;
std::condition_variable waitCV;
std::condition_variable paulCV;
std::mutex mtx;

bool newPress = false;
bool keepChildrenAlive = true; //This var breaks loops for detached children to kill them


boolean isWaitDone = false;
int foopCallNum = 0;

//using namespace std;





LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    switch( wParam )
    {
      case WM_MOUSEMOVE:  qDebug() << "Mouse moved";
            GetCursorPos(&pointer);
            //printf("X %d",pointer.x);
            //printf("Y %d",pointer.y);
            int x = (int)pointer.x;
            int y = (int)pointer.y;

            mouseTracking(x,y);
            //w.eyeMov((double)pointer.x,(double)pointer.y);
    }
    return CallNextHookEx(mHook, nCode, wParam, lParam);
}




//TODO: Keymaping instead thread bullshit

void UpdateKeyState(BYTE *keystate, int keycode)
{
    keystate[keycode] = GetKeyState(keycode);
}

LRESULT CALLBACK MyLowLevelKeyBoardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    //WPARAM is WM_KEYDOWn, WM_KEYUP, WM_SYSKEYDOWN, or WM_SYSKEYUP
    //LPARAM is the key information

    //qDebug() << "Key Pressed!";

    if (wParam == WM_KEYDOWN)
    {
        //Get the key information
        KBDLLHOOKSTRUCT cKey = *((KBDLLHOOKSTRUCT*)lParam);

        wchar_t buffer[5];

        //get the keyboard state
        BYTE keyboard_state[256];
        GetKeyboardState(keyboard_state);
        UpdateKeyState(keyboard_state, VK_SHIFT);
        UpdateKeyState(keyboard_state, VK_CAPITAL);
        UpdateKeyState(keyboard_state, VK_CONTROL);
        UpdateKeyState(keyboard_state, VK_MENU);

        //Get keyboard layout
        //HKL keyboard_layout = GetKeyboardLayout(0);

        //Get the name
        char lpszName[0X100] = {0};

        DWORD dwMsg = 1;
        dwMsg += cKey.scanCode << 16;
        dwMsg += cKey.flags << 24;

        //int i = GetKeyNameText(dwMsg, (LPTSTR)lpszName, 255);

        //Try to convert the key information
        //int result = ToUnicodeEx(cKey.vkCode, cKey.scanCode, keyboard_state, buffer, 4, 0, keyboard_layout);
        buffer[4] = L'\0';

        //Print the output
        qDebug() << "Key: " << cKey.vkCode << " " << QString::fromUtf16((ushort*)buffer) << " " << QString::fromUtf16((ushort*)lpszName);
        w.updateKey(cKey.vkCode, 1);
        newPress = true;
    }



    if (wParam == WM_KEYUP)
    {
        //Get the key information
        KBDLLHOOKSTRUCT cKey = *((KBDLLHOOKSTRUCT*)lParam);

        wchar_t buffer[5];

        //get the keyboard state
        BYTE keyboard_state[256];
        GetKeyboardState(keyboard_state);
        UpdateKeyState(keyboard_state, VK_SHIFT);
        UpdateKeyState(keyboard_state, VK_CAPITAL);
        UpdateKeyState(keyboard_state, VK_CONTROL);
        UpdateKeyState(keyboard_state, VK_MENU);

        //Get keyboard layout
        //HKL keyboard_layout = GetKeyboardLayout(0);

        //Get the name
        char lpszName[0X100] = {0};

        DWORD dwMsg = 1;
        dwMsg += cKey.scanCode << 16;
        dwMsg += cKey.flags << 24;

        //int i = GetKeyNameText(dwMsg, (LPTSTR)lpszName, 255);

        //Try to convert the key information
        //int result = ToUnicodeEx(cKey.vkCode, cKey.scanCode, keyboard_state, buffer, 4, 0, keyboard_layout);
        buffer[4] = L'\0';

        //Print the output
        qDebug() << "Key: " << cKey.vkCode << " " << QString::fromUtf16((ushort*)buffer) << " " << QString::fromUtf16((ushort*)lpszName);
        w.updateKey(cKey.vkCode, 0);
        startTime = clock();
        waitCV.notify_all();
    }


    return CallNextHookEx(kHook, nCode, wParam, lParam);
}

void killAllChildren() {

    qDebug() << "Joining!";
    qDebug() << "Joined!";
    //Join all threads if needed with this
}


void typeStatusDelay() { //This child needs to kill itself when the parent is going to die because it is detached.
    std::unique_lock<std::mutex> lck(mtx);
    clock_t endTime;
    int sleepTime = 500;
    bool debugCall = false;
    qDebug() << "Thread Started";
    while(keepChildrenAlive) {
        debugCall = false;
        waitCV.wait(lck);
        if(w.keyMapState() == true) {
            qDebug() << "Ending without update because a key is still pressed";
            continue;
        }

        qDebug() << "Wait Start!";
        while(!debugCall) {

            Sleep(sleepTime);

            if(w.keyMapState() == true) {
                qDebug() << "Ending without update because a key is still pressed";
                break;
            }


            qDebug() << "Wait Done!";
            endTime = clock();

            double timeDelta = float(endTime - startTime) / CLOCKS_PER_SEC;

            if(timeDelta < 0.55 && timeDelta > 0.45) {
                w.debug();
                debugCall = true;
                sleepTime = 500;
            } else if(sleepTime < 700) {
                sleepTime = 500 - timeDelta * 1000.0;
                qDebug() << "Resleeping for ";
                qDebug() << sleepTime;
                qDebug() << "Delta";
                qDebug() << timeDelta;
            } else {
                qDebug() << "Recovered from excessive sleep";
                w.debug();
                debugCall = true;
                sleepTime = 500;
            }
        }


    }

    Sleep(1000);
    qDebug() << "I'm dead!";
    return;
}

void mouseTracking(int x,int y) {

    if(x > screenW){
        return;
    }

    if(y > screenH) {
        return;
    }

    if(x < 0) {
        return;
    }

    if(y < 0) {
        return;
    }

    x = x - screenW/2.0;
    y = y - screenH/2.0;

    /*if(x < 0) {
        x += (screenW/2.0)*3.0;
    }

    if(y < 0) {
        y += (screenH/2.0)*3.0;
    }*/

    double xP = x/(double)(screenW);
    double yP = y/(double)(screenH);

    w.eyeMov(xP,yP);

}


int main(int argc, char *argv[])
{

    //w.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    //w.setAttribute(Qt::WA_NoSystemBackground, true);
    //w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.show();
    //w.updateKey('a');


    kHook = SetWindowsHookEx(WH_KEYBOARD_LL, MyLowLevelKeyBoardProc, NULL, 0);
    if (kHook == NULL)
    {
        qDebug() << "Hook Failed" << Qt::endl;
    }

    mHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
    if (mHook == NULL)
    {
        qDebug() << "Hook Failed" << Qt::endl;
    }

    //std::thread waiter (waitAndNotify);
    //waiter.detach();
    //std::thread paul (paulDone);
    std::thread waiter(typeStatusDelay);
    //paul.detach();
    waiter.detach();
    //w.setAttribute(Qt::WA_NoSystemBackground, true);
    //w.setAttribute(Qt::WA_TranslucentBackground, true);

    //w.audioTest();
    //waiter.join();
    return a.exec();
}
