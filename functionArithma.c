#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// function declaration
int division(int,int);
void mul(int,int);  
int sub();
void add();  

// function definition
void add(){  
    int a,b;
    printf("\nEnter Two Number For Addtion: ");
    scanf("%d%d",&a,&b);
    printf("\nSum Of %d And %d Is %d",a,b,a+b);
}
int sub(){ 
    int a,b;
    printf("\nEnter Two Number For Subtraction: ");
    scanf("%d%d",&a,&b);
    return(a-b);
}
void mul(int p,int q){  // p and q are formal argument
    printf("\nMul Of %d And %d Is %d",p,q,p*q);
}
int division(int p,int q){
    return(p/q);
}
int menu(){
    int choice;
    printf("\n1. Add Two Number");
    printf("\n2. Sub Two Number");
    printf("\n3. Mul Two Number");
    printf("\n4. Div Two Number");
    printf("\n5. Exit");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);
    return(choice);
}
int main(){ 
    int a,b,result,breakInfiniteLoop=0;
    while(1){
        system("cls");
        switch(menu()){
            case 1:
                add();
                break;
            case 2:
                result=sub();
                printf("\nSubtraction Is %d",result);
                break;
            case 3:
                printf("\nEnter Two Number For Multiplication: ");
                scanf("%d%d",&a,&b);
                mul(a,b);
                break;
            case 4:
                printf("\nEnter Two Number For Division: ");
                scanf("%d%d",&a,&b);
                result=division(a,b);
                printf("\nDivision Of %d And %d Is %d",a,b,result);
                break;
            case 5:
                breakInfiniteLoop=1;
                break;
            default:
                printf("\nInvalid Choice");
                break;
        }//end of switch
        getch();
        if(breakInfiniteLoop==1){
            break;
        }
    }//end of infinite loop
    printf("\nThanks For Using Our Calculator:");
    getch();
    return(0);
}

/*
    1. function without argument and without return value
    2. function without argument and with return value
    3. function with argument and without return value
    4. function with argument and with return value
*/