//============================================================================
// Name        : Physostigmine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Physostigmine Algorithm
//============================================================================


#ifndef __libAntidote__Physostigmine__
#define __libAntidote__Physostigmine__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Physostigmine: public Antidote {
        
    public:
        Physostigmine(double age, double height, double weight);
        virtual ~Physostigmine();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
        double physCalcChild();
    
    
    
    };
}

#endif /* defined(__libAntidote__Physostigmine__) */



