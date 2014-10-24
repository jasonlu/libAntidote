//============================================================================
// Name        : Antidote.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : The abstract class for all algorithm to inheritance from.
//============================================================================
#ifndef ANTIDOTE_H_
#define ANTIDOTE_H_

//#include <iostream>
//#include <string>
#include <math.h>
#include <sstream>
#include <map>

#include "Question.h"


namespace libAntidote {

using namespace std;

class Antidote {
public:
	Antidote(double age, double height, double weight);
	virtual ~Antidote();

	// Pure virtual function, the C++ way for abstract method
	// Append =0 to make a function "pure virtual"
	// virtual string getResult() = 0;
	virtual string getRef();
	virtual bool hasMoreQuestions() = 0;
    virtual Question* getNextQuestion() = 0;
	virtual bool submit(Question *q) = 0;

protected:
	string input;
	double age, heightcm, weightkg;
	template <typename T> string toStr(const T& t) {
	   ostringstream os;
	   os<<t;
	   return os.str();
	}

private:

};
}

#endif /* ANTIDOTE_H_ */
