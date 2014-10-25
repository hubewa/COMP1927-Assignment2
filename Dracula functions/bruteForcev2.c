// Changes made - line 24 - nextMove is set to -1
// line 41 - get rid of the proximity function for now
// line 42 - set the compare constant to an arbitarily high number - because logic fails happened before

LocationID bruteForce(DracView currentView, Map g){
        int distance[4];
        int connections[50];
        int *numLocations;
        int k = 50;
        int *array;
        int trail[6];
       
       
        dracViewPrint (currentView);
       
        giveMeTheTrail(currentView, PLAYER_LORD_GODALMING, trail);
       
        numLocations = &k;
       
        int i = 0;
        int j = 0;
        int l = 0;
       
        int tempDistance = 0;
        int compareDistance = 0;
        LocationID nextMove = -1;
        int isLegalMove = 1;
       
        //Required for brute force
        int path[20];
        int trans[20];
       
        //Finds where Dracula is
        LocationID dracula = whereIs(currentView, PLAYER_DRACULA);
        LocationID hunter1 = whereIs(currentView, PLAYER_LORD_GODALMING);
       
        //Sets all of the values in connections to -1
        for (i = 0; i <= 50; i++) connections[i] = -1;
       
        //Finds the distance between Dracula and all of the other hunters
        //proximity(distance, currentView, dracula); We'll use this later not for now
        compareDistance = 50; //Set an arbitarily big enough number for compareDistance
       
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
