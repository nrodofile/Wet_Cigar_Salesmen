//
//  Graph.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "Graph.h"

/*  Function: Graph - Constructor
 *--------------------------------------------------
 *	Usage: Graph(int vertices)
 *--------------------------------------------------
 *  Constructor which sets the number of vertices in
 *	this Graph
 */
Graph::Graph(int vertices){
	this->verticies = vertices;
}

/*  Function: Graph - Destructor
 *--------------------------------------------------
 *	Usage: ~Graph()
 *--------------------------------------------------
 */
Graph::~Graph(){
	
}

/*  Function: AddVertex
 *--------------------------------------------------
 *	Usage: AddVertex(vertex)
 *--------------------------------------------------
 *  Adds pointer to Vertex to the adjacency list
 *	for this Graph.
 */
void Graph::AddVertex(Vertex *vertex){
	
}

/*  Function: GetVertex
 *--------------------------------------------------
 *	Usage: GetVertex(identifier)
 *--------------------------------------------------
 *  Returns:	pointer to the Vertex with
 *				the identifier/index in the parameter
 */
Vertex* Graph::GetVertex(int identifier){
	return NULL;
}

/*  Function: AddEdge
 *--------------------------------------------------
 *	Usage: AddEdge(edge)
 *--------------------------------------------------
 *  Adds pointer to Edge to the edge list for this
 *	Graph.
 */
void Graph::AddEdge(Edge *edge){
	
}

/*  Function: OptimalTSP
 *--------------------------------------------------
 *	Usage: length = OptimalTSP();
 *--------------------------------------------------
 *  Returns:	Length of the optimal TSP tour
 */
double Graph::OptimalTSP(){
	return 0;
}

/*  Function: ApproximateTSP
 *--------------------------------------------------
 *	Usage: lenght = ApproximateTSP();
 *--------------------------------------------------
 *  Returns:	length of the approximate TSP tour
 *				calculated using the given algorithm
 */
double Graph::ApproximateTSP(){
	return 0;
}


/*  Function: TSPBruteForce
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
double Graph::TSPBruteForce(int, bool*){
	return 0;
}

/*  Function: TSPDp
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
double Graph::TSPDP(int, int){
	return 0;
}

/*  Function: MinimumSpanningTree
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
void Graph::MinimumSpanningTree(){
	
}


/*  Function: DepthFirstSearch
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:  approximation for the TSP tour taken
 *	by traversing the vertices in depth first order of
 *	the sub-graph formed from the MST
 */
double DepthFirstSearch(){
	return 0;
}

