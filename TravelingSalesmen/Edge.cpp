//
//  Edge.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "Edge.h"

/*  Function: Edge - Constructor
 *--------------------------------------------------
 *	Usage: Edge(source, destination, weight)
 *--------------------------------------------------
 *  [Constructor which sets the source vertex, the
 *	destination vertex and the weight for this
 *	Edge
 */
Edge::Edge(Vertex *source, Vertex* destination, double weight){
	this->source = source;
	this->destination = destination;
	this->weight = weight;
}

/*  Function: Edge - Distructor
 *--------------------------------------------------
 *	Usage: ~Edge()
 *--------------------------------------------------
 */
Edge::~Edge(){
	
}

/*  Function: GetSource
 *--------------------------------------------------
 *	Usage: edge->GetSource()
 *--------------------------------------------------
 *  Returns: pointer to the source vertex
 */
Vertex* Edge::GetSource(){
	return source;
}

/*  Function: GetDestination
 *--------------------------------------------------
 *	Usage: edge->GetDestination()
 *--------------------------------------------------
 *  Returns: pointer to the Destination vertex
 */
Vertex* Edge::GetDestination(){
	return destination;
}

/*  Function: GetWeight
 *--------------------------------------------------
 *	Usage: edge->GetWeight()
 *--------------------------------------------------
 *  Returns: double of the weight of the edge
 */
double Edge::GetWeight(){
	return weight;
}

/*  Function: ToString
 *--------------------------------------------------
 *	Usage: edge->ToString()
 *--------------------------------------------------
 *  Returns: string representation of this Edge.
 *			 For testing purposes.
 */
string Edge::ToString(){
	return to_string(weight);
}