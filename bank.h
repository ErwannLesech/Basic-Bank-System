#pragma once

struct account
{
    int iban; // 2 digits
    int balance;
};

struct client
{
    char name[20];
    char surname[20];
    char login[20];
    char password[20];
    int ibans[10]; // 10 x 2 digits
};

struct bank
{
    struct client *clients;
    struct account *accounts;
};

// Bank functions

// Create a bank with 10 clients and 50 accounts
struct bank create_bank();

// print all clients and their accounts
void print_bank(struct bank bank);

// Create a client
struct client create_client(char name[20], char surname[20], char login[20], char password[20]);

// Add a client to the bank
void add_client(struct bank bank, struct client client);

// Find a client in the bank
struct client find_client(struct bank bank, char login[20], char password[20]);

// Remove a client from the bank
void remove_client(struct bank bank, struct client client);

// Add an account to a client
void add_account(struct bank bank, struct client client);

// Remove an account from a client
void remove_account(struct bank bank, struct client client);

// Deposit money to an account
void deposit(struct bank bank, int iban, int amount);

// Withdraw money from an account
void withdraw(struct bank bank, int iban, int amount);

// Transfer money from one account to another
void transfer(struct bank bank, int iban, int iban2, int amount);

// Client functions
void print_client(struct bank bank, struct client client);
