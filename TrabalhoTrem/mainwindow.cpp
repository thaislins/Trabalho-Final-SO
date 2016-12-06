#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
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

    server = std::thread(&MainWindow::watchServer, this);
}

MainWindow::~MainWindow(){
    server.join();
    delete ui;
}

void MainWindow::socketHandler(MainWindow *window, int socketDescriptor, Test test) {
    int byteslidos;

    //Verificando erros
    if (socketDescriptor == -1) {
        printf("Falha ao executar accept()");
        exit(EXIT_FAILURE);
    }

    // Receber uma msg do cliente
    byteslidos = recv(socketDescriptor, &test, sizeof(test), 0);

    if (byteslidos == -1) {
        printf("Falha ao executar recv()");
        exit(EXIT_FAILURE);
    } else if (byteslidos == 0) {
        printf("Cliente finalizou a conexão\n");
        exit(EXIT_SUCCESS);
    }

    if (test.todo == 1) {
        // Define a velocidade de todos os trens como "a".
        window->trainSpeed(test.a);
    } else if (test.todo == 2) {
        // Define a velocidade do trem "a" como "b".
        window->trainSpeed(test.a, test.b);
    } else if (test.todo == 3) {
        // Habilita todos os trens com "a".
        window->setTrainEnable((bool)test.a);
    } else if (test.todo == 4) {
        // Habilita o trem "a" com "b".
        window->setTrainEnable(test.a, (bool)test.b);
    }

    ::close(socketDescriptor);
}

void MainWindow::watchServer() {
    struct sockaddr_in endereco;
    int socketId;

    // variáveis relacionadas com as conexões clientes
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int conexaoClienteId;

    //mensagem enviada pelo cliente
    Test test;

    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    // endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_addr.s_addr = inet_addr("192.168.7.1");  // PUT YOUR IP HERE "ip addr show" no terminal

    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
     */
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    // Verificar erros
    if (socketId == -1) {
        printf("Falha ao executar socket()\n");
        exit(EXIT_FAILURE);
    }

    // Conectando o socket a uma porta. Executado apenas no lado servidor
    if (bind(socketId, (struct sockaddr *) &endereco, sizeof(struct sockaddr)) == -1) {
        printf("Falha ao executar bind()\n");
        exit(EXIT_FAILURE);
    }

    // Habilitando o servidor a receber conexoes do cliente
    if (listen(socketId, 10) == -1) {
        printf("Falha ao executar listen()\n");
        exit(EXIT_FAILURE);
    }

    while (true) {
        // Servidor fica bloqueado esperando uma conexão do cliente
        conexaoClienteId = accept(socketId, (struct sockaddr *) &enderecoCliente, &tamanhoEnderecoCliente);

        //disparar a thread
        std::thread t(&MainWindow::socketHandler, this, conexaoClienteId, test);
        t.detach();
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    server.detach();
    delete s1;
    delete s2;
    delete s3;
}


void MainWindow::updateSemaphoreCounter(){
    ui->count1->display(s1->getContador());
    ui->count2->display(s2->getContador());
    ui->count3->display(s3->getContador());
    //ui->trainS1->setStyleSheet("* { color: blue }");
}


void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
        case 0:
            updateSemaphoreCounter();
            ui->labelTrem00->setGeometry(x,y,20,20);
            break;
        case 1:
            updateSemaphoreCounter();
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            updateSemaphoreCounter();
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            updateSemaphoreCounter();
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
}

void MainWindow::trainSpeed(int velocity){
    trem0->setVelocidade(velocity);
    trem1->setVelocidade(velocity);
    trem2->setVelocidade(velocity);
    trem3->setVelocidade(velocity);
}

void MainWindow::trainSpeed(int train, int velocity){
    switch(train){
    case 0:
        trem0->setVelocidade(velocity);
        break;
    case 1:
        trem1->setVelocidade(velocity);
        break;
    case 2:
        trem2->setVelocidade(velocity);
        break;
    case 3:
        trem3->setVelocidade(velocity);
        break;
    }
}

void MainWindow::setTrainEnable(bool enable) {
    trem0->setEnable(enable);
    trem1->setEnable(enable);
    trem2->setEnable(enable);
    trem3->setEnable(enable);
}

void MainWindow::setTrainEnable(int train, bool enable) {
    switch(train){
    case 0:
        trem0->setEnable(enable);
        break;
    case 1:
        trem1->setEnable(enable);
        break;
    case 2:
        trem2->setEnable(enable);
        break;
    case 3:
        trem3->setEnable(enable);
        break;
    }
}
