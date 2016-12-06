#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    trem0 = new Trem(0,170,20);
    trem1 = new Trem(1,250,220);
    trem2 = new Trem(2,400,120);
    trem3 = new Trem(3,380,320);

    s1 = new Semaforo(1,1,IPC_CREAT|0600);
    s2 = new Semaforo(2,1,IPC_CREAT|0600);
    s3 = new Semaforo(3,1,IPC_CREAT|0600);

    trem0->s1 = s1;
    trem0->s2 = s2;
    trem0->s3 = s3;

    trem1->s1 = s1;
    trem1->s2 = s2;
    trem1->s3 = s3;

    trem2->s1 = s1;
    trem2->s2 = s2;
    trem2->s3 = s3;

    trem3->s1 = s1;
    trem3->s2 = s2;
    trem3->s3 = s3;


    connect(trem0,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem0->start();
    trem1->start();
    trem2->start();
    trem3->start();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::trainSpeed() {
    trem0->setVelocidade(100);
    trem1->setVelocidade(50);
    trem2->setVelocidade(240);
    trem3->setVelocidade(100);
}

void MainWindow::updateSemaphoreCounter() {

    ui->count1->display(s1->getContador());
    ui->count2->display(s2->getContador());
    ui->count3->display(s3->getContador());
}

void MainWindow::closeEvent(QCloseEvent *event) {
    delete s1;
    delete s2;
    delete s3;
}

void MainWindow::updateInterface(int id, int x, int y) {
    switch(id){
        case 0:
            trainSpeed();
            updateSemaphoreCounter();
            ui->labelTrem00->setGeometry(x,y,20,20);
            break;
        case 1:
            trainSpeed();
            updateSemaphoreCounter();
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            trainSpeed();
            updateSemaphoreCounter();
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            trainSpeed();
            updateSemaphoreCounter();
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }

}
