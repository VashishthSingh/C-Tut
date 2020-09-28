#include<iostream>
#include<conio.h>
using namespace std;

int** allocateMemory();
int** allocateMemory(){
    int **p;
    p=new int*[3];  // int p[3][3];
    for(int i=0;i<3;i++){
        p[i]=new int[3];
    }
    return(p);
}
int main(){
    system("cls");
    int **p=allocateMemory();
    for(int i=0;i<3;i++){
        cout<<"\nEnter Three Values: ";
        for(int j=0;j<3;j++){
            cin>>p[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    getch();
    return(0);
}

// #include <iostream>
// #include<conio.h>
// using namespace std;

// int main () {
//    system("cls");
//    int  var[5] = {10,20,30,40,50};
//    int *ptr[5]; // array of pointer  SMA
//    for (int i = 0; i < 5; i++) {
//       ptr[i] = &var[i]; // assign the address of integer array blocks
//    }
//    *ptr[0]=100;//1000
//    for (int i = 0; i < 5; i++) {
//       cout << "Value of var[" << i << "] = ";
//       cout << *ptr[i] << endl;
//    }
//    getch();
//    return 0;
// }
