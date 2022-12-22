#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank create_bank()
{
    struct bank bank;
    bank.clients = malloc(10 * sizeof(struct client));
    bank.accounts = malloc(50 * sizeof(struct account));
    return bank;
}

void print_bank(struct bank bank)
{
    for (int i = 0; i < 10; i++)
    {
        if(bank.clients[i].name[0] != '\0')
        {
            printf("Client %d: %s %s - %s %s\n", i, bank.clients[i].name, bank.clients[i].surname, bank.clients[i].login, bank.clients[i].password);
            for (int j = 0; j < 10; j++)
            {
                if(bank.clients[i].ibans[j] != 0)
                {
                    printf("Account %d: %d - %d\n", j, bank.clients[i].ibans[j], bank.accounts[bank.clients[i].ibans[j]].balance);
                }
            }
        }
    }
}

struct client create_client(char name[20], char surname[20], char login[20], char password[20])
{
    struct client client;
    strcpy(client.name, name);
    strcpy(client.surname, surname);
    strcpy(client.login, login);
    strcpy(client.password, password);
    for (int i = 0; i < 10; i++)
    {
        client.ibans[i] = 0;
    }
    return client;
}

void add_client(struct bank bank, struct client client)
{
    for (int i = 0; i < 10; i++)
    {
        if(bank.clients[i].name[0] == '\0')
        {
            bank.clients[i] = client;
            return;
        }
    }
}

struct client find_client(struct bank bank, char login[20], char password[20])
{
    for (int i = 0; i < 10; i++)
    {
        if(bank.clients[i].name[0] != '\0')
        {
            if(strcmp(bank.clients[i].login, login) == 0 && strcmp(bank.clients[i].password, password) == 0)
            {
                return bank.clients[i];
            }
        }
    }
}

void remove_client(struct bank bank, struct client client)
{
    for (int i = 0; i < 10; i++)
    {
        if(bank.clients[i].name[0] != '\0')
        {
            if(strcmp(bank.clients[i].name, client.name) == 0 && strcmp(bank.clients[i].surname, client.surname) == 0 && strcmp(bank.clients[i].login, client.login) == 0 && strcmp(bank.clients[i].password, client.password) == 0)
            {
                bank.clients[i].name[0] = '\0';
                return;
            }
        }
    }
}

void add_account(struct bank bank, struct client client)
{
    for (int i = 0; i < 10; i++)
    {
        if(bank.clients[i].name[0] != '\0')
        {
            if(strcmp(bank.clients[i].name, client.name) == 0 && strcmp(bank.clients[i].surname, client.surname) == 0 && strcmp(bank.clients[i].login, client.login) == 0 && strcmp(bank.clients[i].password, client.password) == 0)
            {
                for (int j = 0; j < 10; j++)
                {
                    if(bank.clients[i].ibans[j] == 0)
                    {
                        bank.clients[i].ibans[j] = rand() % 50 + 1;
                        bank.accounts[bank.clients[i].ibans[j]].balance = 0;
                        bank.accounts[bank.clients[i].ibans[j]].iban = bank.clients[i].ibans[j];
                        return;
                    }
                }
            }
        }
    }
}

void remove_account(struct bank bank, struct client client)
{
    for (int i = 0; i < 10; i++)
    {
        if(bank.clients[i].name[0] != '\0')
        {
            if(strcmp(bank.clients[i].name, client.name) == 0 && strcmp(bank.clients[i].surname, client.surname) == 0 && strcmp(bank.clients[i].login, client.login) == 0 && strcmp(bank.clients[i].password, client.password) == 0)
            {
                for (int j = 0; j < 10; j++)
                {
                    if(bank.clients[i].ibans[j] != 0)
                    {
                        bank.clients[i].ibans[j] = 0;
                        return;
                    }
                }
            }
        }
    }
}

void deposit(struct bank bank, int iban, int amount)
{
    bank.accounts[iban].balance += amount;
}

void withdraw(struct bank bank, int iban, int amount)
{
    bank.accounts[iban].balance -= amount;
}

void transfer(struct bank bank, int iban1, int iban2, int amount)
{
    bank.accounts[iban1].balance -= amount;
    bank.accounts[iban2].balance += amount;
}

void print_client(struct bank bank, struct client client)
{
    printf("Client: %s %s - %s %s\n", client.name, client.surname, client.login, client.password);
    
    for (int i = 0; i < 10; i++)
    {
        if(client.ibans[i] != 0)
        {
            printf("Account %d: %d - %d\n", i, client.ibans[i], bank.accounts[client.ibans[i]].balance);
        }
    }
}