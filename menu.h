void menu()
{
int choice;
        printf("Welcome to the Virtual Workspace Management System!\n");
        printf("Please select one of the following options:\n");
        printf("1. Create a New Workspace\n");
        printf("2. Join an Existing Workspace\n");
        printf("3. Manage Workspaces\n");
        printf("4. Manage Members\n");
        printf("5. Manage Resources\n");
        printf("6. View Workspace Statistics\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
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
                manageResources();
                break;
            case 6:
                viewStatistics();
                break;
            case 7:
                printf("Thank you for using the Virtual Workspace O'Tabs!!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
}
