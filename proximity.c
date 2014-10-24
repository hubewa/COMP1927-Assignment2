/*This assumes the following

the following insert files are inserted

#include <dracView.h>
#include <gameView.h>
*/

//Proximity

//So this determines the shortest amount of distance between Dracula and the other hunters
//int *distance is a pointer to an array which is defined 

//

void proximity(int *distance, dracView currentView){
	Location dracula = whereIs(currentView, PLAYER_DRACULA);
	Location hunter1 = whereIs(currentView, PLAYER_LORD_GODALMING);
	Location hunter2 = whereIs(currentView, PLAYER_DR_SEWARD);
	Location hunter3 = whereIs(currentView, PLAYER_VAN_HELSING);
	Location hunter4 = whereIs(currentView, PLAYER_MINA_HARKER);

	int path[20];
	int trans[20];
	
	distance[0] = shortestPath(dracula, hunter1, path, trans);
	distance[1] = shortestPath(dracula, hunter2, path, trans);
	distance[2] = shortestPath(dracula, hunter3, path, trans);
	distance[3] = shortestPath(dracula, hunter4, path, trans);
}