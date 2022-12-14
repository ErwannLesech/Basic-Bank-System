#include <stdio.h> // For printf()
#include <stdlib.h> // For exit()
#include "login.h" // For login system
#include "bank.h" // For bank system

// Main function of a login system in C 
int main()
{
    printf("Welcome to the login system!\n");

    struct bank db;

    initDatabase(&db);

    int choice = 0;
    int amount = 0;
    int account_number = 0;
    int account_number2 = 0;
    struct login user;
    int userIndex = 1;

    while (1)
    {
        printDatabase(&db);
        printf(" 1. Login\n 2. Register\n 3. Reset account\n 4. Exit\n Your choice:");
        if(scanf("%i", &choice) > 0)
        {
            switch(choice)
            {
            case 1:
                printf("Login\n");
                loginUser(&user);
                if (findUser(&db, &user) != -1)
                {
                    while(userIndex)
                    {
                        printUser(&user);
                        printf(" 1. Create account\n 2. Print account\n 3. Manage an account\n 4. Exit\n Your choice:");
                        if(scanf("%i", &choice) > 0)
                        {
                            switch(choice)
                            {
                            case 1:
                                printf("Create account\n");
                                createAccount(&user, &db);
                                break;
                            
                            case 2:
                                printf("Print account\n");
                                printf("Account number:");
                                if(scanf("%i", &account_number) > 0)
                                {
                                    printAccount(account_number, &db);
                                }
                                else
                                {
                                    printf("Invalid choice!\n");
                                }
                                break;
                            
                            case 3:
                                printf("Manage an account\n");
                                printf(" 1. Deposit\n 2. Withdraw\n 3. Transfer\n 4. Exit\n Your choice:");
                                if(scanf("%i", &choice) > 0)
                                {
                                    switch(choice)
                                    {
                                    case 1:
                                        printf("Deposit\n");
                                        printf("Account number:");
                                        if(scanf("%i", &account_number) > 0)
                                        {
                                            printf("Amount:");
                                            if(scanf("%i", &amount) > 0)
                                            {
                                                depositMoney(account_number, amount, &db);
                                            }
                                            else
                                            {
                                                printf("Invalid choice!\n");
                                            }
                                        }
                                        else
                                        {
                                            printf("Invalid choice!\n");
                                        }
                                        break;
                                    
                                    case 2:
                                        printf("Withdraw\n");
                                        printf("Account number:");
                                        if(scanf("%i", &account_number) > 0)
                                        {
                                            printf("Amount:");
                                            if(scanf("%i", &amount) > 0)
                                            {
                                                withdrawMoney(choice, amount, &db);
                                            }
                                            else
                                            {
                                                printf("Invalid choice!\n");
                                            }
                                        }
                                        else
                                        {
                                            printf("Invalid choice!\n");
                                        }
                                        break;
                                    
                                    case 3:
                                        printf("Transfer\n");
                                        printf("Account number:");
                                        if(scanf("%i", &account_number) > 0)
                                        {
                                            printf("Amount:");
                                            if(scanf("%i", &amount) > 0)
                                            {
                                                printf("Account number of destination:");
                                                if(scanf("%i", &account_number2) > 0)
                                                {
                                                    transferMoney(account_number, account_number2, amount, &db);
                                                }
                                                else
                                                {
                                                    printf("Invalid choice!\n");
                                                }
                                            }
                                            else
                                            {
                                                printf("Invalid choice!\n");
                                            }
                                        }
                                        else
                                        {
                                            printf("Invalid choice!\n");
                                        }
                                        break;
                                    
                                    case 4:
                                        printf("Exit\n");
                                        break;
                                    
                                    default:
                                        printf("Invalid choice!\n");
                                        break;
                                    }
                                }
                                else
                                {
                                    printf("Invalid choice!\n");
                                }

                            case 4:
                                printf("Exit\n");
                                userIndex = 0;
                                break;

                            default:
                                printf("Invalid choice!\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("Invalid choice!\n");
                        }
                    }
                    
                }
                else
                {
                    printf("Login failed!\n");
                }
                break;
            
            case 2:
                printf("Register\n");
                registerUser(&user);
                addUser(&db, &user);
                break;
            
            case 3:
                printf("Reset account\n");
                loginUser(&user);
                removeUser(&db, &user);
                break;

            case 4:
                exitProgram();
                break;
            
            default:
                printf("Invalid choice!\n");
                break;
            }
        }
        else
        {
            printf("Invalid choice!\n");
        }

    }
}