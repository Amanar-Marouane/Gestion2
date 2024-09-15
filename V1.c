#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 30
#define MAX_EMAIL_LENGTH 256
#define MAX_CONTACTS 100
#define MAX_SEARCHING_LENGTH 256
#define PHONE_NUMBER_LENGTH 10

struct contact{
        char Name[MAX_NAME_LENGTH] ;
        char Phone_Number[MAX_PHONE_NUMBER_LENGTH];
        char Email[MAX_EMAIL_LENGTH];
};
struct contact contacts[MAX_CONTACTS];

int contacts_num = 0;
int search_index = -1;
int delete_index = -1;

int name_validator(int contacts_num);
int num_validator(int contacts_num);
int email_validator(int contacts_num);
void modify();
void search();
void delete();
void add();
int main(){
    char choice[10];

    printf("\n\nWelcome to Contact panel !!\n");
    printf("----------------------------------------------------\n");
    do
    {
        printf("Press 0 to quit.\n");
        printf("Press 1 to add a contact.\n");
        printf("Press 2 to search a contact.\n");
        printf("Press 3 to modify a contact.\n");
        printf("Press 4 to remove a contact.\n");
        printf("Press 5 to display all the contacts.\n");
        printf("==> ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';
        printf("----------------------------------------------------\n");

        switch (choice[0])
        {
        case '0':
            break;
        case '1':
            add();
            break;
        case '2':
            search();
            break;
        case '3':
            modify();
            break;
        case '4':
            delete();
            break;
        
        default:
            printf("Press a valid number.\n");
            printf("----------------------------------------------------\n");
            break;
        }
    } while (choice[0] != '0');
    printf("See you next time !!\n");
    printf("----------------------------------------------------\n");
    return 0;
}
void add(){
    if (contacts_num == MAX_CONTACTS)
    {
        printf("Contacts reached max number !!");
        printf("----------------------------------------------------\n");
        return ;
    }

    do
    {
        printf("Enter a valid name (a-z A-Z) : ");
        fgets(contacts[contacts_num].Name, MAX_NAME_LENGTH, stdin);
        contacts[contacts_num].Name[strcspn(contacts[contacts_num].Name, "\n")] = '\0';
    } while (name_validator(contacts_num) == 1);

    do
    {
        printf("Enter a valid phone number (0-9) : ");
        fgets(contacts[contacts_num].Phone_Number, MAX_NAME_LENGTH, stdin);
        contacts[contacts_num].Phone_Number[strcspn(contacts[contacts_num].Phone_Number, "\n")] = '\0';
    } while (num_validator(contacts_num) == 0);
    
    do
    {
        printf("Enter the email : ");
        fgets(contacts[contacts_num].Email, MAX_NAME_LENGTH, stdin);
        contacts[contacts_num].Email[strcspn(contacts[contacts_num].Email, "\n")] = '\0';
    } while (email_validator(contacts_num) == 1);
    

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

    char choice[10];
    printf("Press 1 to search by the name.\n");
    printf("Press 2 to search by the number.\n");
    printf("Press 3 to search by the email.\n");
    printf("==> ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';
    printf("----------------------------------------------------\n");

    char Search[MAX_SEARCHING_LENGTH];
    int found = 0;

    do
    {
        switch (choice[0])
        {
        case '1':
            printf("Enter the name u want to find : ");
            fgets(Search, MAX_NAME_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Name, Search) == 0)
                {
                    printf("Contact found!\nName: %s.\nPhone: %s.\nEmail: %s\n\n",contacts[i].Name, contacts[i].Phone_Number, contacts[i].Email);
                    printf("----------------------------------------------------\n");
                    found = 1;
                }
            }
            if (found != 1)
            {
                printf("No contact found :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case '2':
            printf("Enter the phone number u want to find : ");
            fgets(Search, MAX_PHONE_NUMBER_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Phone_Number, Search) == 0)
                {
                    printf("Contact found!\nName: %s.\nPhone: %s.\nEmail: %s\n\n",contacts[i].Name, contacts[i].Phone_Number, contacts[i].Email);
                    printf("----------------------------------------------------\n");
                    found = 1;
                }
            }
            if (found != 1)
            {
                printf("No contact found :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case '3':
            printf("Enter the email u want to find : ");
            fgets(Search, MAX_EMAIL_LENGTH, stdin);
            printf("----------------------------------------------------\n");
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Email, Search) == 0)
                {
                    printf("Contact found!\nName: %s.\nPhone: %s.\nEmail: %s\n\n",contacts[i].Name, contacts[i].Phone_Number, contacts[i].Email);
                    printf("----------------------------------------------------\n");
                    found = 1;
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
    } while (!(choice[0] == '1' || choice[0] == '2' || choice[0] == '3'));
     search_index = -1;
}
void modify(){
    if (contacts_num == 0)
    {
        printf("There's no contact to search for modification.\n");
        printf("----------------------------------------------------\n");
        return ;
    }

    char choice[10];
    printf("Press 1 to search by the name to set new modification .\n");
    printf("Press 2 to search by the number to set new modification .\n");
    printf("Press 3 to search by the email to set new modification .\n");
    printf("==> ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';
    printf("----------------------------------------------------\n");

    char Search[MAX_SEARCHING_LENGTH];
    int found = 0;

    switch (choice[0])
    {
    case '1':
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
    case '2':
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
    case '3':
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

    if (search_index == -1)
    {
        return;
    }

    char Y_N[10];
    do
    {
        printf("Press y/n to modify the name ==> ");
        fgets(Y_N, sizeof(Y_N), stdin);
        Y_N[strcspn(Y_N, "\n")] = '\0';
    } while (!(Y_N[0] == 'y' || Y_N[0] == 'n'));
    if (Y_N[0] == 'y')
    {
        memset(contacts[search_index].Name, 0, sizeof(contacts[search_index].Name));
        do
        {
            printf("Set ur new name : ");
            fgets(contacts[search_index].Name, MAX_NAME_LENGTH, stdin);
            contacts[search_index].Name[strcspn(contacts[search_index].Name, "\n")] = '\0';
            printf("----------------------------------------------------\n");
        } while (name_validator(search_index) == 1);
        
    }else{
        printf("----------------------------------------------------\n");
    }

    do
    {
        printf("Press y/n to modify the number ==> ");
        fgets(Y_N, sizeof(Y_N), stdin);
        Y_N[strcspn(Y_N, "\n")] = '\0';
    } while (!(Y_N[0] == 'y' || Y_N[0] == 'n'));
    if (Y_N[0] == 'y')
    {
        memset(contacts[search_index].Phone_Number, 0, sizeof(contacts[search_index].Phone_Number));
        do
        {
            printf("Set ur new phone number : ");
            fgets(contacts[search_index].Phone_Number, MAX_PHONE_NUMBER_LENGTH, stdin);
            contacts[search_index].Phone_Number[strcspn(contacts[search_index].Phone_Number,"\n")] = '\0';
            printf("----------------------------------------------------\n");
        } while (num_validator(search_index) == 0);
        
    }else{
        printf("----------------------------------------------------\n");
    }
    
    do
    {
        printf("Press y/n to modify the email ==> ");
        fgets(Y_N, sizeof(Y_N), stdin);
        Y_N[strcspn(Y_N, "\n")] = '\0';
    } while (!(Y_N[0] == 'y' || Y_N[0] == 'n'));
    if (Y_N[0] == 'y')
    {
        memset(contacts[search_index].Email, 0, sizeof(contacts[search_index].Email));
        do
        {
            printf("Set ur new email : ");
            fgets(contacts[search_index].Email, MAX_PHONE_NUMBER_LENGTH, stdin);
            contacts[search_index].Email[strcspn(contacts[search_index].Email,"\n")] = '\0';
            printf("----------------------------------------------------\n");
        } while (email_validator(search_index) == 1);
        
    }else{
        printf("----------------------------------------------------\n");
    }

    printf("The modification done seccussfuly!!\n");
    printf("----------------------------------------------------\n");
    search_index = -1;
}
int name_validator(int contacts_num){
    contacts[contacts_num].Name[strcspn(contacts[contacts_num].Name," ")] = '\0';
    for (int i = 0;contacts[contacts_num].Name[i] != '\0' ; i++)
    {
        if (!isalpha(contacts[contacts_num].Name[i]))
        {
            printf("==>Contact name is not valid .\n(Must contain only alphabets!!)\n");
            printf("----------------------------------------------------------------\n");
            return 1;
        }
    }
    if (strlen(contacts[contacts_num].Name) == 0)
    {
        printf("==>Contact name is not valid .\n(Empty!!)\n");
        printf("----------------------------------------------------------------\n");
        return 1;
    }
    
    printf("==>Contact name is accepted !!\n");
    printf("----------------------------------------------------------------\n");
    return 0;
}
int num_validator(int contacts_num){
    for (int i = 0;contacts[contacts_num].Phone_Number[i] != '\0' ; i++)
    {
        if (!isdigit(contacts[contacts_num].Phone_Number[i]))
        {
            printf("==>Phone number is not valid.\n(Must contain only digits!!)\n");
            printf("----------------------------------------------------------------\n");
            return 0;
        }
    }
    if (strlen(contacts[contacts_num].Phone_Number) != PHONE_NUMBER_LENGTH)
    {
        printf("==>Phone number is not valid.\n(Must contain 10 digits!!)\n");
        printf("----------------------------------------------------------------\n");
        return 0;
    }
    
    printf("==>Phone number is accepted !!\n");
    printf("----------------------------------------------------------------\n");
    return 1;
}
int email_validator(int contacts_num){
    char *at = strchr(contacts[contacts_num].Email, '@');
    char *dot = strrchr(contacts[contacts_num].Email, '.');

    if (at == NULL || dot == NULL || dot < at)
    {
        printf("==>Email is not valid.\n(Must be in the format username@example.domain)\n");
        printf("----------------------------------------------------------------\n");
        return 1;
    }

    for (char i = 0; i < (at - contacts[contacts_num].Email); i++)
    {
        if (!(isalnum(contacts[contacts_num].Email[i]) || contacts[contacts_num].Email[i] == '.' || contacts[contacts_num].Email[i] == '-' || contacts[contacts_num].Email[i] == '_'))
        {
            printf("==>The username part accept only ('A-Z', 'a-z', '0-9', '.', '-', '_').\n");
            printf("-----------------------------------------------------------------------\n");
            return 1;
        }
    }
    for (char i = (at - contacts[contacts_num].Email) + 1; i < (dot - contacts[contacts_num].Email); i++)
    {
        if (!isalpha(contacts[contacts_num].Email[i]))
        {
            printf("==>Special symbol and numbers not valid atfer '@'.\n");
            printf("-----------------------------------------------------------------------\n");
            return 1;
        }
    }
    for (char i = (dot - contacts[contacts_num].Email) + 1; contacts[contacts_num].Email[i] != '\0'; i++)
    {
        if (!isalpha(contacts[contacts_num].Email[i]))
        {
            printf("==>Special symbol and numbers not valid after the domaine part.\n");
            printf("-----------------------------------------------------------------------\n");
            return 1;
        }
    }
    printf("==>The email accepted !!\n");
    printf("-----------------------------------------------------------------------\n");
    return 0;
}
void delete(){
    if (contacts_num == 0)
    {
        printf("There's no contact to delete.\n");
        printf("----------------------------------------------------\n");
        return ;
    }

    char choice[10];
    printf("Press 1 to input the name of the contact u want to delete .\n");
    printf("Press 2 to input the number of the contact u want to delete .\n");
    printf("Press 3 to input the email of the contact u want to delete .\n");
    printf("==> ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';
    printf("----------------------------------------------------\n");

    char Search[MAX_SEARCHING_LENGTH];
    int found = 0;

    do
    {
        switch (choice[0])
        {
        case '1':
            printf("Enter the name u want to modify his contact : ");
            fgets(Search, MAX_NAME_LENGTH, stdin);
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Name, Search) == 0)
                {
                    found = 1;
                    delete_index = i;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found to delete :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case '2':
            printf("Enter the phone number u want to modify his contact : ");
            fgets(Search, MAX_PHONE_NUMBER_LENGTH, stdin);
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Phone_Number, Search) == 0)
                {
                    found = 1;
                    delete_index = i;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found to delete :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        case '3':
            printf("Enter the email u want to modify his contact : ");
            fgets(Search, MAX_EMAIL_LENGTH, stdin);
            Search[strcspn(Search,"\n")] = '\0';
            for (int i = 0; i < contacts_num; i++)
            {
                if (strcmp(contacts[i].Email, Search) == 0)
                {
                    found = 1;
                    delete_index = i;
                    break;
                }
            }
            if (found != 1)
            {
                printf("No contact found to delete :(\n");
                printf("----------------------------------------------------\n");
            }
            break;
        default:
            printf("Press a valid number.\n");
            printf("----------------------------------------------------\n");
            break;
        }
    } while (!(choice[0] == '1' || choice[0] == '2' || choice[0] == '3'));

    if (delete_index == -1)
    {
        return;
    }

    for (int i = delete_index; i < contacts_num - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    contacts_num--;
    delete_index = -1;
    printf("Contact has been delete successfuly!!\n");
    printf("----------------------------------------------------\n");
}