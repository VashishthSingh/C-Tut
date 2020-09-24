#include<iostream>
#include<conio.h>
using namespace std;

void functionCallByValue(int);
void functionCallByAddress(int*);
void functionCallByReference(int&);

void functionCallByValue(int p){      // Ordinary variable
    p++;  // 
}
void functionCallByAddress(int *p){   // Pointer variable
    (*p)++;  
}
void functionCallByReference(int &p){ // Reference variable
    p++;
}
int main(){
    system("cls");
    int p=5;
    functionCallByValue(p);       // Function Call By Value
    cout<<p<<endl;  //5
    functionCallByAddress(&p);    // Function Call By Address
    cout<<p<<endl;  // 6
    functionCallByReference(p);   // Function Call By Reference
    cout<<p<<endl;  // 7
    getch();
    return(0);
}