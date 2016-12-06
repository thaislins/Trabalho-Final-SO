#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "trem.h"
#include "semaforo.h"
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close

using namespace std;

namespace Ui{
class MainWindow;
}

class Test {
public:
    int todo;
    int a;
    int b;
};

#define MAXNAME 100
#define PORTNUM 1234

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateSemaphoreCounter();
    void trainSpeed(int velocity);
    void trainSpeed(int train, int velocity);
    void setTrainEnable(bool enable);
    void setTrainEnable(int train, bool enable);
    void watchServer();
    static void socketHandler(MainWindow *window, int socketDescriptor, Test test);

public slots:
    void updateInterface(int,int,int);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    Trem *trem0;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Semaforo *s1;
    Semaforo *s2;
    Semaforo *s3;
    std::thread server;

    bool first;
};

#endif // MAINWINDOW_H
