#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator
#include <tables/sin8192_int8.h>
#include <tables/saw8192_int8.h>
#include <tables/smoothsquare8192_int8.h>
#include <tables/square_analogue512_int8.h>

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
// default here is SIN2048_NUM_CELLS and SIN2048_DATA
//Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> aSin(SIN8192_DATA);
// Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);
Oscil <SAW8192_NUM_CELLS, AUDIO_RATE> aSin(SAW8192_DATA);
//Oscil <SMOOTHSQUARE8192_NUM_CELLS, AUDIO_RATE> aSin(SMOOTHSQUARE8192_DATA);
//Oscil <SQUARE_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSin(SQUARE_ANALOGUE512_DATA);

// This Oscil will be operating as an audio generator, so the update rate will be AUDIO_RATE
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin2(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin3(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin4(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin5(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin6(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin7(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin8(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin9(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin10(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin11(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin12(SIN2048_DATA);

// CONTROL_RATE specifies how frequently update_control() is executed
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable
// не занимать пин GP0
#define OCT_BIG 12
#define OCT_SMALL 11
#define OCT_1 10
#define OCT_2 9
#define OCT_3 8

#define BTN_1 12
#define BTN_2 11
#define BTN_3 9
#define BTN_4 10
#define BTN_5 8
#define BTN_6 7
#define BTN_7 6
#define BTN_8 4
#define BTN_9 5
#define BTN_10 21
#define BTN_11 22
#define BTN_12 27
#define BTN_13 26

#define SIN_BTN 2
#define SAW_BTN 3
#define SQR_BTN 4 

float Octave_big[12] = {65.4064,	69.2957,	73.4162,	77.7817,	82.4069,	87.3071,	92.4986,	97.9989,	103.8262,	110,	116.5409,	123.4708};
float Octave_small[12] = {130.8128,	138.5913,	146.8324,	155.5635,	164.8138,	174.6141,	184.9972,	195.9977,	207.6523,	220,	233.0819,	246.9417};
float Octave_1[12] = {261.6256,	277.1826,	293.6648,	311.127,	329.6276,	349.2282,	369.9944,	391.9954,	415.3047,	440,	466.1638,	493.8833};
float Octave_2[12] = {523.2511,	554.3653,	587.3295,	622.254,	659.2551,	698.4565,	739.9888,	783.9909,	830.6094,	880,	932.3275,	987.7666};
float Octave_3[12] = {1046.5023,	1108.7305,	1174.6591,	1244.5079,	1318.5102,	1396.9129,	1479.9777,	1567.9817,	1661.2188,	1760,	1864.655,	1975.5332};

float Octaves[5][12] = {0};
void setup_octave_table() {
  for(size_t i = 0; i < 12; i++) {
    Octaves[0][i] = Octave_big[i];
    Octaves[1][i] = Octave_small[i];
    Octaves[2][i] = Octave_1[i];
    Octaves[3][i] = Octave_2[i];
    Octaves[4][i] = Octave_3[i];
  }
}

void setup(){
    startMozzi(CONTROL_RATE); // :)
    // startMozzi() sets up an interrupt for audio output at a sample rate of 16384 Hz.
    /*This sets up one timer to call updateControl() at the rate chosen and
    another timer which works behind the scenes to send audio samples to the output pin at the fixed rate of
    16384 Hz.
    */
    aSin.setFreq(440); // set the frequency

    Serial.begin(9600);
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

    setup_octave_table();
}

int index_Octave = 0;
//int freq_to_set[12] = {0};
int freq_to_set = 0;
int number_of_active_keys = 0;
void updateControl(){
    freq_to_set = 0;
    //freq_to_set[12] = {0};
    number_of_active_keys = 0;
    // put changing controls in here

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
      //isPlaying = true;
      freq_to_set = Octaves[index_Octave][0];
      number_of_active_keys++;
      Serial.println("on btn1");
    }
    //freq_to_set = isPlaying ? Octaves[index_Octave][0] : 0;
    //isPlaying = false;

    if (!digitalRead(BTN_2)) {
        freq_to_set = Octaves[index_Octave][1];
        number_of_active_keys++;
        Serial.println("on btn2");
    }
    if (!digitalRead(BTN_3)) {
        freq_to_set = Octaves[index_Octave][2];
        number_of_active_keys++;
        Serial.println("on btn3");
    }
    if (!digitalRead(BTN_4)) {
        freq_to_set = Octaves[index_Octave][3];
        number_of_active_keys++;
        Serial.println("on btn4");
    }
    if (!digitalRead(BTN_5)) {
        freq_to_set = Octaves[index_Octave][4];
        number_of_active_keys++;
        Serial.println("on btn5");
    }
    if (!digitalRead(BTN_6)) {
        freq_to_set = Octaves[index_Octave][5];
        number_of_active_keys++;
        Serial.println("on btn6");
    }
    if (!digitalRead(BTN_7)) {
        freq_to_set = Octaves[index_Octave][6];
        number_of_active_keys++;
        Serial.println("on btn7");
    }
    if (!digitalRead(BTN_8)) {
        freq_to_set = Octaves[index_Octave][7];
        number_of_active_keys++;
        Serial.println("on btn8");
    }
    if (!digitalRead(BTN_9)) {
        freq_to_set = Octaves[index_Octave][8];
        number_of_active_keys++;
        Serial.println("on btn9");
    }
    if (!digitalRead(BTN_10)) {
        freq_to_set = Octaves[index_Octave][9];
        number_of_active_keys++;
        Serial.println("on btn10");
    }
    if (!digitalRead(BTN_11)) {
        freq_to_set = Octaves[index_Octave][10];
        number_of_active_keys++;
        Serial.println("on btn11");
    }
    if (!digitalRead(BTN_12)) {
        freq_to_set = Octaves[index_Octave][11];
        number_of_active_keys++;
        Serial.println("on btn12");
    }

    // aSin1.setFreq(freq_to_set[0]);
    // aSin2.setFreq(freq_to_set[1]);
    // aSin3.setFreq(freq_to_set[2]);
    // aSin4.setFreq(freq_to_set[3]);
    // aSin5.setFreq(freq_to_set[4]);
    // aSin6.setFreq(freq_to_set[5]);
    // aSin7.setFreq(freq_to_set[6]);
    // aSin8.setFreq(freq_to_set[7]);
    // aSin9.setFreq(freq_to_set[8]);
    // aSin10.setFreq(freq_to_set[9]);
    // aSin11.setFreq(freq_to_set[10]);
    // aSin12.setFreq(freq_to_set[11]);

    aSin.setFreq(freq_to_set);
}

AudioOutput_t updateAudio(){
  // int8_t All_signal;
  // if (number_of_active_keys != 0) {
  //       All_signal = (aSin1.next() + aSin2.next() + aSin3.next() + aSin4.next() + aSin5.next() + aSin6.next() +
  //                     aSin7.next() + aSin8.next() + aSin9.next() + aSin10.next() + aSin11.next() + aSin12.next()) /
  //                    number_of_active_keys;
  // }
  // else{ 
  //   All_signal = 0;
  // }
  // return MonoOutput::from8Bit(All_signal); // return an int signal centred around 0
  
  return MonoOutput::from8Bit(aSin.next()); // return an int signal centred around 0
  // Oscil’s next() method returns a signed 8 bit value from the oscillator’s wavetable.
  // The int return value of updateAudio() must be in the range -244 to 243 in Mozzi’s default STANDARD audio mode.
}


void loop(){
    audioHook(); // required here
 }
