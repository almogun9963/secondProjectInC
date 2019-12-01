#include <stdbool.h>
#include <stdio.h>
#include "myBank.h"
#include<ctype.h>
int main()
{
    bool theProgFinished = false;
    char tranType;
    double amount;
    double interestRate;
    int accNum;
    printf("menu of Transaction type:\nO - open a new account\nB - balnce checking\nD - deposit\nW - withraw\nC - close the account\nI - interest rate\nP - print all the open accounts\nE - end the whole program\n");
    while(theProgFinished == false)
    {
            printf("Enter Transaction type(O , B , D , W , C , I , P , E): ");
            scanf(" %c", &tranType);
            switch(tranType)
            {
                case 'O':
                    printf("Enter initial deposit: ");
                    scanf(" %le", &amount);
                    openAccount(amount);
                    break;
                case 'B':
                    printf("Enter Account number: ");
                    scanf(" %d", &accNum);
                    balanceChecking(accNum);
                    break;
                case 'D':
                    printf("Enter Account number: ");
                    scanf(" %d", &accNum);
                    printf("Enter Amount of money to put in the account: ");
                    scanf(" %le", &amount);
                    deposit(accNum , amount);
                    break;
                case 'W':
                    printf("Enter Account number: ");
                    scanf(" %d", &accNum);
                    printf("Enter Amount of money to withraw from the account: ");
                    scanf(" %le", &amount);
                    withraw(accNum , amount);
                    break;
                case 'C':
                    printf("Enter Account number: ");
                    scanf(" %d", &accNum);
                    closeAccount(accNum);
                    break;
                case 'I':
                    printf("Enter Interest rate to add to all the accounts: ");
                    scanf(" %le", &interestRate);
                    addInterest(interestRate);
                    break;
                case 'P':
                    printOpenAccounts();
                    break; 
                case 'E':
                    theProgFinished = true;
                    endProgram();
                    break;
                default:
                    printf("Error! Transaction type isn't correct\n");
                    printf("Please Enter a right transaction type(O , B , D , W , C , I , P , E).\n");
                    break;
            }
    }
    return 0;    
}