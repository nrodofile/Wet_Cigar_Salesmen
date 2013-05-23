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
	adjMatrix = new double *[V];
	
	for (int i = FIRST; i < V; i++) {
		adjMatrix[i] = new double[V];
		
		for (int j = FIRST; j < V; j++) {
			adjMatrix[i][j] = INFINATY;
		}
	}
}

/*  Function: Graph - Destructor
 *--------------------------------------------------
 *	Usage: ~Graph()
 *--------------------------------------------------
 */
Graph::~Graph(){	
	
	for (int i = FIRST; i < verticies; i++) {
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;
}

/*  Function: AddVertex
 *--------------------------------------------------
 *	Usage: AddVertex(vertex)
 *--------------------------------------------------
 *  Adds pointer to Vertex to the adjacency list
 *	for this Graph.
 */
void Graph::AddVertex(Vertex *vertex){
	vector<Edge*> e;
	
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
		
	adjMatrix[s][d] = edge->GetWeight();
	
	edges.push(edge);
	
}

/*  Function: OptimalTSP
 *--------------------------------------------------
 *	Usage: length = OptimalTSP();
 *--------------------------------------------------
 
 *	If NUM_CITIES > 11 the TSPDP function should
 *	be used. If NUM_CITIES > 22, this function
 *	should not be called.
 
 *  Returns:	Length of the optimal TSP tour
 */
double Graph::OptimalTSP(){
	double result = INFINATY;
	
	if (verticies > OPTIMAL_MAX){
		cerr << " Cannot Get Optimal tour, there are more than 22 cities";
		
	}else{
		
		if (verticies > TSPDP_MAX){
			
			//	Create memoisation table [N][(1 << N)]
			MT = new double *[TSPDP_MAX];
			//	Set all values in table to UNSET
			for(int b = FIRST; b < verticies; b++){
				
				MT[b] = new double[TSPDP_MAX];
				for (int m = FIRST; m < verticies; m++){
					MT[b][(1 << TSPDP_MAX)] = 0;
				}
			}			
			result = TSPDP(FIRST, 1);
			
		}else{			
			bool *visited = new bool[verticies];		
			for (int i = FIRST; i < verticies; i++) {
				visited[i] = false;
			}
			
			visited[FIRST] = true;			
			result = TSPBruteForce(FIRST, visited);
		}
	}	
	return result;
}

/*  Function: ApproximateTSP
 *--------------------------------------------------
 *	Usage: lenght = ApproximateTSP();
 *--------------------------------------------------
 *  Returns:	length of the approximate TSP tour
 *				calculated using the given algorithm
 */
double Graph::ApproximateTSP(){
	MinimumSpanningTree();
	double TSP = DepthFirstSearch();
	return TSP;
}


/*  Function: TSPBruteForce
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
double Graph::TSPBruteForce(int current, bool* visited){
	double minDistance; 
	bool visitedAll = true;

	for (int v = FIRST; v < verticies; v++){
		if(!visited[v]){
			visitedAll = false;
			break;
		}
	}
	
	if (visitedAll){
		return  adjMatrix[current][adjacencies[FIRST]->GetId()];
	}
	
//	make a copy of visited
	bool* visitedCp = new bool[verticies];
	
	for (int b = FIRST; b < verticies; b++){
		visitedCp[b] = visited[b];
	}
	minDistance = INFINATY;
	
//	for adjacent 'a' from 0 to numVertices-1
	for (int a = FIRST; a <= verticies-1; ++a){
		
//		if current != adjacent AND adjacent not visited
		if (current != adjacencies[a]->GetId() && !visited[a]){
			visitedCp[a] = true;
			
//			dist = distance from current to adjacent +
//			TSPBruteForce(adjacent, copy of visited)
			double dist =
				adjMatrix[current][adjacencies[a]->GetId()] +
						TSPBruteForce(adjacencies[a]->GetId(),visitedCp);

//			minDistance = minimum(minDistance, dist)
			if(minDistance > dist){
				minDistance = dist;
			}
			
			visitedCp[a] = false;
		}
	}
	
	delete[] visitedCp;
	
	return minDistance;

}

/*  Function: TSPDp
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 *  Returns:
 */
double Graph::TSPDP(int current, int bitmask){
	
//	if table[current][bitmask] is not UNSET
	if (MT[current][bitmask]){		
		return MT[current][bitmask];
	}

	if(bitmask == (1 << verticies)-1){
		return adjMatrix[current][adjacencies[FIRST]->GetId()];
	}
	
	double minDistance = INFINATY;
	for (int a = FIRST; a <= verticies-1; a++){
		
//		if current != adjacent AND
		//	((bitmask & (1 << adjacent)) == 0)
		if (adjacencies[current] != adjacencies[a] &&
			((bitmask & (1 << a)) == 0)){
			
//			dist = distance from current to adjacent +
//			TSPDP(adjacent, (bitmask | (1 << adjacent)))			
			double dist = adjMatrix[current][adjacencies[a]->GetId()] +
									TSPDP(a, bitmask | (1 << a));
			
//			minDistance = min(minDistance, dist)
			if(minDistance > dist){
				minDistance = dist;
			}
		}
	}
	
//	table[current][bitmask] = minDistance
	MT[current][bitmask] = minDistance;
	
	return minDistance;
}

/*  Function: MinimumSpanningTree
 *--------------------------------------------------
 *	Usage:
 *--------------------------------------------------
 *  [DESCRIPTION]
 *
 */
void Graph::MinimumSpanningTree(){
	int numEdges = START;
	double w = 0; //test
	
	//	1.Place each vertex in its own cluster or set
	DisjointSet *set = new DisjointSet(verticies);
	
	for (int i = FIRST; i < adjacencies.size(); i++){
		Vertex *v = adjacencies[i];
		MST.push_back(v);
	}
	

	while(numEdges != verticies-1){
//	2.Take the edge e with the smallest weight
//
//		int s = edges[e]->GetSource()->GetId(); //Source
//		int d = edges[e]->GetDestination()->GetId(); //Destination
		Edge *e = edges.top();
		edges.pop();
		
		int s = e->GetSource()->GetId(); //Source
		int d = e->GetDestination()->GetId(); //Destination
		
//		a) If e connects two vertices in different clusters, 
		if (!set->SameComponent(s,d)){
			
//		then e is added to the MST and the
//		two clusters connected by e are merged into a
//		single cluster
			
			set->Union(s, d);
			numEdges++;
			w += e->GetWeight();
			adjacencies[s]->AddAdjacency(adjacencies[d]);
			adjacencies[d]->AddAdjacency(adjacencies[s]);
		}
		
//		b) If e connects two vertices which are already
//		in the same cluster, ignore it
		e ++;
		
//	3.Continue until N – 1 edges are selected
	}
	cout << w << endl;
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

	//dist = 0
	double dist = START;
	
	//   initialise visited array to false
	vector<int> visited;
	visited.assign(adjacencies.size(), false);

	// create empty stack
	stack<Vertex*> stack;
	
	// push vertex 0 onto stack
	stack.push(MST[FIRST]);
	//stack.push(MST.top());
	
	
	// mark vertex 0 visited
	visited[FIRST] = true;
	
	// let current vertex = NULL 
	Vertex *current = NULL;
	
	// let previous vertex = NULL
	Vertex *previous = NULL;
	
	// while stack not empty 
	while(!stack.empty()){
		
		//current = pop from stack
		current = stack.top();
		stack.pop();

		//if previous not NULL
		if(previous != NULL){
			
			// dist = dist + distance from previous to current
			dist = dist + adjMatrix[previous->GetId()][current->GetId()];
		}
		
		//for vertices adjacent to current
		vector<Vertex*> adjacent = current->GetAdjacencies();
		for(int v = FIRST; v < adjacent.size(); ++v){
			
			// if adjacent vertex not visited
			if(!visited[adjacent[v]->GetId()]){
				
				//  push adjacent vertex onto stack
				stack.push(adjacencies[adjacent[v]->GetId()]);
				
				// mark adjacent vertex visited
				visited[adjacent[v]->GetId()] = true;
			}
		}
		//previous = current end while
		previous = current;
	}
	
	//dist = distance from current to vertex 0
	double back = adjMatrix[current->GetId()][MST[FIRST]->GetId()];
	return dist + back;
}
