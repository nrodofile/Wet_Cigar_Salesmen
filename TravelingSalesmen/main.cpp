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
using namespace std;

string testInt(int test, int expected){
	if ( test == expected){
		return "pass";
	}else{
		cout << test << "\t";
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

int main(int argc, const char * argv[])
{

	// insert code here...
	cout << "Hello, World!\n";
	
	testPoint();
	testDisjoint();
	testVerticies();
	
	    return 0;
}


