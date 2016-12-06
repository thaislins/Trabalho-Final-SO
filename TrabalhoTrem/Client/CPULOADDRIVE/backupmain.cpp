#include "BlackGPIO/BlackGPIO.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
   	//GPIO_50 está faltando no arquivo BlackGPIO.h
   	BlackLib::BlackGPIO   led1(BlackLib::GPIO_48,BlackLib::output, BlackLib::SecureMode);
   	BlackLib::BlackGPIO   button1(BlackLib::GPIO_115,BlackLib::input);

   	//int count;

	while(1){
   		//count = button1.getNumericValue();
		if (button1.getNumericValue()){
			while (1){
				led1.setValue(BlackLib::high);
				if (button1.getNumericValue())
					break;
			}
		}

		//sleep(1);
	   	led1.setValue(BlackLib::low);    
	}

    return 0;
    	
}