/********************************************************************
 * This is a 6 button BLE Macro Foot-Switch.                         *
 * Button 1 sends the stored command from buttons 2-6 over Bluetooth. *
 * Just map the pins, set the macros, and go                          *
 *                                                                   *
 * Changing the name of the device, manufaturer, and initial battery *
 * level can be done at "BleKeyboard bleKeyboard" below              *
 *                                                                   *
 * The BleKeyboard Library is not availble on the library manager so *
 * will need to be installed from Github.                            *
 * https://github.com/T-vK/ESP32-BLE-Keyboard                        *
 ********************************************************************/
#include <BleKeyboard.h>
BleKeyboard bleKeyboard("Macro Foot-Switch", "Daaan", 69);
const int button0=36;    // set GPIO pins on ESP32.
int buttonState0=0;     // Keep state to 0

const int button1=39;
int buttonState1=0;

const int button2=34;
int buttonState2=0;

const int button3=35;
int buttonState3=0;

const int button4=32;
int buttonState4=0;

const int button5=33;
int buttonState5=0;

void setup() {
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT); 
  pinMode(button5, INPUT);

  Serial.begin(115200);
  Serial.println("Starting Bluetooth!");
  bleKeyboard.begin();
}

void macro_keys(uint8_t key_name){
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.press(key_name);
  delay(100);
  bleKeyboard.releaseAll();
  delay(1000);
}

void loop() {

  buttonState0=(digitalRead(button0)==HIGH)? 1:0;

  buttonState1=(digitalRead(button1)==HIGH)? 1:0;
  buttonState2=(digitalRead(button2)==HIGH)? 2:0;
  buttonState3=(digitalRead(button3)==HIGH)? 4:0;
  buttonState4=(digitalRead(button4)==HIGH)? 8:0;
  buttonState5=(digitalRead(button5)==HIGH)? 16:0;
  totalState=buttonState0*(buttonState1+buttonState2+buttonState3+buttonState4+buttonState5)

    //Macro-1
    if(bleKeyboard.isConnected()){
      switch(totalState){
        // Button 1 only
      case 1:
      Serial.println("Sending Ctrl+Alt_Shift+F1");
      macro_keys(KEY_F1);
      break;
        // Button 2 only
      case 2:
      Serial.println("Sending Ctrl+Alt_Shift+F2");
      macro_keys(KEY_F2);
      break;
        // Button 3 only
      case 4:
      Serial.println("Sending Ctrl+Alt_Shift+F3");
      macro_keys(KEY_F3);
      break;
        // Button 4 only
      case 8:
      Serial.println("Sending Ctrl+Alt_Shift+F4");
      macro_keys(KEY_F4);
      break;
        // Button 5 only
      case 16:
      Serial.println("Sending Ctrl+Alt_Shift+F5");
      macro_keys(KEY_F5);
      break;
      }
    }
}
