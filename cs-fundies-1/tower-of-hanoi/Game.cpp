/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  
  int i = 0;
  while(i < 100) {
    i = i +1;
    // Prints out the state of the game:
    cout << *this << endl;

    if(moveTop(stacks_[0], stacks_[2]) == 0) continue;
    if(moveTop(stacks_[0], stacks_[1]) == 0) continue;
    if(moveTop(stacks_[1], stacks_[2]) == 0) continue;
    if(moveTop(stacks_[2], stacks_[1]) == 0) continue;
    if(moveTop(stacks_[2], stacks_[0]) == 0) continue;
    if(moveTop(stacks_[1], stacks_[0]) == 0) continue;
    break;
  }
}

int Game::moveTop(Stack &stack1, Stack &stack2) {
  if(stack1.size() > 0) {
    if(stack2.size() == 0 || stack2.peekTop().getLength() > stack1.peekTop().getLength()) {
      stack2.push_back(stack1.removeTop());
      return 0;
    }
  }
  return 1;
}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
