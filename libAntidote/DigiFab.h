//============================================================================
// Name        : DigiFab.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : DigiFab Algorithm
//============================================================================


#ifndef __libAntidote__DigiFab__
#define __libAntidote__DigiFab__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class DigiFab: public Antidote {
        
    public:
        DigiFab(double age, double height, double weight);
        virtual ~DigiFab();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        
    
    
    
    };
}

#endif /* defined(__libAntidote__DigiFab__) */



