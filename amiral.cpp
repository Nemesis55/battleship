#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

const int HEIGHT = 10;
const int WIDTH = 10;

bool placeShips(bool[HEIGHT][WIDTH], int , int );
void showBoard(bool[HEIGHT][WIDTH] );
int randomInt(int , int );

int main() {
	srand(time(NULL));
	bool board[HEIGHT][WIDTH];
	
	int i;
	int j;
	for(i=0;i<10;i++) for(j=0;j<10;j++) board[i][j] = false;
	
	placeShips(board,7,4);
	
	printf("\n");
	
	showBoard(board);
	
	printf("\n\n");
	system("PAUSE");
}
void showBoard(bool board[HEIGHT][WIDTH]) {
	
	/*
	TODO: Letters will be shown instead of 1's and 0's.
	*/
	
	int i;
	int j;
	for(i=0;i<HEIGHT;i++) {
		for(j=0;j<WIDTH;j++) {
			printf("%d ",board[i][j]);	
		}	
		printf("\n");
	}
		
}
bool placeShips(bool board[HEIGHT][WIDTH], int shipNum, int maxShipSize) {
	
	
	bool conflict, isVertical;
	int size, x, y;
	
	int n;
	for(n=0;n<shipNum;n++) {
		
		do {
			
			conflict = false;
			
			size = randomInt(1,maxShipSize);
			isVertical = (bool)randomInt(0,1);
			
			if(isVertical) {
				y = randomInt(0,HEIGHT-size);
				x = randomInt(0,WIDTH-1);
			}
			else {
				y = randomInt(0,HEIGHT-1);
				x = randomInt(0,WIDTH-size);
			}
			
			
			
			if(board[y][x] || 
			(y!=0 && board[y-1][x]) || (y!=HEIGHT-1 && board[y+1][x]) || 
			(x!=0 && board[y][x-1]) || (x!=WIDTH -1 && board[y][x+1]) ) conflict = true;
			
			
			if(!conflict) {
				
				if(isVertical) {
					int i=y;
					while(!conflict && i<y+size) {
						if(board[i][x] || 
						(i!=0 && board[i-1][x]) || (i!=HEIGHT-1 && board[i+1][x]) || 
						(x!=0 && board[i][x-1]) || (x!=WIDTH -1 && board[i][x+1]) ) conflict = true;	
						
						i++;
					}
				}
				else {
					int i=x;
					while(!conflict && i<x+size) {
						if(board[y][i] || 
						(y!=0 && board[y-1][i]) || (y!=HEIGHT-1 && board[y+1][i]) || 
						(i!=0 && board[y][i-1]) || (i!=WIDTH -1 && board[y][i+1]) ) conflict = true;	
						
						i++;
					}	
				}
			} 
			
		}while(conflict);
		
		int i;
		if(isVertical) for(i=y;i<y+size;i++) board[i][x] = true;
		else for(i=x;i<x+size;i++) board[y][i] = true;
		
		printf("%d %d %d %d\n",y,x,isVertical,size);
	}
		
}

int randomInt(int min, int max) {
	
	return (rand() % (max-min+1))+min;
}
