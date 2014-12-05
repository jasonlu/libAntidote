//============================================================================
// Name        : MetBlue.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : MetBlue Algorithm
//============================================================================


#ifndef __libAntidote__MetBlue__
#define __libAntidote__MetBlue__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class MetBlue: public Antidote {
        
    public:
        MetBlue(double age, double height, double weight);
        virtual ~MetBlue();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a, b, c;
    
    
    };
}

#endif /* defined(__libAntidote__MetBlue__) */



