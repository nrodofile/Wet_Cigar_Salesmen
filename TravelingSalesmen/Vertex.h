//
//  Vertex.h
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __TravelingSalesmen__Vertex__
#define __TravelingSalesmen__Vertex__

#include <iostream>

#include <vector>
using namespace std;
class Vertex {
	
private:
	int identifier;
	vector<Vertex*> adjacent;
	
public:
	
/*  Function: Vertex - Constructor
 *-------------------------------------------------
 *	Usage: Vertex(identifier);
 *-------------------------------------------------
 *  Constructor which sets the vertex
 *	identifier (useful for indexing into
 *	collections of vertices)
 */
	Vertex(int identifier);
	
/*  Function: ~Vertex - Destructor
 *-------------------------------------------------
 *	Usage: ~Vertex()
 *-------------------------------------------------
 */
	~Vertex();
	
/*  Function: GetId
 *--------------------------------------------------
 *	Usage: id = vertex->GetId()
 *-------------------------------------------------
 *  Accessor for this vertex’ identifier
 *
 *  Returns: The identifier as an Int
 */
	int GetId();
	
/*  Function: AddAdjacencies
 *--------------------------------------------------
 *	Usage: vertex->AddAdjacency(vertex2)
 *-------------------------------------------------
 *  Adds a pointer to a Vertex to this Vertex’
 *	adjacency list
 */
	void AddAdjacency(Vertex *vertex);
	
/*  Function: GetAdjacencies
 *-------------------------------------------------
 *	Usage: adjacencies = vertex->GetAdjacencies()
 *-------------------------------------------------
 *  Returns: A collection of pointer of Vertex,
 *			 being the vertices adjacent to this 
 *			 Vertex
 */
	vector<Vertex*> GetAdjacencies();
	
/*  Function: ToString
 *--------------------------------------------------
 *	Usage: vertex->ToString()
 *-------------------------------------------------
 *  Returns: a string representation of this Vertex.
 *			 For testing purposes.
 */
	string ToString();
};

#endif /* defined(__TravelingSalesmen__Vertex__) */
