//this program will randomly test the salvager card

/*
    expected results are
    Gain 1 extra buy
    Trash 1 card from hand
    net card exchange should be 1 in trash, 1 in played pile
    gain coins == coin cost of trashed card.


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
    int coin_bonus, coin_pre, coin_post, buys_pre, buys_post, discard_pre, discard_post;
    int c1, c2, c3, hp, player, coin_cost;
    int result, card;
    printf("starting game for testing\n");

    for(int tries = 0; tries < 2000; tries++)
    {
        //initialize game
        initializeGame(2, k, 1, &G);
        //randomize relevant values for salvager card
        player = rand() % 2;
        G.whoseTurn = player;
        do{
        G.handCount[player] = rand() % MAX_HAND;
        } while(G.handCount[player] == 0);
        G.deckCount[player] = rand() % MAX_DECK; //- G.handCount[player];//rand() % MAX_HAND;
    //      printf("DECK COUNT: %d\n", G.deckCount[player]);
        G.discardCount[player] = rand() % MAX_DECK;
        G.numBuys = rand() % 256;   //randomize buy count
        G.coins = rand() % 256;     //randommize coincount
        //generate random hand
        for(int i = 0; i < G.handCount[player]; i++)
        {
            card = rand() % 27;
            G.hand[player][i] = card;
        }
         //randomize cardEffect input parameters within reasonable bounds
        hp = rand() % MAX_HAND;
        do{       
            
            c1 = rand() % G.handCount[player];
        } while (c1 == hp);
        c2 = rand() % 3;
        c3 = rand() % 3;
        
        G.hand[player][hp] = salvager;
        //record pre-card play state
        buys_pre = G.numBuys;  
        coin_pre = G.coins;
        discard_pre = G.discardCount[player];
        coin_cost = getCost(G.hand[player][c1]);
        //play the card
        result = cardEffect(salvager, c1, c2, c3, &G, hp, &coin_bonus);
        //expected output should be as follows
        //coins = coin_prev + coin value of discard
        //buys = buys_pre + 1
        //discard pile should grow by 1
        
     //   coin_cost = getCost(handCard(c1, &G));
        coin_post = coin_pre + coin_cost;
        buys_post = buys_pre + 1;
        discard_post = discard_pre + 1;
        //do the comparisons
        if (result != 0)
            printf("CardEffect call has gone some sort of wrong\n");
        if(coin_post != G.coins)
        {
            printf("Salvager has handled coins incorrectly\n");
            printf("before: %d  cost: %d  after: %d  state: %d\n", coin_pre, coin_cost, coin_post, G.coins);
        }
        if(buys_post != G.numBuys)
            printf("Salvager has handled the buys incorrectly\n");
        if(discard_post != G.discardCount[player])
            printf("Salvager has handled the discard/trash incorrectly\n");
      //  printf("on iteration %d\n", tries);
    }
    printf("SALVAGER CARD TESTING FINISHED\n");

}