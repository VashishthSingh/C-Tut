#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    system("cls");
    
    int counter;
    for(counter=1;counter<=10;counter++){
        if(counter==7){
            continue;
        }
        cout<<counter<<"\n";
    }
               
    int c1=1;
    while(c1<=10){ //condtion is checked during entry time
        if(c1==2){
            c1++;
            continue;
        }
        cout<<c1<<"\n";
        c1++;
    }

    int c2=1;
    do{
        if(c2==3){
            c2++;
            continue;
        }
        cout<<c2<<"\n";
        c2++;
    }while(c2<=10); //condtion is checked during exit time
    
    getch();
    return(0);
}