//============================================================================
// Name        : BabyBIG.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : BabyBIG Algorithm
//============================================================================


#ifndef __libAntidote__BabyBIG__
#define __libAntidote__BabyBIG__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class BabyBIG: public Antidote {
        
    public:
        BabyBIG(double age, double height, double weight);
        virtual ~BabyBIG();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string calculateBIG();
        string rateBIG15();
        string rateBIGDuration();
    
    
    
    };
}

#endif /* defined(__libAntidote__BabyBIG__) */



