/*I'll assume the following functions are included

#include <dracView.h>
#include <gameView.h>

*/

/* This function checks if we have been spotted
by the hunters 

If the hunters go along any part of the chain, then we set an alert 

And the function name is a world of Tanks reference because why not

The alert array contains four  things (in this order) - alert status, location of closest hunter,
how many players are on the trail and who is the closest player on the trail.*/

void sixthSense(int *alert,  dracView currentView){
	Location hunters[4]  // Sets an array for the location of the hunters
	
	
	//Finds where all the hunters are
	Location hunter[0] = whereIs(currentView, PLAYER_LORD_GODALMING);
	Location hunter[1] = whereIs(currentView, PLAYER_DR_SEWARD);
	Location hunter[2] = whereIs(currentView, PLAYER_VAN_HELSING);
	Location hunter[3] = whereIs(currentView, PLAYER_LORD_GODALMING);
	
	//If Dracula has been spotted, spotted = 1, else spotted = 0
	int spotted = 0;
	
	//Set once the spotted counter has been set
	Location closestLocation;
	int closestPerson;
	int huntersOnTrail = 0;
	
	//Runs through both arrays to see if hunters have spotted dracula
	for (i == 0; i <= 5; i++){
		for (j == 0, j <= 3; j++){
			if (hunter[j] == currentView->trailLocs[i]){
				//If Dracula hasn't previously been spotted, do this and set the
				//closest player locations
				if(spotted == 0){
					spotted = 1;
					closestLocation = hunter[j];
					closestPlayer = j;
				}
				huntersOnTrail++;
			}
		}
	}
	
	//Sets the alert array
	alert[0] = spotted;
	alert[1] = closestLocation;
	alert[2] = closestPlayer;
	alert[3] = huntersOnTrail;
}