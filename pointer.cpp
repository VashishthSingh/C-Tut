#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    system("cls");
    int x=5;
    int *p=&x;
    int **q=&p;
    int ***r=&q;

    cout<<x<<endl;
    cout<<*p<<endl;
    cout<<**q<<endl;
    cout<<***r<<endl;
    
    cout<<&x<<endl;
    cout<<p<<endl;
    cout<<*q<<endl;
    cout<<**r<<endl;

    getch();
    return(0);
}