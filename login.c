#include <stdio.h>
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

void registerUser(struct login *user)
{
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void loginUser(struct database *db)
{
    struct login user;

    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(user.username, username);
    strcpy(user.password, password);

    int current_user = findUser(&db, &user);

    if (current_user != (-1) && strcmp(password, db->users[current_user]->password) == 0)
    {
        printf("Login successful!\n");
    }
    else
    {
        printf("Login failed!\n");
    }
}

void exitProgram()
{
    printf("Exiting program...\n");
    exit(0);
}