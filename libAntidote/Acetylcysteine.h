//============================================================================
// Name        : Acetylcysteine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Acetylcysteine Algorithm
//============================================================================

#ifndef __libAntidote__Acetylcysteine_H__
#define __libAntidote__Acetylcysteine_H__

#include "Antidote.h"

namespace libAntidote {

using namespace std;

class Acetylcysteine: public Antidote {

public:
	Acetylcysteine(double age, double height, double weight);
	virtual ~Acetylcysteine();
	string getRef();
    virtual Question* getNextQuestion();

protected:
    

private:
    string calculateActivatedCharcoal();
    string calculateAcetylcysteine();
    string bloodSampleSuggestions();
    
    double hoursSinceExposure, toxinLevel, sampleHoursAfterExposure; // Remove this, unused?
    bool apapToxicityTest();        // Remove this, unused?
    double treatmentThreshold();    // Remove this, unused?
};


}
#endif /* __libAntidote__Acetylcysteine_H__ */
