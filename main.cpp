#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QChar>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <ctime>
#include <thread>
#include <condition_variable>
#include <mutex>

#define MOD_NOREPEAT 0x4000
#define MOD_ALT 0x0001

int foo;
char *poo[0];
QApplication a(foo, poo);//This is necessary for some reason
MainWindow w;

HHOOK hHook = NULL;


clock_t startTime;
std::thread waiter;
std::thread paul;
std::condition_variable waitCV;
std::condition_variable paulCV;
std::mutex mtx;


int isWaitDone = 1;
int foopCallNum = 0;
//using namespace std;

void UpdateKeyState(BYTE *keystate, int keycode)
{
    keystate[keycode] = GetKeyState(keycode);
}

LRESULT CALLBACK MyLowLevelKeyBoardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    //WPARAM is WM_KEYDOWn, WM_KEYUP, WM_SYSKEYDOWN, or WM_SYSKEYUP
    //LPARAM is the key information

    qDebug() << "Key Pressed!";

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
    }


    return CallNextHookEx(hHook, nCode, wParam, lParam);
}


void foop(){
    printf("Yah!");
    isWaitDone = 0;
    foopCallNum++;
    std::thread waiter (waitAndNotify);
    waiter.detach();


}

void waitAndNotify() {
    std::unique_lock<std::mutex> lck(mtx);
    //while(true) {
        isWaitDone = foopCallNum;
        //waitCV.wait(lck);
        Sleep(500);
        //paulCV.notify_all();
        printf("Wait done!");

        if(isWaitDone != foopCallNum) {
            return;
        }

        isWaitDone = 1;
        w.debug();
        foopCallNum = 0;

    //}


}


void paulDone() {//This will require threading
    std::unique_lock<std::mutex> lck(mtx);

    while(true) {
        if(startTime != -1) {
            startTime = -1;
        }
        waitCV.wait(lck);
        paulCV.wait(lck);

        if(startTime == -1) {
            printf("Paul done type!");
            w.debug();
        }
    }
}


int main(int argc, char *argv[])
{
    //a = QApplication(argc, argv);
    //w.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    //w.setAttribute(Qt::WA_NoSystemBackground, true);
    //w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.show();
    //w.updateKey('a');

    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, MyLowLevelKeyBoardProc, NULL, 0);
    if (hHook == NULL)
    {
        qDebug() << "Hook Failed" << Qt::endl;
    }
    //std::thread waiter (waitAndNotify);
    //waiter.detach();
    std::thread paul (paulDone);
    paul.detach();
    //w.setAttribute(Qt::WA_NoSystemBackground, true);
    //w.setAttribute(Qt::WA_TranslucentBackground, true);


    return a.exec();
}