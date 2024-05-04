#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin8192_int8.h> // sine table for oscillator
#include <tables/saw8192_int8.h>
#include <tables/smoothsquare8192_int8.h>
#include "synth.h"

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
// default here is SIN2048_NUM_CELLS and SIN2048_DATA
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> aSIN(SIN8192_DATA);
Oscil <SAW8192_NUM_CELLS, AUDIO_RATE> aSAW(SAW8192_DATA);
Oscil <SMOOTHSQUARE8192_NUM_CELLS, AUDIO_RATE> aSQR(SMOOTHSQUARE8192_DATA);
// CONTROL_RATE specifies how frequently update_control() is executed
#define CONTROL_RATE 64           // Hz, powers of 2 are most reliable
enum mode { NONE, SIN, SAW, SQR };
int k = mode::NONE;               // индекс, по которому определяем какой сигнал на выходе

float Octaves[5][13] = {0};
void setup(){
  startMozzi(CONTROL_RATE); // :)
  // startMozzi() sets up an interrupt for audio output at a sample rate of 16384 Hz.
  /*This sets up one timer to call updateControl() at the rate chosen and
  another timer which works behind the scenes to send audio samples to the output pin at the fixed rate of
  16384 Hz.*/

  aSIN.setFreq(440);  // set the frequency
  aSAW.setFreq(440);
  aSQR.setFreq(440);

  Serial.begin(9600); // begin Serial com for debugging purposes

  setup_button_pins();
  setup_octave_table();
}

int index_Octave = 0;
int freq_to_set = 0;
void updateControl() {
// put changing controls in here
  freq_to_set = 0;  // reset the frequency so it's played only as long as a button is pressed

  // changing octave
  if (!digitalRead(OCT_BIG)) {
    index_Octave = 0;
    Serial.println("Big Octave");
  }
  if (!digitalRead(OCT_SMALL)) {
    index_Octave = 1;
    Serial.println("Small Octave");
  }
  if (!digitalRead(OCT_1)) {
    index_Octave = 2;
    Serial.println("1 Octave");
  }
  if (!digitalRead(OCT_2)) {
    index_Octave = 3;
    Serial.println("2 Octave");
  }
  if (!digitalRead(OCT_3)) {
    index_Octave = 4;
    Serial.println("3 Octave");
  }

  // changing keys
  if (!digitalRead(BTN_1)) {
    freq_to_set = Octaves[index_Octave][0];
    Serial.println("on btn1");
  }
  if (!digitalRead(BTN_2)) {
    freq_to_set = Octaves[index_Octave][1];
    Serial.println("on btn2");
  }
  if (!digitalRead(BTN_3)) {
    freq_to_set = Octaves[index_Octave][2];
    Serial.println("on btn3");
  }
  if (!digitalRead(BTN_4)) {
    freq_to_set = Octaves[index_Octave][3];
    Serial.println("on btn4");
  }
  if (!digitalRead(BTN_5)) {
    freq_to_set = Octaves[index_Octave][4];
    Serial.println("on btn5");
  }
  if (!digitalRead(BTN_6)) {
    freq_to_set = Octaves[index_Octave][5];
    Serial.println("on btn6");
  }
  if (!digitalRead(BTN_7)) {
    freq_to_set = Octaves[index_Octave][6];
    Serial.println("on btn7");
  }
  if (!digitalRead(BTN_8)) {
    freq_to_set = Octaves[index_Octave][7];
    Serial.println("on btn8");
  }
  if (!digitalRead(BTN_9)) {
    freq_to_set = Octaves[index_Octave][8];
    Serial.println("on btn9");
  }
  if (!digitalRead(BTN_10)) {
    freq_to_set = Octaves[index_Octave][9];
    Serial.println("on btn10");
  }
  if (!digitalRead(BTN_11)) {
    freq_to_set = Octaves[index_Octave][10];
    Serial.println("on btn11");
  }
  if (!digitalRead(BTN_12)) {
    freq_to_set = Octaves[index_Octave][11];
    Serial.println("on btn12");
  }
  if (!digitalRead(BTN_13)) {
    freq_to_set = Octaves[index_Octave][12];
    Serial.println("on btn13");
  }

  // changing type of output signal
  if (!digitalRead(SIN_BTN)) {
    k = mode::SIN;
    Serial.println("SIN");
  }
  if (!digitalRead(SAW_BTN)) {
    k = mode::SAW;
    Serial.println("SAW");
  }
  if (!digitalRead(SQR_BTN)) {
    k = mode::SQR;
    Serial.println("SQR");
  }

  aSIN.setFreq(freq_to_set);
  aSAW.setFreq(freq_to_set);
  aSQR.setFreq(freq_to_set);
}

AudioOutput_t updateAudio(){
  // return an int signal centred around 0
  switch(k) {
    case mode::SIN:
      return MonoOutput::from8Bit(aSIN.next());
      break;
    case mode::SAW:
      return MonoOutput::from8Bit(aSAW.next());
      break;
    case mode::SQR:  
      return MonoOutput::from8Bit(aSQR.next());
      break;
    case mode::NONE:
    default:
      return 0;
      break;
  }
  // Oscil’s next() method returns a signed 8 bit value from the oscillator’s wavetable.
  // The int return value of updateAudio() must be in the range -244 to 243 in Mozzi’s default STANDARD audio mode.
}


void loop(){
  audioHook(); // required here
}

/* ---- КОД НАСТРОЙКИ ---- */
void setup_octave_table() {
  for(size_t i = 0; i < 13; i++) {
    Octaves[0][i] = Octave_big[i];
    Octaves[1][i] = Octave_small[i];
    Octaves[2][i] = Octave_1[i];
    Octaves[3][i] = Octave_2[i];
    Octaves[4][i] = Octave_3[i];
  }
}

void setup_button_pins() {
  // Смотрим какая октава выбрана
  pinMode(OCT_1, INPUT_PULLUP);
  pinMode(OCT_2, INPUT_PULLUP);
  pinMode(OCT_3, INPUT_PULLUP);
  pinMode(OCT_BIG, INPUT_PULLUP);
  pinMode(OCT_SMALL, INPUT_PULLUP);

  // Смотрим какие клавиши нажаты
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
  pinMode(BTN_13, INPUT_PULLUP);

  // Смотрим какой тип сигнала на выходе
  pinMode(SIN_BTN, INPUT_PULLUP);
  pinMode(SAW_BTN, INPUT_PULLUP);
  pinMode(SQR_BTN, INPUT_PULLUP);
}
