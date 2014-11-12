//============================================================================
// Name        : BATbotulism.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : BATbotulism Algorithm
//============================================================================


#ifndef __libAntidote__BabyBIG__
#define __libAntidote__BabyBIG__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class BATbotulism: public Antidote {
        
    public:
        BATbotulism(double age, double height, double weight);
        virtual ~BATbotulism();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:

        double calculateDripRate();
        string calculateInfantRate();
        double SalisburyRule();
    };
}

#endif /* defined(__libAntidote__BabyBIG__) */



