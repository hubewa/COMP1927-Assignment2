/*This assumes the following

the following insert files are inserted

#include <dracView.h>
#include <gameView.h>
*/

//Proximity

//So this determines the shortest amount of distance between Dracula and the other hunters
//int *distance is a pointer to an array which is defined to contain data about the distance
//between the hunters and the player. So, prior to this, the distance array must be 4 long

//

//

void proximity(int *distance, dracView currentView, Location dracula){
	Location dracula = whereIs(currentView, PLAYER_DRACULA);
	Location hunter1 = whereIs(currentView, PLAYER_LORD_GODALMING);
	Location hunter2 = whereIs(currentView, PLAYER_DR_SEWARD);
	Location hunter3 = whereIs(currentView, PLAYER_VAN_HELSING);
	Location hunter4 = whereIs(currentView, PLAYER_MINA_HARKER);

	int path[20];
	int trans[20];
	
	//Determines how many moves a hunter is from dracula.
	distance[0] = shortestPath(dracula, hunter1, path, trans, 1);
	distance[1] = shortestPath(dracula, hunter2, path, trans, 1);
	distance[2] = shortestPath(dracula, hunter3, path, trans, 1);
	distance[3] = shortestPath(dracula, hunter4, path, trans, 1);
}