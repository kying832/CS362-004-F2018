/*
    This program tests the Sea Hag card in dominion.c
    The Sea Hag when played compels all other players to discard their top card of their deck
    and gain 1 curse card in its place

    expected results are no net change in deck count(discard played card, gain 1 additional)
    and all other players have a top curse card.

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
    int coin_bonus, deck_before, curse_before = 0, curse_before_1 = 0,  curse_after = 0 , curse_after_1 = 0;

  
    printf("Starting Game for Testing\n");
    initializeGame(2, k, 5, &G);
    printf("Now Testing Sea Hag Card\n");
    G.whoseTurn = 1;
    deck_before = G.deckCount[0];
    for(int i = 0 ; i <  G.deckCount[0]; i++)
    {
        if(G.deck[0][i] == curse)
            curse_before++;

    }
    cardEffect(sea_hag, 0, 0, 0, &G, 0, &coin_bonus);
    if(deck_before != G.deckCount[0])
        printf("The net deck count should be unchanged\n");
    
    for(int i = 0 ; i <  G.deckCount[0]; i++)
    {
        if(G.deck[0][i] == curse)
            curse_after++;

    }
    if((curse_after - curse_before) != 1)
    {
        printf("The curse card hasn't been added.\n");
    }
    if(G.deck[0][G.deckCount[0] - 1]   != curse)
    {
        printf("The curse card hasn't been placed at the top of the deck\n");
    }
}