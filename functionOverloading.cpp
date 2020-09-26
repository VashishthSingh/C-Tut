#include<iostream>
#include<conio.h>
using namespace std;
// function return type, function name, arguments
void acceptChar(float);
void acceptFloat(double);
void area(int,int);
void area(int);
void area(double);

void area(int l,int b){
    cout<<"\nArea Of Rectangle = "<<l*b<<endl;
}
void area(int r){
    cout<<"\nArea Of Circle = "<<3.14*r*r<<endl;
}
void area(double a){
    cout<<"\nArea Od Square = "<<a*a<<endl;
}
void acceptChar(int ch){
    cout<<ch;
}
void acceptChar(double d){
    cout<<d;
}
int main(){
    system("cls");
    area(4,5);
    area(5);
    area(4.4);
    char x='A';
    acceptChar(x);
    getch();
    return(0);
}

/*
    How Compiler Resolves Function Overloading
    1. Exact Match
    2. Type Promotion :  char, unsigned char, sort--> int, float --> double
    3. Type Conversion : Any Primitive --> Any Primitive
*/
