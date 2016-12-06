#include "BlackGPIO/BlackGPIO.h" 
#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <iostream>     //close
#include <sstream>
#include <fstream>

using namespace std;
 
#define MAXMSG 1024
#define MAXNAME 100
#define PORTNUM 1234
#define PATH_ADC "/sys/bus/iio/devices/iio:device0/in_voltage"
 
class Test {
public:
    int todo;
    int a;
    int b;
};

int readAnalog(int number){
   std::stringstream ss;
   ss << PATH_ADC << number << "_raw";
   std::fstream fs;
   fs.open(ss.str().c_str(), std::fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int PotentiometerSpeed() {

    int velocidade;

    BlackLib::BlackGPIO   button1(BlackLib::GPIO_115,BlackLib::input); 
    BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);

    while(1) {
        if (readAnalog(1) > 0 and readAnalog(1) <= 1365) {
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::high);
          velocidade = 250;
            }
        else if (readAnalog(1) > 1365 and readAnalog(1) <= 2720) {
          ledR.setValue(BlackLib::low);
          ledG.setValue(BlackLib::high);
          ledB.setValue(BlackLib::low);
          velocidade = 100;
            }
        else if (readAnalog(1) > 2720 and readAnalog(1) <=4095) {
          ledR.setValue(BlackLib::high);
          ledG.setValue(BlackLib::low);
          ledB.setValue(BlackLib::low);
          velocidade = 50;
            }
        if(button1.getNumericValue()) break; 
    }
    return velocidade;
}
 
int main(int argc, char *argv[])
{

    BlackLib::BlackGPIO   led1(BlackLib::GPIO_48,BlackLib::output, BlackLib::SecureMode);
    led1.setValue(BlackLib::high);

    struct sockaddr_in endereco;
    int socketId;
    Test test;

    cout << "-------------------------------------" << endl;
    cout << "              *MENU*" << endl;
    cout << "-------------------------------------" << endl;
    sleep(1);
    cout << "\nOpções:" << endl;
    cout << "   1.Defina a velocidade de todos os trens" << endl;
    cout << "   2.Defina a velocidade de um trem específico" << endl;
    cout << "   3.Ligar ou desligar todos os trens" << endl;
    cout << "   4.Ligar ou desligar um trem específico" << endl;

    while(1) {
        std::cout << endl << "Qual função de 1 à 4 executar: " << endl;
        std::cin >> test.todo;

        switch(test.todo){
            case 1:
                std::cout << "Qual será a velocidade para todos os trens?" << std::endl;
                test.a = PotentiometerSpeed();
                break;
            case 2:
                std::cout << "Escolha um trem: ";
                std::cin >> test.a;
                std::cout << "Qual será a sua velocidade? " << endl;
                test.a = PotentiometerSpeed(); 
                break;
            case 3:
                std::cout << "Você quer ligar ou desligar os trens?" << endl;
                std::cin >> test.a;
            case 4:
                std::cout << "Escolha um trem para ligar ou desligar? " << endl;
                std::cin >> test.a;
                std::cout << "Você quer ligar ou desligar o trem? " << endl;
                std::cin >> test.b;
        default:
                break;
    }
}

    /*std::cout << "A: ";
    std::cin >> test.a;

    if (test.todo == 2 || test.todo == 4) {
        std::cout << "B: ";
        std::cin >> test.b;
    }*/

    int bytesenviados;
 
    /*
     * Configurações do endereço
    */
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    endereco.sin_addr.s_addr = inet_addr("192.168.7.1"); // PUT YOUR IP HERE "ip addr show" no terminal
 
    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
    */
    socketId = socket(AF_INET, SOCK_STREAM, 0);
 
    //Verificar erros
    if (socketId == -1)
    {
        printf("Falha ao executar socket()\n");
        exit(EXIT_FAILURE);
    }
 
    //Conectando o socket cliente ao socket servidor
    if ( connect (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
        printf("Falha ao executar connect()\n");
        exit(EXIT_FAILURE);
    }
    printf ("Cliente conectado ao servidor\n");
 
    //Enviar uma msg para o cliente que se conectou
    printf("Cliente vai enviar uma mensagem\n");
    bytesenviados = send(socketId,&test,sizeof(test),0);
 
    if (bytesenviados == -1)
    {
        printf("Falha ao executar send()");
        exit(EXIT_FAILURE);
    }
    printf("Cliente enviou a seguinte msg (%d bytes) para o servidor: %c \n",bytesenviados,test.todo);
 
    close(socketId);
 
    return 0;
}