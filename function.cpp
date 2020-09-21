#include <iostream>
#include <conio.h>
using namespace std;

void add(int,int); //function declaration
void add(int a,int b){ //function definition  a=4 b=5
    a++; // a=5 b=5
    cout<<"a="<<a<<"\n";
    cout << a + b<<"\n"; // 10
}
int main(){
    system("cls");
    int a, b;
    cout << "\nEnter Two Number: ";
    cin >> a >> b;
    cout<<"a="<<a<<" b="<<b<<"\n"; // a=4 b=5
    add(a,b); // function call
    cout<<"a="<<a<<" b="<<b<<"\n"; // a=4 b=5
    getch();
    return (0);
}

