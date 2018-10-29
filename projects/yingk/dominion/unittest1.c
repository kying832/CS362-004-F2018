/*
    This program tests the drawCard function in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int ret_val, before_draw;
    printf("Starting Game for Testing\n");

    initializeGame(2, k, 5, &G);

    printf("*********NOW TESTING FUNCTION drawCard(int player, struct gameState * state)  *********** \n");
    printf("case 1: deck is empty\n");
    before_draw = G.handCount[0];
    G.deckCount[0] = 0;

    ret_val = drawCard(0, &G);
    if((before_draw + 1) != G.handCount[0])
        printf("FAILED EMPTY DECK CASE\n");

    printf("case 2: deck is non-empty\n");
    //re-initialize game
    initializeGame(2, k, 5, &G);
    before_draw = G.handCount[0];
    ret_val = drawCard(0, &G);
    
    if((before_draw + 1) != G.handCount[0])
        printf("FAILED NON-EMPTY DECK CASE\n");

    return 0;




}