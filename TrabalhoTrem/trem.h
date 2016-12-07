#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <QString>
#include <thread>
#include <chrono>
#include "semaforo.h"
using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int);
    ~Trem();
    void start();
    void run();
    void stop();
    void setVelocidade(int);
    void setEnable(bool);
    Semaforo *s1;
    Semaforo *s2;
    Semaforo *s3;

signals:
    void updateGUI(int,int,int,bool);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int velocidade;
   bool enable;
   bool usingSemaphore;
};

#endif // TREM_H



