//
//  Edge.h
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __TravelingSalesmen__Edge__
#define __TravelingSalesmen__Edge__

#include <iostream>
#include "Vertex.h"

class Edge {

private:
	double weight;
	Vertex *source;
	Vertex *destination;

public:
/*  Function: Edge - Constructor
 *--------------------------------------------------
 *	Usage: Edge(source, destination, weight)
 *--------------------------------------------------
 *  [Constructor which sets the source vertex, the
 *	destination vertex and the weight for this
 *	Edge
 */
	Edge(Vertex *source, Vertex* destination, double weight);
	
/*  Function: Edge - Distructor
 *--------------------------------------------------
 *	Usage: ~Edge()
 *--------------------------------------------------
 */
	~Edge();
	
/*  Function: GetSource
 *--------------------------------------------------
 *	Usage: edge->GetSource()
 *--------------------------------------------------
 *  Returns: pointer to the source vertex
 */
	Vertex* GetSource();
	
/*  Function: GetDestination
 *--------------------------------------------------
 *	Usage: edge->GetDestination()
 *--------------------------------------------------
 *  Returns: pointer to the Destination vertex
 */
	Vertex* GetDestination();
	
/*  Function: GetWeight
 *--------------------------------------------------
 *	Usage: edge->GetWeight()
 *--------------------------------------------------
 *  Returns: double of the weight of the edge
 */
	double GetWeight();
	
/*  Function: ToString
 *--------------------------------------------------
 *	Usage: edge->ToString()
 *--------------------------------------------------
 *  Returns: string representation of this Edge.
 *			 For testing purposes.
 */
	string ToString();

};

#endif /* defined(__TravelingSalesmen__Edge__) */
