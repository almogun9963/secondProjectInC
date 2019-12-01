// 0 is closed
// 1 is opened
// 901 is the first place in the array and 950 is the last place
#include <stdbool.h>
#include <stdio.h>
double arr[50][2];

// Open a new account 
void openAccount(double amount)
{
    if(amount < 0)
    {
         printf("The first amount of money should be positive\n");
    }
    else
    {
        bool canOpen = false;
        int j;
        for(int i = 0; i < 50 && canOpen == false; i++)
        {
            if(arr[i][1]==0)
            {
                canOpen=true;
                j = i;
            }
        }
        if(canOpen)
        {
            arr[j][1] = 1;
            arr[j][0] = amount;
            printf("The new account number is: %d" , j + 901);
            printf("\n");
        } 
        else
        {
            printf("There are 50 bank accounts, no place to add another account\n");
        }
    }
}
// Check the balance of the giving account number
void balanceChecking(int numAcc)
{
    int newNum = numAcc - 901;
    if(numAcc > 950 || numAcc < 901)
    {
        printf("The number of this account isn't legal\n");
    }
    else
    {
        if(arr[newNum][1] == 0)
        {
            printf("The account should be open\n");
        }
        else
        {
            printf("Account number: %d has balance of: %0.2f\n" , numAcc , arr[newNum][0]);
        }
    }
}
//Add money to the giving account
void deposit(int numAcc, double newAmount)
{
    int newNum = numAcc - 901;
    if(numAcc > 950 || numAcc < 901)
    {
        printf("The number of this account isn't legal\n");
    }
     else
    {
        if(arr[newNum][1] == 0)
        {
            printf("The account should be open\n");
        }
        else
        {
            arr[newNum][0] += newAmount;
            printf("The new balance is: ");
            printf("%0.2f\n" , arr[newNum][0]);
        }
    }
}
//Subtract money from the giving account
void withraw(int numAcc, double newAmount)
{
    int newNum = numAcc - 901;
    if(numAcc > 950 || numAcc < 901)
    {
        printf("The number of this account isn't legal\n");
    }
     else
    {
        double checkingIfPositive = arr[newNum][0] - newAmount;
        if(arr[newNum][1] == 0)
        {
            printf("The account should be open\n");
        }
        else if(checkingIfPositive < 0)
        {
             printf("There are no enough cash to withraw\n");
        }
        else
        {
            arr[newNum][0] = arr[newNum][0] - newAmount;
            printf("The new balance is: ");
            printf("%0.2f\n" , arr[newNum][0]);
        }
    }
}
//Close the account
void closeAccount(int numAcc)
{
    int newNum = numAcc - 901;
    if(numAcc > 950 || numAcc < 901)
    {
        printf("The number of this account isn't legal\n");
    }
    else
    {
        if(arr[newNum][1] == 0)
        {
            printf("The account is already closed\n");
        }
        else
        {
            arr[newNum][1] = 0;
            arr[newNum][0] = 0;
        }
    }
}
//Add interest(%) to all open accounts
void addInterest(double interest)
{
    interest = interest / 100;
    for (int i = 0; i < 50; i++) 
    {
        if(arr[i][1] == 1)
        {
            arr[i][0] = arr[i][0] + (arr[i][0] * interest);
        }
    }
}
//Print all the open accounts
void printOpenAccounts()
{
    for (int i = 0; i < 50; i++) 
    {
        if(arr[i][1] == 1)
        {
            printf("Account number: %d has balance of: %0.2f\n" , i + 901 , arr[i][0]);
        }
    }
}
//Close all the open accounts in the bank
void endProgram()
{
    for (int i = 0; i < 50; i++) 
    {
        if(arr[i][1] == 1)
        {
             closeAccount(i+901);
        }
    }
}

