//============================================================================
// Name        : Octreotide.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Octreotide Algorithm
//============================================================================


#ifndef __libAntidote__Octreotide__
#define __libAntidote__Octreotide__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Octreotide: public Antidote {
        
    public:
        Octreotide(double age, double height, double weight);
        virtual ~Octreotide();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
        string octCalcChild();
    
    
    
    };
}

#endif /* defined(__libAntidote__Octreotide__) */



