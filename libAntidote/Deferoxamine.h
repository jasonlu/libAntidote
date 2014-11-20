//============================================================================
// Name        : Deferoxamine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Deferoxamine Algorithm
//============================================================================


#ifndef __libAntidote__Deferoxamine__
#define __libAntidote__Deferoxamine__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Deferoxamine: public Antidote {
        
    public:
        Deferoxamine(double age, double height, double weight);
        virtual ~Deferoxamine();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string calculateBIG();
        string rateBIG15();
        string rateBIGDuration();
    
    
    
    };
}

#endif /* defined(__libAntidote__Deferoxamine__) */



