#include <iostream>
#define IMAGESIZE 64000*4800
typedef struct RGB{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}RGB;

struct RGB in[IMAGESIZE];
unsigned char out[IMAGESIZE];

void setupIMG(){
    int i;
    for(i = 0; i < IMAGESIZE; i++){
        in[i].R = rand() % 256;
        in[i].G = rand() % 256;
        in[i].B = rand() % 256;
    }
}


void calc(){
    int i;
    for(i = 0; i < IMAGESIZE; i++){
        double r,g,b;
        unsigned char yy;
        r = in[i].R;
        g = in[i].G;
        b = in[i].B;
        int y = r * 1224 + g * 2404 + b * 467;
        y=y>>12;
        out[i] = y;
    }
}

int main(int argc, char *argv[])
{
    setupIMG();

    calc();

    std::cout <<"finish.";
    return 0;
}
