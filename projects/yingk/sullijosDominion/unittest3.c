/*
    This program tests the compare function in dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <limits.h>


int main()
{
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int ret_val;
    int x, y;
    printf("Starting Game for Testing\n");

    initializeGame(2, k, 5, &G);
    printf("*********NOW TESTING FUNCTION compare  *********** \n");
    printf("case 1: a > b, a > 0 and b > 0\n");
    x = INT_MAX;
    y = 5;
    ret_val = compare(&x, &y);
    if(ret_val < 1)
        printf("Failed Case 1\n");
    
    printf("case 2, a < b, a > 0 and b > 0\n");
    ret_val = compare(&y, &x);
    if(ret_val > -1)
        printf("Failed Case 2\n");
    
    printf("case 3, a = b, a > 0, b > 0");
    x = 5;
    ret_val = compare(&x, &y);
    if(ret_val != 0 )
        printf("Failed case 3\n");
    
    //printf("case 4: a > b, ");


    return 0;
}