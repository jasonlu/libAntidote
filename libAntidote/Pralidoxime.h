//============================================================================
// Name        : Pralidoxime.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Pralidoxime Algorithm
//============================================================================


#ifndef __libAntidote__Pralidoxime__
#define __libAntidote__Pralidoxime__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Pralidoxime: public Antidote {
        
    public:
        Pralidoxime(double age, double height, double weight);
        virtual ~Pralidoxime();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
        string praCalIV();
    
    
    };
}

#endif /* defined(__libAntidote__Pralidoxime__) */



