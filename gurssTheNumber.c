#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
int main(){
    int generatedNumber,suffleOrder=0,endProgram,noOfTurnTaken;
    char userNumber,ch;
    while(1){
        endProgram=0;
        noOfTurnTaken=0;
        srand(time(0));
        generatedNumber=rand()%10; // 1 to 9
        if(generatedNumber==0){
            generatedNumber++;
        }
        while(1){
            system("cls");
        printf("\nEnter A Number 1-9 To Guess Or Enter 'H' To Get Hint: ");
        fflush(stdin);
        scanf("%c",&userNumber);
        if(userNumber>=49 && userNumber<=57){ // 1 to 9 
            noOfTurnTaken++; 
            if(generatedNumber==userNumber-48){
                if(noOfTurnTaken==1){
                    printf("\nOhh Genius .. It Is Correct. NoOgTurnTaken = %d",noOfTurnTaken);
                }
                else
                    printf("\nWell Done You Did It.. Correct, NoOgTurnTaken = %d",noOfTurnTaken);
                endProgram=1;
            }
            else if(abs(generatedNumber-(userNumber-48))==1){
                printf("\nSooooo.. Close:");
            }
            else if(abs(generatedNumber-(userNumber-48))<=2){
                printf("\nClose:");
            }
            else if(abs(generatedNumber-(userNumber-48))>2 && abs(generatedNumber-(userNumber-48))<=4){
                printf("\nLittele Away:");
            }
            else if(abs(generatedNumber-(userNumber-48))>4 && abs(generatedNumber-(userNumber-48))<=6){
                printf("\nAway:");
            }
            else{
                printf("\nFar Away:");
            }
        }
        else{
            if(userNumber=='H' || userNumber=='h'){
                if(generatedNumber==1)
                    printf("\n1, 2, 3");
                else if(generatedNumber==9)
                    printf("\n7, 8, 9");
                else{
                    if(suffleOrder%2==0)
                        printf("\n%d, %d, %d",generatedNumber-1,generatedNumber,generatedNumber+1);
                    else
                        printf("\n%d, %d, %d",generatedNumber,generatedNumber+1,generatedNumber+2);
                    suffleOrder++;
                }
            }
            else if(userNumber=='Q' || userNumber=='q'){
                printf("\nYou Quit The Game:");
                endProgram=1;
            }
            else{
                printf("\nEntered Value Is Invalid:");
            }
        }
            getch();
            if(endProgram==1){
                break;
            }
        }//end of inner infinite loop
        if(endProgram==1){
            printf("\nEnter Y/N");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='N' || ch=='n'){
                break;
            }
        }
    }//end of outer infinite loop
    printf("\nThanks For Playing This Game:");
    getch();
}//end of main function