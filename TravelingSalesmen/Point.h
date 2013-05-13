//
//  Point.h
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#ifndef __TravelingSalesmen__Point__
#define __TravelingSalesmen__Point__

#include <iostream>

using namespace std;

class Point
{
public:
/*  Function: Point - Constructor
 *--------------------------------------------------
 *	Usage: Point(x, y)
 *-------------------------------------------------
 *  Constructor that sets the x and y co-ordinates for
 *	the Point object
 */
	Point(int x, int y);

/*  Function: Point - Destructor
 *--------------------------------------------------
 *	Usage: ~Point()
 *-------------------------------------------------
 */
	~Point();
	
/*  Function: DistanceToPoint
 *--------------------------------------------------
 *	Usage: distance = point.DistanceToPoint(point2)
 *-------------------------------------------------
 *  Returns: the Euclidean distance between this Point
 *	and the Point* parameter to the function
 */
	double DistanceTo(Point*);

/*  Function: ToString
 *--------------------------------------------------
 *	Usage: string = point->ToString()
 *-------------------------------------------------
 *  Returns: string representation of this Point
 */
	string ToString();
private:
	//co-ordinates on the plane
	int x;
	int y;
};


#endif /* defined(__TravelingSalesmen__Point__) */
