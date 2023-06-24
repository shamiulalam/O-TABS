#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include"splash.h"
#include"delay.h"
#include"invisible.h"
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#define MAX_WORKSPACES 100
#define MAX_MEMBERS 100

void animateLoading(int percentage) {
    if (percentage > 100) {
        return; // Stop recursion when base case 100
    }

    // Call the main function with the current percentage
    printf("\r\t\t\t\t\t\tp   r   o   g   r   a    m     i s     l   o   a   d   i   n   g   [%d%%]", percentage);
    fflush(stdout); // Flush the output to ensure immediate printing

    Sleep(8); // Pause for seconds (adjust as needed)

    // Recursive call with the next percentage
    animateLoading(percentage + 1);
}

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

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tFirst Name       : \t");
    takeinput(user.fname);

    printf("\n\t\t\t\t\t\t\t\tLast Name        : \t");
    takeinput(user.lname);

    printf("\n\t\t\t\t\t\t\t\tEmail            : \t");
    takeinput(user.email);

    printf("\n\t\t\t\t\t\t\t\tUser Name        : \t");
    takeinput(user.username);

    printf("\n\t\t\t\t\t\t\t\tPassword         : \t");
    takepassword(user.password);

    printf("\n\n\t\t\t\t\t\t\t\tConfirm Password : \t");
    takepassword(password2);

    if (strcmp(user.password, password2) == 0) {
        system("cls");
        FILE *fp = fopen("txt1.txt", "a+");
        if (fp != NULL) {
            fprintf(fp, "%s %s %s %s %s\n", user.fname, user.lname, user.email, user.username, user.password);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYou have successfully signed up in O'Tabs! Your username is %s.\n", user.username);
            fclose(fp);
            char key;
            while(1){
                printf("\n\n\t\t\t\t  Press 's' to sign in to your account. Press 'm' to go back to menu option. Press any other key to exit from O'Tabs.\n");
                key = getch();
                invisible(1);
                key;
                if(key == 's'){
                    login();
                    break;
                }
                else if(key == 'm'){
                    menuLogin();
                    break;
                }
                else{
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tThank you for being with O'Tabs :)\n");
                    delay(1);
                    system("cls");
                    exit(0);
                }
            }

            fclose(fp);
        } else {
            printf("\n\n\n\t\t\t\t\t\t\t\tFailed to open the file\n");
        }
    }
    else {
        printf("\n\n\n\t\t\t\t\t\t\t\tPasswords do not match. Please Try Again.\n");
        Beep(1000, 1500);
        system("cls");
        sign_up();
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tUser Name : \t");
        takeinput(username);
        printf("\n\n\t\t\t\t\t\t\t\tPassword  : \t");
        takepassword(password);
        fseek(fp,0,SEEK_SET);
        for (int i = 0; i < count; i++) {
            if (strcmp(username, logInfo[i].username) == 0 && strcmp(password, logInfo[i].password) == 0) {
                printf("\n\n\n\t\t\t\t\t\t\t\tLogin successful!!!\n");
                printf("\n\n\n\n\t\t\t\t\t\t\t\tWelcome to O'Tabs %s %s.\n", logInfo[i].fname, logInfo[i].lname);

                s = 0;
                break;
            }
       }

        if (s != 0) {
            printf("\n\n\n\n\t\t\t\t\t\t\t\tInvalid username or password! Please login again.");
            Beep(1000, 1500);
            login();
            break;
        }

        fclose(fp);
    } while(s!=0);
}


void menuLogin()
{

    int opt;

    printf("\n\t\t\t\t\t\t\t\tWelcome to the authentication system of O'Tabs");
    printf("\n\t\t\t\t\t\t\t\t\tPlease choose your operation\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t1. Sign up\n");
    printf("\t\t\t\t\t\t\t\t\t\t2. Login\n");
    printf("\t\t\t\t\t\t\t\t\t\t3. Exit\n");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  Please enter your choice of action :    ");
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
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t     Thank you for being with O'Tabs :)\n");
            delay(2);
            system("cls");
            exit(0);

        default:
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tInvalid choice of action!!!\n");
            delay(1);
            system("cls");
            menuLogin();
    }
}

void menu()
{
    system("cls");
    int choice;
        printf("\n\t\t\t\t\t\t\t! Welcome to the Virtual Workspace Management System O'Tabs !");
        printf("\n\n\t\t\t\t\t\t\t\tPlease select one of the following options:\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t       1. Create a New Workspace\n");
        printf("\t\t\t\t\t\t\t\t       2. Join an Existing Workspace\n");
        printf("\t\t\t\t\t\t\t\t       3. Manage Workspaces\n");
        printf("\t\t\t\t\t\t\t\t       4. Manage Members\n");
        printf("\t\t\t\t\t\t\t\t       5. View Workspace Statistics\n");
        printf("\t\t\t\t\t\t\t\t       6. Exit\n");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   Please enter your choice of action: \t");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createWorkspace();
                break;
            case 2:
                joinWorkspace();
                break;
            case 3:
                manageWorkspaces();
                break;
            case 4:
                manageMembers();
                break;
            case 5:
                viewStatistics();
                break;
            case 6:
                printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tThank you for using the Virtual Workspace O'Tabs!!\n");
                delay(2);
                system("cls");
                exit(0);
            default:
                printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t     Invalid choice. Please try again.\n");
                delay(1);
                system("cls");
                menu();
        }
}

struct Workspace {
    char name[100];
    char description[100];
    char privacy[10];
};


void createWorkspace()
{
    system("cls");
    struct Workspace workspace;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tCreating a new workspace...\n");

    printf("\n\n\t\t\t\t\t\t\t\tPlease enter the details for the new workspace: \t\n");

    printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace Name: \t"); //must be one word. can add symbols to prolong the word.
    scanf("%s", workspace.name);

    printf("\n\n\t\t\t\t\t\t\t\tWorkspace Description: \t"); //description has to be only one word. you can add '_' or other symbol to prolong the word
    scanf("%s", workspace.description);

    printf("\n\n\t\t\t\t\t\t\t\tWorkspace Privacy (Public/Private-P/R): \t"); //only public(enter 'P') is available at the moment
    scanf("%s", workspace.privacy);

    system("cls");

    // Open the file in append mode to store the workspace information
       FILE *file = fopen("workspaces.txt", "a+");
       if (file != NULL) {
         fprintf(file, "%s %s %s\n", workspace.name, workspace.description, workspace.privacy);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYou have successfully created a workspace in O'Tabs!!\n");
            fclose(file);
            char key1;
            while(1){
                printf("\n\n\t\t\tPress 'w' to access into your workspace right now. Press 'm' to go back to menu selection screen. Press any other key to exit from O'Tabs.\n");
                key1 = getch();
                invisible(1);
                key1;
                if(key1 == 'w'){
                    joinWorkspace();
                    break;
                }
                else if(key1 == 'm'){
                    system("cls");
                    menu();
                    break;
                }
                else{
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Thank you for being with O'Tabs :)\n");
                    delay(2);
                    system("cls");
                    break;
                }
            }
            fclose(file);
    }
      else {
            printf("\nFailed to open the file\n");
      }
}


void joinWorkspace()
{
    system("cls");
    struct Workspace fileInfo[100];
    int count = 0;
    char workspaceName[100];

    FILE *file = fopen("workspaces.txt", "r");
    while(fscanf(file, "%s %s %s", fileInfo[count].name, fileInfo[count].description, fileInfo[count].privacy)==3){
        count++;
    }

    int s = -1;

    do{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tJoining an existing workspace...\n");
    printf("\n\t\t\t\t\t\t\t\tPlease enter the workspace name you want to join: \t");
    scanf("%s", workspaceName);
    fseek(file,0,SEEK_SET);
    for(int i=0; i<count; i++) {
        if(strcmp(workspaceName, fileInfo[i].name) == 0){
            printf("\n\n\n\t\t\t\t\t\t\t\tSuccessfully joined the workspace: %s\n", workspaceName);

            s = 0;
            delay(2);
            system("cls");
            break;
        }
    }

    if (s != 0) {
            printf("\n\n\n\t\t\t\t\t\t\t\tInvalid workspace name. Please join again!\n");
            Beep(1000, 1000);
            system("cls");
            joinWorkspace();
            break;
        }
    fclose(file);
    } while(s != 0);
}

void manageWorkspaces() {
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t    ...Managing workspaces...\n");

    int choice;
    printf("\n\n\t\t\t\t\t\t\t\tPlease choose one of the following options:\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t1. View Workspaces\n");
    printf("\t\t\t\t\t\t\t\t2. Rename Workspace\n");
    printf("\t\t\t\t\t\t\t\t3. Change Workspace Description\n");
    printf("\t\t\t\t\t\t\t\t4. Delete Workspace\n");
    printf("\t\t\t\t\t\t\t\t5. Go Back to Menu\n");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPlease enter your choice of action :   ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            viewWorkspaces();
            break;
        case 2:
            renameWorkspace();
            break;
        case 3:
            changeWorkspaceDescription();
            break;
        case 4:
            deleteWorkspace();
            break;
        case 5:
            menu();
            break;

        default:
            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid choice.\n");
            break;
    }
    char key2;
    while(1){
                printf("\n\n\n\n\tPress 'm' to go back to menu selection screen.\nPress any other key to exit from O'Tabs.\n");
                key2 = getch();
                invisible(1);
                key2;
                if(key2 == 'm'){
                    system("cls");
                    menu();
                    break;
                }
                else{
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Thank you for being with O'Tabs :)\n");
                    delay(1);
                    system("cls");
                    break;
                }
    }

}

void viewWorkspaces() {
    system("cls");
    printf("\n\tViewing workspaces...\n");
    delay(2);

    struct Workspace workspace;
    FILE* file = fopen("workspaces.txt", "r");
    if (file != NULL) {
        printf("\n\tWorkspace List:\n");
        while (fscanf(file, "%s %s %s", workspace.name, workspace.description, workspace.privacy) == 3) {
            printf("\tName: %s\n", workspace.name);
            printf("\tDescription: %s\n", workspace.description);
            printf("\tPrivacy: %s\n", workspace.privacy);
            printf("\t------------------------\n");
        }
        fclose(file);
    } else {
        printf("Failed to open the file.\n");
    }
    delay(1);
}

void renameWorkspace() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tRenaming a workspace...\n");

    char workspaceName[100];
    char newWorkspaceName[100];

    printf("\n\n\t\t\t\t\t\t\t\tEnter the name of the workspace to rename: \t");
    scanf("%s", workspaceName);
    printf("\n\n\t\t\t\t\t\t\t\tEnter the new name for the workspace: \t");
    scanf("%s", newWorkspaceName);

    struct Workspace workspace;
    FILE* file = fopen("workspaces.txt", "r+");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s", workspace.name, workspace.description, workspace.privacy) == 3) {
            if (strcmp(workspace.name, workspaceName) == 0) {
                fseek(file, -(strlen(workspace.name) + strlen(workspace.description) + strlen(workspace.privacy)+2), SEEK_CUR);
                fprintf(file, "%s %s %s\n", newWorkspaceName, workspace.description, workspace.privacy);
                printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace renamed successfully.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace not found.\n");
    } else {
        printf("Failed to open the file.\n");
    }
}

void changeWorkspaceDescription() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tChanging workspace description...\n");

    char workspaceName[100];
    char newDescription[100];

    printf("\n\n\t\t\t\t\t\t\t\tEnter the name of the workspace to change the description: \t");
    scanf("%s", workspaceName);
    printf("\n\n\t\t\t\t\t\t\t\tEnter the new description for the workspace: \t");
    scanf("%s", newDescription);

    struct Workspace workspace;
    FILE* file = fopen("workspaces.txt", "r+");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s", workspace.name, workspace.description, workspace.privacy) == 3) {
            if (strcmp(workspace.name, workspaceName) == 0) {
                fseek(file, -(strlen(workspace.name) + strlen(workspace.description) + strlen(workspace.privacy)+2), SEEK_CUR);
                fprintf(file, "%s %s %s\n", workspace.name, newDescription, workspace.privacy);
                printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace description changed successfully.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace not found.\n");
    } else {
        printf("Failed to open the file.\n");
    }
}

void deleteWorkspace() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tDeleting a workspace...\n");

    char workspaceName[100];
    printf("\n\n\t\t\t\t\t\t\t\tEnter the name of the workspace to delete: \t");
    scanf("%s", workspaceName);

    struct Workspace workspace;
    FILE* file = fopen("workspaces.txt", "r+");
    if (file != NULL) {
        FILE* tempFile = fopen("temp.txt", "w+");
        if (tempFile != NULL) {
            int deleted = 0;
            while (fscanf(file, "%s %s %s", workspace.name, workspace.description, workspace.privacy) == 3) {
                if (strcmp(workspace.name, workspaceName) == 0) {
                    deleted = 1;
                } else {
                    fprintf(tempFile, "%s %s %s\n", workspace.name, workspace.description, workspace.privacy);
                }
            }
            if (deleted) {
                printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace deleted successfully.\n");
            } else {
                printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace not found.\n");
            }

            fclose(file);
            fclose(tempFile);
            remove("workspaces.txt");
            rename("temp.txt", "workspaces.txt");
        } else {
            printf("\n\n\n\n\t\t\t\t\t\t\t\tFailed to create temporary file.\n");
        }
    } else {
        printf("Failed to open the file.\n");
    }
}

void manageMembers() {
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t...Managing Members...\n\n");
    printf("\n\t\t\t\t\t\t\t\t1. Add a Member to a Workspace\n");
    printf("\t\t\t\t\t\t\t\t2. Remove a Member from a Workspace\n");
    printf("\t\t\t\t\t\t\t\t3. Go Back to Menu\n");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tPlease enter your choice of action :    ");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            addMember();
            break;
        case 2:
            removeMember();
            break;
        case 3:
            menu();
            break;
        default:
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid option. Please try again.\n");
            break;
    }
}

void addMember() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tAdding a member to a workspace...\n");

    char workspaceName[50];
    char memberName[50];
    struct user user;

    printf("\n\n\t\t\t\t\t\t\t\tEnter the name of the workspace: \t");
    scanf("%s", workspaceName);

    printf("\n\t\t\t\t\t\t\t\tEnter the member's name: \t");
    scanf("%s", memberName);

    // Read user details from file
    FILE* fp = fopen("txt1.txt", "r");
    if (fp != NULL) {
        int memberFound = 0;
        while (fscanf(fp, "%s %s %s %s %s", user.fname, user.lname, user.email, user.username, user.password) == 5) {
            if (strcmp(user.username, memberName) == 0) {
                memberFound = 1;
                break;
            }
        }
        fclose(fp);

        if (memberFound) {
            // Check if the workspace exists and perform the necessary logic to add the member
            FILE* file = fopen("workspaces.txt", "r+");
            FILE* file2 = fopen("workInfo.txt", "a+");
            if (file != NULL) {
                struct Workspace workspace;
                int workspaceFound = 0;
                long int workspaceStartPos = -1;

                while (fscanf(file, "%s %s %s", workspace.name, workspace.description, workspace.privacy) == 3) {
                    if (strcmp(workspace.name, workspaceName) == 0) {
                        workspaceFound = 1;
                        workspaceStartPos = ftell(file);
                        break;
                    }
                }

                if (workspaceFound) {
                    // Move the file pointer to the end of the workspace's member list
                    fseek(file2, 0, SEEK_END);

                    // Write the new member to the workspace file
                    fprintf(file2, "%s %s\n", workspace.name, memberName);

                    printf("\n\n\n\n\t\t\t\t\t\t\t\tMember added successfully to the workspace: %s\n", workspaceName);
                    delay(2);
                    system("cls");
                } else {
                    printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace not found.\n");
                    delay(2);
                    system("cls");
                }

                fclose(file);
                fclose(file2);
            } else {
                printf("Failed to open the file.\n");
            }
        } else {
            printf("\n\n\n\n\t\t\t\t\t\t\t\tMember not found.\n");
        }
    } else {
        printf("Failed to open the file.\n");
    }
}

void removeMember() {
    system("cls");
    char workspaceName[50];
    char memberName[50];

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tRemoving a member from a workspace...");

    printf("\n\n\n\n\t\t\t\t\t\t\t\tEnter the workspace name: \t");
    scanf("%s", workspaceName);

    printf("\n\n\t\t\t\t\t\t\t\tEnter the member username: \t");
    scanf("%s", memberName);

    FILE* inputFile = fopen("workInfo.txt", "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (inputFile == NULL || tempFile == NULL) {
        printf("Failed to open files.\n");
        return;
    }

    char line[100];
    int memberRemoved = 0;

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char tempWorkspaceName[50];
        char tempMemberName[50];

        if (sscanf(line, "%s %s", tempWorkspaceName, tempMemberName) == 2) {
            if (strcmp(tempWorkspaceName, workspaceName) == 0 && strcmp(tempMemberName, memberName) == 0) {
                memberRemoved = 1;
                continue; // Skip writing the line for the member to be removed
            }
        }

        fprintf(tempFile, "%s", line);
    }

    fclose(inputFile);
    fclose(tempFile);

    if (memberRemoved) {
        remove("workInfo.txt");
        rename("temp.txt", "workInfo.txt");
        printf("\n\n\n\n\t\t\t\t\t\t\t\tMember removed successfully from the workspace.\n");
        delay(2);
        system("cls");
    } else {
        remove("temp.txt");
        printf("\n\n\n\n\t\t\t\t\t\t\t\tWorkspace or member not found.\n");
        delay(1);
        printf("\n\n\n\t\t\t\t\t\t\t\tGoing back to the menu screen...");
        delay(2);
        system("cls");
        menu();
    }
}

void viewOTABSusers() {
    system("cls");
    printf("\n    ...Viewing O'TABS Users...\n\n");
    delay(2);
    FILE *file;
    char firstName[100], lastName[100], email[100], username[100], password[100];

    // Open txt1.txt file in read mode
    file = fopen("txt1.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        return;
    }

    // Read and print username and email from txt1.txt file
    while (fscanf(file, "%s %s %s %s %s", firstName, lastName, email, username, password) != EOF) {
        printf("Username: \t%s\n\tEmail: \t%s\n\n", username, email);
    }

    // Close the file
    fclose(file);
}

struct workspaceS {
    char name[100];
    char members[MAX_MEMBERS][100];
    int memberCount;
};

void viewWorkspaceMembers() {
    system("cls");
    printf("\n\t   ...Viewing Workspace Member...\n\n");
    delay(2);
    FILE *file;
    struct workspaceS workspaces[MAX_WORKSPACES];
    char workspaceName[100], memberName[100];
    int i, j, workspaceCount = 0;

    // Open workInfo.txt file in read mode
    file = fopen("workInfo.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        return;
    }

    // Read workspace and member names from workInfo.txt file
    while (fscanf(file, "%s %s", workspaceName, memberName) != EOF) {
        int workspaceIndex = -1;
        // Check if the workspace already exists in the array
        for (i = 0; i < workspaceCount; i++) {
            if (strcmp(workspaces[i].name, workspaceName) == 0) {
                workspaceIndex = i;
                break;
            }
        }

        // If workspace doesn't exist, add it to the array
        if (workspaceIndex == -1) {
            workspaceIndex = workspaceCount;
            strcpy(workspaces[workspaceIndex].name, workspaceName);
            workspaces[workspaceIndex].memberCount = 0;
            workspaceCount++;
        }

        // Add member to the workspace
        strcpy(workspaces[workspaceIndex].members[workspaces[workspaceIndex].memberCount], memberName);
        workspaces[workspaceIndex].memberCount++;
    }

    // Close the file
    fclose(file);

    // Print the workspace and member details
    for (i = 0; i < workspaceCount; i++) {
        printf("\n\tWorkspace: %s\n\tMembers: ", workspaces[i].name);
        for (j = 0; j < workspaces[i].memberCount; j++) {
            printf(" %s", workspaces[i].members[j]);
        }
        printf("\n");
    }
    delay(1);
}
void viewStatistics() {
    system("cls");
    int option;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPlease choose one of the following options.\n");
    printf("\n\n\t\t\t\t\t\t\t\t1. View all workspace users\n");
    printf("\t\t\t\t\t\t\t\t2. View all workspace members\n");
    printf("\t\t\t\t\t\t\t\t3. Go Back to Menu\n");
    printf("\n\n\t\t\t\t\t\t\t\tt$ Your Pick:   ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            viewOTABSusers();
            break;
        case 2:
            viewWorkspaceMembers();
            break;
        case 3:
            system("cls");
            menu();
            break;
        default:
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid option selected.\n");
            Beep(1000, 1000);
            viewStatistics();
    }
}

int main(void)
{
    system("color 0b");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    animateLoading(0);
    printf("\n\n\t\t\t\t\t\t\t    L  o  a  d  i  n  g    c  o  m  p  l  e  t  e\n");
    delay(1);
    system("cls");
    splashScreen();
    delay(3);
    system("cls");
    menuLogin();
    delay(2);
    system("cls");
    menu();
    return 0;
}
