#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct AtmInfo{
    int accNo,pin;
    int totalAmount,totalDepo,totalWith,totalTrans;
};
struct CreateNewAcc{
    char name[50];
    int age,contactNo;
    char password[50],dob[50],address[100],citizenShip[50];
    struct AtmInfo atmInfo;
};
struct AllAccountDetails{
    struct CreateNewAcc allAccDetails[10];
};

int mainMenu();
int menuForATM();
void bankDetail();
void createNewAccount();
void atmManagement(int,int,int,int);
void writeAccountDetailToFile();
void initialInitializationFunction();
void fetchAllAccountsDetails();
void loadAccountDetail();

int totNoOfAccount=0;
struct AllAccountDetails all;

int main(){
    int breakInfiniteOuterLoop=0,breakInfinieInnerLoop,returnToMainMenu;
    int accNumber,pinNumber,i,k;
    initialInitializationFunction();
    loadAccountDetail();
    while(1){
        breakInfinieInnerLoop=0;
        returnToMainMenu=0;
        k=0;
        system("cls");
        switch(mainMenu()){
            case 1:
                bankDetail();
                break;
            case 2:
                createNewAccount();
                break;
            case 3:
                printf("\nEnter Your Account Number: ");
                scanf("%d",&accNumber);
                printf("\nEnter Your 4 Digit Pin: ");
                scanf("%d",&pinNumber);
                for(i=0;i<totNoOfAccount;i++){
                    if(accNumber==all.allAccDetails[i].atmInfo.accNo && pinNumber==all.allAccDetails[i].atmInfo.pin){
                        k=1;
                        break;
                    }
                }
                if(k==1)
                while(1){
                    system("cls");
                    printf("\nWorking On Below Mentioned Account:");
                    printf("\nName = %s  Acc No = %d  Pin = %d",all.allAccDetails[i].name,all.allAccDetails[i].atmInfo.accNo,all.allAccDetails[i].atmInfo.pin);
                    switch(menuForATM()){
                        case 1:
                            atmManagement(1,accNumber,pinNumber,i);
                            break;
                        case 2:
                            atmManagement(2,accNumber,pinNumber,i);
                            break;
                        case 3:
                            atmManagement(3,accNumber,pinNumber,i);
                            break;
                        case 4:
                            atmManagement(4,accNumber,pinNumber,i);
                            break;
                        case 5:
                            returnToMainMenu=1;
                            break;
                        case 6:
                            breakInfinieInnerLoop=1;
                            break;
                        default:
                        printf("\nInvalid Choice For Atm Menu:");
                    }//end of switch
                    if(breakInfinieInnerLoop==1 || returnToMainMenu==1){
                        break;
                    }
                    getch();
                }//end of inner loop
                else{
                    printf("\nEntered Acc No Or Pin Did Not Match:");
                }
                break;
            case 4:
                breakInfiniteOuterLoop=1;
                break;
            case 5:
                fetchAllAccountsDetails();
                printf("\nTotal Number Of Acc: %d",totNoOfAccount);
                break;
            default:
                printf("\nInvalid Choice for Main Menu: ");
        }//end of switch
        if(breakInfiniteOuterLoop==1 || breakInfinieInnerLoop==1){
            break;
        }
        getch();
    }//end of outer loop
    printf("\nThanks For Using My Bank:");
    return(0);
}
int mainMenu(){
    int ch;
    printf("\n1. Bank Detail");
    printf("\n2. Create New Account");
    printf("\n3. Atm Management");
    printf("\n4. Exit");
    printf("\n5. Get All Accounts Details:");
    printf("\nEnter Your Choice: ");
    scanf("%d",&ch);
    return(ch);
}
int menuForATM(){
    int ch;
    printf("\n1. Deposit Amount");
    printf("\n2. Withdraw Amount");
    printf("\n3. Transfer Amount");
    printf("\n4. Check details");
    printf("\n5. RETURN TO MAIN MENU");
    printf("\n6. Exit");
    printf("\nEnter Your Choice: ");
    scanf("%d",&ch);
    return(ch);
}
void bankDetail(){
    printf("\nAbout Bank Detail");
}
void createNewAccount(){
    printf("\nCreating New Account");
    struct CreateNewAcc newAcc;
    fflush(stdin);
    printf("\nEnter Your Name: ");
    gets(newAcc.name);
    fflush(stdin);
    printf("\nEnter Your Age: ");
    scanf("%d",&newAcc.age);
    fflush(stdin);
    printf("\nEnter Your Contact Number: ");
    scanf("%d",&newAcc.contactNo);
    fflush(stdin);
    printf("\nEnter Your Password: ");
    gets(newAcc.password);
    fflush(stdin);
    printf("\nEnter Your DOB: ");
    gets(newAcc.dob);
    fflush(stdin);
    printf("\nEnter Your Address: ");
    gets(newAcc.address);
    fflush(stdin);
    printf("\nEnter Your CitizenShip: ");
    gets(newAcc.citizenShip);

    fflush(stdin);
    printf("\nEnter Account Number: ");
    scanf("%d",&newAcc.atmInfo.accNo);
    fflush(stdin);
    printf("\nEnter 4 Digit Pin For ATM: ");
    scanf("%d",&newAcc.atmInfo.pin);

    newAcc.atmInfo.totalAmount=1000;
    newAcc.atmInfo.totalDepo=0;
    newAcc.atmInfo.totalTrans=0;
    newAcc.atmInfo.totalWith=0;
    
    all.allAccDetails[totNoOfAccount]=newAcc;

    writeAccountDetailToFile();
}
void writeAccountDetailToFile(){
    FILE *outfile; 
    outfile = fopen ("accountDetails.txt", "w"); 
    if (outfile == NULL){ 
        fprintf(stderr, "\nError opend file\n"); 
    } 
    fwrite (&all, sizeof(struct AllAccountDetails), 1, outfile); 
    if(fwrite != 0){
        printf("\n! Account Detail to file written successfully !");
        getch();
    } 
    else{
        printf("error writing file !\n"); 
    }
    fclose (outfile); 
}
void initialInitializationFunction(){
    for(int i=0;i<10;i++){
        all.allAccDetails[i].atmInfo.accNo=0;
    }
}
void fetchAllAccountsDetails(){
    FILE *infile; 
    infile = fopen ("accountDetails.txt", "r"); 
    if (infile == NULL){ 
        fprintf(stderr, "\nError opening file\n"); 
    } 
    while(fread(&all, sizeof(struct AllAccountDetails), 1, infile));
    fclose (infile); 
    totNoOfAccount=0;
    for(int i=0;i<10;i++){
        if(all.allAccDetails[i].atmInfo.accNo!=0){
            printf("\nname= %s accNo= %d pin= %d",all.allAccDetails[i].name,all.allAccDetails[i].atmInfo.accNo,all.allAccDetails[i].atmInfo.pin);
            totNoOfAccount++;
        }
        else{
            break;
        }
    }
}
void loadAccountDetail(){
    FILE *infile; 
    infile = fopen ("accountDetails.txt", "r"); 
    if (infile == NULL)
        fprintf(stderr, "\nError opening file\n"); 
    while(fread(&all, sizeof(struct AllAccountDetails), 1, infile));
    fclose (infile); 
    totNoOfAccount=0;
    for(int i=0;i<10;i++){
        if(all.allAccDetails[i].atmInfo.accNo!=0)
            totNoOfAccount++;
        else{break;}
    }
}
void atmManagement(int ch,int accNumber,int pinNumber,int i){
    printf("\nManaging ATM Detail");
    int amount;
    switch(ch){
        case 1:
            printf("\nDepositing Amount");
            printf("\nEnter The Amount To Deposite: ");
            scanf("%d",&amount);
            all.allAccDetails[i].atmInfo.totalAmount+=amount;
            all.allAccDetails[i].atmInfo.totalDepo+=amount;
            printf("\nDepositing Amount Successful");
            break;
        case 2:
            printf("\nWithdrawing Amount");
            printf("\nEnter The Amount To Withdraw: ");
            scanf("%d",&amount);
            all.allAccDetails[i].atmInfo.totalAmount-=amount;
            all.allAccDetails[i].atmInfo.totalWith+=amount;
            printf("\nWithdraw Amount Successful");
            break;
        case 3:
            printf("\nTransfer Amount");
            printf("\nEnter The Amount To Transfer: ");
            scanf("%d",&amount);
            all.allAccDetails[i].atmInfo.totalAmount-=amount;
            all.allAccDetails[i].atmInfo.totalTrans+=amount;
            printf("\nTransfer Amount Successful");
            break;
        case 4:
            printf("\nTotal Balance: %d",all.allAccDetails[i].atmInfo.totalAmount);
            printf("\nTotal Deposite: %d",all.allAccDetails[i].atmInfo.totalDepo);
            printf("\nTotal Withdraw: %d",all.allAccDetails[i].atmInfo.totalWith);
            printf("\nTotal Transfer: %d",all.allAccDetails[i].atmInfo.totalTrans);
            break;
    }
    if(ch!=4){
        writeAccountDetailToFile();
    }
}
 