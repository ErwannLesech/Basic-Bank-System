#include <stdio.h>
#include "login.h"

// Main function of a login system in C 
int main()
{
    printf("Welcome to the login system!\n");

    int choice;

    scanf("%i 1. Login \n2. Register \n3. Exit \n", choice);

    switch (choice)
    {
    case 1:
        loginUser();
        break;
    
    case 2:
        registerUser();
        break;
    
    case 3:
        exitProgram();
        break;
    
    default:
        printf("Invalid choice!\n");
        break;
    }
}