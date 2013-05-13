//
//  random.h
//  PokerEval
//
//  Created by Nicholas Rodofile on 14/04/13.
//	Student# n8036039



#ifndef __PokerEval__random__
#define __PokerEval__random__

#include <iostream>
#include <cstdlib>
#include <ctime>

class Random
{
public:
	
	/*
	 *  Function: Random Constructor 
	 *--------------------------------------------------
	 *	Usage: Random *rand = new Random(high, low);
	 *--------------------------------------------------
	 *  Argument constructor – Initialises low and
	 *  height.
	 *  Initialises random generator
	 */
    Random(int low, int high);
   
	/*
	 *  Function: Random Destructor
	 *--------------------------------------------------
	 *  Destroys any pointers in the class
	 */
	~Random();
	
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
    int RandomInt();
	
private:
    int low;	// Minimum random number generated
    int high;	// Maximum random number
	
	/*
	 *  Function: Randomise
	 *
	 *	Usage: Randomise();
	 *--------------------------------------------------
	 *  Initialises the random-number generator.
	 */
    void Randomise();


};

#endif /* defined(__PokerEval__random__) */
