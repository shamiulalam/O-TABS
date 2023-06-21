#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"splash.h"
#include"delay.h"
#include"menuLogin.h"

int main(void)
{
    system("color 0b");
    splashScreen();
    delay(4);
    system("cls");
    menuLogin();
    delay(2);
    return 0;
}