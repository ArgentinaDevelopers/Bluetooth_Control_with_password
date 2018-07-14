/*
 Bluetooth_Control_with_password  
 Library for comunicating with key.
 Created by Argentina Developers, Julio 24, 2017.
*/

#ifndef Bluetooth_Control_with_password_h
#define Bluetooth_Control_with_password_h
#include "Arduino.h"
class Bluetooth_Control_with_password {
  public:
    void setupBluetooth(String PASSWORD);
	int checkData();
  private:
	
    char _secretCode[30];
	int _largo;
    
};

#endif
