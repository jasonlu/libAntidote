//============================================================================
// Name        : Flumazenil.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Flumazenil Algorithm
//============================================================================


#ifndef __libAntidote__Flumazenil__
#define __libAntidote__Flumazenil__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Flumazenil: public Antidote {
        
    public:
        Flumazenil(double age, double height, double weight);
        virtual ~Flumazenil();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a, b, c;
        double calcFlum();
    
    
    };
}

#endif /* defined(__libAntidote__Flumazenil__) */



