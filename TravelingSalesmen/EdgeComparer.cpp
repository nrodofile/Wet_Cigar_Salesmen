//
//  EdgeComparer.cpp
//  TravelingSalesmen
//
//  Created by Nicholas Rodofile on 13/05/13.
//  Copyright (c) 2013 Nicholas Rodofile. All rights reserved.
//

#include "EdgeComparer.h"

bool EdgeComparer::operator()(Edge *first, Edge *second){
	return (first->GetWeight() < second->GetWeight());
}