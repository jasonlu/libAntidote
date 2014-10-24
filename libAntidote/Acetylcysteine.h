//============================================================================
// Name        : Acetylcysteine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Acetylcysteine Algorithm
//============================================================================

#ifndef ACETYLCYSTEINE_H_
#define ACETYLCYSTEINE_H_

#include "Antidote.h"

namespace libAntidote {

using namespace std;

class Acetylcysteine: public Antidote {


public:
	Acetylcysteine(double age, double height, double weight);
	virtual ~Acetylcysteine();
    
	// was string stringAcetylcysteineRef();
	string getRef();
	// was string acetylcysteine(double age, double heightcm, double weightkg);
	string getResult();

	virtual bool hasMoreQuestions();
    virtual Question* getNextQuestion();
	virtual bool submit(Question *q);




protected:
    
    typedef std::pair<std::string, Question*> strQuestionMapPair;
    map<string, Question*> prompts;


private:
	double hoursSinceExposure, toxinLevel, sampleHoursAfterExposure;
	bool moreQuestions;
    
    string calculateActivatedCharcoal();
    string calculateAcetylcysteine();
    string bloodSampleSuggestions();
    bool apapToxicityTest();
    double treatmentThreshold();

};






}
#endif /* ACETYLCYSTEINE_H_ */
