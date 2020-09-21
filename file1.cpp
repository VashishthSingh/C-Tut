#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main(){ 
    system("cls");
    int num1,num2;
    cout<<"Enter A Number: ";
    cin>>num1;
    for(num2=1;num2<=20;num2++){
        cout<<num1<<setw(5)<<"X"<<setw(5)<<num2<<setw(5)<<"="<<setw(5)<<num1*num2<<endl;
    }
    cout<<setw(5)<<"Hello C++!\n";
    getch();
    return(0);
}