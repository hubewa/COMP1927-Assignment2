//Changes made: added history array
// placed history in giveMeTheTrail instead of trail - line 18 

LocationID bruteForce(DracView currentView, Map g){
	int distance[4];
	int connections[50];
	int *numLocations;
	int k = 50;
	int *array;
	LocationID history[366];
	LocationID trail[6];
	
	int i = 0;
	int j = 0;
	int l = 0;
	
	// Changes happened here
	
	dracViewPrint (currentView);
	////////////////////////////////
	// Changes happened here
	giveMeTheTrail(currentView, PLAYER_LORD_GODALMING, history);
	
	//Move first 6 values of history into trail
	for(i = 0; i <= 5; i++){
		trail[i] = history[i];
	}
	
	//We then try to find the real trail
	
	
	///////////////////////////////////////
	
	numLocations = &k;

	
	int tempDistance;
	int compareDistance;
	LocationID nextMove;
	int isLegalMove;
	
	//Required for brute force
	int path[20];
	int trans[20];
	
	//Finds where Dracula is
	LocationID dracula = whereIs(currentView, PLAYER_DRACULA);
	LocationID hunter1 = whereIs(currentView, PLAYER_LORD_GODALMING);
	
	//Sets all of the values in connections to -1
	for (i = 0; i <= 50; i++) connections[i] = -1;
	
	//Finds the distance between Dracula and all of the other hunters
	proximity(distance, currentView, dracula);
	compareDistance = distance[0];
	
	//Where can Dracula travel by road
	array = whereCanIgo(currentView, numLocations, 1, 0);
	
	for (l = 0; l < 50; l++) {
		connections [l] = array[l];
	}
	
	i = 0;
	if(connections[0] != -1){
		while(connections[i] != -1){
			//Finds the shortest distance and then puts it on.
			tempDistance = shortestPath(g, connections[i], hunter1, path, trans);
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
	
	return nextMove;
	
}