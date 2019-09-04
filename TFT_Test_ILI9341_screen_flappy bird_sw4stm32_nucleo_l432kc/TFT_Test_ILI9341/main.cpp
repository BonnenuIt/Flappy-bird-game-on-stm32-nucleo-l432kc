#include "stdio.h"
#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial28x28.h"
#include <stdlib.h> 
#include <time.h>

extern unsigned char bird1[];  // the bird
extern unsigned char background[];  // the background
extern unsigned char GAME1[];  // the characters "GAME"
extern unsigned char OVER1[];  // the characters "OVER"
extern unsigned char START[];  // the characters "GAME START"
extern unsigned char COLUMN[];  // the column
extern unsigned char SCORE[];  // the characters "SCORE"
extern unsigned char BEST[];  // the characters "BEST"
extern unsigned char DOWN[];  // the component of the gap
extern unsigned char UP[];  // the component of the gap

SPI_TFT_ILI9341 TFT(D2, D10, A1, D3, A6, D5, "TFT"); // mosi, miso, sclk, cs, reset, dc

float getRand() {
    return rand() / (RAND_MAX + 1.0);
} //Initialize the system of random rumbers

void OPEN(void) {
    TFT.claim(stdout);      // send stdout to the TFT display
    //TFT.claim(stderr);      // send stderr to the TFT display
    TFT.background(White);    // set background to white
    TFT.foreground(Black);    // set chars to black
    TFT.cls();                // clear the screen
    TFT.set_orientation(0);   //set the direction of the display*
    TFT.Bitmap(30, 130, 180, 31, START);  //Display the characters "GAME START"
    wait(2);
    TFT.background(White);    // set background to white
    TFT.foreground(Black);    // set chars to black
    TFT.cls();                // clear the screen    
}//Initialize the system of tft screen

void gap(int left, int up) {
    TFT.Bitmap(left, up, 40, 40, UP);
    TFT.fillrect(left, (up + 40), (left + 40), (up + 80), White);
    TFT.Bitmap(left, (up + 80), 40, 40, DOWN);
}  //Display the gap which allows the bird to pass through

void END(int score_1, int best_1) {
    TFT.Bitmap(30, 53, 70, 24, GAME1);
    TFT.Bitmap(140, 50, 70, 27, OVER1);
    TFT.Bitmap(72, 120, 100, 31, SCORE);
    //    TFT.Bitmap(75,190,90,31,BEST);
    TFT.set_font((unsigned char*)Arial28x28);
    TFT.locate(100, 160);
    TFT.printf("%d", score_1);
    //    TFT.set_font((unsigned char*) Arial28x28);
    //    TFT.locate(100,220);
    //    TFT.printf("%d",best_1);
}  //Display the characters "GMAE OVER" and your score

int random_f(int max) {
    int result;
    result = getRand()*max;
    result++;
    return result;
}  //Function which can generate and deal with the random numbers

int judge(int position_l, int column_position, int random_) {
    //bird（p，p+30，p+20，p+50）   （The upper left，The upper right，The lower left，The lower right） 
    int ret = 0;
    if (90 + 30>240 - column_position && 90<280 - column_position) {
        if (position_l<random_ + 20 || position_l>random_ + 90) {
            ret = 1;
        }
    } //hit the column
    if (position_l >= 310) {
        ret = 1;
    } //hit the ground
    return ret;
} //Determine if the game is over

AnalogOut kout(A3);
DigitalOut led(D9);
AnalogIn kin(A0);
//Control the motion of the bird and set an LED

int main()
{
    begin:
    srand(time(NULL)); // //Initialize the system of random rumbers
    getRand(); // kick-start the random numbers 
    OPEN(); //Initialize the system of tft screen

    //the part of the game

    int score = 0;  //your score
    int best = 0;  //your best score
    int begin_h = 180; //The starting height of the bird
    int column_position;  //the position of the column 
    int random_ = 150;  //random number(set the first height of the gap to make the game easier)
    int endless = 0;  //Determine if the game is over
    column_position = 40;
    kout = 0.8; 
    while (1) {     

        if (column_position <= 240) {
            TFT.Bitmap(0, 275, 240, 45, background);  //Draw the background
            for (int zhuzi = 0; zhuzi<8; zhuzi++) {
                TFT.Bitmap(240 - column_position, (zhuzi * 40), 40, 40, COLUMN);
            }
            gap(240 - column_position, random_);
        }
        //Draw the background and the columns
        //The first gap: Height=150   Left:200  
        //The height of the following gap is random 
        //The height of the upper column = random_+20（width:200 and 240）
        //The height of the lower column = random_+100（width:200 and 240）
        //Actually the length of the gap is 80 
        if (column_position > 240) { //When the column moves to the far left
            random_ = 0;
            while (random_<20 || random_>180) {
                random_ = random_f(275);
            }
            //Only allow the columns to be created at the position of 20-200
            column_position = 40;
            //Column's regeneration
        }
        //Column's disappearance and regeneration
        if (column_position == 130) {
            score++;
        }
        //Calculate the score
        if (best <= score) {
            best = score;
        }
        //Calculate the best score
        endless = judge(begin_h, column_position, random_);
        if (endless == 1) {
            goto end;
        }//Game over

        column_position += 15;
        //The column moves 15 to the left
        TFT.Bitmap(90, begin_h, 30, 20, bird1);
        begin_h += 15;
        //The bird moves down 15 once
        //begin_h is the height of the top left corner of the bird， bird：30*20 
        TFT.cls();
        //clear the screen 

        if (kin >= 0.53f) {
            begin_h -= 35;
            led = 1;
        }
        //Control the bird based on the keyboard
        else {
            led = 0;
        }
    }
end:
    TFT.cls();
    END(score, best);
    //Game Over
    while(1){
        if(kin>=0.53f){
            goto begin;
        }
    }
}
