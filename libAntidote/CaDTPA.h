//============================================================================
// Name        : CaDTPA.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CaDTPA Algorithm
//============================================================================


#ifndef __libAntidote__CaDTPA__
#define __libAntidote__CaDTPA__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class CaDTPA: public Antidote {
        
    public:
        CaDTPA(double age, double height, double weight);
        virtual ~CaDTPA();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        double calcDtpaChild();
    };
}

#endif /* defined(__libAntidote__CaDTPA__) */



