//
//  DisjointSet.h
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __TravelingSalesmen__DisjointSet__
#define __TravelingSalesmen__DisjointSet__

#include <iostream>

class DisjointSet {

public:
/*  Function: DisjointSet - Constructor
 *--------------------------------------------------
 *	Usage: DisjointSet(size);
 *--------------------------------------------------
 *  Constructor which sets the size of this
 *	DisjointSet
 */
	DisjointSet(int size);
	
/*  Function: DisjointSet - Destructor
 *--------------------------------------------------
 *	Usage: ~Disjoint();
 *--------------------------------------------------
 */
	~DisjointSet();
	
/*  Function: Find
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	The index of the parent set of the
 *				element in the parameter
 */
	int Find(int);
	
/*  Function: Union
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	Creates the union of two disjoint sets whose
 *				indexes are passed as parameters
 */
	void Union(int, int);
	
/*  Function: SameComponent
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	true if the two indexes passed as
 *				parameters are in the same set
 */
	bool SameComponent(int,int);
  
};

#endif /* defined(__TravelingSalesmen__DisjointSet__) */
