//#include "stdio.h"
//#include "mbed.h"
//#include "SPI_TFT_ILI9341.h"
//#include "string"
//#include "Arial28x28.h"
//#include <stdlib.h> 
//#include <time.h>
//
//extern unsigned char bird1[];  // the mbed logo
//extern unsigned char background[];  // the mbed logo
//extern unsigned char GAME1[];  // the mbed logo
//extern unsigned char OVER1[];  // the mbed logo
//extern unsigned char START[];  // the mbed logo
//extern unsigned char COLUMN[];  // the mbed logo
//extern unsigned char SCORE[];  // the mbed logo
//extern unsigned char BEST[];  // the mbed logo
//extern unsigned char DOWN[];  // the mbed logo
//extern unsigned char UP[];  // the mbed logo
//
//SPI_TFT_ILI9341 TFT(D2, D10, A1, D3, A6, D5, "TFT"); // mosi, miso, sclk, cs, reset, dc
//
//
//float getRand() {
//    return rand() / (RAND_MAX + 1.0);
//}
//
//void OPEN(void) {
//    TFT.claim(stdout);      // send stdout to the TFT display
//                            //TFT.claim(stderr);      // send stderr to the TFT display
//    TFT.background(White);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    TFT.cls();                // clear the screen
//    TFT.set_orientation(0);
//    TFT.Bitmap(30, 130, 180, 31, START);
//    wait(2);
//    TFT.background(White);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    TFT.cls();                // clear the screen    
//}
//
//void kongxi(int left, int up) {
//    TFT.Bitmap(left, up, 40, 40, UP);
//    TFT.fillrect(left, (up + 40), (left + 40), (up + 80), White);
//    TFT.Bitmap(left, (up + 80), 40, 40, DOWN);
//}
//
//void END(int score_1, int best_1) {
//    TFT.Bitmap(30, 50, 70, 24, GAME1);
//    TFT.Bitmap(140, 50, 70, 27, OVER1);
//    TFT.Bitmap(72, 120, 100, 31, SCORE);
////    TFT.Bitmap(75,190,90,31,BEST);
//    TFT.set_font((unsigned char*)Arial28x28);
//    TFT.locate(100, 160);
//    TFT.printf("%d", score_1);
////    TFT.set_font((unsigned char*) Arial28x28);
////    TFT.locate(100,220);
////    TFT.printf("%d",best_1);
//}
//
//int random_f(int max) {
//    int result;
//    result = getRand()*max;
//    result++;
//    return result;
//}
//
//int judge(int position_l, int first, int random_) { //鸟坐标（p，p+30，p+20，p+50）   （左上，右上，左下，右下） 
//    int ret=0;
//    if (90 + 30>240 - first && 90<280 - first) {
//        if (position_l<random_ + 20 || position_l>random_ + 100) {
//            ret=1;
//        }
//    }
//    if (position_l >= 300) {
//        ret=1;
//    }
//    return ret;
//} //判断鸟撞到柱子或地，游戏结束  
//
//AnalogOut kout(A4);
//AnalogIn kin(A0);
//
//int main()
//{
//    srand(time(NULL)); // init random  
//    getRand(); // kick-start the random numbers 
//    OPEN();
//
//    //游戏部分
//
//    int score = 0;
//    int best = 0;
//    int begin_h = 180; //鸟起始高度
//    int first;
//    int random_ = 150;
//    int endless=0;
//    first = 40;
//    kout=0.8;
//    while (1) {
//
//        if (first <= 240) {
//            TFT.Bitmap(0, 275, 240, 45, background);
//            for (int zhuzi = 0; zhuzi<8; zhuzi++) {
//                TFT.Bitmap(240 - first, (zhuzi * 40), 40, 40, COLUMN);
//            }
//            kongxi(240 - first, random_);
//        }
//        //柱子、背景描绘，先高150处空隙，左200处，随后随机空隙        上柱高random_+20（200与240）  下柱高random_+100（200与240）    空隙实际长80 
//        if (first >= 240) { //柱子移动到最左端 
//            random_ = 0;
//            while (random_<45 || random_>200) {
//                random_ = random_f(275);
//            }
//            //只让空隙产生于45-230处
//            first = 40;
//            //柱子再生
//        }
//        //柱子消失、再生
//        if (first == 130) {
//            score++;
//        }
//        //分数计算
//        if(best<=score){
//            best=score;
//        }
//
//        endless=judge(begin_h, first, random_);
//        if(endless==1){
//            goto end; 
//        }//游戏结束
//
//        first += 15;
//        //柱子往左移动15
//        TFT.Bitmap(90, begin_h, 30, 20, bird1);
//        begin_h += 10;
//        //鸟，每次下移10
//        //begin_h即鸟左上角高度，鸟：30*20 
//        TFT.cls();
//        //画面刷新
//
//        if (kin>=0.7 && kin<=0.9) {
//            begin_h -= 40;
//        }
//        //鸟飞起高度40，维持飞翔
//    }
//    end:
//    TFT.cls();
//    END(score, best);
//}
