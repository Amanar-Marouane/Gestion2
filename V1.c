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

void modify();
void search_for_modify();
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
        printf("==> ");
        scanf("%i",&choice);
        printf("----------------------------------------------------\n");

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        case 3:
            modify();
            break;
        
        default:
            printf("Press a valid number.\n");
            printf("----------------------------------------------------\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
void add(){
    if (contacts_num == MAX_CONTACTS)
    {
        printf("Contacts reached max number !!");
        printf("----------------------------------------------------\n");
        return ;
    }

    printf("Enter the name : ");
    getchar();
    fgets(contacts[contacts_num].Name, MAX_NAME_LENGTH, stdin);
    printf("----------------------------------------------------\n");
    contacts[contacts_num].Name[strcspn(contacts[contacts_num].Name, "\n")] = '\0';

    printf("Enter the phone number : ");
    scanf("%s",contacts[contacts_num].Phone_Number);
    printf("----------------------------------------------------\n");

    printf("Enter the email : ");
    scanf("%s",contacts[contacts_num].Email);
    printf("----------------------------------------------------\n");

    contacts_num++;
    printf("Contact added successfully!\n");
    printf("----------------------------------------------------\n");
}
void search(){
    if (contacts_num == 0)
    {
        printf("There's no contact to search for.\n");
        printf("----------------------------------------------------\n");
        return ;
    }

    int choice;
    printf("Press 1 to search by the name.\n");
    printf("Press 2 to search by the number.\n");
    printf("Press 3 to search by the email.\n");
    printf("==> ");
    scanf("%i",&choice);
    getchar();
    printf("----------------------------------------------------\n");

    char Search[MAX_SEARCHING_LENGTH];
    int found = 0;

    do
    {
        switch (choice)
        {
        case 1:
            printf("Enter the name u want to find : ");
            fgets(Search, MAX_NAME_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Name, Search) == 0)
                {
                    printf("Contact found!\nName: %s.\nPhone: %s.\nEmail: %s\n",contacts[i].Name, contacts[i].Phone_Number, contacts[i].Email);
                    printf("----------------------------------------------------\n");
                    found = 1;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case 2:
            printf("Enter the phone number u want to find : ");
            fgets(Search, MAX_PHONE_NUMBER_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Phone_Number, Search) == 0)
                {
                    printf("Contact found!\nName: %s.\nPhone: %s.\nEmail: %s\n",contacts[i].Name, contacts[i].Phone_Number, contacts[i].Email);
                    printf("----------------------------------------------------\n");
                    found = 1;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case 3:
            printf("Enter the email u want to find : ");
            fgets(Search, MAX_EMAIL_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Email, Search) == 0)
                {
                    printf("Contact found!\nName: %s.\nPhone: %s.\nEmail: %s\n",contacts[i].Name, contacts[i].Phone_Number, contacts[i].Email);
                    printf("----------------------------------------------------\n");
                    found = 1;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        default:
            printf("Press a valid number.\n");
            printf("----------------------------------------------------\n");
            break;
        }
    } while (!(choice >= 1 && choice <= 3));
     
}
void modify(){
    if (contacts_num == 0)
    {
        printf("There's no contact to search for modification.\n");
        printf("----------------------------------------------------\n");
        return ;
    }

    int choice;
    printf("Press 1 to search by the name to set new modification .\n");
    printf("Press 2 to search by the number to set new modification .\n");
    printf("Press 3 to search by the email to set new modification .\n");
    printf("==> ");
    scanf("%i",&choice);
    getchar();
    printf("----------------------------------------------------\n");

    char Search[MAX_SEARCHING_LENGTH];
    int found = 0;

    do
    {
        switch (choice)
        {
        case 1:
            printf("Enter the name u want to modify his contact : ");
            fgets(Search, MAX_NAME_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Name, Search) == 0)
                {
                    found = 1;
                    search_index = i;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found to modify :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case 2:
            printf("Enter the phone number u want to modify his contact : ");
            fgets(Search, MAX_PHONE_NUMBER_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Phone_Number, Search) == 0)
                {
                    found = 1;
                    search_index = i;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found to modify :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case 3:
            printf("Enter the email u want to modify his contact : ");
            fgets(Search, MAX_EMAIL_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Email, Search) == 0)
                {
                    found = 1;
                    search_index = i;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found to modify :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        default:
            printf("Press a valid number.\n");
            printf("----------------------------------------------------\n");
            break;
        }
    } while (!(choice >= 1 && choice <= 3));

    if (search_index == -1)
    {
        return;
    }

    char Y_N;
    do
    {
        printf("Press y/n to modify the name ==> ");
        scanf(" %c",&Y_N);
        getchar();
        printf("----------------------------------------------------\n");
    } while (!(Y_N == 'y' || Y_N == 'n'));
    if (Y_N == 'y')
    {
        memset(contacts[search_index].Name, 0, sizeof(contacts[search_index].Name));
        printf("Set ur new name : ");
        fgets(contacts[search_index].Name, MAX_NAME_LENGTH, stdin);
        contacts[search_index].Name[strcspn(contacts[search_index].Name, "\n")] = '\0';
        printf("----------------------------------------------------\n");
    }

    do
    {
        printf("Press y/n to modify the number ==> ");
        scanf(" %c",&Y_N);
        printf("----------------------------------------------------\n");
    } while (!(Y_N == 'y' || Y_N == 'n'));
    if (Y_N == 'y')
    {
        memset(contacts[search_index].Phone_Number, 0, sizeof(contacts[search_index].Phone_Number));
        printf("Set ur new phone number : ");
        scanf("%s",contacts[search_index].Phone_Number);
        getchar();
        printf("----------------------------------------------------\n");
    }
    
    do
    {
        printf("Press y/n to modify the email ==> ");
        scanf(" %c",&Y_N);
        printf("----------------------------------------------------\n");
    } while (!(Y_N == 'y' || Y_N == 'n'));
    if (Y_N == 'y')
    {
        memset(contacts[search_index].Email, 0, sizeof(contacts[search_index].Email));
        printf("Set ur new email : ");
        scanf("%s",contacts[search_index].Email);
        getchar();
        printf("----------------------------------------------------\n");
    }

    printf("The modification done seccussfuly!!\n");
    printf("----------------------------------------------------\n");
    search_index = -1;
}