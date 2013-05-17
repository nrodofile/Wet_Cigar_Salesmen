//
//  main.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include <iostream>
#include "Point.h"
#include "DisjointSet.h"
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
using namespace std;

string testInt(int test, int expected){
	if ( test == expected){
		return "pass";
	}else{
		cout << expected << " Got " << test << "\t";
		return "fail";
	}
}

string testBool(bool test, bool expected){
	if ( test == expected){
		return "pass";
	}else{
		cout << test << "\t";
		return "fail";
	}
}

string testVertex(Vertex test, int expected[]){
	vector<Vertex*> list = test.GetAdjacencies();
	for(int i = 0; i < list.size(); ++i){
		int id = list[i]->GetId();
		int exp = expected[i];
		if(testInt(id, exp) != "pass"){
			return "fail";
		}
	}
	return "pass";
}

void testPoint(){
	
	cout << endl << "Point Test" << endl;
	Point *point1 = new Point(2,1);
	Point *point2 = new Point(2,3);
	Point *point3 = new Point(3,1);
	Point *point4 = new Point(2,4);
	Point *point5 = new Point(5,1);
	Point *point6 = new Point(2,7);
	Point *point7 = new Point(16,40);
	Point *point8 = new Point(22,4);
	
	cout << testInt(point1->DistanceTo(point2), 2) << endl;
	cout << testInt(point1->DistanceTo(point3), 1) << endl;
	cout << testInt(point1->DistanceTo(point4), 3) << endl;
	cout << testInt(point1->DistanceTo(point5), 3) << endl;
	cout << testInt(point1->DistanceTo(point6), 6) << endl;
	cout << testInt(point2->DistanceTo(point3), 2) << endl;
	cout << testInt(point2->DistanceTo(point4), 1) << endl;
	cout << testInt(point2->DistanceTo(point5), 3) << endl;
	cout << testInt(point2->DistanceTo(point6), 4) << endl;
	cout << testInt(point7->DistanceTo(point8), 36) << endl;
	
	delete point1;
	delete point2;
	delete point3;
	delete point4;
	delete point5;
	delete point6;
	delete point7;
	delete point8;
}

void testDisjoint(){
	cout << endl << "Disjoint Test" << endl;
	DisjointSet *set1 = new DisjointSet(10);
	cout << testBool(set1->SameComponent(3, 4), false) << endl;
	set1->Union(3, 4);
	cout << testBool(set1->SameComponent(3, 4), true) << endl;
	cout << testBool(set1->SameComponent(4, 9), false) << endl;
	set1->Union(4, 9);
	cout << testBool(set1->SameComponent(4, 9), true) << endl;
	cout << testBool(set1->SameComponent(8, 0), false) << endl;
	set1->Union(8, 0);
	cout << testBool(set1->SameComponent(8, 0), true) << endl;
	cout << testBool(set1->SameComponent(2, 3), false) << endl;
	set1->Union(2, 3);
	cout << testBool(set1->SameComponent(2, 3), true) << endl;
	cout << testBool(set1->SameComponent(5, 6), false) << endl;
	set1->Union(5, 6);
	cout << testBool(set1->SameComponent(5, 6), true) << endl;
	cout << testBool(set1->SameComponent(5, 9), false) << endl;
	set1->Union(5, 9);
	cout << testBool(set1->SameComponent(5, 9), true) << endl;
	cout << testBool(set1->SameComponent(7, 3), false) << endl;
	set1->Union(7, 3);
	cout << testBool(set1->SameComponent(7, 3), true) << endl;
	cout << testBool(set1->SameComponent(4, 8), false) << endl;
	set1->Union(4, 8);
	cout << testBool(set1->SameComponent(4, 8), true) << endl;
	cout << testBool(set1->SameComponent(6, 1), false) << endl;
	set1->Union(6, 1);
	cout << testBool(set1->SameComponent(6, 1), true) << endl;

	
	delete set1;
}

void testVerticies(){
	cout << endl << "Verticies Test" << endl;
	Vertex *v1 = new Vertex(1);
	Vertex *v2 = new Vertex(2);
	Vertex *v3 = new Vertex(3);
	Vertex *v4 = new Vertex(4);
	Vertex *v5 = new Vertex(5);
	Vertex *v6 = new Vertex(6);
	Vertex *v7 = new Vertex(7);
	Vertex *v8 = new Vertex(8);
	Vertex *v9 = new Vertex(9);
	Vertex *v10 = new Vertex(10);
	
	cout << testInt(v1->GetId(), 1) << endl;
	cout << testInt(v2->GetId(), 2) << endl;
	cout << testInt(v3->GetId(), 3) << endl;
	cout << testInt(v4->GetId(), 4) << endl;
	cout << testInt(v5->GetId(), 5) << endl;
	cout << testInt(v6->GetId(), 6) << endl;
	cout << testInt(v7->GetId(), 7) << endl;
	cout << testInt(v8->GetId(), 8) << endl;
	cout << testInt(v9->GetId(), 9) << endl;
	cout << testInt(v10->GetId(), 10) << endl;
	
	cout << endl << "Verticies Adjacentcies Test" << endl;
	v1->AddAdjacency(v2);
	v1->AddAdjacency(v3);
	v1->AddAdjacency(v4);
	v1->AddAdjacency(v5);
	int test1[] = {2, 3, 4, 5};
	cout << testVertex(*v1, test1) << endl;

	v2->AddAdjacency(v5);
	v2->AddAdjacency(v3);
	v2->AddAdjacency(v8);
	v2->AddAdjacency(v1);
	int test2[] = {5, 3, 8, 1};
	cout << testVertex(*v2, test2) << endl;
	
	v3->AddAdjacency(v8);
	v3->AddAdjacency(v1);
	v3->AddAdjacency(v10);
	v3->AddAdjacency(v6);
	int test3[] = {8, 1, 10, 6};
	cout << testVertex(*v3, test3) << endl;
	
	delete v1;
	delete v2;
	delete v3;
	delete v4;
	delete v5;
	delete v6;
	delete v7;
	delete v8;
	delete v9;
	delete v10;
}

void testEdge(){
	cout << endl << "Edge Test" << endl;
	Vertex *v1 = new Vertex(1);
	Vertex *v2 = new Vertex(2);
	Vertex *v3 = new Vertex(3);
	Vertex *v4 = new Vertex(4);
	Vertex *v5 = new Vertex(5);
	
	Edge *e1 = new Edge(v1, v2, 3);
	Edge *e2 = new Edge(v2, v3, 6);
	Edge *e3 = new Edge(v3, v4, 8);
	Edge *e4 = new Edge(v4, v5, 7);
	Edge *e5 = new Edge(v5, v1, 5);
	
	cout << testInt((e1->GetSource())->GetId(), 1) << endl;
	cout << testInt((e1->GetDestination())->GetId(), 2) << endl;
	cout << testInt(e1->GetWeight(), 3) << endl;
	
	cout << testInt((e2->GetSource())->GetId(), 2) << endl;
	cout << testInt((e2->GetDestination())->GetId(), 3) << endl;
	cout << testInt(e2->GetWeight(), 6) << endl;
	
	cout << testInt((e3->GetSource())->GetId(), 3) << endl;
	cout << testInt((e3->GetDestination())->GetId(), 4) << endl;
	cout << testInt(e3->GetWeight(), 8) << endl;
	
	cout << testInt((e4->GetSource())->GetId(), 4) << endl;
	cout << testInt((e4->GetDestination())->GetId(), 5) << endl;
	cout << testInt(e4->GetWeight(), 7) << endl;
	
	cout << testInt((e5->GetSource())->GetId(), 5) << endl;
	cout << testInt((e5->GetDestination())->GetId(), 1) << endl;
	cout << testInt(e5->GetWeight(), 5) << endl;

	
	delete e1;
	delete e2;
	delete e3;
	delete e4;
	delete e5;
	delete v1;
	delete v2;
	delete v3;
	delete v4;
	delete v5;

}

void testGraph(){
	cout << endl << "Edge Graph" << endl;
	Vertex *A = new Vertex(0);
	Vertex *B = new Vertex(1);
	Vertex *C = new Vertex(2);
	Vertex *D = new Vertex(3);
	Vertex *E = new Vertex(4);
	Vertex *F = new Vertex(5);
	
	A->AddAdjacency(B);
	A->AddAdjacency(C);
	A->AddAdjacency(E);

	Edge *e1 = new Edge(A, B, 5);
	Edge *e2 = new Edge(A, C, 4);
	Edge *e3 = new Edge(A, E, 2);
	
	B->AddAdjacency(A);
	B->AddAdjacency(D);
	B->AddAdjacency(F);
	
	Edge *e4 = new Edge(B, A, 5);
	Edge *e5 = new Edge(B, D, 2);
	Edge *e6 = new Edge(B, F, 3);
	
	C->AddAdjacency(A);
	C->AddAdjacency(E);
	
	Edge *e7 = new Edge(C, A, 4);
	Edge *e8 = new Edge(C, E, 3);
	
	D->AddAdjacency(A);
	D->AddAdjacency(B);
	D->AddAdjacency(E);
	D->AddAdjacency(F);
	
	Edge *e9 = new Edge(D, A, 6);
	Edge *e10 = new Edge(D, B, 2);
	Edge *e11 = new Edge(D, E, 1);
	Edge *e12 = new Edge(D, F, 2);
	
	E->AddAdjacency(A);
	E->AddAdjacency(C);
	E->AddAdjacency(F);
	
	Edge *e13 = new Edge(E, A, 2);
	Edge *e14 = new Edge(E, C, 3);
	Edge *e15 = new Edge(E, F, 4);
	
	F->AddAdjacency(B);
	F->AddAdjacency(D);
	F->AddAdjacency(E);
	
	Edge *e16 = new Edge(F, B, 3);
	Edge *e17 = new Edge(F, D, 2);
	Edge *e18= new Edge(F, E, 4);
	
	Graph *graph1 = new Graph(6);
	graph1->AddVertex(A);
	graph1->AddVertex(B);
	graph1->AddVertex(C);
	graph1->AddVertex(D);
	graph1->AddVertex(E);
	graph1->AddVertex(F);
	
	int test0[] = {1, 2, 4};
	cout << testVertex(*graph1->GetVertex(0), test0) << endl;
	
	int test1[] = {0, 3, 5};
	cout << testVertex(*graph1->GetVertex(1), test1) << endl;
	
	int test2[] = {0, 4};
	cout << testVertex(*graph1->GetVertex(2), test2) << endl;
	
	int test3[] = {0, 1, 4, 5};
	cout << testVertex(*graph1->GetVertex(3), test3) << endl;
	
	int test4[] = {0, 2, 5};
	cout << testVertex(*graph1->GetVertex(4), test4) << endl;
	
	int test5[] = {1, 3, 4};
	cout << testVertex(*graph1->GetVertex(5), test5) << endl;
	



	delete e1;
	delete e2;
	delete e3;
	delete e4;
	delete e5;
	delete e6;
	delete e7;
	delete e8;
	delete e9;
	delete e10;
	delete e11;
	delete e12;
	delete e13;
	delete e14;
	delete e15;
	delete e16;
	delete e17;
	delete e18;
	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete F;
	
}




int main(int argc, const char * argv[])
{

	// insert code here...
	cout << "Hello, World!\n";
	
	testPoint();
	testDisjoint();
	testVerticies();
	testEdge();
	testGraph();
	
	    return 0;
}


