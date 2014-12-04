//============================================================================
// Name        : Etoh.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Etoh Algorithm
//============================================================================


#ifndef __libAntidote__Etoh__
#define __libAntidote__Etoh__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Etoh: public Antidote {
        
    public:
        Etoh(double age, double height, double weight);
        virtual ~Etoh();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a, b, c;
    
    
    };
}

#endif /* defined(__libAntidote__Etoh__) */



