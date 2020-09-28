#include<iostream>
#include<conio.h>
using namespace std;
// SMA --> static memory allocation
// DMA --> Dynamic memory allocation // new
int main(){
    system("cls");
    int *p=new int[5];  // malloc(), calloc(), free()
    for(int i=0;i<5;i++){
        cin>>p[i];
    }
    for(int i=0;i<5;i++){
        cout<<p[i]<<" ";
    }
    delete []p;
    getch();
    return(0);
}