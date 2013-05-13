//
//  DisjointSet.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "DisjointSet.h"
/*  Function: DisjointSet - Constructor
 *--------------------------------------------------
 *	Usage: DisjointSet(size);
 *--------------------------------------------------
 *  Constructor which sets the size of this
 *	DisjointSet
 */
DisjointSet::DisjointSet(int size){
	this->size = size;
}

/*  Function: DisjointSet - Destructor
 *--------------------------------------------------
 *	Usage: ~Disjoint();
 *--------------------------------------------------
 */
DisjointSet::~DisjointSet(){
	
}

/*  Function: Find
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	The index of the parent set of the
 *				element in the parameter
 */
int DisjointSet::Find(int){
	return 0;
}

/*  Function: Union
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	Creates the union of two disjoint sets whose
 *				indexes are passed as parameters
 */
void DisjointSet::Union(int, int){
	
}

/*  Function: SameComponent
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	true if the two indexes passed as
 *				parameters are in the same set
 */
bool DisjointSet::SameComponent(int,int){
	return false;
}