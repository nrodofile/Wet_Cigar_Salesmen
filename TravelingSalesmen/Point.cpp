//
//  Point.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "Point.h"

/*  Function: Point - Constructor
 *--------------------------------------------------
 *	Usage: Point(x, y)
 *-------------------------------------------------
 *  Constructor that sets the x and y co-ordinates for
 *	the Point object
 */
Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

/*  Function: Point - Destructor
 *--------------------------------------------------
 *	Usage: ~Point()
 *-------------------------------------------------
 */
Point::~Point(){
	
}

/*  Function:
 *--------------------------------------------------
 *	Usage: GetX
 *--------------------------------------------------
 *  Returns: the X position for this point
 */
int Point::GetX(){
	return x;
}

/*  Function:
 *--------------------------------------------------
 *	Usage: GetY
 *--------------------------------------------------
 *  Returns: the Y position for this point
 */
int Point::GetY(){
	return y;
}

/*  Function: DistanceToPoint
 *--------------------------------------------------
 *	Usage: distance = point.DistanceToPoint(point2)
 *-------------------------------------------------
 *  Returns: the Euclidean distance between this Point
 *	and the Point* parameter to the function
 */
double Point::DistanceTo(Point *point){
	
	double squared = 2.0;
	return sqrt((pow(x - point->GetX(), squared) +
			pow(y - point->GetY(), squared)));
}

/*  Function: ToString
 *--------------------------------------------------
 *	Usage: string = point->ToString()
 *-------------------------------------------------
 *  Returns: string representation of this Point
 */
string Point::ToString(){
	return "(" + to_string(x) + ", " + to_string(y) + ")"; 
}