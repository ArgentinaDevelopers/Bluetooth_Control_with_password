/*
 Bluetooth_Control_with_password  
 Library for comunicating with key.
 Created by Argentina Developers, Julio 24, 2017.
*/

/*A               _____________________
 *R          -----| RXD      HC-05     |
 *D    RX0   -----| TXD        or      |
 *U    GND   -----| GND      HC-06     |
 *I    +5V   -----| VCC                |
 *N               |____________________|
 *O 
 */
#include <Bluetooth_Control_with_password.h>
Bluetooth_Control_with_password BluePass;
void setup() {
  Serial.begin(9600);
  BluePass.setupBluetooth("PASSWORD");//here set up your password
}

void loop() {
	int number=BluePass.checkData();//read de incoming data from the serial port
  if(number!=-1)         //check if there is some data  
  {
	  if(number==-2)      //code of error means that you have put a Bad password
	  {
		  Serial.println("You have inserted a bad password");
	  }
	  else
	  {
		  Serial.print("You have pressed door number ");
		  Serial.println(number);
	  }
  }
  


}
