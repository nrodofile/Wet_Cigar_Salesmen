//
//  main.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include <iostream>
#include "Point.h"
using namespace std;

string test(int test, int expected){
	if ( test == expected){
		return "pass";
	}else{
		cout << test << "\t";
		return "fail";
	}
}

int main(int argc, const char * argv[])
{

	// insert code here...
	cout << "Hello, World!\n";
	
	Point *point1 = new Point(2,1);
	Point *point2 = new Point(2,3);
	Point *point3 = new Point(3,1);
	Point *point4 = new Point(2,4);
	Point *point5 = new Point(5,1);
	Point *point6 = new Point(2,7);	
	Point *point7 = new Point(16,40);
	Point *point8 = new Point(22,4);
	
	cout << test(point1->DistanceTo(point2), 2) << endl;
	cout << test(point1->DistanceTo(point3), 1) << endl;
	cout << test(point1->DistanceTo(point4), 3) << endl;
	cout << test(point1->DistanceTo(point5), 3) << endl;
	cout << test(point1->DistanceTo(point6), 6) << endl;
	cout << test(point2->DistanceTo(point3), 2) << endl;
	cout << test(point2->DistanceTo(point4), 1) << endl;
	cout << test(point2->DistanceTo(point5), 3) << endl;
	cout << test(point2->DistanceTo(point6), 4) << endl;
	cout << test(point7->DistanceTo(point8), 36) << endl;
	
	delete point1;
	delete point2;
	delete point3;
	delete point4;
	delete point5;
	delete point6;
	delete point7;
	delete point8;
    return 0;
}


