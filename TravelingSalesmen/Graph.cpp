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
	edges.push_back(edge);

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
			//	Set all values in table to UNSET
			for(int b = FIRST; b < verticies; b++){
				bitset<TSPDP_MAX> set;
				MT.push_back(set);
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
	
	for (int i = FIRST ; i < MST.size(); ++i){
		cout << MST[i]->ToString() << endl;
	}/////TEST
	
	cout << endl;
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
	
//	return minDistance
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
	int eIdx = FIRST;
	
	//	1.Place each vertex in its own cluster or set
	sort(edges.begin(), edges.end(), EdgeComparer());
	DisjointSet *set = new DisjointSet(verticies);
	
	for (int i = FIRST; i < adjacencies.size(); i++){
		Vertex *v = adjacencies[i];
		v->ClearAdjacentcies();
		MST.push_back(v);
	}

	while(numEdges != verticies-1){
//	2.Take the edge e with the smallest weight

		int s = edges[eIdx]->GetSource()->GetId(); //Source
		int d = edges[eIdx]->GetDestination()->GetId(); //Destination
		
//		a) If e connects two vertices in different clusters, 
		if (!set->SameComponent(s,d)){
			
//		then e is added to the MST and the
//		two clusters connected by e are merged into a
//		single cluster
			
			set->Union(s, d);
			numEdges++;
			MST[s]->AddAdjacency(MST[d]);
			MST[d]->AddAdjacency(MST[s]);
			
		}
		
//		b) If e connects two vertices which are already
//		in the same cluster, ignore it
		eIdx ++;
		
//	3.Continue until N – 1 edges are selected
	}
	
	delete set;
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

	int dist = START;
	
	vector<bool> visited;
	visited.assign(adjacencies.size(), false);

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
				stack.push(adjacent[v]);
				visited[adjacent[v]->GetId()] = true;
			}
		}
		previous = current;
	}
	return dist + adjMatrix[current->GetId()][adjacencies[FIRST]->GetId()];
}
