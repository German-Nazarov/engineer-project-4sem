#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>



int main()
{
    // Массивы частот для Октав в Гц
    float Octave_big[12] = {65.4064,	69.2957,	73.4162,	77.7817,	82.4069,	87.3071,	92.4986,	97.9989,	103.8262,	110,	116.5409,	123.4708};
    float Octave_small[12] = {130.8128,	138.5913,	146.8324,	155.5635,	164.8138,	174.6141,	184.9972,	195.9977,	207.6523,	220,	233.0819,	246.9417};
    float Octave_1[12] = {261.6256,	277.1826,	293.6648,	311.127,	329.6276,	349.2282,	369.9944,	391.9954,	415.3047,	440,	466.1638,	493.8833};
    float Octave_2[12] = {523.2511,	554.3653,	587.3295,	622.254,	659.2551,	698.4565,	739.9888,	783.9909,	830.6094,	880,	932.3275,	987.7666};
    float Octave_3[12] = {1046.5023,	1108.7305,	1174.6591,	1244.5079,	1318.5102,	1396.9129,	1479.9777,	1567.9817,	1661.2188,	1760,	1864.655,	1975.5332};

    // Объединение в один массив (так удобнее будет через if выбирать частоты)
    float Octaves[5][12] = {0};
    for(size_t i =0; i < 12; i++){
        Octaves[0][i] = Octave_big[i];
        Octaves[1][i] = Octave_small[i];
        Octaves[2][i] = Octave_1[i];
        Octaves[3][i] = Octave_2[i];
        Octaves[4][i] = Octave_3[i];
    }

/*
   for(size_t i = 0; i < 5; i++){
        for(size_t j =0; j < 12; j++) {
            printf("%f \n", Octaves[i][j]);
        }
    }
*/



    int Array_Key[12] = {0};             // Задание пустого массива значения кнопок

    int Key_Generation_mode;             // Значение кнопки, отвечающей за сигнал - синус, треуг, пила, прямоуг
    int Key_Octave;                      // Значение кнопки, отвечающей за октаву - Большая, Малая, 1, 2, 3
    int Key_1;                           // 12 кнопок
    // ...
    int m;                                // Выходной сигнал на каждом шаге
    double pi = M_PI;



    int k = 0;
    while(k<10){

        double time_spent = 0.0;            // Я попытался нагуглить как это делать в таймере RP, но тщетно
        clock_t begin = clock();            // Нужно для генерации sin(wt) и для разности времён
        int nu_output = 44100;              // Частота выходного сигнала в Гц


        scanf("%d", &Key_Generation_mode);      // (0 sin)
        scanf("%d", &Key_Octave);               //
        scanf("%d", &Key_1);                    // Значение с 1-ой нотной кнопки
        //...

        if(fabs(Key_Octave - 0) <= 0.0001){
            printf("Use big octave \n");
        }
        if(fabs(Key_Octave - 1) <= 0.0001){
            printf("Use small octave \n");
        }
        if(fabs(Key_Octave - 2) <= 0.0001){
            printf("Use 1-st octave \n");
        }
        if(fabs(Key_Octave - 3) <= 0.0001){
            printf("Use 2-nd octave \n");
        }
        if(fabs(Key_Octave - 4) <= 0.0001) {
            printf("Use 3-rd octave \n");
        }


        m = gen_signal(Key_Generation_mode, Key_Octave, Key_1);

        gen_signal(Key_Generation_mode, Key_Octave, Key_1){
            m = 0
            if(fabs(Key_Generation_mode-0)<0.0001){
                if(fabs(Key_Octave-0)<0.0001){
                    if(fabs(Key_1 - 1)){
                        m += sin(begin*2*pi*Octaves[0][0]);
                    }
                    // if(...){}
                }
            }


            return m;
        }



        k += 1;
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds", time_spent);
        sleep(1/nu_output - time_spent);



    }


    return 0;
}