/*This assumes the following

the following insert files are included

#include <dracView.h>
#include <gameView.h>
#include <map.h>
*/

//The objective of this function is to find a space for godalming to move into.
//I'm going to assume here that the map has already been created in the main function
//And that I can call it here.

//This function returns the next possible location.
// If the next location doesnt work due to				illegal move - -1 will be returned
//														Lord Godalming is sitting on Dracula - -2 will be returned.

// int shortestPath(Map g, Location start, Location end, Location path[], Transport trans[], int rail) will be used

Location stalkGodalming(DracView currentView, Map g){
	//Finds where Dracula and lord godalming is going to be
	Location dracula = whereIs(currentView, PLAYER_DRACULA);
	Location hunter1 = whereIs(currentView, PLAYER_LORD_GODALMING);
	
	//Sets variables so you can use shortest Path
	Location path[50];
	Transport trans[50];
	int pathLength;
	
	//Finds the shortestPath between Dracula and Godalming
	pathLength = shortestPath(g, dracula, hunter1, path, trans, 0);
	
	//Checks if pathLength is greater than 1, that is if Lord_Godalming isn't sitting
	//on Dracula
	if(pathLength >= 1){
		location nextMove = path[1];
	} else {
		return -2;
	}
	
	//Checks nextMove to see if its in the trail
	for(i = 0; i <= 5; i++){
		if (nextMove == currentView -> trailLocs[i]) return -1;
	}
	
	//Next move is an accurate move, so we can use that now
	return nextMove;
}