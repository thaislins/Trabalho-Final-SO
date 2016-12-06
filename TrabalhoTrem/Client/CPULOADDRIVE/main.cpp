#include "BlackGPIO/BlackGPIO.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

#define PATH_ADC "/sys/bus/iio/devices/iio:device0/in_voltage"

int readAnalog(int number){
   stringstream ss;
   ss << PATH_ADC << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

void photoresist(){
		cout << "\n-----------------------------------------------------" << endl;
		cout << "### Photoresistor connection lost;" << endl;
		cout << "### Using the battery to keep everything running;" << endl;
		cout << "### Continuing to run in 5 seconds." << endl;
		cout << "-----------------------------------------------------\n" << endl;
		sleep(5);
}

void boot(){
	int valor = 0, num = 0, v1 = 0, s1 = 0;
	srand(time(NULL));
	num = rand() % 8 + 1;
	v1 = 90/num;
	if (readAnalog(0) >= 100){
		cout << "\n### CHECKING HARDWARE STATUS ###\n" << endl;
		cout << "-Battery Status:       Okay!" << endl;
		s1 = 7/num;
		sleep(s1);
		cout << "-RGB LED Status:       Okay!" << endl;
		s1 = 6/num;
		sleep(s1);
		cout << "-RED LED Status:       Okay!" << endl;
		s1 = 8/num;
		sleep(s1);
		cout << "-LDR Status:           Okay!" << endl;
		s1 = 5/num;
		sleep(s1);
		cout << "-Potentiometer Status: Okay!" << endl;
		s1 = 3/num;
		sleep(s1);
		cout << "-Resistors Status:     Okay!" << endl;
		s1 = 5/num;
		sleep(s1);
		cout << "-Start Button Status:  Okay!\n" << endl;		
		s1 = 10/num;
		sleep(s1);
		cout << "--> SYSTEM IS RECEIVING ENERGY FROM THE SOURCE" << endl;
		sleep(1);
		cout << "--> CHARGING THE BATTERY TO START THE SYSTEM"<< endl;
		s1 = 5/num;
		sleep(s1);
		cout << "#BATTERY AT " << v1 << "%" << endl;
		s1 = 6/num;
		sleep(s1);
		cout << "#BATTERY CHARGED!\n" << endl;
	}
	else{
		cout << "\n--> SYSTEM WITHOUT ENERGY" << endl;
		sleep(1);
		cout << "--> TRYING CONNECTION WITH THE PHOTORESIST IN " << endl;
		cout << "3 " << endl;
		sleep(1);
		cout << "2 " << endl;
		sleep(1);
		cout << "1 " << endl;
		sleep(1); 
		boot();
	}
}


int main(int argc, char *argv[])
{
   	BlackLib::BlackGPIO   button1(BlackLib::GPIO_115,BlackLib::input); 
   	BlackLib::BlackGPIO   led1(BlackLib::GPIO_48,BlackLib::output, BlackLib::SecureMode);
   	BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);
	
	boot();
	cout << "-------------------------------------" << endl;
	cout << "*   WELCOME TO THE CPU LOAD DRIVER  *" << endl;
	cout << "-------------------------------------" << endl;
	sleep(1);
	cout << "\nAbout:" << endl;
	cout << "   -This hardware exchanges information via USB and generates a stress\n    test for the CPU based on the desired intensity." << endl;
	cout << "\nInstructions:" << endl;
	cout << "   -To turn off: properly rotate to catch while in blue." << endl;
	cout << "   -Keep the photoresistor from receiving light so the system will lack energy." << endl;
	cout << "   -Don't let the load go over 95%, that will overheat the CPU." << endl;
	cout << "   -It is strongly recommended to wait for the battery to recharge." << endl;
	cout << "\nInformation:" << endl;
	cout << "   -When blue: 0% to 33% of system load capacity." << endl;
	cout << "   -When Green: 34% to 66% of system load capacity." << endl;
	cout << "   -When Red: 67% to 100% of system load capacity." << endl;
	cout << "   -When the red led turns on: the battery and the photoresistor are ready." << endl;
	//cout << "   -While the red led still flicking the driver hasn't started." << endl;
	sleep(4);
	cout << "\nPress the button to start the cpu load." << endl;
	if (readAnalog(0) < 500) photoresist();

	while(1){
		led1.setValue(BlackLib::high);
		//if (readAnalog(0) >= 100){
		if (readAnalog(0) < 500) photoresist();
		if (button1.getNumericValue()){
			if (readAnalog(0) < 500) photoresist();
			cout << "\nPREPARING THE DRIVER" << endl;
			sleep(2);
			if (readAnalog(0) < 500) photoresist();
			cout << "Ready to go.\n" << endl;
			do{
				if (readAnalog(0) < 500) photoresist();
				if (readAnalog(1) > 0 and readAnalog(1) <= 20){
					cout << "The system will turn off in 10 seconds if it continues in this position." << endl;
					if (readAnalog(1) > 20){ cout << "\nPress the button again." << endl; break;}
					if (readAnalog(0) < 500) photoresist();
					sleep(2);
					if (readAnalog(1) > 20){ cout << "\nPress the button again." << endl; break;}
					if (readAnalog(0) < 500) photoresist();
					sleep(2);
					if (readAnalog(1) > 20){ cout << "\nPress the button again." << endl; break;}
					if (readAnalog(0) < 500) photoresist();
					sleep(2);
					if (readAnalog(1) > 20){ cout << "\nPress the button again." << endl; break;}
					if (readAnalog(0) < 500) photoresist();
					sleep(2);
					if (readAnalog(1) > 20){ cout << "\nPress the button again." << endl; break;}
					if (readAnalog(0) < 500) photoresist();
					sleep(2);
					led1.setValue(BlackLib::low);
				    ledR.setValue(BlackLib::low);
	    			ledG.setValue(BlackLib::low);
	   				ledB.setValue(BlackLib::low);
					return 0;
				}
				else if (readAnalog(1) > 20 and readAnalog(1) <= 1365){
					//if (readAnalog(0) < 500) photoresist();
			        ledR.setValue(BlackLib::low);
   					ledG.setValue(BlackLib::low);
    				ledB.setValue(BlackLib::high);
				}
				else if (readAnalog(1) > 1365 and readAnalog(1) <= 2720){
					if (readAnalog(0) < 500) photoresist();
				    ledR.setValue(BlackLib::low);
	    			ledG.setValue(BlackLib::high);
	   				ledB.setValue(BlackLib::low);
				}
				else if (readAnalog(1) > 2720 and readAnalog(1) <=4050){
					if (readAnalog(0) < 500) photoresist();
				    ledR.setValue(BlackLib::high);
	    			ledG.setValue(BlackLib::low);
	   				ledB.setValue(BlackLib::low);
				}
				else if (readAnalog(1) > 4050){
					cout << "\n#WARNING#" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					cout << "--> USING MORE THAN 95% OF THE CAPACITY" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					cout << "--> THE SYSTEM IS OVERHEATING" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(3);
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					cout << "--> IN 8 SECONDS THE SYSTEM WILL SHUTDOWN" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					cout << "8" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "7" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "6" << endl;
					cout << "--> LOST CONNECTION WITH SOME COMPONENTS" << endl;
					led1.setValue(BlackLib::low);
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "5" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "4" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "3" << endl;
					cout << "--> TURN BACK FOR LESS THAN 95% NOW!" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "2" << endl;
					if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					sleep(1);
					cout << "1" << endl;
				    ledR.setValue(BlackLib::low);
			        ledG.setValue(BlackLib::low);
			        ledB.setValue(BlackLib::low);
			        if (readAnalog(0) < 500) photoresist();
					if (readAnalog(1) < 4050){ cout << "\nPress the button again." << endl; break;}
					cout << "\nForced power off." << endl;
					return 0;
				}
			} while (1);
		}
	}
    return 0;    	
}

//Something went wrong.
/*
else {
	if (withoutenergy() == 1){
		return 0;
	}
	else {
		cout << "\n--> ENERGY RECEIVED AGAIN.\n" << endl;
		sleep(1);
		cout << "-->REBOOTING SYSTEM.\n" << endl;
		boot();
	}

int withoutenergy(){
   	BlackLib::BlackGPIO   led1(BlackLib::GPIO_48,BlackLib::output, BlackLib::SecureMode);
   	BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);

	cout << "\n#WARNING#\n" << endl;
	if (readAnalog(0) >= 500) return 0;
	cout << "--> SYSTEM HAS LOST CONNECTION WITH THE PHOTORESIST" << endl;
	cout << "--> USING BACKUP BATTERY" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(3);
	if (readAnalog(0) >= 500) return 0;
	cout << "--> IN 10 SECONDS THE SYSTEM WILL SHUTDOWN" << endl;
	cout << "10" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "9" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "8" << endl;
	cout << "--> LOST CONNECTION WITH SOME COMPONENTS" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "7" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "6" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "5" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "4" << endl;
	if (readAnalog(0) >= 500) return 0;
	led1.setValue(BlackLib::low);
	sleep(0.5);
	led1.setValue(BlackLib::high);
	sleep(0.3);
	led1.setValue(BlackLib::low);
	cout << "3" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	cout << "2" << endl;
	if (readAnalog(0) >= 500) return 0;
	sleep(1);
	ledR.setValue(BlackLib::low);
	ledG.setValue(BlackLib::low);
	ledB.setValue(BlackLib::low);
	cout << "1" << endl;
	sleep(1);
	cout << "\nPower off." << endl;
	return 1;
}
*/
