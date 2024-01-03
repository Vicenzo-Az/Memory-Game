#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int chooseGrid(int grid_view[4][4], int grid[4][4]);

 int checkGrid(int grid_view[4][4], int grid[4][4]);


main(){
	
	int grid_view[4][4], i, j, numale, grid[4][4], q, flag, r, v, gameEnd;
	
	srand((unsigned)time(NULL));
	
	system("color 5f");


//Genarates the grid with random numbers from 1 to 8
	for(i=0; i<4; i++){
		v = 0; 
		for(j=0; v<4; j++){
				
			numale = rand() % 8 + 1;
				
			flag = 0;
				
			for(q=0; q<4; q++){
				for(r=0; r<4; r++){
						
					if(numale == grid[q][r]){
						flag++;
					}
				}
			}		
			if(flag <= 1){
				grid[i][v] = numale;
				v++;
			}
		}
	}
/*	Prints the real grid
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
				
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
*/

//Starts the game
	printf("                   MEMORY GAME\n\n");

	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			grid_view[i][j] = 0;
		}
	}


//Prints the visible grid
	for(i=0; i<4; i++){
		printf("                     ");
	
		for(j=0; j<4; j++){
			printf("%d ", grid_view[i][j]);
		}
		printf("\n");
	}
	
	
//Main gameplay cycle
	do{
	//Choses and verifies the numbers of the grid
		chooseGrid(grid_view, grid);
		
	//Verifies if the game is over
		gameEnd = checkGrid(grid_view, grid);
		
//		printf("\n\n %d \n\n", gameEnd);
		
		if(gameEnd == 0){
			
			printf(" Choose again: \n");
			
			for(i=0; i<4; i++){
				printf("                     ");
			
				for(j=0; j<4; j++){
					printf("%d ", grid_view[i][j]);
				}
				printf("\n");
			}
		}
	}while(gameEnd == 0);
	
	printf("\n\n            CONGRATULATIONS! YOU WON!\n\n");
	
	system("pause");

	return 0;
}

int chooseGrid(int grid_view[4][4], int grid[4][4]){
	
	int backup[4][4], i, j, col1, col2, lin1, lin2;
	
//Creation of a backup grid in case the selected numbers are different
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			backup[i][j] = grid_view[i][j];
		}
	}
	
//Selection of the coordinates of the first number
	printf("\n Choose a column to be shown (1 to 4): ");
	scanf("%d", &col1);
	
	while(col1 > 4 || col1 < 1){
		printf("\n Choose a column to be shown (ONLY from 1 to 4): ");
		scanf("%d", &col1);
	}
		
		
	printf("\n Choose a row to be shown (1 to 4): ");
	scanf("%d", &lin1);
	
	while(lin1 > 4 || lin1 < 1){
		printf("\n Choose a row to be shown (ONLY from 1 to 4): ");
		scanf("%d", &lin1);
	}
		
//Row and column from the visible grid receive the same row and column from the real grid
	grid_view[lin1-1][col1-1] = grid[lin1-1][col1-1];
	
	
	printf("\n");

	for(i=0; i<4; i++){
		printf("                     ");

		for(j=0; j<4; j++){
			printf("%d ", grid_view[i][j]);
		}
		printf("\n");
	}
	
//Selection of the coordinates of the second number
	printf("\n Choose a column to be shown (1 to 4): ");
	scanf("%d", &col2);
	
	while(col2 > 4 || col2 < 1){
		printf("\n Choose a column to be shown (ONLY from 1 to 4): ");
		scanf("%d", &col2);
	}
	
	
	printf("\n Choose a row to be shown (1 to 4): ");
	scanf("%d", &lin2);
	
	while(lin2 > 4 || lin2 < 1){
		printf("\n Choose a row to be shown (ONLY from 1 to 4): ");
		scanf("%d", &lin2);
	}
	
	
	grid_view[lin2-1][col2-1] = grid[lin2-1][col2-1];
	
	
	printf("\n");

	for(i=0; i<4; i++){
		printf("                     ");

		for(j=0; j<4; j++){
			printf("%d ", grid_view[i][j]);
		}
		printf("\n");
	}
	
	
//Checks if the numbers of the first and second coordinates are different
	if(lin1-1 != lin2-1 || col1-1 != col2-1){
		
//In case of the first number being equal to the second, returns visible grid in its current state
		if(grid_view[lin1-1][col1-1] == grid_view[lin2-1][col2-1]){
			printf(" That's right!");
			return grid_view[4][4];
		}
	
//In case the first number selected being different to the second, copies the backup grid into the visible grid and return it
		else{
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					grid_view[i][j] = backup[i][j];
				}
			}
			return grid_view[4][4];
		}
	}
	
	else{
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				grid_view[i][j] = backup[i][j];
			}
		}
		printf(" Type different coordinates.");
		return grid_view[4][4];
	}
}


int checkGrid(int grid_view[4][4], int grid[4][4]){
	
	int i, j, test1, test2;

//Add all numbers of the grid to verify the game over 
	test1 = 0;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			test1 = test1 + grid_view[i][j];
		}
	}
	
	test2 = 0;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			test2 = test2 + grid[i][j];
		}
	}
	
//In case the sum of all the numbers from the visible grid is the same as the sum of the real grid, returns "true"
	if (test1 == test2){
		return 1;
	}
	
	else{
		return 0;
	}
}
