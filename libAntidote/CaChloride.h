//============================================================================
// Name        : CaChloride.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CaChloride Algorithm
//============================================================================


#ifndef __libAntidote__CaChloride__
#define __libAntidote__CaChloride__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class CaChloride: public Antidote {
        
    public:
        CaChloride(double age, double height, double weight);
        virtual ~CaChloride();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        double childMaxGl();
        double childMaxCl();
        double adultGl();
        double adultCl();
        
        
    };
}

#endif /* defined(__libAntidote__CaChloride__) */



