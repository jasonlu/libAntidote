//============================================================================
// Name        : PrussianBlue.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : PrussianBlue Algorithm
//============================================================================


#ifndef __libAntidote__PrussianBlue__
#define __libAntidote__PrussianBlue__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class PrussianBlue: public Antidote {
        
    public:
        PrussianBlue(double age, double height, double weight);
        virtual ~PrussianBlue();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
    
    };
}

#endif /* defined(__libAntidote__PrussianBlue__) */



