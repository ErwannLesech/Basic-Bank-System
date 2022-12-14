#include <stdio.h> // For printf()
#include <stdlib.h> // For exit()
#include <string.h> // For strcmp()
#include "login.h"

void initDatabase(struct database *db)
{
    for (int i = 0; i < 10; i++)
    {
        db->users[i].username[0] = '\0';
        db->users[i].password[0] = '\0';
    }
}

void addUser(struct database *db, struct login *user)
{
    for (int i = 0; i < 10; i++)
    {
        if (db->users[i].username[0] == '\0')
        {
            db->users[i] = *user;
            break;
        }
    }
    if (db->users[9].username[0] != '\0')
    {
        printf("Database is full!\n");
    }
}

void removeUser(struct database *db, struct login *user)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(db->users[i].username, user->username) == 0)
        {
            db->users[i].username[0] = '\0';
            db->users[i].password[0] = '\0';
            break;
        }
    }
}

int findUser(struct database *db, struct login *user)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(db->users[i].username, user->username) == 0)
        {
            return i;
        }
    }

    return -1;
}

void printDatabase(struct database *db)
{
    for (int i = 0; i < 10; i++)
    {
        if (db->users[i].username[0] != '\0')
        {
            printf("Username: %s Password: %s\n", db->users[i].username, db->users[i].password);
        }
    }
}

void registerUser(struct login *user)
{
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void loginUser(struct login *user)
{
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void checkUser(struct database *db, struct login *user)
{
    int index = findUser(db, user);

    if (index == -1)
    {
        printf("User not found!\n");
    }
    else
    {
        printf("User found!\n");
    }
}

void exitProgram()
{
    printf("Exiting program...\n");
    exit(0);
}