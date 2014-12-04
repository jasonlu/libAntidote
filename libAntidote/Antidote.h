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

#define FDA "FDA approved use."
#define FDO "Unapproved use."


namespace libAntidote {

using namespace std;

class Antidote {
public:
	Antidote(double age, double height, double weight);
	virtual ~Antidote();

	// Pure virtual function, the C++ way for abstract method
	// Append =0 to make a function "pure virtual"
	// virtual string getResult() = 0;
    virtual Question* getNextQuestion() = 0;
	virtual string getRef();
    
    bool hasMoreQuestions();
    bool submit(Question *q);

protected:
    
    void insertToMap(string str, Question *question);
    void insertToMap(string str, string question);
	string input;
	
    double age, heightcm, weightkg;
    
    typedef std::pair<std::string, Question*> strQuestionMapPair;
    map<string, Question*> prompts;
    bool moreQuestions;

    //enum fdaApprovedEnum {FDA_NOT_APPROVED = 0, FDA_APPROVED = 1, FDA_QUESTIONABLE = 2};
    //int flowchartFinalized;
    
	template <typename T> string toStr(const T& t) {
	   ostringstream os;
	   os<<t;
	   return os.str();
	}

private:

};
}

#endif /* ANTIDOTE_H_ */
