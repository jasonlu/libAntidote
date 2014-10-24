//============================================================================
// Name        : Antidote.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : The abstract class for all algorithm to inheritance from.
//============================================================================

#include "Antidote.h"

namespace libAntidote {

Antidote::Antidote(double age, double height, double weight) {
	// TODO Auto-generated constructor stub
	this->age = age;
	this->heightcm = height;
	this->weightkg = weight;

}

Antidote::~Antidote() {
	// TODO Auto-generated destructor stub
}


string Antidote::getRef() {
	return "Ref...";
}

}
