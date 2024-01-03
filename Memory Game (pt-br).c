#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int chooseGrid(int grid_view[4][4], int grid[4][4]);

 int checkGrid(int grid_view[4][4], int grid[4][4]);


main(){
	
	int grid_view[4][4], i, j, numale, grid[4][4], q, flag, r, v, gameEnd;
	
	srand((unsigned)time(NULL));
	
	system("color 5f");


//Gera o grid com n�meros aleat�rios de 1 a 8
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
/*	Imprime o grid verdadeiro:
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
				
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
*/

//Inicia o jogo
	printf("                 JOGO DA MEMORIA\n\n");

	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			grid_view[i][j] = 0;
		}
	}


//Imprime o grid vis�vel			
	for(i=0; i<4; i++){
		printf("                     ");
	
		for(j=0; j<4; j++){
			printf("%d ", grid_view[i][j]);
		}
		printf("\n");
	}
	
	
//Ciclo de gameplay principal
	do{
	//Escolhe os n�meros da grade e faz a sua verifica��o
		chooseGrid(grid_view, grid);
		
	//Verifica se o jogo j� terminou
		gameEnd = checkGrid(grid_view, grid);
		
//		printf("\n\n %d \n\n", gameEnd);
		
		if(gameEnd == 0){
			
			printf(" Escolha novamente: \n");
			
			for(i=0; i<4; i++){
				printf("                     ");
			
				for(j=0; j<4; j++){
					printf("%d ", grid_view[i][j]);
				}
				printf("\n");
			}
		}
	}while(gameEnd == 0);
	
	printf("\n\n              PARABENS! VOCE GANHOU!\n\n");
	
	system("pause");

	return 0;
}

int chooseGrid(int grid_view[4][4], int grid[4][4]){
	
	int backup[4][4], i, j, col1, col2, lin1, lin2;
	
//Cria��o de um grid de backup para caso os n�meros selecionados forem diferentes
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			backup[i][j] = grid_view[i][j];
		}
	}
	
//Sele��o das coordenadas do primeiro n�mero
	printf("\n Escolha uma coluna para ser desvirada(de 1 a 4): ");
	scanf("%d", &col1);
	
	while(col1 > 4 || col1 < 1){
		printf("\n Escolha uma coluna para ser desvirada(SOMENTE de 1 a 4): ");
		scanf("%d", &col1);
	}
		
		
	printf("\n Escolha uma linha para ser desvirada(de 1 a 4): ");
	scanf("%d", &lin1);
	
	while(lin1 > 4 || lin1 < 1){
		printf("\n Escolha uma linha para ser desvirada(SOMENTE de 1 a 4): ");
		scanf("%d", &lin1);
	}
		
//Linha e coluna do grid vis�vel recebem o n�mero da mesma linha e coluna do grid verdadeiro
	grid_view[lin1-1][col1-1] = grid[lin1-1][col1-1];
	
	
	printf("\n");

	for(i=0; i<4; i++){
		printf("                     ");

		for(j=0; j<4; j++){
			printf("%d ", grid_view[i][j]);
		}
		printf("\n");
	}
	
//Sele��o das coordenadas do segundo n�mero
	printf("\n Escolha uma coluna para ser desvirada(de 1 a 4): ");
	scanf("%d", &col2);
	
	while(col2 > 4 || col2 < 1){
		printf("\n Escolha uma coluna para ser desvirada(SOMENTE de 1 a 4): ");
		scanf("%d", &col2);
	}
	
	
	printf("\n Escolha uma linha para ser desvirada(de 1 a 4): ");
	scanf("%d", &lin2);
	
	while(lin2 > 4 || lin2 < 1){
		printf("\n Escolha uma linha para ser desvirada(SOMENTE de 1 a 4): ");
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
	
	
//Verifica se a sele��o das casas n�o foi repetida na primeira e na segunda sele��o	
	if(lin1-1 != lin2-1 || col1-1 != col2-1){
		
//Caso o primeiro n�mero selecionado for igual ao segundo ser� retornado o grid vis�vel em seu estado atual
		if(grid_view[lin1-1][col1-1] == grid_view[lin2-1][col2-1]){
			printf(" Voce acertou!");
			return grid_view[4][4];
		}
	
//Caso o primeiro n�mero selecionado seja diferente do segundo o grid de backup ser� copiado ao grid vis�vel que ser� retornado
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
		printf(" Digite casas diferentes.");
		return grid_view[4][4];
	}
}
	


int checkGrid(int grid_view[4][4], int grid[4][4]){
	
	int i, j, test1, test2;

//Adi��o de todos n�meros do grid para se fazer a verifica��o de fim de jogo
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
	
//Caso a adi��o de todos n�meros do grid vis�vel seja igual a adi��o de todos n�meros do grid verdadeiro, ser� retornado "true"
	if (test1 == test2){
		return 1;
	}
	
	else{
		return 0;
	}
}
