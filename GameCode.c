#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

/*
	INSTRUCTIONS
		1. Use key 'a' to move left
		2. Use key 's' to move right
		3. Use key 'w' to move up
		4. Use key 'z' to move down
		5. Press 'q' To Quit The Game Any Time
*/

//Function Declaration. U must declare all the function
void drawBoundary(int,int,int*,int*,int*,int*,int*,int*,int*,int*);
void changeUserLocationOnButtonClick(int *,int *,char,int*,int*,int*);

void drawBoundary(int x,int y,int *posX,int *posY,int *gameOver,int *noOfJwel,int *energy,int *noOfMoves,int *energyX,int *energyY){ // Passing User Coordinate And JWEL Coordinate
	int i,j,k;
	for(i=-1;i<=10;i++){
		for(j=-1;j<=50;j++){
			if(i==-1 || i==10 || j==-1 || j==50){
				printf("#");
			}
			else{
				if(i==y && j==x){
					printf("P");
					for(k=0;k<4;k++){
						if(posX[k]==x && posY[k]==y){
							posX[k]=-1;
							posY[k]=-1;
							(*gameOver)++;
							(*noOfJwel)++;
						}
					}
					for(k=0;k<2;k++){
						if(energyX[k]==x && energyY[k]==y){
							energyX[k]=-1;
							energyY[k]=-1;
							(*energy)=(*energy)+10;
						}
					}
				}	
				else{
					if(posX[0]==j && posY[0]==i){
						printf("a");
					}
					else if(posX[1]==j && posY[1]==i){
						printf("b");
					}
					else if(posX[2]==j && posY[2]==i){
						printf("c");
					}
					else if(posX[3]==j && posY[3]==i){
						printf("d");
					}
					else if(j==energyX[0] && i==energyY[0]){
						printf("E");
					}
					else if(j==energyX[1] && i==energyY[1]){
						printf("E");
					}
					else{
						printf(" ");
					}		
				}		
			}
		}
		printf("\n");
	}
	printf("\n\n\tEnergy Left = %d",*energy);
	printf("\n\n\tNo Of Moves = %d",*noOfMoves);
}

void changeUserLocationOnButtonClick(int *x,int *y,char keyPressed,int *noOfMoves,int *gameQuit,int *energy){
	int static step=0;
	if(step==5){
		step=0;
		(*energy)--;
	}
	switch(keyPressed){
		case 'w':     // ASCII value of  UP Arrow Key
			if(*y!=0){
				(*noOfMoves)++;
				step++;
				(*y)--;     // Changing y 
			}	  
			break;
		case 'a':     // ASCII value of  LEFT Arrow Key
			if(*x!=0){
				(*noOfMoves)++;
				step++;
				(*x)--;  // Changing x
			}	
			break;
		case 's':     // ASCII value of  RIGHT Arrow Key
			if(*x!=49){
				(*noOfMoves)++;
				step++;
				(*x)++;  // Changing x
			}	
			break;
		case 'z':     // ASCII value of  DOWN Arrow Key
			if(*y!=9){
				(*noOfMoves)++;
				step++;
				(*y)++;  // Changing y 
			}	
			break;
		case 'q':
			*gameQuit=1; // storing 1 to gameQuit variable indicate that user has quit the GAME
			break;
	}
}

int main(){
	int x=0,y=0; // for user position
	char ch;     // to store the key Pressed
	int positionX[4]={0}; // Jwel X Position
	int positionY[4]={0}; // Jwel Y Position

	// Energy 
	int energyX[2]={0};  // Energy X Position
	int energyY[2]={0};  // Energy Y Position
	
	int randomNum,i=0;
	int gameOver=0,noOfMoves=0,gameQuit=0,noOfJwel=0,energy=10; // gameOver To generate the food again
	
	srand(time(0)); 
	// Storing the random X Position For JWEL
	while(i<4){     
		randomNum=rand()%50;
		positionX[i]=randomNum;
		i++;
	}
	// Storing the random Y Position For JWEL
	i=0;
	while(i<4){
		randomNum=rand()%10;
		positionY[i]=randomNum;
		i++;
	}
	
	// Storing the random X Position For Energy
	i=0;
	while(i<2){
		randomNum=rand()%10;
		energyX[i]=randomNum;
		i++;
	}
	// Storing the random Y Position For Energy
	i=0;
	while(i<2){
		randomNum=rand()%10;
		energyY[i]=randomNum;
		i++;
	}
	
	drawBoundary(x,y,positionX,positionY,&gameOver,&noOfJwel,&energy,&noOfMoves,energyX,energyY); // Function Call
	
	while(1){
		if(kbhit()){
			ch=getch();
			system("cls");
			changeUserLocationOnButtonClick(&x,&y,ch,&noOfMoves,&gameQuit,&energy);
			if(energy==0){
				system("cls");
				printf("\nOh No! You Lost!!\n");
				printf("\nYou Collected %d Jwels!\n",noOfJwel); 
				printf("\nAfter %d Moves You Quit!\n",noOfMoves); 
				printf("\nEnergy Left Is %d\n",energy);
				printf("\n[][][][] Game Over [][][][]\n");
				break;
			}
			if(gameQuit==0){ // if gameQuit is 1 means user has pressed 'q' key 
				drawBoundary(x,y,positionX,positionY,&gameOver,&noOfJwel,&energy,&noOfMoves,energyX,energyY);
				if(gameOver==4){
                    	gameOver=0;
						srand(time(0)); 
                    	i=0;
						while(i<4){     
							randomNum=rand()%50;
							positionX[i]=randomNum;
							i++;
						}
						i=0;
						while(i<4){
							randomNum=rand()%10;
							positionY[i]=randomNum;
							i++;
						}
						i=0;
						while(i<2){
							randomNum=rand()%10;
							energyX[i]=randomNum;
							i++;
						}
						i=0;
						while(i<2){
							randomNum=rand()%10;
							energyY[i]=randomNum;
							i++;
						}
				}
			}
			else{
				system("cls");
				printf("\nOh No! You Quit!!\n");
				printf("\nYou Collected %d Jwels!\n",noOfJwel); 
				printf("\nAfter %d Moves You Quit!\n",noOfMoves); 
				printf("\nEnergy Left Is %d\n",energy);
				printf("\n[][][][] Game Over [][][][]\n");
				break;	//breaking the infinite loop
			}
		}
	}
	getch();
	return(0);
}
