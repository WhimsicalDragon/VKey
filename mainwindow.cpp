#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <QTime>
#include <QChar>
#include <QDesktopWidget>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <ctime>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <math.h>
#include <QAudio>
#include <QAudioInput>
#include <unordered_map>
#pragma comment(lib, "user32.lib")

#define MOD_NOREPEAT 0x4000
#define MOD_ALT 0x0001

//Keymap that I didn't want to implement :(
std::map<char, bool> keyMap;

void MainWindow::initKeyMap() {
    keyMap.insert({'a',false});
    keyMap.insert({'b',false});
    keyMap.insert({'c',false});
    keyMap.insert({'d',false});
    keyMap.insert({'e',false});
    keyMap.insert({'f',false});
    keyMap.insert({'g',false});
    keyMap.insert({'h',false});
    keyMap.insert({'i',false});
    keyMap.insert({'j',false});
    keyMap.insert({'k',false});
    keyMap.insert({'l',false});
    keyMap.insert({'m',false});
    keyMap.insert({'n',false});
    keyMap.insert({'o',false});
    keyMap.insert({'p',false});
    keyMap.insert({'q',false});
    keyMap.insert({'r',false});
    keyMap.insert({'s',false});
    keyMap.insert({'t',false});
    keyMap.insert({'u',false});
    keyMap.insert({'v',false});
    keyMap.insert({'w',false});
    keyMap.insert({'x',false});
    keyMap.insert({'y',false});
    keyMap.insert({'z',false});
    keyMap.insert({' ',false});
    keyMap.insert({'-',false});//Backspace
}

bool MainWindow::keyMapState() {


    //std::map<int, int> m;

    for(std::map<char,bool>::iterator it = keyMap.begin(); it != keyMap.end(); ++it) {
      if(it->second) {
          return true;
      }
    }
    return false;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    initKeyMap();

    ui->setupUi(this);
    ui->keyA->setVisible(false);
    ui->keyB->setVisible(false);
    ui->keyC->setVisible(false);
    ui->keyD->setVisible(false);
    ui->keyE->setVisible(false);
    ui->keyF->setVisible(false);
    ui->keyG->setVisible(false);
    ui->keyH->setVisible(false);
    ui->keyI->setVisible(false);
    ui->keyJ->setVisible(false);
    ui->keyK->setVisible(false);
    ui->keyL->setVisible(false);
    ui->keyM->setVisible(false);
    ui->keyN->setVisible(false);
    ui->keyO->setVisible(false);
    ui->keyP->setVisible(false);
    ui->keyQ->setVisible(false);
    ui->keyR->setVisible(false);
    ui->keyS->setVisible(false);
    ui->keyT->setVisible(false);
    ui->keyU->setVisible(false);
    ui->keyV->setVisible(false);
    ui->keyW->setVisible(false);
    ui->keyX->setVisible(false);
    ui->keyY->setVisible(false);
    ui->keyZ->setVisible(false);
    ui->keyBKSP->setVisible(false);
    ui->keySpace->setVisible(false);
    /*RegisterHotKey((HWND)MainWindow::winId(),   // Set the system identifier of the widget window that will handle the HotKey
                   100,                         // Set identifier HotKey
                   MOD_NOREPEAT,         // Set modifiers
                   'A');
    */


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event) { //This doesn't work how I thought it would so it's still crashing
    //Cleanup prompt to save unsaved user setting changes when implemented.
    event->accept();
}

void MainWindow::updateKey(int key, int state){
    if(state == 1) {
        QPixmap monkeType (":/images/resources/MonkeType.png");
        ui->Paul->setPixmap(monkeType);
    }

    switch (key) {
    //It's no magic numbers it's ascii :')
        case 65:
            //A
            if(ui->keyA->isVisible() && state == 0) {
                ui->keyA->setVisible(false);
                keyMap['a'] = false;
            } else {
                ui->keyA->setVisible(true);
                keyMap['a'] = true;
            }
            break;
        case 66:
            //B
            if(ui->keyB->isVisible() && state == 0) {
                ui->keyB->setVisible(false);
                keyMap['b'] = false;
            } else {
                ui->keyB->setVisible(true);
                keyMap['b'] = true;
            }
            break;
        case 67:
            //C
            if(ui->keyC->isVisible() && state == 0) {
                ui->keyC->setVisible(false);
                keyMap['c'] = false;
            } else {
                ui->keyC->setVisible(true);
                keyMap['c'] = true;
            }
            break;
        case 68:
            //D
            if(ui->keyD->isVisible() && state == 0) {
                ui->keyD->setVisible(false);
                keyMap['d'] = false;
            } else {
                ui->keyD->setVisible(true);
                keyMap['d'] = true;
            }
            break;
        case 69://Nice!
            //E
            if(ui->keyE->isVisible() && state == 0) {
                ui->keyE->setVisible(false);
                keyMap['e'] = false;
            } else {
                ui->keyE->setVisible(true);
                keyMap['e'] = true;
            }
            break;
        case 70:
            //F
            if(ui->keyF->isVisible() && state == 0) {
                ui->keyF->setVisible(false);
                keyMap['f'] = false;
            } else {
                ui->keyF->setVisible(true);
                keyMap['f'] = true;
            }
            break;
        case 71:
            //G
            if(ui->keyG->isVisible() && state == 0) {
                ui->keyG->setVisible(false);
                keyMap['g'] = false;
            } else {
                ui->keyG->setVisible(true);
                keyMap['g'] = true;
            }
            break;
        case 72:
            //H
            if(ui->keyH->isVisible() && state == 0) {
                ui->keyH->setVisible(false);
                keyMap['h'] = false;
            } else {
                ui->keyH->setVisible(true);
                keyMap['h'] = true;
            }
            break;
        case 73:
            //I
            if(ui->keyI->isVisible() && state == 0) {
                ui->keyI->setVisible(false);
                keyMap['i'] = false;
            } else {
                ui->keyI->setVisible(true);
                keyMap['i'] = true;
            }
            break;
        case 74:
            //J
            if(ui->keyJ->isVisible() && state == 0) {
                ui->keyJ->setVisible(false);
                keyMap['j'] = false;
            } else {
                ui->keyJ->setVisible(true);
                keyMap['j'] = true;
            }
            break;
        case 75:
            //K
            if(ui->keyK->isVisible() && state == 0) {
                ui->keyK->setVisible(false);
                keyMap['k'] = false;
            } else {
                ui->keyK->setVisible(true);
                keyMap['k'] = true;
            }
            break;
        case 76:
            //L
            if(ui->keyL->isVisible() && state == 0) {
                ui->keyL->setVisible(false);
                keyMap['l'] = false;
            } else {
                ui->keyL->setVisible(true);
                keyMap['l'] = true;
            }
            break;
        case 77:
            //M
            if(ui->keyM->isVisible() && state == 0) {
                ui->keyM->setVisible(false);
                keyMap['m'] = false;
            } else {
                ui->keyM->setVisible(true);
                keyMap['m'] = true;
            }
            break;
        case 78:
            //N
            if(ui->keyN->isVisible() && state == 0) {
                ui->keyN->setVisible(false);
                keyMap['n'] = false;
            } else {
                ui->keyN->setVisible(true);
                keyMap['n'] = true;
            }
            break;
        case 79:
            //O
            if(ui->keyO->isVisible() && state == 0) {
                ui->keyO->setVisible(false);
                keyMap['o'] = false;
            } else {
                ui->keyO->setVisible(true);
                keyMap['o'] = true;
            }
            break;
        case 80:
            //P
            if(ui->keyP->isVisible() && state == 0) {
                ui->keyP->setVisible(false);
                keyMap['p'] = false;
            } else {
                ui->keyP->setVisible(true);
                keyMap['p'] = true;
            }
            break;
        case 81:
            //Q
            if(ui->keyQ->isVisible() && state == 0) {
                ui->keyQ->setVisible(false);
                keyMap['q'] = false;
            } else {
                ui->keyQ->setVisible(true);
                keyMap['q'] = true;
            }
            break;
        case 82:
            //R
            if(ui->keyR->isVisible() && state == 0) {
                ui->keyR->setVisible(false);
                keyMap['r'] = false;
            } else {
                ui->keyR->setVisible(true);
                keyMap['r'] = true;
            }
            break;
        case 83:
            //S
            if(ui->keyS->isVisible() && state == 0) {
                ui->keyS->setVisible(false);
                keyMap['s'] = false;
            } else {
                ui->keyS->setVisible(true);
                keyMap['s'] = true;
            }
            break;
        case 84:
            //T
            if(ui->keyT->isVisible() && state == 0) {
                ui->keyT->setVisible(false);
                keyMap['t'] = false;
            } else {
                ui->keyT->setVisible(true);
                keyMap['t'] = true;
            }
            break;
        case 85:
            //U
            if(ui->keyU->isVisible() && state == 0) {
                ui->keyU->setVisible(false);
                keyMap['u'] = false;
            } else {
                ui->keyU->setVisible(true);
                keyMap['u'] = true;
            }
            break;
        case 86:
            //V
            if(ui->keyV->isVisible() && state == 0) {
                ui->keyV->setVisible(false);
                keyMap['v'] = false;
            } else {
                ui->keyV->setVisible(true);
                keyMap['v'] = true;
            }
            break;
        case 87:
            //W
            if(ui->keyW->isVisible() && state == 0) {
                ui->keyW->setVisible(false);
                keyMap['w'] = false;
            } else {
                ui->keyW->setVisible(true);
                keyMap['w'] = true;
            }
            break;
        case 88:
            //X
            if(ui->keyX->isVisible() && state == 0) {
                ui->keyX->setVisible(false);
                keyMap['x'] = false;
            } else {
                ui->keyX->setVisible(true);
                keyMap['x'] = true;
            }
            break;
        case 89:
            //Y
            if(ui->keyY->isVisible() && state == 0) {
                ui->keyY->setVisible(false);
                keyMap['y'] = false;
            } else {
                ui->keyY->setVisible(true);
                keyMap['y'] = true;
            }
            break;
        case 90:
            //Z
            if(ui->keyZ->isVisible() && state == 0) {
                ui->keyZ->setVisible(false);
                keyMap['z'] = false;
            } else {
                ui->keyZ->setVisible(true);
                keyMap['z'] = true;
            }
            break;
        case 8:
            //BKSP
            if(ui->keyBKSP->isVisible() && state == 0) {
                ui->keyBKSP->setVisible(false);
                keyMap['-'] = false;
            } else {
                ui->keyBKSP->setVisible(true);
                keyMap['-'] = true;
            }
            break;
        case 32:
            //SPACE
            if(ui->keySpace->isVisible() && state == 0) {
                ui->keySpace->setVisible(false);
                keyMap[' '] = false;
            } else {
                ui->keySpace->setVisible(true);
                keyMap[' '] = true;
            }
            break;
        case 37:
            //Left
            if(state == 1) {
                this->move(this->x() - 5,this->y());
            }
            break;
        case 38:
            //Up
            if(state == 1) {
                this->move(this->x(),this->y() - 5);
            }
            break;
        case 39:
            //Right
            if(state == 1) {
                this->move(this->x() + 5,this->y());
            }
            break;
        case 40:
            //Right
            if(state == 1) {
                this->move(this->x(),this->y() + 5);
            }
            break;
    }
    //printf("Time at last start was %f\n", (double) startTime / (double) CLOCKS_PER_SEC);
    //std::future<void> paul = std::async (paulDone,startTime,waiter);
    //printf("Setkey!\n");
}

void MainWindow::eyeMov(double x,double y) {
    double h = ui->textBrowser->height();
    double w = ui->textBrowser->width();


    double xP = x * sqrt(1-y * y /2.0);
    double yP = y * sqrt(1-x * x /2.0);



    double centerW = ui->textBrowser->x() + w/2.0;


    xP *= w/4.0;
    yP *= h/4.0;
/*
    xP -= w/5.0;
    yP -= h/5.0;

    if(xP < 0) {
        xP += (w/5.0)*3.0;
    }

    if(yP < 0) {
        yP += (h/5.0)*3.0;
    }
*/

    xP += ui->textBrowser->x() + w/2.0 - ui->Eyes->width()/2.0;
    yP += ui->textBrowser->y() + h/2.0 - ui->Eyes->height()/2.0;


    ui->Eyes->move(xP,yP);

   // audioTest();

}


//void MainWindow::audioTest(){
//    QIODevice mic = QAudioInput::start();
//}



void MainWindow::debug(){
    QPixmap monkeType (":images//resources//HeThinkin.jpg");
    ui->Paul->setPixmap(monkeType);

}



