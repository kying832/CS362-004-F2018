/*
    This program tests the Smithy card in dominion.c
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
    int ret_val;
    int before_hand_count_0,before_hand_count_1, coin_bonus;

    printf("Starting Game for Testing\n");

    initializeGame(2, k, 5, &G);
    before_hand_count_0 = G.handCount[0];
    before_hand_count_1 = G.handCount[1];
    printf("*********NOW TESTING SMITHY CARD  *********** \n");
    ret_val = cardEffect(smithy, 0, 0, 0, &G, 0, &coin_bonus);

    if((before_hand_count_0 != G.handCount[0] - 2) || (before_hand_count_1 != G.handCount[1] - 2))
        printf("Smithy card is not properly drawing 3 cards\n");

}
