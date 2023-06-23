#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user {
    char fname[50];
    char lname[50];
    char email[50];
    char username[50];
    char password[50];
};

void takeinput(char ch[50]) {
    fgets(ch, 50, stdin);
    ch[strcspn(ch, "\n")] = '\0';
}

void takepassword(char pwd[50]) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();

        if (ch == ENTER || ch == TAB) {
            pwd[i] = '\0';
            break;
        } else if (ch == BCKSPC) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

void sign_up() {
    system("cls");
    struct user user;
    char password2[50];

    printf("\nFirst Name       : \t");
    takeinput(user.fname);

    printf("Last Name        : \t");
    takeinput(user.lname);

    printf("Email            : \t");
    takeinput(user.email);

    printf("User Name        : \t");
    takeinput(user.username);

    printf("Password         : \t");
    takepassword(user.password);

    printf("\nConfirm Password : \t");
    takepassword(password2);

    if (strcmp(user.password, password2) == 0) {
        FILE *fp = fopen("txt1.txt", "a+");
        if (fp != NULL) {
            fprintf(fp, "%s %s %s %s %s\n", user.fname, user.lname, user.email, user.username, user.password);
            printf("\n\nYou have successfully signed up in O'Tabs! Your username is %s.\n", user.username);
            fclose(fp);
            char key;
            while(1){
                printf("\n\nPress 's' to sign in to your account.\nPress 'm' to go back to menu option.\nPress any other key to exit from O'Tabs.\n");
                key = getch();
                invisible(1);
                key;
                if(key == 's'){
                    login();
                    break;
                }
                else if(key == 'm'){
                    menuLogin();
                }
                else{
                    system("cls");
                    printf("\n\tThank you for being with O'Tabs :)\n");
                    break;
                }
            }

            fclose(fp);
        } else {
            printf("\nFailed to open the file\n");
        }
    }
    else {
        printf("\nPasswords do not match. Enter the correct password.\n");
        Beep(750, 300);
    }
}

void login() {
    system("cls");
    struct user logInfo[100];
    int count = 0;
    char username[50], password[50];

    FILE *fp = fopen("txt1.txt", "r");

        while (fscanf(fp, "%s %s %s %s %s", logInfo[count].fname, logInfo[count].lname, logInfo[count].email, logInfo[count].username, logInfo[count].password) == 5) {
            count++;
        }

        int s = -1;
        do{
        printf("\n\n\n\tUser Name : \t");
        takeinput(username);
        printf("\n\tPassword  : \t");
        takepassword(password);
        fseek(fp,0,SEEK_SET);
        for (int i = 0; i < count; i++) {
            if (strcmp(username, logInfo[i].username) == 0 && strcmp(password, logInfo[i].password) == 0) {
                printf("\n\n\tLogin successful!!!\n");
                printf("\tWelcome to O'Tabs %s %s.\n", logInfo[i].fname, logInfo[i].lname);

                s = 0;
                break;
            }
       }

        if (s != 0) {
            printf("\n\nInvalid username or password!\n\nPlease login again.\n");
            Beep(800, 300);
            delay(2);
            login();
            break;
        }

        fclose(fp);
    } while(s!=0);
}


void menuLogin()
{

    int opt;

    printf("\n\t\t\t----------Welcome to the authentication system of O'Tabs----------");
    printf("\n\t\t\t\t\tPlease choose your operation\n\n");
    printf("\t\t\t\t\t\t  1. Sign up\n");
    printf("\t\t\t\t\t\t  2. Login\n");
    printf("\t\t\t\t\t\t  3. Exit\n");

    printf("\n\nPlease enter your choice of action : \t");
    scanf("%d", &opt);
    fflush(stdin);

    switch (opt) {
        case 1:
            sign_up();
            break;

        case 2:
            login();
            break;

        case 3:
            printf("\n\t\t\t\t      Thank you for being with O'Tabs :)\n");
            break;

        default:
            printf("\n\t\t\t\t\tInvalid choice of action!!!\n");
            break;
    }
}
