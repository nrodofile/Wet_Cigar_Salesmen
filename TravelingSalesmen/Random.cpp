//
//  random.cpp
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//	Student# n8036039


#include "random.h"
/*
 *  Function: Random Constructor
 *--------------------------------------------------
 *	Usage: Random *rand = new Random(high, low);
 *--------------------------------------------------
 *  Argument constructor – Initialises low and
 *  height.
 *  Initialises random generator
 */
Random::Random(int low, int high){
    this->low = low;
    this->high = high;
    Randomise();
}

/*
 *  Function: Random Destructor
 *--------------------------------------------------
 *  Destroys any pointers in the class
 */
Random::~Random(){
    //Does nothing 
}

/*
 *  Function: RandomInt
 *--------------------------------------------------
 *	Usage: int rand = random->RandomInt()
 *--------------------------------------------------
 *  creates random number in decimal then casts it
 *  to an integer.
 *
 *  Returns:    RandomInt derived from high and low
 *--------------------------------------------------
 */
int Random::RandomInt(){
    double random = double(rand() / (double(RAND_MAX) + 1));
    int randomInt = int(random * (high - low));
    return low + randomInt;
}

/*
 *  Function: Randomise
 *
 *	Usage: Randomise();
 *--------------------------------------------------
 *  Initialises the random-number generator.
 */

void Random::Randomise(){
    srand(int(time(NULL)));
}