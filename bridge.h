#ifndef BRIDGE_H
#define BRIDGE_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char rank;
    char suit;
} Card;

typedef struct hand{
    Card cards[13];
} Hand;

int readFromFile(Hand hands[]);
void saveData(const Hand hands[], int numHands);
int readFromInput(Hand hands[]);
void printHand(Hand hand);
bool balanced(Hand hand);
int hcp(Hand hand);
int declarer(Hand hand);
void response(Hand hand);

int readFromInput(Hand hands[]) 
{
    int numHands = 0;
    scanf("%d", &numHands);

    for (int i = 0; i < numHands; i++) 
    {
        for (int j = 0; j < 13; j++) 
        {
            scanf(" %c%c", &hands[i].cards[j].rank, &hands[i].cards[j].suit);
        }
    }
    return numHands;
}

void printHand(Hand hand) {
    const char *suits[4] = {"SPADES:", "HEARTS:", "DIAMONDS:", "CLUBS:"};
    char suitSymbols[4] = {'S', 'H', 'D', 'C'};
    char ranks[] = "AKQJT98765432"; 

    for (int s = 0; s < 4; s++) 
    {
        printf("%-9s ", suits[s]); 
        for (int r = 0; r < 13; r++) 
        {
            for (int j = 0; j < 13; j++) 
            {
                if (hand.cards[j].suit == suitSymbols[s] && hand.cards[j].rank == ranks[r]) 
                { 
                  printf("%c ", ranks[r]); 
                }
            }
        }
        printf("\n");
    }
}

bool balanced(Hand hand) 
{
    int suitCount[4] = {0}; 
    for (int i = 0; i < 13; i++) 
    {
        char suit = hand.cards[i].suit;
        if (suit == 'S')
          suitCount[0]++;
        else if (suit == 'H')
          suitCount[1]++;
        else if (suit == 'D')
          suitCount[2]++;
        else if (suit == 'C')
          suitCount[3]++;
    }

    int twoCardSuits = 0; 
    for (int i = 0; i < 4; i++) 
    {
      if (suitCount[i] < 2) 
        return false; 
      if (suitCount[i] == 2) 
        twoCardSuits++;
    }

    return twoCardSuits <= 1; 
}

int hcp(Hand hand) 
{
    int points = 0;
    for (int i = 0; i < 13; i++) 
    {
        char rank = hand.cards[i].rank;
        
        if (rank == 'A') 
        {
            points += 4;
        } 
        else if (rank == 'K') 
        {
            points += 3;
        } 
        else if (rank == 'Q') 
        {
            points += 2;
        } 
        else if (rank == 'J') 
        {
            points += 1;
        } 
    }
    
    return points;
}

int declarer(Hand hand) 
{
    int suitCount[4] = {0}; 
    for (int i = 0; i < 13; i++) 
    {
        char suit = hand.cards[i].suit;
        if (suit == 'S') suitCount[0]++;
        else if (suit == 'H') suitCount[1]++;
        else if (suit == 'D') suitCount[2]++;
        else if (suit == 'C') suitCount[3]++;
    }

    int distributionPoints = 0;
    for (int i = 0; i < 4; i++) 
    {
        if (suitCount[i] > 4) 
        {
          distributionPoints += suitCount[i] - 4; 
        }
    }

    return distributionPoints;
}

void response(Hand hand) 
{
    int hcpPoints = hcp(hand);
    int distributionPoints = declarer(hand);
    int totalPoints = hcpPoints + distributionPoints;
    int suitCount[4] = {0}; 

    for (int i = 0; i < 13; i++) 
    {
        char suit = hand.cards[i].suit;
        if (suit == 'S') suitCount[0]++;
        else if (suit == 'H') suitCount[1]++;
        else if (suit == 'D') suitCount[2]++;
        else if (suit == 'C') suitCount[3]++;
    }

    if (hcpPoints >= 22) 
    {
        printf("2 CLUBS\n");
    } 
    else if (balanced(hand) && (hcpPoints >= 20 && hcpPoints <= 21)) 
    {
        printf("2NT\n");
    } 
    else if (balanced(hand) && (hcpPoints >= 15 && hcpPoints <= 17)) 
    {
        printf("1NT\n");
    } 
    else if (totalPoints >= 13) 
    {
        if (suitCount[0] >= 5 && suitCount[1] <= 5) 
        {
          printf("1 SPADES\n");
        } 
        else if (suitCount[1] >= 5) {
          printf("1 HEARTS\n");
        } 
        else if (suitCount[2] >= 4 && suitCount[0] < 5 && suitCount[1] < 5) 
        {
          printf("1 DIAMONDS\n");
        } 
        else if (suitCount[0] < 5 && suitCount[1] < 5 && suitCount[2] < 4) 
        {
          printf("1 CLUBS\n");
        }
    } 
    else 
    {
        printf("PASS\n");
    }
}

int readFromFile(Hand hands[]) 
{
    char fileName[100]; 
    scanf("%99s", fileName); 

    FILE *file = fopen(fileName, "r"); 
    if (file == NULL) 
    {
        perror("Error opening file");
        return -1; 
    }

    int numHands = 0;
    fscanf(file, "%d", &numHands); 

    for (int i = 0; i < numHands; i++) 
    {
        for (int j = 0; j < 13; j++) 
        {
            fscanf(file, " %c%c", &hands[i].cards[j].rank, &hands[i].cards[j].suit);
        }
    }

    fclose(file); 
    return numHands; 
}

void saveData(const Hand hands[], int numHands) 
{
    char fileName[100]; 
    scanf("%99s", fileName); 

    FILE *file = fopen(fileName, "w"); 
    if (file == NULL) 
    {
        perror("Error opening file");
        return; 
    }

    fprintf(file, "%d\n", numHands);

    const char *suits[4] = {"SPADES:", "HEARTS:", "DIAMONDS:", "CLUBS:"};
    char suitSymbols[4] = {'S', 'H', 'D', 'C'};
    char ranks[] = "AKQJT98765432";

    for (int i = 0; i < numHands; i++) 
    {
        for (int s = 0; s < 4; s++) 
        {
            fprintf(file, "%-9s ", suits[s]);
            for (int r = 0; r < 13; r++) 
            {
                for (int j = 0; j < 13; j++) 
                {
                    if (hands[i].cards[j].suit == suitSymbols[s] && hands[i].cards[j].rank == ranks[r]) 
                    {
                        fprintf(file, "%c ", ranks[r]);
                    }
                }
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n"); 
    }
    fclose(file); 
}

#endif
