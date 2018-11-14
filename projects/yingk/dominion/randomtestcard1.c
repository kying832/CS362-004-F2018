//this program will randomly test the Village card
//expected results are no net change in hand count
//and 2 extra actions.
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
    int coin_bonus, handSize, actions;
    int c1, c2, c3, hp, player;
    int result;
    printf("starting game for testing\n");

    for(int tries = 0; tries < 2000; tries++)
    {
        initializeGame(2, k, 1, &G);
    //fill the struct up with garbage
    /*
        it seems that randomizing the entire struct for card effects causes 
        undefined behavior for other card function dependencies.  For now, only
        the parameters for the card's direct inputs and outputs will be randomized.
        for (int i = 0; i < sizeof(struct gameState); i++) {

            ((char*)&G)[i] = floor(Random() * 256);
        }
     */   
    //fill the relevant struct fields with reasonable data
    player = rand() % 2;
    G.whoseTurn = player;
    
    G.handCount[player] = rand() % MAX_HAND;
    G.deckCount[player] = rand() % MAX_DECK - rand() % MAX_HAND;//G.handCount[player];
    G.discardCount[player] = rand() % MAX_DECK;
    //randomize cardEffect input parameters within reasonable bounds
    c1 = rand() % 3;
    c2 = rand() % 3;
    c3 = rand() % 3;
    hp = rand() % MAX_HAND;
    
    //store data before card effect is called
    actions = G.numActions;
    handSize = G.handCount[player];
    
    //use the village card
    result = cardEffect(village, c1, c2, c3, &G, hp, &coin_bonus);
    //probe for effects
    if(result != 0)
    {
        printf("CardEffect did not return 0\n");
    }
    if(G.numActions - actions != 2)
    {
        printf("Actions should be increased by 2\n");
    }
    if(G.handCount[player] != handSize)
    {
        printf("Hand count is mismatched\n");
    }

    }
    printf("DONE WITH VILLAGE CARD TESTS\n");
}