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

	for (int i = 0; i < size; i++) {
		id[i] = i;
		this->size[i] = 1;
	}
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
int DisjointSet::Find(int i){
	while (i != id[i]) {
		id[i] = id[id[i]]; // make elements point to their grandparent
		i = id[i];
	}
	return i;}

/*  Function: Union
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	Creates the union of two disjoint sets whose
 *				indexes are passed as parameters
 */
void DisjointSet::Union(int p, int q){
	int i = Find(p);
	int j = Find(q);
	if (size[i] < size[j]) {
		id[i] = j;
		size[j] += size[i];
	} else {
		id[j] = i;
		size[i] += size[j];
	}
}

/*  Function: SameComponent
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:	true if the two indexes passed as
 *				parameters are in the same set
 */
bool DisjointSet::SameComponent(int p, int q){
	return Find(p) == Find(q);
}