//
//  Graph.h
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __TravelingSalesmen__Graph__
#define __TravelingSalesmen__Graph__

#include <iostream>
#include "Vertex.h"
#include "Edge.h"

class Graph {
	
public:
	
/*  Function: Graph - Constructor
 *--------------------------------------------------
 *	Usage: Graph(int vertices)
 *--------------------------------------------------
 *  Constructor which sets the number of vertices in
 *	this Graph
 */
	Graph(int vertices);
	
/*  Function: Graph - Destructor
 *--------------------------------------------------
 *	Usage: ~Graph()
 *--------------------------------------------------
 */
	~Graph();
	
/*  Function: AddVertex
 *--------------------------------------------------
 *	Usage: AddVertex(vertex)
 *--------------------------------------------------
 *  Adds pointer to Vertex to the adjacency list
 *	for this Graph.
 */
	void AddVertex(Vertex *vertex);
	
/*  Function: GetVertex
 *--------------------------------------------------
 *	Usage: GetVertex(identifier)
 *--------------------------------------------------
 *  Returns:	pointer to the Vertex with
 *				the identifier/index in the parameter
 */
	Vertex* GetVertex(int identifier);
	
/*  Function: AddEdge
 *--------------------------------------------------
 *	Usage: AddEdge(edge)
 *--------------------------------------------------
 *  Adds pointer to Edge to the edge list for this
 *	Graph.
 */
	void AddEdge(Edge *edge);
	
/*  Function: OptimalTSP
 *--------------------------------------------------
 *	Usage: length = OptimalTSP();
 *--------------------------------------------------
 *  Returns:	Length of the optimal TSP tour
 */
	double OptimalTSP();
	
/*  Function: ApproximateTSP
 *--------------------------------------------------
 *	Usage: lenght = ApproximateTSP();
 *--------------------------------------------------
 *  Returns:	length of the approximate TSP tour
 *				calculated using the given algorithm
 */
	double ApproximateTSP();
	
private:
	
	vector<vector<Edge>> adjacencyMatrix;
	
/*  Function: TSPBruteForce
 *--------------------------------------------------
 *	Usage:	
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
	double TSPBruteForce(int, bool*);
	
/*  Function: TSPDp
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
	double TSPDP(int, int);

/*  Function: MinimumSpanningTree
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
	void MinimumSpanningTree();
	
	
/*  Function: DepthFirstSearch
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:  approximation for the TSP tour taken
 *	by traversing the vertices in depth first order of
 *	the sub-graph formed from the MST
 */
	double DepthFirstSearch();

};

#endif /* defined(__TravelingSalesmen__Graph__) */
