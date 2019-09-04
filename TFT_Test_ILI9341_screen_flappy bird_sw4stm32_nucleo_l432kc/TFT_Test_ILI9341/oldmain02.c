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
//extern unsigned char OVER[];  // the mbed logo
//extern unsigned char START[];  // the mbed logo
//extern unsigned char COLUMN[];  // the mbed logo
//extern unsigned char SCORE[];  // the mbed logo
//extern unsigned char BEST[];  // the mbed logo
//extern unsigned char DOWN[];  // the mbed logo
//extern unsigned char UP[];  // the mbed logo
//
//SPI_TFT_ILI9341 TFT(D2, D10, A1, D3, A6, D5,"TFT"); // mosi, miso, sclk, cs, reset, dc
//
//float getRand() {
//    return rand() / (RAND_MAX + 1.0); 
//} 
//
//void OPEN(void){
//    TFT.claim(stdout);      // send stdout to the TFT display
//    //TFT.claim(stderr);      // send stderr to the TFT display
//    TFT.background(White);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    TFT.cls();                // clear the screen
//    TFT.set_orientation(0);
//    TFT.Bitmap(30,130,180,31,START);
//    wait(2);
//    TFT.background(White);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    TFT.cls();                // clear the screen    
//}
//
//void kongxi(int left,int up){
//    TFT.Bitmap(left,up,40,40,UP);
//    TFT.fillrect(left,(up+40),(left+40),(up+80),White);
//    TFT.Bitmap(left,(up+80),40,40,DOWN); 
//}
//
//void END(int score_1,int best_1){
//    TFT.Bitmap(0,275,240,45,background);  
//    wait(0.5);
//
//    TFT.Bitmap(30,50,180,31,OVER);
//    TFT.Bitmap(72,100,100,31,SCORE);
////    TFT.Bitmap(75,180,90,31,BEST);
//    TFT.set_font((unsigned char*) Arial28x28);
//    TFT.locate(100,140);
//    TFT.printf("%d",score_1);
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
//int main()
//{
//    srand(time(NULL)); // init random  
//    getRand(); // kick-start the random numbers 
//    OPEN();
//    
////游戏部分
//
//    int score=0;
//    int best=0;
//    int begin_h=150; //鸟起始高度
//    int n=8;
//    int first;
//    int random_=150;
//    first=40;
//    while(n>0){
//        while(begin_h<300){
//            if(first<=240){
//                TFT.Bitmap(0,275,240,45,background);
//                for(int zhuzi=0;zhuzi<8;zhuzi++){
//                    TFT.Bitmap(240-first,(zhuzi*40),40,40,COLUMN);
//                }
//                kongxi(240-first,random_);   
//            }
//            //柱子、背景描绘，先高150处空隙，左200处，随后随机空隙
//            if(first>=240){ //柱子移动
//                random_=0;
//                while(random_<45 || random_>230){
//                    random_=random_f(275);
//                }
//                //只让空隙产生于45-230处
//                first=40;
//                //柱子再生
//            }
//            //柱子消失、再生
//            if(first==130){
//                score++;
//            }
//            //分数计算
//            first+=15;
//            //柱子往左移动15
//            TFT.Bitmap(90,begin_h,30,20,bird1);
//            begin_h+=10;
//            //鸟，每次下移10
//            TFT.cls();
//            //画面刷新
//        }
//        n--;
//        //飞次数
//        begin_h-=50;
//        //鸟飞起高度50，维持飞翔
//    }
//    END(score,best);
//}
