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