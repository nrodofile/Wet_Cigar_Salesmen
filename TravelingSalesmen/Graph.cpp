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
Graph::Graph(int V){
	this->verticies = V;
	//edges = new int[V];
	
	for (int i = 0; i < V; i++) {
		//edges[i] = *new int[V];
		vector<int> e;
		for(int j = 0; j < V; j++){
			e.push_back(0);
		}
		edges.push_back(e);
	}
}

/*  Function: Graph - Destructor
 *--------------------------------------------------
 *	Usage: ~Graph()
 *--------------------------------------------------
 */
Graph::~Graph(){
	
	//delete[] edges;
}

/*  Function: AddVertex
 *--------------------------------------------------
 *	Usage: AddVertex(vertex)
 *--------------------------------------------------
 *  Adds pointer to Vertex to the adjacency list
 *	for this Graph.
 */
void Graph::AddVertex(Vertex *vertex){
	adjacencies.push_back(vertex);
	
}

/*  Function: GetVertex
 *--------------------------------------------------
 *	Usage: GetVertex(identifier)
 *--------------------------------------------------
 *  Returns:	pointer to the Vertex with
 *				the identifier/index in the parameter
 */
Vertex* Graph::GetVertex(int identifier){
	return adjacencies[identifier];
}

/*  Function: AddEdge
 *--------------------------------------------------
 *	Usage: AddEdge(edge)
 *--------------------------------------------------
 *  Adds pointer to Edge to the edge list for this
 *	Graph.
 */
void Graph::AddEdge(Edge *edge){
	int s = (edge->GetSource())->GetId();
	int d = (edge->GetDestination())->GetId();
	
	edges[s][d] = edge->GetWeight();
	
//	map< int, vector <Edge*> >::iterator it;	
//	int id = (edge->GetSource())->GetId();
//	it = edges.find(id);
//	
//	if(it != edges.end()){
//		vector<Edge*> e = edges.at(id);
//		e.push_back(edge);
//	}else{
//		vector<Edge*> e;
//		e.push_back(edge);
//		edges.insert(pair<int, vector <Edge*> >(id, e));
//	}
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
//	create array of bool named visited with size = numVertices
//	initialise visited to false
//	set first element of visited to true
//	result = TSPBruteForce(0, visited)
//	TSPBruteForce(current, visited):
//	if all elements in visited are true
//		return distance from current to 0
//		make a copy of visited
//		set minDistance to INFINITY
//		for adjacent from 0 to numVertices-1
//			if current != adjacent AND adjacent not visited
//				set adjacent in copy of visited to true
//				dist = distance from current to adjacent +
//				TSPBruteForce(adjacent, copy of visited)
//				minDistance = minimum(minDistance, dist)
//				set adjacent in copy of visited to false
//			end if
//		end for
//		return minDistance
//	end
	
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
	

//	Create memoisation table [N][(1 << N)]
//	Set all values in table to UNSET
//	result = TSPDP(0, 1)
//	TSPDP(current, bitmask):
//	if table[current][bitmask] is not UNSET
//		return table[current][bitmask]
//	if bitmask == ((1 << N) – 1)
//			return distance from current to 0
//	minDistance = INFINTY
//	for adjacent from 0 to N-1
//		if current != adjacent AND
//			((bitmask & (1 << adjacent)) == 0)
//			dist = distance from current to adjacent +
//			TSPDP(adjacent, (bitmask | (1 << adjacent)))
//			minDistance = min(minDistance, dist)
//		endif
//	endfor
//	table[current][bitmask] = minDistance
//	return minDistance
	
	
	return 0;
}

/*  Function: MinimumSpanningTree
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 */
void Graph::MinimumSpanningTree(){
//	1.Place each vertex in its own cluster or
//	set
	
//	2.Take the edge e with the smallest weight
//		a) If e connects two vertices in different
//		clusters, then e is added to the MST and the
//		two clusters connected by e are merged into a
//		single cluster
//		b) If e connects two vertices which are already
//		in the same cluster, ignore it
//	3.Continue until N – 1 edges are selected
}


/*  Function: DepthFirstSearch
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  Returns:  approximation for the TSP tour taken
 *	by traversing the vertices in depth first order of
 *	the sub-graph formed from the MST
 */
double Graph::DepthFirstSearch(){

	int dist = 0;
	
//	initialise visited array to false
	vector<bool> visited;
	visited.assign (verticies,false);

//	create empty stack
	stack<Vertex*> stack;
	
//	push vertex 0 onto stack
	stack.push(adjacencies[0]);
	
//	mark vertex 0 visited
	visited[0] = true;
	
//	current vertex = NULL
	Vertex *current = NULL;
	
//	let previous vertex = NULL
	Vertex *previous = NULL;
	
//	while stack not empty
	while(!stack.empty()){

//		current = pop from stack
		current = stack.top();
		stack.pop();
		
//		if previous not NULL
		if(!previous){
//			dist = dist + distance from previous to current
			dist = dist + edges[previous->GetId()][current->GetId()];
		}
//		end if
		
//		for vertices adjacent to current
		for (int v = 0; v < verticies; v++ ){

//			if adjacent vertex not visited
			if (!visited[v]){
				
//				push adjacent vertex onto stack
				stack.push(adjacencies[v]);
				
//				mark adjacent vertex visited
				visited[v] = true;
			}
		}
//		previous = current
		previous = current;
	}

//	end while
//	dist = distance from current to vertex 0
	dist = dist = dist + edges[current->GetId()][adjacencies[0]->GetId()];
	delete current;
	delete previous;
	
	return dist;
}

