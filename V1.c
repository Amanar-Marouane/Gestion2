#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 30
#define MAX_EMAIL_LENGTH 256
#define MAX_CONTACTS 50
#define MAX_SEARCHING_LENGTH 256

struct contact{
        char Name[MAX_NAME_LENGTH];
        char Phone_Number[MAX_PHONE_NUMBER_LENGTH];
        char Email[MAX_EMAIL_LENGTH];
};
struct contact contacts[MAX_CONTACTS];

int contacts_num = 0;
int search_index = -1;

void search();
void add();
int main(){
    int choice;
    
    do
    {
        printf("Press 0 to quit.\n");
        printf("Press 1 to add a contact.\n");
        printf("Press 2 to search a contact.\n");
        printf("Press 3 to modify a contact.\n");
        printf("Press 4 to remove a contact.\n");
        printf("Press 5 to display all the contacts.\n");
        scanf("%i",&choice);

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        
        default:
            printf("Press a valid number.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
void add(){
    if (contacts_num == MAX_CONTACTS)
    {
        printf("Contacts reached max number !!");
        return ;
    }

    printf("Enter the name : ");
    fgets(contacts[contacts_num].Name, MAX_NAME_LENGTH, stdin);
    contacts[contacts_num].Name[strcspn(contacts[contacts_num].Name, "\n")] = '\0';

    printf("Enter the phone number : ");
    scanf("%s",contacts[contacts_num].Phone_Number);

    printf("Enter the email : ");
    scanf("%s",contacts[contacts_num].Email);

    contacts_num++;
    printf("Contact added successfully!\n");
}
void search(){
    if (contacts_num == 0)
    {
        printf("There's no contact to search for.\n");
        return ;
    }

    int choice;
    printf("Press 1 to search by the name.\n");
    printf("Press 2 to search by the number.\n");
    printf("Press 3 to search by the email.\n");
    scanf("%i",&choice);
    getchar();

    char Search[MAX_SEARCHING_LENGTH];
    int found = 0;
    switch (choice)
    {
    case 1:
        printf("Enter the name u want to find : ");
        fgets(Search, MAX_NAME_LENGTH, stdin);
        Search[strcspn(Search,"\n")] = '\0';
        break;
    default:
        printf("Press a valid number.\n");
        break;
    } 
}