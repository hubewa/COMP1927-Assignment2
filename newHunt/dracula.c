// dracula.c
// Implementation of your "Fury of Dracula" Dracula AI

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Game.h"
#include "DracView.h"
#include "Map.h"

static void dracViewPrint (DracView gameView);
LocationID bruteForce(DracView currentView, Map g);


void decideDraculaMove(DracView gameState)
{
	int location = 0;
		
	Map g = newMap ();
	
	
	if (giveMeTheRound (gameState) == 0) {
		registerBestPlay (idToAbbrev(13),"");
	} else {
		location = bruteForce (gameState, g);
		registerBestPlay (idToAbbrev(location),"");
	}
	
	printf ("The value of location is %d\n", location);
} 
/*This assumes the following

the following insert files are included

#include <dracView.h>
#include <gameView.h>
#include <map.h>
*/

LocationID bruteForce(DracView currentView, Map g){
	LocationID nextMove = 0;
	int trail[6];
	
		int i =0 ;
		
			int *array;
			int *seaArray;
				int *numLocations;
					int k = 50;

	
	numLocations = &k;


	dracViewPrint (currentView);
	
	giveMeTheTrail(currentView, PLAYER_DRACULA, trail); 
	
	int connections[NUM_MAP_LOCATIONS];

	//Sets all of the values in connections to -1
	//for (i = 0; i < NUM_MAP_LOCATIONS; i++) connections[i] = -1;
	
	//Where can Dracula travel by road
	
	array = malloc (sizeof (int) * NUM_MAP_LOCATIONS);
	
	array = whereCanIgo(currentView, numLocations, 1, 0);
	

	
		
	
	
		int l = 0;
	for (l = 0; l < NUM_MAP_LOCATIONS; l++) {
		if (array [l] == 0) {
			connections [l] = -1;
		} else {
			connections [l] = array[l];
		}
		printf ("%d ", connections [l]);
	}
	
	printf ("\n");
	

	
		int tempDistance = 0;
			int compareDistance = 	50;

				int isLegalMove = 1;



		//Finds where Dracula is
	LocationID hunter1 = whereIs(currentView, PLAYER_LORD_GODALMING);
	
		int path[20];
	int trans[20];
	
		int j;
	
	i = 0;
	if(connections[0] != -1){
		while(connections[i] != -1){
			//Finds the shortest distance and then puts it on.
			tempDistance = shortestPath(g, connections[i], hunter1, path, trans);
			
			printf ("The value of tempDistance is %d\n", tempDistance);
			printf ("The value of compareDistance is %d\n", compareDistance);
			printf ("Comparing %d to %d\n", connections [i], hunter1);

			
			
			if(compareDistance > tempDistance){
				for(j = 0; j <= 5; j++){
					if (trail[j] == connections[i]) {
						isLegalMove = 0;
					}	
				}
				if(isLegalMove == 1){//If its a legal move change the following.
					compareDistance = tempDistance;
					nextMove = connections[i];
				} else {
					isLegalMove = 1; // Resets the isLegalMove flag
				}
			}
			i++;
		}
	}

	int z = 0;
	int x = 0;
	int y = 0;
	isLegalMove = 1;
	
	seaArray = malloc (sizeof (int) * NUM_MAP_LOCATIONS);
	
	if (nextMove == 0) { // Run out of land options, go to sea
		printf ("Hello we're going to sea!\n");
		seaArray = whereCanIgo(currentView, numLocations, 0, 1);
		
		for (y = 0; y < NUM_MAP_LOCATIONS; y++) {
			printf ("%d ", seaArray [y]);
		}
		
		while (seaArray [z] != 0) {
			for (x = 0; x < TRAIL_SIZE; x++) {
				if (seaArray [z] == trail [x]) {
					isLegalMove = 0;
				}
			}
			z++;
		}
		if (x == TRAIL_SIZE) {
			printf ("The value of isLegalMove is %d\n", isLegalMove);
			if (isLegalMove == 0) { // Means we have to hide or double back
				nextMove = DOUBLE_BACK_1;
				printf ("We are doubling back!\n");
				return nextMove;
			}
		
			printf ("The value of nextMove at sea is %d\n", seaArray[z -1]);
			nextMove = seaArray [z -1];
			return nextMove;
		}
		
	}
	

	
	printf ("The value of next move is %d\n", nextMove);
	
	return nextMove;
	
}




static void dracViewPrint (DracView gameView) {
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