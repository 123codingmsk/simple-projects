#include <cstdlib>
#include <ctime>
#include <iostream>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3

using namespace std;

void displayThrow(int throwValue) {
  switch (throwValue) {
  case ROCK:
    cout << "Rock";
    break;
  case PAPER:
    cout << "Paper";
    break;
  case SCISSOR:
    cout << "Scissor";
    break;
  }
}

int main() {
  srand((unsigned int)time(NULL)); // Seed random number generator

  int playerThrow = 0;
  int aiThrow = 0;
  int playerScore = 0;
  int aiScore = 0;

  cout << "Welcome to Rock-Paper-Scissors!" << endl;
  cout << "First to reach 5 wins is the champion!" << endl;

  // Main game loop
  while (playerScore < 5 && aiScore < 5) {
    cout << "\nSelect your throw..." << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissor" << endl;
    cout << "Selection: ";
    cin >> playerThrow;

    // Validate input
    while (playerThrow < 1 || playerThrow > 3) {
      cout << "Invalid input. Please select 1, 2, or 3: ";
      cin >> playerThrow;
    }

    // AI throw
    aiThrow = (rand() % 3 + 1);
    cout << "AI throws ";
    displayThrow(aiThrow);
    cout << "." << endl;

    // Determine the outcome
    if (playerThrow == aiThrow) {
      cout << "Draw! Play again!" << endl;
    } else if (playerThrow == ROCK && aiThrow == SCISSOR) {
      cout << "ROCK beats SCISSOR! YOU WIN." << endl;
      playerScore++;
    } else if (playerThrow == ROCK && aiThrow == PAPER) {
      cout << "PAPER beats ROCK! YOU LOSE." << endl;
      aiScore++;
    } else if (playerThrow == PAPER && aiThrow == ROCK) {
      cout << "PAPER beats ROCK! YOU WIN." << endl;
      playerScore++;
    } else if (playerThrow == PAPER && aiThrow == SCISSOR) {
      cout << "SCISSOR beats PAPER! YOU LOSE." << endl;
      aiScore++;
    } else if (playerThrow == SCISSOR && aiThrow == ROCK) {
      cout << "ROCK beats SCISSOR! YOU LOSE." << endl;
      aiScore++;
    } else if (playerThrow == SCISSOR && aiThrow == PAPER) {
      cout << "SCISSOR beats PAPER! YOU WIN." << endl;
      playerScore++;
    }

    cout << "Score - You: " << playerScore << " | AI: " << aiScore << endl;
  }

  // Determine the overall winner
  if (playerScore == 5) {
    cout << "\nCongratulations! You are the champion!" << endl;
  } else {
    cout << "\nAI is the champion! Better luck next time!" << endl;
  }

  cout << "Thanks for playing!" << endl;
  return 0;
}
