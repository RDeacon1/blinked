#include "mbed.h"
#include "constants.h"
#include "vt100.h"
#include "display.h"

extern things_t myData;

void displayTask() {
    DigitalOut green(GREENLED);
    printf("\033[2J");  // Clear the terminal display
    ThisThread::sleep_for(1000ms);
    printf("\033[?25l"); // Hide the Visible Cursor

    printf("\033[1;20H\033[1;37mEnvironmental Sensing\033[0;37m");
    ThisThread::sleep_for(100ms);

    while (true) {
      ThisThread::sleep_for(500ms);
      printf("\033[8;3HThe LED is %s\n",
             myData.buttonState ? "\033[1;32mOn \033[0;37m" 
                                : "\033[2;32mOff\033[0;37m");
      if (myData.buttonState == true) {
        green = true;
      } else {
        green = false;
      }
      ThisThread::sleep_for(1ms);
      printf("\033[10;3HTemperature: %2.1fC \n", myData.tempC);
      ThisThread::sleep_for(500ms);
      printf("\033[12;3HLight Level: %3.0f%c \n", myData.lightL, '%');
    }

}