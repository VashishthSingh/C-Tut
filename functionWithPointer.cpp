#include<iostream>
#include<conio.h>
using namespace std;

void swap(int*,int*);
void swap(int *p,int *q){
    int temp=*p; // temp=a;
    *p=*q; // a=b
    *q=temp; // b=temp
}
int main(){
    system("cls");
    int a=4,b=5;
    cout<<"a="<<a<<" b="<<b<<endl; // a=4 b=5
    swap(&a,&b);// function call by address
    cout<<"a="<<a<<" b="<<b<<endl; // a=5 b=4
    getch();
    return(0);
}