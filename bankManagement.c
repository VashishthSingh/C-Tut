#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){  
    system("cls");
    int balance=1000;
    int choice,amout,breakInfiniteLoop=0;
    while(1){
        system("cls");
        printf("\n1. Deposit Money");
        printf("\n2. Withdraw Money");
        printf("\n3. Check Balanacs/Status");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
       switch(choice){
           case 1:
                printf("\nEnter The Amount You Want To Deposit: ");
                scanf("%d",&amout);
                balance=balance+amout;
                printf("\nSuccess");
                getch();
                break;
           case 2:
                printf("\nEnter The Amount You Want To Withdraw: ");
                scanf("%d",&amout);
                if(amout<=balance){
                    balance=balance-amout;
                    printf("\nSuccess");
                }
                else{
                    printf("\nWithdraw Amount Is Greater Than Ur Actual Balance:");
                    printf("\nWithdraw Not Possible:");
                }
                getch();
                break;
           case 3:
                printf("\nYour Current Balance Is: %d",balance);
                getch();
                break;
           case 4:
                breakInfiniteLoop=1;
                break;
           default:
            printf("\nInvalid Choice");
            getch();
            break;
       }//end of switch
       if(breakInfiniteLoop==1){
           break;
       }
    }//end of infinite loop
    printf("\nThanks For Using This Software:");
    getch();
    return 0;
}
/*
    1. Deposit Money
    2. Withdraw Money
    3. Check Balance
*/