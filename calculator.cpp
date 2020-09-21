#include<iostream>
#include<conio.h>
using namespace std;

void add();
int subtract();
void multiply(int,int);
float div(float,float);
void add(){
    int a,b;
    cout<<"\nEnter Two Number: ";
    cin>>a>>b;
    cout<<"\nSum = "<<a+b<<"\n";
}
int subtract(){
    int a,b;
    cout<<"\nEnter Two Number: ";
    cin>>a>>b;
    return a>b?(a-b):(b-a);  
}
void multiply(int a,int b){
    cout<<"\nMultiplication = "<<a*b<<"\n";
}
float div(float a,float b){
    return(a/b);
}
int menu(){
    cout<<"1. add\n";
    cout<<"2. Sub\n";
    cout<<"3. Mul\n";
    cout<<"4. Div\n";
    cout<<"5. Exit\n";
    int ch;
    cout<<"\nEnter Your Choice: ";
    cin>>ch;
    return(ch);
}
int main(){
    int a,b;int sub;float di;
    float p,q;
    int breakInfiniteLoop=0;
    while(1){
        system("cls");
        switch (menu()) {
            case 1:
                add();
                getch();
                break;
            case 2:
                sub=subtract();
                cout<<"\nSubtraction = "<<sub<<"\n";
                getch();
                break;
            case 3:
                cout<<"\nEnter Two Number For Mul: ";
                cin>>a>>b;
                multiply(a,b);
                getch();
                break;
            case 4:
                cout<<"\nEnter Two Number For Div: ";
                cin>>p>>q;
                di=div(p,q);
                cout<<"\nDiv = "<<di<<"\n";
                getch();
                break;
            case 5:
                breakInfiniteLoop=1;
                break;
            default:
                cout<<"\nInvalid Choice:";
        }//end of switch
        if(breakInfiniteLoop==1){
            break;
        }
    }//end of while loop

    return(0);
}