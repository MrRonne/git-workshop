#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_OFF 5
#define PIN_BUTTON_SPEED 4
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonOff(PIN_BUTTON_OFF);
Button buttonSpeed(PIN_BUTTON_SPEED);
Buzzer buzzer(PIN_BUZZER);

unsigned long speeds[] = {25, 50, 100, 150, 200, 300, 400, 800};
int currentSpeed = 2;
int speedsLength = 8;

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

// maybe somewhere in the future we will have one more button...
//#define PIN_BUTTON_MEL_TWO 4
//Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);

// and the second melody
//int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
//double durations2[] = {4, 1, 4, 1};
//int melodyLength2 = 4;

//Кеша
double R = 4;
int notes3[] = {NOTE_E2,
                NOTE_SILENCE,
                NOTE_E2,
                NOTE_SILENCE, 
                NOTE_G2,
                NOTE_SILENCE,
                NOTE_E2,
                NOTE_SILENCE,
                NOTE_D2,
                NOTE_SILENCE,
                NOTE_C2,
                NOTE_SILENCE,
                NOTE_B1,
                NOTE_SILENCE};
double durations3[] = {6*R,//
                       2*R,
                       2*R,//
                       R,
                       R/2,//
                       R/2,
                       R/2,//
                       R/2,
                       R/2,//
                       R/2,
                       R,//
                       2*R,
                       2*R,//
                       2*R};
int melodyLength3 = 14;

void setup()
{
    //Serial.begin(115200);
    buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    buzzer.playSound();
    //Serial.print(begin);
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }

    if (buttonMelodyOne.wasPressed())
    {
        //buzzer.setMelody(notes, durations, melodyLength);
        //buzzer.setMelody(notes2, durations2, melodyLength2);
        buzzer.setMelody(notes3, durations3, melodyLength3);
        buzzer.turnSoundOn();
    }
    /*
    if (buttonMelodyTwo.wasPressed())
    {
        //buzzer.setMelody(notes, durations, melodyLength);
        //buzzer.setMelody(notes2, durations2, melodyLength2);
        buzzer.setMelody(notes3, durations3, melodyLength3);
        buzzer.turnSoundOn();
    }
    */
    if (buttonSpeed.wasPressed())
    {
        currentSpeed = (currentSpeed + 1)%speedsLength;
        buzzer.setNoteDuration(speeds[currentSpeed]);
    }
}
