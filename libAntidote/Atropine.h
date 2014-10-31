//============================================================================
// Name        : Atropine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Atropine Algorithm
//============================================================================

#ifndef __libAntidote__Atropine__
#define __libAntidote__Atropine__

#include "Antidote.h"

namespace libAntidote {
    
using namespace std;
    
class Atropine: public Antidote {

public:
    Atropine(double age, double height, double weight);
	virtual ~Atropine();
    
    // override
    string getRef();
    Question* getNextQuestion();
    string calculateAtropine();

private:
    
};
    
    
    
}
#endif /* defined(__libAntidote__Atropine__) */
