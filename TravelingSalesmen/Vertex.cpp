//
//  Vertex.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "Vertex.h"

/*  Function: Vertex - Constructor
 *-------------------------------------------------
 *	Usage: Vertex(identifier);
 *-------------------------------------------------
 *  Constructor which sets the vertex
 *	identifier (useful for indexing into
 *	collections of vertices)
 */
Vertex::Vertex(int identifier){
	this->identifier = identifier;
}

/*  Function: ~Vertex - Destructor
 *-------------------------------------------------
 *	Usage: ~Vertex()
 *-------------------------------------------------
 */
Vertex::~Vertex(){
	
}

/*  Function: GetId
 *--------------------------------------------------
 *	Usage: id = vertex->GetId()
 *-------------------------------------------------
 *  Accessor for this vertex’ identifier
 *
 *  Returns: The identifier as an Int
 */
int Vertex::GetId(){
	return identifier;
}

/*  Function: AddAdjacencies
 *--------------------------------------------------
 *	Usage: vertex->AddAdjacency(vertex2)
 *-------------------------------------------------
 *  Adds a pointer to a Vertex to this Vertex’
 *	adjacency list
 */
void Vertex::AddAdjacency(Vertex *vertex){
	adjacent.push_back(vertex);
}

/*  Function: GetAdjacencies
 *-------------------------------------------------
 *	Usage: adjacencies = vertex->GetAdjacencies()
 *-------------------------------------------------
 *  Returns: A collection of pointer of Vertex,
 *			 being the vertices adjacent to this
 *			 Vertex
 */
vector<Vertex*> Vertex::GetAdjacencies(){
	return adjacent;
}

/*  Function: ToString
 *--------------------------------------------------
 *	Usage: vertex->ToString()
 *-------------------------------------------------
 *  Returns: a string representation of this Vertex.
 *			 For testing purposes.
 */
string Vertex::ToString(){
	return to_string(identifier);
}
