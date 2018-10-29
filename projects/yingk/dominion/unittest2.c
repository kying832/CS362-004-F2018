/*
    This program tests the isGameOver function in dominion.c
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

    printf("*********NOW TESTING FUNCTION isGameOver(struct gameState * state)  *********** \n");
    printf("Case 1: stack of province cards empty\n");
    G.supplyCount[province] = 0;
    ret_val = isGameOver(&G);
    if(ret_val != 1)
        printf("FAILED CASE 1\n");


    printf("Case 2: 3 supply piles are 0\n");
    //re-initialize game
    initializeGame(2, k, 5, &G);
    //set all supply piles to 0
    for(int i = 0; i < 25; i++)
    {
        G.supplyCount[i] = 0;

    }
    ret_val = isGameOver(&G);
    if(ret_val != 1)
        printf("FAILED CASE 2\n");
    printf("Case 3: Neither of above, game is not yet over\n");
    //reset game
    initializeGame(2, k, 5, &G);
    ret_val = isGameOver(&G);
    if(ret_val != 0)
        printf("FAILED CASE 3\n");

    return 0;

}