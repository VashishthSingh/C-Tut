#include <iostream>
#include<conio.h>
using namespace std;

void getInput(int *arr, int size);
void showInput(int arr[5], int size);
double getAverage(int arr[], int size);

void getInput(int *arr, int arraySize) {        // Formal parameter as a pointer
    int i;
    for(i=0;i<arraySize;i++){
        cout<<"Enter "<<i+1<<" value: ";
        cin>>arr[i];
    }
}
void showInput(int arr[5], int arraySize ) {    // Formal parameter as a sized array
    int i;
    for(i=0;i<arraySize;i++){
        cout<<arr[i]<<" ";
    }
}
double getAverage(int arr[], int arraySize) { // Formal parameter as an unsized array
    int i=0,sum=0;
    for(i=0;i<arraySize;i++){
        sum=sum+arr[i];
    }
    double average=(double)sum/arraySize;
    return(average);
}
int main () {
   system("cls");
   int arr[5];
   getInput(arr,5); // array name holds the base address of array 
   showInput(arr,5);
   showInput(arr,5);
   cout<<"\nAverage: "<<getAverage(arr,5);
   getch();
   return 0;
}