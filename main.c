#include <stdio.h> // For printf()
#include <stdlib.h> // For exit()
#include "login.h" // For login system

// Main function of a login system in C 
int main()
{
    printf("Welcome to the login system!\n");

    struct database db;

    initDatabase(&db);

    int choice = 0;
    struct login user;
    while (choice != 3)
    {
        printDatabase(&db);
        printf(" 1. Login\n 2. Register\n 3. Reset account\n 4. Exit\n Your choice:");
        if(scanf("%i\n", &choice))
        {
            switch(choice)
            {
            case 1:
                loginUser(&user);
                checkUser(&db, &user);
                break;
            
            case 2:
                registerUser(&user);
                addUser(&db, &user);
                break;
            
            case 3:
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