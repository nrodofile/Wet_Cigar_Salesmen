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
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include "Vertex.h"
#include "Edge.h"
#include "DisjointSet.h"
#include "EdgeComparer.h"

#define INFINATY 9999999
#define OPTIMAL_MAX 23
#define TSPDP_MAX 11
#define FIRST 0
#define UNSET -1

class Graph {
	
	vector<Vertex*> adjacencies;
	double **adjMatrix;
	vector<Vertex*> MST;	//Minimum Spanning Tree Subgraph 
	std::priority_queue<Edge*, vector<Edge*>, EdgeComparer> edges;
	double **table; //memoisation table
	int verticies;

public:
	
	/*  Function: Graph - Constructor
	 *--------------------------------------------------
	 *	Usage: Graph(int vertices)
	 *--------------------------------------------------
	 *  Constructor which sets the number of vertices in
	 *	this Graph
	 */
	Graph(int verticies);
	
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
	 *	If NUM_CITIES > 11 the TSPDP function should
	 *	be used. If NUM_CITIES > 22, this function
	 *	should not be called.	 
	 *  Returns:	Length of the optimal TSP tour
	 */
	double OptimalTSP();
	
	/*  Function: ApproximateTSP
	 *--------------------------------------------------
	 *	Usage: lenght = ApproximateTSP();
	 *--------------------------------------------------
	 *  Returns:	length of the approximate TSP tour
	 */
	double ApproximateTSP();
	
private:

	
	/*  Function: TSPBruteForce
	 *--------------------------------------------------
	 *	Usage: TSPBruteForce(current, * visited)
	 *--------------------------------------------------
	 *  computes every combination of tour through all
	 *	vertices finding the minimum. It relies on recursion
	 *	and backtracking to find the solution.
	 *
	 *  Returns: double of the minimum distance
	 */
	double TSPBruteForce(int, bool*);
	
	/*  Function: TSPDP
	 *--------------------------------------------------
	 *	Usage: TSPDP(current, bitmask)
	 *--------------------------------------------------
	 *  uses a similar approach to the Brute Force algorithm
	 *	but uses a problem solving approach know as Dynamic Programming
	 *	to store optimal solutions to sub-problems of the larger
	 *	problem being solved
	 *
	 *  Returns: double of minimum optimal distance of the tour
	 */
	double TSPDP(int, int);

	/*  Function: MinimumSpanningTree
	 *--------------------------------------------------
	 *	Usage: MinimumSpanningTree()
	 *--------------------------------------------------
	 *  Uses Kruskal’s algorithm to find the Minimum
	 *	Spanning Tree (MST) for this Graph. Stores the
	 *	edges of the MST in the adjacency list of each
	 *	Vertex
	 *
	 */
	void MinimumSpanningTree();
	
	
	/*  Function: DepthFirstSearch
	 *--------------------------------------------------
	 *	Usage: DepthFirstSearch()
	 *--------------------------------------------------
	 *  Returns:  approximation for the TSP tour taken
	 *	by traversing the vertices in depth first order of
	 *	the sub-graph formed from the MST
	 */
	double DepthFirstSearch();
	
};

#endif /* defined(__TravelingSalesmen__Graph__) */
