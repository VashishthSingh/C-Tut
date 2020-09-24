#include<iostream>
#include<conio.h>
using namespace std;

void increment(int&);
void increment(int &y){ // ordinary, pointer, reference
    cout<<y<<endl; //5
    y++;
}
int main(){
    system("cls");
    int x=5; 
    increment(x); // function call by reference
    cout<<x<<endl; //6
    getch();
    return(0);
}