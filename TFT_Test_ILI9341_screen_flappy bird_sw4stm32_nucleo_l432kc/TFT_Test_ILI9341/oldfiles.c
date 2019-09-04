// // example to test the TFT Display
//// Thanks to the GraphicsDisplay and TextDisplay classes
//// test2.bmp has to be on the mbed file system
//
////#define NO_DMA
//
//#include "stdio.h"
//#include "mbed.h"
//#include "SPI_TFT_ILI9341.h"
//#include "string"
////#include "Arial24x23.h"
//#include "Arial28x28.h"
//#include "font_big.h"
//
//extern unsigned char bird1[];  // the mbed logo
//extern unsigned char background[];  // the mbed logo
//extern unsigned char OVER[];  // the mbed logo
//extern unsigned char START[];  // the mbed logo
//extern unsigned char COLUMN[];  // the mbed logo
//extern unsigned char MIDDLE[];  // the mbed logo
//extern unsigned char SCORE[];  // the mbed logo
//extern unsigned char BEST[];  // the mbed logo
//extern unsigned char DOWN[];  // the mbed logo
//extern unsigned char UP[];  // the mbed logo
//
//SPI_TFT_ILI9341 TFT(D2, D10, A1, D3, A6, D5,"TFT"); // mosi, miso, sclk, cs, reset, dc
//
//int main()
//{
//    TFT.claim(stdout);      // send stdout to the TFT display
//    //TFT.claim(stderr);      // send stderr to the TFT display
//    
//    TFT.background(White);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    TFT.cls();                // clear the screen
//    TFT.set_orientation(0);
//    
//    TFT.Bitmap(30,130,180,31,START);
//    
//    wait(2);
//    TFT.background(White);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    TFT.cls();                // clear the screen
////    TFT.set_font((unsigned char*) Arial12x12);
////    TFT.locate(0,0);
////    printf("  Hello Mbed ");
////    wait(5);        // wait two seconds
////    // draw some graphics
////    TFT.cls();
////    TFT.set_font((unsigned char*) Arial24x23);
////    TFT.locate(100,100);
////    TFT.printf("Graphic");
////
////    TFT.line(0,0,100,0,Green);
////    TFT.line(0,0,0,200,Green);
////    TFT.line(0,0,100,200,Green);
////
////    TFT.rect(100,50,150,100,Red);
////    TFT.fillrect(180,25,220,70,Blue);
////
////    TFT.circle(80,150,33,White);
////    TFT.fillcircle(160,190,20,Yellow);
////
////    double s;
////
////    for (i=0; i<320; i++) {
////        s =20 * sin((long double) i / 10 );
////        TFT.pixel(i,100 + (int)s ,Red);
////    }
////    wait(5);        // wait two seconds
////    TFT.foreground(White);
////    TFT.background(Blue);
////    TFT.cls();
////    TFT.set_font((unsigned char*) Arial24x23);
////    TFT.locate(0,0);
////    TFT.printf("Different Fonts :");
////
////    TFT.set_font((unsigned char*) Neu42x35);
////    TFT.locate(0,30);
////    TFT.printf("Hello Mbed 1");
////    TFT.set_font((unsigned char*) Arial24x23);
////    TFT.locate(20,80);
////    TFT.printf("Hello Mbed 2");
////    TFT.set_font((unsigned char*) Arial12x12);
////    TFT.locate(35,120);
////    TFT.printf("Hello Mbed 3");
////    wait(5);
////
////    // mbed logo
////    TFT.background(Black);
////    TFT.cls();
//
//
//
////游戏部分
//    int score=0;
//    int best=0;
//
//    int q=150;
//    int n;
//    int d;
//    d=q-150;
//    for(n=2;n>0;n--){
//        while(q<300){
//            TFT.Bitmap(0,275,240,45,background);
//            for(int zhuzi=0;zhuzi<8;zhuzi++){
//                TFT.Bitmap(240-d,(zhuzi*40),40,40,background);
//            }
////            TFT.Bitmap(240-d,100,45,45,UP);
////            TFT.Bitmap(240-d,145,45,45,MIDDLE);
////            TFT.Bitmap(240-d,190,45,45,DOWN);
//            TFT.Bitmap(90,q,30,20,bird1);
//            wait(0.07);
//            TFT.cls();
//            q+=10;
//            d+=10;
//        }
//        q-=50;
//    }
//    TFT.Bitmap(0,275,240,45,background);
//    wait(0.5);
//    
//    
//    
//    TFT.Bitmap(30,50,180,31,OVER);
//    TFT.Bitmap(72,100,100,31,SCORE);
//    TFT.Bitmap(75,180,90,31,BEST);
//    TFT.set_font((unsigned char*) Arial28x28);
//    TFT.locate(100,140);
//    TFT.printf("%d",score);
//    TFT.set_font((unsigned char*) Arial28x28);
//    TFT.locate(100,220);
//    TFT.printf("%d",best);
//    
//    wait(10);
//    TFT.cls();                // clear the screen
//    TFT.background(Black);    // set background to black
//    TFT.foreground(Black);    // set chars to white
//    
//    //TFT.cls();
////    TFT.set_font((unsigned char*) Arial12x12);
////    TFT.locate(10,10);
////    TFT.printf("Graphic from File System");
////    TFT.locate(10,20);
////    TFT.printf("open test.bmp");
////    int err = TFT.BMP_16(20,50,"test.bmp");
////    if (err != 1) TFT.printf(" - Err: %d",err);
//}
