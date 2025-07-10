#include<stdio.h>
#include<string.h>

void main()
{
    FILE *ptr;
    int ch;
    char txt[100];

    printf("*****************************************\n");
    printf("\tTO DO APPLICATION\n");
    printf("1-- CREATE A TO DO LIST\n");
    printf("2-- VIEW THE TO DO LIST\n");
    printf("3-- ADD NEW THING TO THE TO DO LIST\n");
    printf("4-- DELETE THE TO DO LIST\n");
    printf("5-- EXIT\n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            ptr = fopen("text.txt", "w");
            if (ptr == NULL) {
                printf("Error opening file!\n");
                return;
            }
            printf("Enter your to-do items (end with 'done' on a new line): \n");
            while (1) {
                scanf(" %[^\n]s", txt);
                if (strcmp(txt, "done") == 0) break;
                fprintf(ptr, "%s\n", txt);
            }
            fclose(ptr);
            printf("To-do list created successfully!\n");
            break;

        case 2: // View the to-do list
            ptr = fopen("text.txt", "r");
            if (ptr == NULL) {
                printf("Error opening file or file does not exist!\n");
                return;
            }
            printf("Your To-Do List:\n");
            while (fgets(txt, sizeof(txt), ptr) != NULL) {
                printf("%s", txt);
            }
            fclose(ptr);
            break;

        case 3:
            ptr = fopen("text.txt", "a");
            if (ptr == NULL) {
                printf("Error opening file!\n");
                return;
            }
            printf("Enter new to-do items (end with 'done' on a new line): \n");
            while (1) {
                scanf(" %[^\n]s", txt);
                if (strcmp(txt, "done") == 0) break;
                fprintf(ptr, "%s\n", txt);
            }
            fclose(ptr);
            printf("New items added successfully!\n");
            break;

        case 4:
            if (remove("text.txt") == 0) {
                printf("To-do list deleted successfully!\n");
            } else {
                printf("Error deleting the file or file does not exist!\n");
            }
            break;

        case 5:
            printf("Exiting the program. \n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
  printf("*****************************************\n");
}
