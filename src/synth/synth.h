#ifndef SYNTH_H
#define SYNTH_H

/* ---- ПРЕДВАРИТЕЛЬНОЕ ОБЪЯВЛЕНИЕ ФУНКЦИЙ ---- */
void setup_octave_table();
void setup_button_pins();

/* ---- НАСТРОЙКА ПИНОВ ---- */
// Не занимать пин GP0, там звук!
#define OCT_BIG 16
#define OCT_SMALL 17
#define OCT_1 18
#define OCT_2 19
#define OCT_3 20

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

#define SIN_BTN 13
#define SAW_BTN 14
#define SQR_BTN 15

/* ---- ОБЪЯВЛЕНИЕ ОКТАВ ---- */
// Последний элемент каждой октавы - нота "До" из следующей октавы.
constexpr float Octave_big[13] 
  = {65.4064,	69.2957,	73.4162,	77.7817,	82.4069,	87.3071,	92.4986,	97.9989,	103.8262,	110,	116.5409,	123.4708, 130.8128};
constexpr float Octave_small[13] 
  = {130.8128,	138.5913,	146.8324,	155.5635,	164.8138,	174.6141,	184.9972,	195.9977,	207.6523,	220,	233.0819,	246.9417, 261.6256};
constexpr float Octave_1[13] 
  = {261.6256,	277.1826,	293.6648,	311.127,	329.6276,	349.2282,	369.9944,	391.9954,	415.3047,	440,	466.1638,	493.8833, 523.2511};
constexpr float Octave_2[13] 
  = {523.2511,	554.3653,	587.3295,	622.254,	659.2551,	698.4565,	739.9888,	783.9909,	830.6094,	880,	932.3275,	987.7666, 1046.5023};
constexpr float Octave_3[13] 
  = {1046.5023,	1108.7305,	1174.6591,	1244.5079,	1318.5102,	1396.9129,	1479.9777,	1567.9817,	1661.2188,	1760,	1864.655,	1975.5332, 2093.0046};

#endif