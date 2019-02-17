#include <iostream>
#include "upm/jhd1313m1.hpp"

#define I2C_BUS  0
#define RGB_WHT 0xff,0xff,0xff
#define RGB_RED 0xff,0x00,0x00
#define RGB_GRN 0x00,0xff,0x00
#define RGB_BLU 0x00,0x00,0xff
#define SLEEP_TIME 1

using namespace std;
upm::Jhd1313m1* lcd;

void display(string str1, string str2, int red, int green, int blue)
{
        lcd->clear();
        lcd->setColor(red, green, blue);
        //lcd->setCursor(0,0); /* first row */
        //lcd->write(str1);
        //lcd->setCursor(1,2); /* second row */
        //lcd->write(str2);
        sleep(SLEEP_TIME);
}
int red(char c)
{
        return c * c % 255;
}

int green(char c)
{
        return c * red(c) % 255;
}

int blue(char c)
{
        return c * green(c) % 255;
}
int main(int argc, char* argv[])
{
        string str3 = argv[1];
        lcd = new upm::Jhd1313m1(I2C_BUS, 0x3e, 0x62);
        for(int i = 0; str3[i] != '\0';i++)
        {
                display(str3,str3,red(str3[i]),green(str3[i]),blue(str3[i]));
        }
        delete lcd;
        return 0;
}

