#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem0 = new Trem(0,170,20);
    trem1 = new Trem(1,250,220);
    trem2 = new Trem(2,400,120);
    trem3 = new Trem(3,380,320);

    //s1 = new Semaforo(1,1,IPC_CREAT|0600);

    connect(trem0,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem0->start();
    trem1->start();
    trem2->start();
    trem3->start();



    //delete s1;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 0:
            ui->labelTrem00->setGeometry(x,y,20,20);
            break;
        case 1:
             ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }

}
