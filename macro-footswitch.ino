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

  void loop() {
  buttonState0=digitalRead(button0);
  buttonState1=digitalRead(button1);
  buttonState2=digitalRead(button2);
  buttonState3=digitalRead(button3);
  buttonState4=digitalRead(button4);
  buttonState5=digitalRead(button5);
  
  //Macro-1
  if(bleKeyboard.isConnected() && buttonState0 == HIGH && buttonState1 == HIGH && buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == LOW) {
    Serial.println("Sending Ctrl+Alt+F1...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F1);
    delay(100);
    bleKeyboard.releaseAll();
    delay(1000);
  } 
   //Macro-2
  if(bleKeyboard.isConnected() && buttonState0 == HIGH && buttonState1 == LOW && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == LOW) {
    Serial.println("Sending Ctrl+Alt+F2...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F2);
    delay(100);
    bleKeyboard.releaseAll();
    delay(1000);
  }
   //Macro-3
 if (bleKeyboard.isConnected() && buttonState0 == HIGH && buttonState1 == LOW && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == LOW && buttonState5 == LOW) {
    Serial.println("Sending Ctrl+Alt+F3...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F3);
    delay(100);
    bleKeyboard.releaseAll();
    delay(1000);
  }
   //Macro-4
 if (bleKeyboard.isConnected() && buttonState0 == HIGH && buttonState1 == LOW && buttonState2 == LOW && buttonState3 == LOW && buttonState4 == HIGH && buttonState5 == LOW) {
    Serial.println("Sending Ctrl+Alt+F4...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F4);
    delay(100);
    bleKeyboard.releaseAll();
    delay(1000);
  }
   //Macro-5
 if (bleKeyboard.isConnected() && buttonState0 == HIGH && buttonState1 == LOW && buttonState2 == LOW && buttonState3 == LOW && buttonState4 == LOW && buttonState5 == HIGH) {
    Serial.println("Sending Ctrl+Alt+F5...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F5);
    delay(100);
    bleKeyboard.releaseAll();
    delay(1000);
 }
}
