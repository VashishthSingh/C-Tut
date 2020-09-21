#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    system("cls");
    int day; // 1 to 7
    cout<<"\nEnter The Day Number: ";
    cin>>day;
    switch (day) {
        case 1:
            cout<<"Monday";
            break;
        case 2:
            cout<<"Tuesday";
            break;
        case 3:
            cout<<"Wednesday";
            break;
        case 4:
            cout<<"Thursday";
            break;
        case 5:
            cout<<"Friday";
            break;
        case 6:
            cout<<"Saturday";
            break;
        case 7:
            cout<<"Sunday";
            break;
        default:
            cout<<"\nEnter Number Btween 1-7 only";
    }
    getch();
    return(0);
}