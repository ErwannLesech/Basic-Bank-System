#pragma once

struct login
{
    char username[20];
    char password[20];
};

struct database
{
    struct login users[10];
};

// DATABASE FUNCTIONS

// Function to initialize the database
void initDatabase(struct database *db);

// Function to add a user to the database
void addUser(struct database *db, struct login *user);

// Function to remove a user from the database
void removeUser(struct database *db, struct login *user);

// Function to find a user in the database
int findUser(struct database *db, struct login *user);

// USER FUNCTIONS

// Function to register a new user
void registerUser(struct login *user);

// Function to login a user
void loginUser(struct login *user);

// Function to exit the program
void exitProgram();