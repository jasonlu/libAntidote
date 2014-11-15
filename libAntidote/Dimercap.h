//============================================================================
// Name        : Dimercap.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Dimercap Algorithm
//============================================================================


#ifndef __libAntidote__Dimercap__
#define __libAntidote__Dimercap__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Dimercap: public Antidote {
        
    public:
        Dimercap(double age, double height, double weight);
        virtual ~Dimercap();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string calculateBIG();
        string rateBIG15();
        string rateBIGDuration();
    
    
    
    };
}

#endif /* defined(__libAntidote__Dimercap__) */



