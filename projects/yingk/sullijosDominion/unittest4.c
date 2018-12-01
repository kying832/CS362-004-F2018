/*
    This program tests the numHandCards function in dominion.c
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
    printf("Starting Game for Testing\n");

    initializeGame(2, k, 5, &G);

    printf("*********NOW TESTING FUNCTION numHandCards()  *********** \n");
    printf("Game should start with 5 cards in hand\n");

    ret_val = numHandCards(&G);
    if(ret_val != 5)
        printf("got %d cards instead.\n", ret_val);
    else
        printf("Game correctly starts w/ 5 cards in hand\n");

}
