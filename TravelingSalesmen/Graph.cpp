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
		delete[] table[i];
	}
	delete[] adjMatrix;
	delete[] table;
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
		cerr << "Cannot Get Optimal tour, there are more than "
				<< OPTIMAL_MAX << " cities" << endl;
		
		result = 0;
	}else{
		
		if (verticies > TSPDP_MAX){
			
			//	Create memoisation table [N][(1 << N)]
			table = new double *[verticies];
			
			//	Set all values in table to UNSET
			for(int b = FIRST; b < verticies; b++){
				table[b] = new double[1 << verticies];
				
				for (int m = FIRST; m < (1 << verticies); m++){
					table[b][m] = UNSET;
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
 */
double Graph::ApproximateTSP(){
	MinimumSpanningTree();
	
	return DepthFirstSearch();
}


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
double Graph::TSPBruteForce(int current, bool* visited){
	double minDistance; 
	bool visitedAll = true;

	// check if all verticies are visited
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
	
	for (int a = FIRST; a <= verticies-1; ++a){
		
		if (current != adjacencies[a]->GetId() && !visited[a]){
			visitedCp[a] = true;
			
			double dist =
				adjMatrix[current][adjacencies[a]->GetId()] +
						TSPBruteForce(adjacencies[a]->GetId(),visitedCp);

			if(minDistance > dist){
				minDistance = dist;
			}
			
			visitedCp[a] = false;
		}
	}	
	return minDistance;
}

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
double Graph::TSPDP(int current, int bitmask){
	
	if (table[current][bitmask] != UNSET){
		return table[current][bitmask];
	}

	if(bitmask == (1 << verticies)-1){
		return adjMatrix[current][adjacencies[FIRST]->GetId()];
	}
	
	double minDistance = INFINATY;
	for (int a = FIRST; a <= verticies-1; a++){
		
		if (adjacencies[current] != adjacencies[a] &&
			((bitmask & (1 << a)) == 0)){
						
			double dist = adjMatrix[current][adjacencies[a]->GetId()] +
									TSPDP(a, bitmask | (1 << a));
			
			if(minDistance > dist){
				minDistance = dist;
			}
		}
	}
	
	table[current][bitmask] = minDistance;
	
	return minDistance;
}

/*  Function: MinimumSpanningTree
 *--------------------------------------------------
 *	Usage: MinimumSpanningTree()
 *--------------------------------------------------
 *  Uses Kruskal’s algorithm to find the Minimum
 *	Spanning Tree (MST) for this Graph. Stores the
 *	edges of the MST in the adjacency list of each
 *	Vertex
 */
void Graph::MinimumSpanningTree(){
	int numEdges = FIRST;
	
	//	Place each vertex in its own cluster or set
	DisjointSet *set = new DisjointSet(verticies);
	
	for (int i = FIRST; i < adjacencies.size(); i++){
		Vertex *v = adjacencies[i];
		MST.push_back(v);
	}
	
	while(numEdges != verticies-1){
		
		//	Take the edge e with the smallest weight
		Edge *e = edges.top();
		edges.pop();
		
		int s = e->GetSource()->GetId(); //Source
		int d = e->GetDestination()->GetId(); //Destination
		
		if (!set->SameComponent(s,d)){
			
			set->Union(s, d);
			numEdges++;
			adjacencies[s]->AddAdjacency(adjacencies[d]);
			adjacencies[d]->AddAdjacency(adjacencies[s]);
		}
	}
}


/*  Function: DepthFirstSearch
 *--------------------------------------------------
 *	Usage: DepthFirstSearch()
 *--------------------------------------------------
 *  Returns:  approximation for the TSP tour taken
 *	by traversing the vertices in depth first order of
 *	the sub-graph formed from the MST
 */
double Graph::DepthFirstSearch(){

	double dist = FIRST;
	
	bool *visited = new bool[verticies];
	
	//   initialise visited array to false
	for (int b = 0; b < verticies; b++) {
		visited[b] = false;
	}
	
	stack<Vertex*> stack;
	stack.push(MST[FIRST]);
	visited[FIRST] = true;
	
	Vertex *current = NULL;
	Vertex *previous = NULL;
	
	while(!stack.empty()){		
		current = stack.top();
		stack.pop();

		if(previous != NULL){
			dist = dist + adjMatrix[previous->GetId()][current->GetId()];
		}
		
		vector<Vertex*> adjacent = current->GetAdjacencies();
		for(int v = FIRST; v < adjacent.size(); ++v){
			
			if(!visited[adjacent[v]->GetId()]){
				
				stack.push(adjacencies[adjacent[v]->GetId()]);
				visited[adjacent[v]->GetId()] = true;
			}
		}
		previous = current;
	}
	return dist + adjMatrix[current->GetId()][MST[FIRST]->GetId()];;
}
