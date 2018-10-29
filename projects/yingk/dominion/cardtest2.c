/*
    This program tests the Adventurer card in dominion.c
    for the Adventurer, the result of playing that card is 2 additional 
    treasure-type cards in hand (bronze, silver, gold)

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
    int treasure_count = 0, coin_bonus, treasure_after = 0;

    printf("Starting Game for Testing\n");
    initializeGame(2, k, 5, &G);
    G.whoseTurn = 0;
    for(int i = 0; i < G.handCount[0]; i++)
    {
        if(G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold)
            treasure_count++;
    }
    cardEffect(adventurer, 0, 0, 0, &G, 0, &coin_bonus);

    for(int i = 0; i < G.handCount[0]; i++)
    {
        if(G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold)
            treasure_after++;
    }
    if(treasure_after - treasure_count != 2 )
        printf("adventurer did not find the 2 additional cards\n");
    else
        printf("adventure passed\n");

}