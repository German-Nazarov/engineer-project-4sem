#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable
// не занимать пин GP0
#define OCT_BIG 12
#define OCT_SMALL 11
#define OCT_1 10
#define OCT_2 9
#define OCT_3 8

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
#define BTN_12 13

float Octave_big[12] = {65.4064,	69.2957,	73.4162,	77.7817,	82.4069,	87.3071,	92.4986,	97.9989,	103.8262,	110,	116.5409,	123.4708};
float Octave_small[12] = {130.8128,	138.5913,	146.8324,	155.5635,	164.8138,	174.6141,	184.9972,	195.9977,	207.6523,	220,	233.0819,	246.9417};
float Octave_1[12] = {261.6256,	277.1826,	293.6648,	311.127,	329.6276,	349.2282,	369.9944,	391.9954,	415.3047,	440,	466.1638,	493.8833};
float Octave_2[12] = {523.2511,	554.3653,	587.3295,	622.254,	659.2551,	698.4565,	739.9888,	783.9909,	830.6094,	880,	932.3275,	987.7666};
float Octave_3[12] = {1046.5023,	1108.7305,	1174.6591,	1244.5079,	1318.5102,	1396.9129,	1479.9777,	1567.9817,	1661.2188,	1760,	1864.655,	1975.5332};

float Octaves[5][12] = {0};
for(size_t i =0; i < 12; i++){
Octaves[0][i] = Octave_big[i];
Octaves[1][i] = Octave_small[i];
Octaves[2][i] = Octave_1[i];
Octaves[3][i] = Octave_2[i];
Octaves[4][i] = Octave_3[i];
}

void setup(){
    startMozzi(CONTROL_RATE); // :)
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
    pinMode(OCT_4, INPUT_PULLUP);
    pinMode(OCT_5, INPUT_PULLUP);

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
}


int freq_to_set = 0;
int index_Octave = 0;
void updateControl(){
    freq_to_set = 0;
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

    aSin1.setFreq(freq_to_set);
}


AudioOutput_t updateAudio(){
    return MonoOutput::from8Bit(aSin.next()); // return an int signal centred around 0
}


void loop(){
    audioHook(); // required here
}
