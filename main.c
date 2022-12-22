#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <string.h>

#include "bank.h"

int main()
{
    struct bank bank = create_bank();

    int choice = 0;

    printf("Welcome to the bank!\n");
    while(choice != 3)
    {
        print_bank(bank);
        printf("Choose an option:\n");
        printf("1. Register in the bank\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Register in the bank\n");
            printf("Name: ");
            char name[20];
            scanf("%s", name);
            printf("Surname: ");
            char surname[20];
            scanf("%s", surname);
            printf("Login: ");
            char login[20];
            scanf("%s", login);
            printf("Password: ");
            char password[20];
            scanf("%s", password);
            struct client client = create_client(name, surname, login, password);
            print_client(client);
            add_client(bank, client);
            break;
        case 2:
            printf("Login\n");
            printf("Login: ");
            char login2[20];
            scanf("%s", login2);
            printf("Password: ");
            char password2[20];
            scanf("%s", password2);
            struct client client2 = find_client(bank, login2, password2);
            if(client2.name[0] == '\0')
            {
                printf("Wrong login or password!\n");
                break;
            }
            int choice2 = 0;
            while (choice2 != 6 && client2.name[0] != '\0')
            {
                printf("Welcome %s %s!\n", client2.name, client2.surname);
                printf("Choose an option:\n");
                printf("1. Create account\n");
                printf("2. Deposit\n");
                printf("3. Withdraw\n");
                printf("4. Transfer\n");
                printf("5. Print profile\n");
                printf("6. Exit\n");
                
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    printf("Create account\n");
                    add_account(bank, client2);
                    print_client(bank, client2);
                    break;
                case 2:
                    printf("Deposit\n");
                    printf("IBAN: ");
                    int iban = 0;
                    scanf("%d", &iban);
                    printf("Amount: ");
                    int amount = 0;
                    scanf("%d", &amount);
                    deposit(bank, iban, amount);
                    break;
                case 3:
                    printf("Withdraw\n");
                    int iban2 = 0;
                    scanf("%d", &iban2);
                    printf("Amount: ");
                    int amount2 = 0;
                    scanf("%d", &amount2);
                    withdraw(bank, iban2, amount2);
                    break;
                case 4:
                    printf("Transfer\n");
                    printf("IBAN: ");
                    int iban3 = 0;
                    scanf("%d", &iban3);
                    printf("IBAN2: ");
                    int iban4 = 0;
                    scanf("%d", &iban4);
                    printf("Amount: ");
                    int amount3 = 0;
                    scanf("%d", &amount3);
                    transfer(bank, iban3, iban4, amount3);
                    break;
                case 5: 
                    printf("Print profile\n");
                    print_client(bank, client2);
                    break;
                case 6:
                    printf("Exit\n");
                    break;
                default:
                    break;
                }   
            }
            break;
        case 3:
            printf("Exit\n");
            break;
        default:
            break;
        }
    }

    return EXIT_SUCCESS;
}