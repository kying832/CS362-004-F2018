/*
    This program tests the Village card in dominion.c
    The Village card lets the player draw 1 additional card
    and gain 2 actions.

    expected results are no net change in hand count(discard played card, draw 1 additional)
    and 2 extra actions.

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
    int coin_bonus, hand_before, actions_before;

   
    printf("Starting Game for Testing\n");
    initializeGame(2, k, 5, &G);
     printf("**********NOW TESTING THE VILLAGE CARD ***************\n");
    G.whoseTurn = 0;
    hand_before = G.handCount[0];
    actions_before = G.numActions;
    cardEffect(village, 0, 0 ,0, &G, 0, &coin_bonus );
    if(hand_before != G.handCount[0])
        printf("Playing this card should not change # of cards overall\n");

    if(G.numActions - actions_before != 2)
        printf("Playing this card should result in 2 more actions\n");

}