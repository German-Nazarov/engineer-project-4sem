#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable
#define BTN_1 16
#define BTN_2 17
#define BTN_3 18
#define BTN_4 19
#define BTN_5 20
#define BTN_6 21
#define BTN_7 22
#define BTN_8 26
#define BTN_9 27
#define BTN_10 28
#define BTN_11 14
#define BTN_12 15

const float Octave_1[12] = 
  {261.6256,	277.1826,	293.6648,	311.127,	329.6276,	349.2282,	369.9944,	391.9954,	415.3047,	440,	466.1638,	493.8833};


void setup(){
  startMozzi(CONTROL_RATE); // :)
  /*This sets up one timer to call updateControl() at the rate chosen and 
  another timer which works behind the scenes to send audio samples to the output pin at the fixed rate of 
  16384 Hz.
  */
  aSin.setFreq(440); // set the frequency

  Serial.begin(9600);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);
  pinMode(BTN_5, INPUT_PULLUP);
  pinMode(BTN_6, INPUT_PULLUP);
  pinMode(BTN_7, INPUT_PULLUP);
  pinMode(BTN_8, INPUT_PULLUP);
  pinMode(BTN_9, INPUT_PULLUP);
  pinMode(BTN_10, INPUT_PULLUP);
  pinMode(BTN_11, INPUT_PULLUP);
  pinMode(BTN_12, INPUT_PULLUP);
}

int freq_to_set = 0;
void updateControl(){
  // put changing controls in here
  if (!digitalRead(BTN_1)) {
    freq_to_set = Octave_1[0];
    Serial.println("on btn1");
  }
  if (!digitalRead(BTN_2)) {
    freq_to_set = Octave_1[1];
    Serial.println("on btn2");
  }
  if (!digitalRead(BTN_3)) {
    freq_to_set = Octave_1[2];
    Serial.println("on btn3");
  }
  if (!digitalRead(BTN_4)) {
    freq_to_set = Octave_1[3];
    Serial.println("on btn4");
  }
  if (!digitalRead(BTN_5)) {
    freq_to_set = Octave_1[4];
    Serial.println("on btn5");
  }
  if (!digitalRead(BTN_6)) {
    freq_to_set = Octave_1[5];
    Serial.println("on btn6");
  }
  if (!digitalRead(BTN_7)) {
    freq_to_set = Octave_1[6];
    Serial.println("on btn7");
  }
  if (!digitalRead(BTN_8)) {
    freq_to_set = Octave_1[7];
    Serial.println("on btn8");
  }
  if (!digitalRead(BTN_9)) {
    freq_to_set = Octave_1[8];
    Serial.println("on btn9");
  }
  if (!digitalRead(BTN_10)) {
    freq_to_set = Octave_1[9];
    Serial.println("on btn10");
  }
  if (!digitalRead(BTN_11)) {
    freq_to_set = Octave_1[10];
    Serial.println("on btn11");
  }
  if (!digitalRead(BTN_12)) {
    freq_to_set = Octave_1[11];
    Serial.println("on btn12");
  }

  aSin.setFreq(freq_to_set);
}


AudioOutput_t updateAudio(){
  return MonoOutput::from8Bit(aSin.next()); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}
