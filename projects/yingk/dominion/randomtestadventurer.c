//this program will randomly test the Adventurer card
/*
    expected results are:
     2 additional treasure-type cards in hand (bronze, silver, gold)

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int treasure_count = 0, coin_bonus, treasure_after = 0;
    int player, c1, c2, c3, hp;
    int result, card;
    //set up random trials
    for(int trials = 0; trials < 2000; trials++)
    {
        treasure_count = 0;
        treasure_after = 0;
    //initialize game
        initializeGame(2, k, 1, &G);
        //randomize relevant inputs
        player = rand() % 2;
        G.whoseTurn = player;
        
        G.handCount[player] = rand() % MAX_HAND;
        G.deckCount[player] = rand() % MAX_DECK; //- G.handCount[player];//rand() % MAX_HAND;
    //      printf("DECK COUNT: %d\n", G.deckCount[player]);
        G.discardCount[player] = rand() % MAX_DECK;
        //generate random hand
        for(int i = 0; i < G.handCount[player]; i++)
        {
            card = rand() % 27;
            G.hand[player][i] = card;
            if(card == gold || card == silver || card == copper)
                treasure_count++;
        }
         //randomize cardEffect input parameters within reasonable bounds
        c1 = rand() % 3;
        c2 = rand() % 3;
        c3 = rand() % 3;
        hp = rand() % MAX_HAND;    

        //execute adventurer card
        result = cardEffect(adventurer, c1, c2, c3, &G, hp, &coin_bonus);
        //probe for results
        if(result != 0)
            printf("cardEffect did not return 0\n");
        //check if correct # of treasure cards are found
        
        for(int i = 0; i < G.handCount[player]; i++)
        {
            card = G.hand[player][i];
            if(card == gold || card == silver || card == copper)
                treasure_after++;   
        }
        if(treasure_after - treasure_count != 2)
            printf("incorrect # of treasure cards added to hand\n");
    }   //end trials for loop

    printf ("ADVENTURER TEST COMPLETE\n");
}