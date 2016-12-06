#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "semaforo.h"
#include <QMainWindow>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateSemaphoreCounter();
    void trainSpeed();

public slots:
    void updateInterface(int,int,int);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_playbutton_clicked();

private:
    Ui::MainWindow *ui;
    Trem *trem0;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Semaforo *s1;
    Semaforo *s2;
    Semaforo *s3;

    bool first;
};

#endif // MAINWINDOW_H
