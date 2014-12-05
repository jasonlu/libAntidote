//============================================================================
// Name        : SodiumBicarbonate.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : SodiumBicarbonate Algorithm
//============================================================================


#ifndef __libAntidote__SodiumBicarbonate__
#define __libAntidote__SodiumBicarbonate__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class SodiumBicarbonate: public Antidote {
        
    public:
        SodiumBicarbonate(double age, double height, double weight);
        virtual ~SodiumBicarbonate();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
    
    
    };
}

#endif /* defined(__libAntidote__SodiumBicarbonate__) */



