// hunter.c
// Implementation of your "Fury of Dracula" hunter AI

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Game.h"
#include "HunterView.h"
	static void hunterViewPrint (HunterView gameView);

void decideHunterMove(HunterView gameState)
{
     srand (time(NULL));
	int round = giveMeTheRound(gameState);
    int player = whoAmI(gameState);
	int numLocations = NUM_MAP_LOCATIONS;
    LocationID *possibleMoves 
	possibleMoves = (LocationID *)(malloc(sizeof(LocationID)*NUM_MAP_LOCATIONS));
	int bestMove = 0;
    //int health = howHealthyIs(gameState, player);
    
  
	hunterViewPrint (gameState);

	//ROUND 0
    if(round == 0){
        if(player == PLAYER_LORD_GODALMING) { 
            registerBestPlay("SR", "LG SR"); //godalming starts at Saragossa
        } else if (player == PLAYER_DR_SEWARD) {
            registerBestPlay("MU", "DS MU"); //seward starts at Munich
        } else if(player == PLAYER_VAN_HELSING) {
            registerBestPlay("SZ", "VH SZ"); //helsing starts at Szeged
        } else if(player == PLAYER_MINA_HARKER) {
            registerBestPlay("PA", "MH PA"); //harker starts at Paris
        }
    } else {
		int i = 0; // moved this line up
		
		for (i = 0;, i < sizeOfArray; i++){
			possibleMoves[i] = -1;
		} //Instead of setting unused values to -1 earlier, I set them here instead.
		
		//Fills possibleMoves with places the hunter can go
		possibleMoves = whereCanIgo(gameState, &numLocations, 1, 1, 1);
		
		//Finds the location of the hunter
		int location = whereIs (gameState, player);
		
		/*for (i = 0; i < NUM_MAP_LOCATIONS - 1; i++) {
			if (possibleMoves [i] == 0 || possibleMoves [i] > NUM_MAP_LOCATIONS) {
				possibleMoves [i] = -1;
			}
			printf ("%d ", possibleMoves [i] );
		} old code not used anymore. I replaced it at the top	*/
		
		//int j = 0 - Removed since an extra counter is not required since we
		//placed it in a for loop
		
		for (i = 0; i < NUM_MAP_LOCATIONS; i++) {
			if (possibleMoves [i] != location) {
				bestMove = possibleMoves[i];
				registerBestPlay(idToAbbrev(bestMove), ""); 
				return;
			}
			i++;
		}

		free (possibleMoves);
    }
	

}

static void hunterViewPrint(HunterView gameView) {
        printf ("\n================= GAME VIEW VALUES ====================\n");
        printf ("The current round is %d\n", giveMeTheRound (gameView));
		printf ("The current score is %d\n", giveMeTheScore(gameView));
        printf ("Lord Godalming HP is %d\n", howHealthyIs (gameView, PLAYER_LORD_GODALMING));
        printf ("Dr Seward HP is %d\n", howHealthyIs (gameView, PLAYER_DR_SEWARD));
        printf ("Van Helsing HP is %d\n", howHealthyIs (gameView, PLAYER_VAN_HELSING));
        printf ("Mina Harker HP is %d\n", howHealthyIs (gameView, PLAYER_MINA_HARKER));
        printf ("Dracula HP is %d\n\n", howHealthyIs (gameView, PLAYER_DRACULA));
		
		int trail [6];
		
        int i = 0;
        printf ("Lord Godalming's trail is: \n");
		
		giveMeTheTrail (gameView, PLAYER_LORD_GODALMING, trail);
		
        for (i = 0; i < TRAIL_SIZE; i++) {
                printf ("%d ", trail[i]);
        }
        printf ("\n\n");
		
		        printf ("Dr Seward's trail is: \n");
		
		giveMeTheTrail (gameView, PLAYER_DR_SEWARD, trail);
		
        for (i = 0; i < TRAIL_SIZE; i++) {
                printf ("%d ", trail[i]);
        }
        printf ("\n\n");        
		
		printf ("Van Helsing's trail is: \n");
		
		giveMeTheTrail (gameView, PLAYER_VAN_HELSING, trail);
		
        for (i = 0; i < TRAIL_SIZE; i++) {
                printf ("%d ", trail[i]);
        }
        printf ("\n\n");        printf ("Mina Harker's trail is: \n");
		
		giveMeTheTrail (gameView, PLAYER_MINA_HARKER, trail);
		
        for (i = 0; i < TRAIL_SIZE; i++) {
                printf ("%d ", trail[i]);
        }
        printf ("\n\n");        printf ("Dracula's trail is: \n");
		
		giveMeTheTrail (gameView, PLAYER_DRACULA, trail);
		
        for (i = 0; i < TRAIL_SIZE; i++) {
                printf ("%d ", trail[i]);
        }
        printf ("\n\n");
       
       
       
        printf ("=======================================================\n\n");
 
}