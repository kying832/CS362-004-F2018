#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "card_functions.h"
/*
while (drawntreasure < 2)
{
    if (state->deckCount[currentPlayer] < 1)
    { //if the deck is empty we need to shuffle discard and add to deck
        shuffle(currentPlayer, state);
    }
    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1]; //top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
        drawntreasure++;
    else
    {
        temphand[z] = cardDrawn;
        state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
        z++;
    }
}
while (z - 1 >= 0)
{
    state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
    z = z - 1;
}
*/
//parameters are gamestate state struct, int currentPlayer, int drawnTreasure, int [] tempHand, 
void adventurer_card(struct gameState * state, int currentPlayer, int drawnTreasure, int temp_counter,  int temp_hand[])
{
    int cardDrawn; //id of card based on CARD ENUM in dominion.h
    while(drawnTreasure < 2)
    {
        if (state->deckCount[currentPlayer] < 1)
        { //if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1]; //top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)    //if card is a treasure card, increment drawnTreasure
            drawnTreasure++;
        else
        {
            temp_hand[temp_counter] = cardDrawn;
            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            temp_counter++;
        }
    }
    while (temp_counter - 1 >= 0)
    {
        state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temp_hand[temp_counter - 1]; // discard all cards in play that have been drawn
        temp_counter = temp_counter - 1;
    }
}
