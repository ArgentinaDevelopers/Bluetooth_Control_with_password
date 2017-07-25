/*
 Bluetooth_Control_with_password
 Library for comunicating with key.
 Created by Argentina Developers, Julio 24, 2017.
*/

#include "Arduino.h"
#include "Bluetooth_Control_with_password.h"


void Bluetooth_Control_with_password::setupBluetooth(String PASSWORD) {
  PASSWORD.toCharArray(_secretCode,30);
  Serial.begin(9600);
  _largo=PASSWORD.length();
}



int Bluetooth_Control_with_password::checkData() {
	int varRet= -1;
  if (Serial.available()) {
    char rx[30];
    delay(200);//wait to receive all the message
    int i = 0;
    while (Serial.available())
    {
      rx[i] = Serial.read();
      i++;
    }
    if (rx[0] == 'i')
    {

      boolean ok = true;
      for (int j = 0; j < _largo; j++)
      {
        if (rx[j + 1] != _secretCode[j])

          ok = false;

      }

      if (ok && rx[_largo + 1] == '*' && rx[_largo + 3] == '-')
      {
        int pin = rx[_largo + 2] - 48 ;
        varRet=pin;

      }
	  else
		  varRet=-2;

    }
  }
	return varRet;

}
