void animateLoading(int percentage) {
    if (percentage > 100) {
        return; // Stop recursion when base case 100
    }

    // Call the main function with the current percentage
    printf("\r\t\t\t\tp   r   o   g   r   a   m      i s      l   o  a   d   i   n    g    [%d%%]", percentage);
    fflush(stdout); // Flush the output to ensure immediate printing

    Sleep(5); // Pause for seconds (adjust as needed)

    // Recursive call with the next percentage
    animateLoading(percentage + 1);
}

void splashScreen(void)
{
printf("                 ,---,        ,----,                        \n");
printf("    ,----..   ,`--.' |      ,/   .`|                            \n");
printf("   /   /   \\  |   :  :    ,`   .'  : ,---,           ,---,.   .--.--.    \n");
printf("  /   .     : |   |  '  ;    ;     /'  .' \\        ,'  .'  \\ /  /    '.  \n");
printf(" .   /   ;.  \\'   :  |.'___,/    ,'/  ;    '.    ,---.' .' ||  :  /`. /  \n");
printf(".   ;   /  ` ;;   |.' |    :     |:  :       \\   |   |  |: |;  |  |--`   \n");
printf(";   |  ; \\ ; |'---'   ;    |.';  ;:  |   /\\   \\  :   :  :  /|  :  ;_     \n");
printf("|   :  | ; | '        `----'  |  ||  :  ' ;.   : :   |    ;  \\  \\    `.  \n");
printf(".   |  ' ' ' :            '   :  ;|  |  ;/  \\   \\|   :     \\  `----.   \\ \n");
printf("'   ;  \\; /  |            |   |  ''  :  | \\  \\ ,'|   |   . |  __ \\  \\  | \n");
printf(" \\   \\ ',  /             '   :  ||  |  '  '--'  '   :  '; | /  /`--'  / \n");
printf("  ;   :    /              ;   |.' |  :  :        |   |  | ; '--'.     /  \n");
printf("   \\   \\ .'               '---'   |  | ,'        |   :   /    `--'---'   \n");
printf("    `---`                         `--''          |   | ,'                \n");
printf("         IMAGINATION IS THE LIMIT                `----'                  \n");

printf("\n\n                      NSU CSE115L PROJECT SHOWCASE                     \n\n");
}
