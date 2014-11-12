//============================================================================
// Name        : CoralSnake.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CoralSnake Algorithm
//============================================================================


#ifndef __libAntidote__CoralSnake__
#define __libAntidote__CoralSnake__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class CoralSnake: public Antidote {
        
    public:
        CoralSnake(double age, double height, double weight);
        virtual ~CoralSnake();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
    
    
    
    };
}

#endif /* defined(__libAntidote__CoralSnake__) */



