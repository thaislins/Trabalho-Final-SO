#include "trem.h"

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 20;
    enable = true;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::stop() {

    if(id == 0) {
        //Primeira Região Crítica
         if(x == 150 and y == 110) {
             s1->P();
         }
         //Saiu da primeira região crítica
         if (x == 290 and y == 110) {
             s1->V();
         }
    }
    else if(id == 1) {
        //Primeira região crítica
         if(x == 150 and y == 130) {
             s1->P();
             s2->P();
          }
         //saiu da primeira região crítica
         if(x == 290 and y == 130) {
             s1->V();
             //s2->P();
         }
         //saiu da segunda região crítica
         if(x ==280 and y == 220) {
             s2->V();
         }
    }
    if(id == 2) {
        //Terceira região crítica
       if(x == 430 and y == 210) {
             s3->P();
             s2->P();
       }
       //saiu da terceira região crítica
       if(x == 290 and y == 210) {
            s3->V();
       }
       //saiu da segunda região crítica
       if(x == 300 and y == 120) {
           s2->V();
       }
    }
    else {
        if(x == 290 and y == 230) {
           s3->P();
        }
        if(x == 430 and y == 230) {
           s3->V();
        }
    }
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        switch(id){
        case 0:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 20 && x > 150)
                    x-=10;
                else if (x == 150 && y < 120)
                    y+=10;
                else if (x < 290 && y == 120)
                    x+=10;
                else
                    y-=10;
            }
            break;
        case 1:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <290)
                    x+=10;
                else if (x == 290 && y < 220)
                    y+=10;
                else if (x > 150 && y == 220)
                    x-=10;
                else
                    y-=10;
            }
            if (enable)
                break;
            case 2:
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <430)
                    x+=10;
                else if (x == 430 && y < 220)
                    y+=10;
                else if (x > 290 && y == 220)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 3:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 220 && x <430)
                    x+=10;
                else if (x == 430 && y < 320)
                    y+=10;
                else if (x > 290 && y == 320)
                    x-=10;
                else
                    y-=10;
            }
            break;
        default:
            break;
        }
        stop();
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}
