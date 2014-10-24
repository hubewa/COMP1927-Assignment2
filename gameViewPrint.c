static void gameViewPrint (GameView gameView) {
	printf ("\n================= GAME VIEW VALUES ====================\n");
	printf ("The current round is %d\n", gameView->currentRound); 
    printf ("The current turn is %d\n", gameView->currentTurn); 
    printf ("The current score is %d\n", gameView->currentScore); 
	printf ("Lord Godalming HP is %d\n", gameView->lordGodalmingHP); 
	printf ("Dr Seward HP is %d\n", gameView->drSewardHP); 
	printf ("Van Helsing HP is %d\n", gameView->vanHelsingHP); 
	printf ("Mina Harker HP is %d\n", gameView->minaHarkerHP); 
	printf ("Dracula HP is %d\n\n", gameView->draculaHP); 
	int i = 0;
	printf ("Lord Godalming's trail is: \n");
	for (i = 0; i < TRAIL_SIZE; i++) {
		printf ("%d ", gameView->lordGodalming[i]);
	}
	printf ("\n\n");
	printf ("Dr Sewards's trail is: \n");
	for (i = 0; i < TRAIL_SIZE; i++) {
		printf ("%d ", gameView->drSeward[i]);
	}
	printf ("\n\n");
	printf ("Van Helsing's trail is: \n");
	for (i = 0; i < TRAIL_SIZE; i++) {
		printf ("%d ", gameView->vanHelsing[i]);
	}
	printf ("\n\n");
	printf ("Mina Harker's trail is: \n");
	for (i = 0; i < TRAIL_SIZE; i++) {
		printf ("%d ", gameView->minaHarker[i]);
	}
	printf ("\n\n");	
	printf ("Dracula's trail is: \n");
	for (i = 0; i < TRAIL_SIZE; i++) {
		printf ("%d ", gameView->dracula[i]);
	}
	printf ("\n\n");	
	
	if (gameView->lordGodalmingLocation != -1) {
		printf ("Lord Godalming's location is %s\n", idToName(gameView->lordGodalmingLocation));
	}
	if (gameView->drSewardLocation != -1) {
		printf ("Dr Seward's location is %s\n", idToName(gameView->drSewardLocation));
	}

	if (gameView->vanHelsingLocation != -1) {
		printf ("Van Helsing's location is %s\n", idToName(gameView->vanHelsingLocation));
	}
	
	if (gameView->minaHarkerLocation != -1) {
		printf ("Mina Harker's location is %s\n", idToName(gameView->minaHarkerLocation));
	}
	
	if (gameView->draculaLocation != -1) {
		printf ("Dracula's location is %s\n", idToName(gameView->draculaLocation));
	}
	
	printf ("=======================================================\n\n");

}`