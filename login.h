#ifndef LOGIN_H
#define LOGIN_H
#include "bank.h"

struct login
{
    char username[20];
    char password[20];
    struct bank_account accounts[10];
};

struct bank
{
    struct login users[10];
    struct bank_account accounts[100];
};

// DATABASE FUNCTIONS

// Function to initialize the bank database
void initDatabase(struct bank *db);

// Function to add a user to the bank database
void addUser(struct bank *db, struct login *user);

// Function to remove a user from the bank database
void removeUser(struct bank *db, struct login *user);

// Function to find a user in the bank database
int findUser(struct bank *db, struct login *user);

// Function to print the bank database
void printDatabase(struct bank *db);

// USER FUNCTIONS

// Function to register a new user
void registerUser(struct login *user);

// Function to login a user
void loginUser(struct login *user);

// Function to check if a user exists in the database
int checkUser(struct bank *db, struct login *user);

// Function to print a user
void printUser(struct login *user);

// Function to exit the program
void exitProgram();

#endif