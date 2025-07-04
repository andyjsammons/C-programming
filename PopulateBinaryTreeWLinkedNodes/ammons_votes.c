#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct nominee_struct{
	char name[50];
	int votes = 0;
	int rank;
} nominee;


int main(){
	
	nominee nominees[38];

	FILE* inf = fopen("class.txt","r");
	int nom;
	int Rank[38];
	
	char* names;
	
	names = (char*)malloc(sizeof(char[50]));
	
	for (int i = 0; i < 38; i++){
		
	
		fgets(nominees[i].name, 50,inf );
		nominees[i].rank = Rank[i] = i+1;
		
		if (nominees[i].name[strlen(nominees[i].name)] == '\n'){
			nominees[i].name[strlen(nominees[i].name)] = '\0';
		}
		
	}
	
	while (1 != 0){
		for (int i = 0; i < 38; i++){
		printf("Rank: %-15dVotes:%-15d %s",Rank[i],nominees[i].votes,nominees[i].name);
		}
		printf("Vote for? (0 to quit) ");
	
		scanf("%d",&nom);
		if (nom == 0){
			break;
		}
		else if (nom <= 38){
			
	
			for (int p = 0; p < 38; p++){
				if ( nom == nominees[p].rank ){
					nominees[p].votes ++;
			
					nominee temp;
					int max;
			
					for (int i = 0; i < 38; i++){
						max = i;
						for (int j = i + 1; j < 38; ++j) {
  
							if (nominees[j].votes > nominees[max].votes) {
								max = j;
							}
						}
						temp = nominees[i];
						nominees[i] = nominees[max];
						nominees[max] = temp;
						for (int k = 0; k < 38; k++){
							nominees[k].rank = Rank[k];
						}
						
					}
					
					break;
				}

			}
			
		}
		else break;
		
	}
		
		
	
	


	
	return 0;
}



	