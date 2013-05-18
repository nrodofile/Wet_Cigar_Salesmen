//
//  EdgeComparer.h
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __TravelingSalesmen__EdgeComparer__
#define __TravelingSalesmen__EdgeComparer__

#include <iostream>
#include "Edge.h"

class EdgeComparer{
	
public:
/*	Function: operator
 *--------------------------------------------------
 *	Usage: bool IsLessThan =
 *			EdgeComperer operator() (*first, *second);
 *
 *  Returns:	true if and only if the
 *				weight of the first Edge is less than the weight
				of the second Edge
 */
	bool operator() (Edge*, Edge*);
};
#endif /* defined(__TravelingSalesmen__EdgeComparer__) */
