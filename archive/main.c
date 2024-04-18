/**
 * Главная идея:
 * 44100 раз в секунду подавать на ЦАП нужное значения для получения требуемого сигнала.
 * Типы выводов: синусоида, менадр, треугольник, пила
**/
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
void read_keys();
int gen_pcm();
void to_dac(int);
bool repeating_timer_callback(struct repeating_timer *t);

struct State {
  int Key_Generation_mode;  // Значение кнопки, отвечающей за сигнал - синус, треуг, пила, прямоуг
  int Key_Octave;           // Значение кнопки, отвечающей за октаву - Большая, Малая, 1, 2, 3
  int Array_Key[12];  // Задание пустого массива значения кнопок
} state;

const uint LED_PIN = 25;
int main() {
  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  struct repeating_timer timer;

  const int us = 23;    // 1/44100Hz
  add_repeating_timer_us(us, repeating_timer_callback, &state, &timer);

  // Main program loop
  while(1) {
    read_keys(); // maybe do this thru interrupts.
    //int m = gen_pcm();
    //to_dac(m);
  }
}

void read_keys() {

}

bool repeating_timer_callback(struct repeating_timer *t) {
  printf("Repeat at %lld\n", time_us_64());
  struct State *pp = (*t).user_data;

  return true;
}

int gen_pcm() {
  printf("Timer");
  return 0;
}

void to_dac(int value) {

}
