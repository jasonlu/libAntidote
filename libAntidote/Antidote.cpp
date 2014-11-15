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
    this->moreQuestions = true;
    this->fdaApproved = FDA_APPROVED;
    this->flowchartFinalized = true;
}

Antidote::~Antidote() {
	// TODO Auto-generated destructor stub
}

void Antidote::insertToMap(string str, Question *question) {
    prompts.insert(strQuestionMapPair(str, question));
}
    
void Antidote::insertToMap(string str, string question) {
    prompts.insert(strQuestionMapPair(str, new Question(question)));
}

string Antidote::getRef() {
	return "Ref...";
}
    
bool Antidote::hasMoreQuestions()  {
    return this->moreQuestions;
}

    
bool Antidote::submit(Question *q) {
    this->moreQuestions = false;
    return false;
}

}
