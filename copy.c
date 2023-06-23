#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include"splash.h"
#include"delay.h"
#include"invisible.h"
#include"login.h"

int main(void)
{
    system("color 0b");
    animateLoading(0);
    printf("\n\n\t\t\t\t\t\t L o a d i n g   c o m p l e t e.\n");
    delay(2);
    system("cls");
    splashScreen();
    delay(3);
    system("cls");
    menuLogin();
    delay(2);
    return 0;
}
