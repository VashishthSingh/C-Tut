#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    system("cls");
    int marks[5]={1,2,3,4,5},i;
    int *p=marks;
    for(i=0;i<5;i++){
        cout<<*p<<endl;
        p++;
    }
    getch();
    return(0);
}