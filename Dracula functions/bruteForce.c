/*This assumes the following

the following insert files are included

#include <dracView.h>
#include <gameView.h>
#include <map.h>
*/

Location bruteForce(DracView currentView, Map g){
	int distance[4];
	int connections[50];
	int *numLocations;
	
	int i;
	int j;
	
	int tempDistance;
	int compareDistance;
	Location nextMove;
	int isLegalMove;
	
	//Required for brute force
	int path[20];
	int trans[20];
	
	//Finds where Dracula is
	Location dracula = whereIs(currentView, PLAYER_DRACULA);
	
	//Sets all of the values in connections to -1
	for (i = 0; i <= 50; i++) connections[i] = -1;
	
	//Finds the distance between Dracula and all of the other hunters
	proximity(distance, currentView, dracula);
	compareDistance = distance[0];
	
	//Where can Dracula travel by road
	connections = whereCanIGo(currentView, numLocations, 1, 0);
	
	i = 0;
	if(connections[0] != -1){
		while(connections[i] != -1){
			//Finds the shortest distance and then puts it on.
			tempDistance = shortestPath(connections[i], hunter1, path, trans, 0);
			if(compareDistance > tempDistance){
				for(j = 0, j <= 5, j++){
					if(currentView->trailLocs[j] == connections[i]) isLegalMove = 0;
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
	return nextMove;
	
}