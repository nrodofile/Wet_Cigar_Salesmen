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
	
//	for (int i = 0; i < V; i++) {
//		//edges[i] = *new int[V];
//		vector<Edge> e;
//		for(int j = 0; j < V; j++){
//			e.push_back(NULL);
//		}
//		edges.push_back(e);
//	}
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
	vector<Edge*> e;
	adjacencies.push_back(vertex);
	edges.push_back(e);
	
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
//	int s = (edge->GetSource())->GetId();
//	int d = (edge->GetDestination())->GetId();
	
	int s = GetIndex(edge->GetSource(), adjacencies);
	vector<Edge*> e = edges[s];
	e.push_back(edge);
	edges[s] = e;
	
	//edges[s][d] = edge->GetWeight();
	//edges[s][d] = edge;

//	
//	map< int, vector <Edge*> >::iterator it;	
//	int id = (edge->GetSource())->GetId();
//	it = edges.find(id);
//	vector<Edge*> e;
//	if(it != edges.end()){
//		vector<Edge*> e = edges.at(id);
//		e.push_back(edge);
//		it->second = e;
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
	
	//	create array of bool named visited with size = numVertices
	vector<int> visited;
	
	//bool *visited;
	
	//	initialise visited to false
	//visited = new bool[verticies];
	visited.assign(verticies, 0);
	
	//for (int i = 0; i < verticies; i++) {
	//	visited[i] = false;
	//}
	
	//	set first element of visited to true
	visited[0] = true;
	
	//	result = TSPBruteForce(0, visited)
	//double result = TSPBruteForce(0, visited);
	
	//delete visited;
	
	//-------
	//	Create memoisation table [N][(1 << N)]
	//	Set all values in table to UNSET
	for(int b = 0; b < verticies; b++){
		bitset<23> t;
		MT.push_back(t);
	}
	
	double result2 = TSPDP(0, 1);
	
	return result2;
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
	for (int i = 0 ; i < MST.size(); ++i){
		cout << MST[i]->ToString() << endl;
	}
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
double Graph::TSPBruteForce(int current, vector<int> visited){
	double minDistance; 
	
//	if all elements in visited are true
	bool visitedAll = true; 
	for (int v = 0; v < verticies; v++){
		if(!visited[v]){
			visitedAll = false;
			break;
		}
	}
	
	if (visitedAll){
		
//		return distance from current to 0
		return  GetWeight(adjacencies[current], adjacencies[0]);
	}
//	make a copy of visited
	vector<int> visitedCp;
	visitedCp.assign(verticies, 0);
	//bool* visitedCp = new bool[verticies];
	
	for (int b = 0; b < verticies; b++){
		visitedCp[b] = visited[b];
	}
		
//	set minDistance to INFINITY
	minDistance = INFINATY;
	
//	for adjacent from 0 to numVertices-1
	for (int a = 0; a <= verticies-1; ++a){
		
//		if current != adjacent AND adjacent not visited
		if (current != adjacencies[a]->GetId() && !visited[a]){
			
//			set adjacent in copy of visited to true
			visitedCp[a] = true;
			
//			dist = distance from current to adjacent +
//			TSPBruteForce(adjacent, copy of visited)
			double dist =
				GetWeight(adjacencies[current],adjacencies[a]) +
						TSPBruteForce(adjacencies[a]->GetId(),visitedCp);

//			minDistance = minimum(minDistance, dist)
			if(minDistance > dist){
				minDistance = dist;
			}
			
//			set adjacent in copy of visited to false
			visitedCp[a] = false;
		}
	}
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
	
//	TSPDP(current, bitmask):
//	if table[current][bitmask] is not UNSET
	if (MT[current][bitmask]){
		
//		return table[current][bitmask]
		return MT[current][bitmask];
	}

//	if bitmask == ((1 << N) – 1)
	if(bitmask == (1 << verticies) - 1){

//		return distance from current to 0
		return GetWeight(adjacencies[current], adjacencies[0]);
	}

//	minDistance = INFINTY
	double minDistance = INFINATY;
	
//	for adjacent from 0 to N-1
	for (int a = 0; a <= verticies-1; a++){
		
//		if current != adjacent AND
		//	((bitmask & (1 << adjacent)) == 0)
		if (adjacencies[current] != adjacencies[a] &&
			((bitmask & (1 << a)) == 0)){
			
//			dist = distance from current to adjacent +
//			TSPDP(adjacent, (bitmask | (1 << adjacent)))			
			double dist = GetWeight(adjacencies[current], adjacencies[a])+
									TSPDP(a, bitmask | (1 << a));
			
//			minDistance = min(minDistance, dist)
			if(minDistance > dist){
				minDistance = dist;
			}
		}
	}
	
//	table[current][bitmask] = minDistance
	MT[current][bitmask] = minDistance;
	
//	return minDistance
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
//	1.Place each vertex in its own cluster or
//	set
	int numEdges = 0;
	int eIdx = 0;
	SortEdges();
	DisjointSet *set = new DisjointSet(verticies);
	for (int i = 0; i < adjacencies.size(); i++){
		Vertex *v = adjacencies[i];
		v->ClearAdjacentcies();
		MST.push_back(v);
	}

	while(numEdges != adjacencies.size()-1){
//	2.Take the edge e with the smallest weight
		Edge e = *SortedEdges[eIdx];
		int s = e.GetSource()->GetId(); //Source
		int d = e.GetDestination()->GetId(); //Destination
		
//		a) If e connects two vertices in different
		if (!set->SameComponent(s,d)){
			
//		clusters, then e is added to the MST and the
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
	}
//	3.Continue until N – 1 edges are selected
	
	
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

	int dist = 0;
	
//	initialise visited array to false
	vector<int> visited;
	visited.assign(adjacencies.size(), 0);

//	create empty stack
	stack<Vertex*> stack;
	
//	push vertex 0 onto stack
	stack.push(MST[0]);
	
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
		if(previous != NULL){
			
//			dist = dist + distance from previous to current
			dist = dist + GetWeight(previous, current);

		}

//		for vertices adjacent to current
		vector<Vertex*> adjacent = current->GetAdjacencies();
		for(int v = 0; v < adjacent.size(); ++v){
			
//			if adjacent vertex not visited
			if(!visited[adjacent[v]->GetId()]){
//				push adjacent vertex onto stack
				stack.push(adjacent[v]);
				
//				mark adjacent vertex visited
				visited[adjacent[v]->GetId()] = true;
			}
		}
	
//		previous = current
		previous = current;
	}


//	dist = distance from current to vertex 0
	dist = dist + GetWeight(current, adjacencies[0]);

	return dist;
}

double Graph::GetWeight(Vertex *p, Vertex *c){
	vector<Edge*> e;
	e = edges[GetIndex(p, adjacencies)];
	
	for(int j = 0; j < e.size(); j++){
		if((e[j]->GetDestination())->GetId() == c->GetId()){
			return e[j]->GetWeight();
		}
	}
	return INFINATY;
}

void Graph::SortEdges(){
	for(int i = 0; i< adjacencies.size(); i++){
		for (int j = 0; j < edges[i].size(); j++){
			SortedEdges.push_back(edges[i][j]);
		}
	}
	sort(SortedEdges.begin(), SortedEdges.end(), EdgeComparer());
}

int Graph::GetIndex(Vertex *v, vector<Vertex*> a){
	for(int i = 0; i < a.size(); i++){
		if(a[i]->GetId() == v->GetId()){
			return i;
		}
	}
	return NULL;
}
