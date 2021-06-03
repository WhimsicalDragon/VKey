#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QKeyEvent>
#include <QApplication>
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
#pragma comment(lib, "user32.lib")

#define MOD_NOREPEAT 0x4000
#define MOD_ALT 0x0001

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

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




void MainWindow::updateKey(int key, int state){
    if(state == 1) {
        QPixmap monkeType ("resources/MonkeType.png");
        ui->Paul->setPixmap(monkeType);
        foop();
    }

    switch (key) {
    //It's no magic numbers it's ascii :')
        case 65:
            //A
            if(ui->keyA->isVisible() && state == 0) {
                ui->keyA->setVisible(false);
            } else {
                ui->keyA->setVisible(true);
            }
            break;
        case 66:
            //B
            if(ui->keyB->isVisible() && state == 0) {
                ui->keyB->setVisible(false);
            } else {
                ui->keyB->setVisible(true);
            }
            break;
        case 67:
            //C
            if(ui->keyC->isVisible() && state == 0) {
                ui->keyC->setVisible(false);
            } else {
                ui->keyC->setVisible(true);
            }
            break;
        case 68:
            //D
            if(ui->keyD->isVisible() && state == 0) {
                ui->keyD->setVisible(false);
            } else {
                ui->keyD->setVisible(true);
            }
            break;
        case 69://Nice!
            //E
            if(ui->keyE->isVisible() && state == 0) {
                ui->keyE->setVisible(false);
            } else {
                ui->keyE->setVisible(true);
            }
            break;
        case 70:
            //F
            if(ui->keyF->isVisible() && state == 0) {
                ui->keyF->setVisible(false);
            } else {
                ui->keyF->setVisible(true);
            }
            break;
        case 71:
            //G
            if(ui->keyG->isVisible() && state == 0) {
                ui->keyG->setVisible(false);
            } else {
                ui->keyG->setVisible(true);
            }
            break;
        case 72:
            //H
            if(ui->keyH->isVisible() && state == 0) {
                ui->keyH->setVisible(false);
            } else {
                ui->keyH->setVisible(true);
            }
            break;
        case 73:
            //I
            if(ui->keyI->isVisible() && state == 0) {
                ui->keyI->setVisible(false);
            } else {
                ui->keyI->setVisible(true);
            }
            break;
        case 74:
            //J
            if(ui->keyJ->isVisible() && state == 0) {
                ui->keyJ->setVisible(false);
            } else {
                ui->keyJ->setVisible(true);
            }
            break;
        case 75:
            //K
            if(ui->keyK->isVisible() && state == 0) {
                ui->keyK->setVisible(false);
            } else {
                ui->keyK->setVisible(true);
            }
            break;
        case 76:
            //L
            if(ui->keyL->isVisible() && state == 0) {
                ui->keyL->setVisible(false);
            } else {
                ui->keyL->setVisible(true);
            }
            break;
        case 77:
            //M
            if(ui->keyM->isVisible() && state == 0) {
                ui->keyM->setVisible(false);
            } else {
                ui->keyM->setVisible(true);
            }
            break;
        case 78:
            //N
            if(ui->keyN->isVisible() && state == 0) {
                ui->keyN->setVisible(false);
            } else {
                ui->keyN->setVisible(true);
            }
            break;
        case 79:
            //O
            if(ui->keyO->isVisible() && state == 0) {
                ui->keyO->setVisible(false);
            } else {
                ui->keyO->setVisible(true);
            }
            break;
        case 80:
            //P
            if(ui->keyP->isVisible() && state == 0) {
                ui->keyP->setVisible(false);
            } else {
                ui->keyP->setVisible(true);
            }
            break;
        case 81:
            //Q
            if(ui->keyQ->isVisible() && state == 0) {
                ui->keyQ->setVisible(false);
            } else {
                ui->keyQ->setVisible(true);
            }
            break;
        case 82:
            //R
            if(ui->keyR->isVisible() && state == 0) {
                ui->keyR->setVisible(false);
            } else {
                ui->keyR->setVisible(true);
            }
            break;
        case 83:
            //S
            if(ui->keyS->isVisible() && state == 0) {
                ui->keyS->setVisible(false);
            } else {
                ui->keyS->setVisible(true);
            }
            break;
        case 84:
            //T
            if(ui->keyT->isVisible() && state == 0) {
                ui->keyT->setVisible(false);
            } else {
                ui->keyT->setVisible(true);
            }
            break;
        case 85:
            //U
            if(ui->keyU->isVisible() && state == 0) {
                ui->keyU->setVisible(false);
            } else {
                ui->keyU->setVisible(true);
            }
            break;
        case 86:
            //V
            if(ui->keyV->isVisible() && state == 0) {
                ui->keyV->setVisible(false);
            } else {
                ui->keyV->setVisible(true);
            }
            break;
        case 87:
            //W
            if(ui->keyW->isVisible() && state == 0) {
                ui->keyW->setVisible(false);
            } else {
                ui->keyW->setVisible(true);
            }
            break;
        case 88:
            //X
            if(ui->keyX->isVisible() && state == 0) {
                ui->keyX->setVisible(false);
            } else {
                ui->keyX->setVisible(true);
            }
            break;
        case 89:
            //Y
            if(ui->keyY->isVisible() && state == 0) {
                ui->keyY->setVisible(false);
            } else {
                ui->keyY->setVisible(true);
            }
            break;
        case 90:
            //Z
            if(ui->keyZ->isVisible() && state == 0) {
                ui->keyZ->setVisible(false);
            } else {
                ui->keyZ->setVisible(true);
            }
            break;
        case 8:
            //BKSP
            if(ui->keyBKSP->isVisible() && state == 0) {
                ui->keyBKSP->setVisible(false);
            } else {
                ui->keyBKSP->setVisible(true);
            }
            break;
        case 32:
            //SPACE
            if(ui->keySpace->isVisible() && state == 0) {
                ui->keySpace->setVisible(false);
            } else {
                ui->keySpace->setVisible(true);
            }
            break;
        case 37:
            //Left
            if(state == 1) {
                this->move(this->x() - 5,this->y());
            }
            break;
        case 38:
            //Ui
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

void MainWindow::debug(){
    QPixmap monkeType ("resourrces/HeThinkin.jpg");
    ui->Paul->setPixmap(monkeType);

}


