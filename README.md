# Bridge-Hand-Evaluator

## Overview
This project provides a set of C functions for reading, processing, and evaluating hands of playing cards, specifically for the game of bridge. It includes functionality for reading hands from user input or a file, evaluating the balance and high card points (HCP) of a hand, and determining the appropriate response in a bridge game based on the hand's composition.

Bridge is a trick-taking card game using a standard 52-card deck. It is played by four players in two partnerships. The project focuses on evaluating the hands of cards and providing responses that would be appropriate in a standard bridge bidding system.

## Features
- **Reading Hands**: Functions to read hands from user input or a file.
- **Hand Evaluation**: Functions to evaluate the balance and high card points (HCP) of a hand.
- **Response Determination**: Functions to determine the appropriate response in a bridge game based on the hand's composition.

## Detailed Explanation

The code is designed to handle the evaluation of playing card hands for bridge. It includes functions to read hands from input or files, print hands, evaluate if a hand is balanced, calculate high card points (HCP), and determine the appropriate game response.

### Game of Bridge
Bridge is played with a standard deck of 52 cards, divided into four suits: spades (S), hearts (H), diamonds (D), and clubs (C). Each suit has 13 cards (A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2). The game involves dealing the cards to four players, each receiving 13 cards, called a "hand".

### Functions

- **readFromInput(Hand hands[])**
  - Reads hands from user input.
  - Returns the number of hands read.
  - Example: 
    ```c
    Hand hands[10];
    int numHands = readFromInput(hands);
    ```

- **printHand(Hand hand)**
  - Prints a hand in a formatted manner, showing cards by suit.
  - Example:
    ```c
    printHand(hands[0]);
    ```

- **balanced(Hand hand)**
  - Evaluates if a hand is balanced.
  - A balanced hand has no suit with fewer than 2 cards and at most one suit with exactly 2 cards.
  - Example:
    ```c
    bool isBalanced = balanced(hands[0]);
    ```

- **hcp(Hand hand)**
  - Calculates the high card points (HCP) of a hand.
  - Assigns points as follows: Ace = 4, King = 3, Queen = 2, Jack = 1.
  - Example:
    ```c
    int points = hcp(hands[0]);
    ```

- **declarer(Hand hand)**
  - Calculates the distribution points of a hand based on the length of suits.
  - Example:
    ```c
    int distributionPoints = declarer(hands[0]);
    ```

- **response(Hand hand)**
  - Determines the appropriate response in a game based on HCP and distribution points.
  - Example:
    ```c
    response(hands[0]);
    ```

### File Reading and Writing

- **readFromFile(Hand hands[])**
  - Reads hands from a file.
  - Returns the number of hands read.
  - Example:
    ```c
    int numHands = readFromFile(hands);
    ```

- **saveData(const Hand hands[], int numHands)**
  - Saves hands to a file in a formatted manner.
  - Example:
    ```c
    saveData(hands, numHands);
    ```

### Example Code

Here is an example of the main code structure:

```c
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char rank;
    char suit;
} Card;

typedef struct {
    Card cards[13];
} Hand;

int readFromInput(Hand hands[]);
void printHand(Hand hand);
bool balanced(Hand hand);
int hcp(Hand hand);
int declarer(Hand hand);
void response(Hand hand);

int main() {
    Hand hands[10];
    int numHands = readFromInput(hands);
    for (int i = 0; i < numHands; i++) {
        printHand(hands[i]);
        response(hands[i]);
    }
    return 0;
}
