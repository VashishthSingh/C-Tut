#include<iostream>
#include<conio.h>
using namespace std;
// function return type, function name, arguments
void area(int,int); 
void area(int);
void setChar(int); 
void setChar(double);
void setFloat(double);
void printChar(float);
void printChar(double);

void area(int l,int b){cout<<"\nArea Of Rectangle";}
void area(int r){ cout<<"\nArea Of Circle";}

void setChar(int ch){cout<<"\nSetting char --> int";}
void setChar(double ch){cout<<"\nSetting char --> double";}

void setFloat(double flag){cout<<"\nsetting flag --> double";}

void printChar(float ch){cout<<"printing Char --> float";}
void printChar(double ch){cout<<"printing Char --> double";}

int main(){
    system("cls");
    area(4,5); 
    area(5);

    char a='A'; 
    setChar(a);

    float flag=4.5f; 
    setFloat(flag);

    char b='B'; 
    //printChar(b); // int, float, double

    getch();
    return(0);
}
/*
    How Compiler Resolves Function Overloading
    1. Exact Match
    2. Type Promotion :  char, unsigned char, sort--> int, float --> double
    3. Type Conversion : Any Primitive --> Any Primitive
*/
