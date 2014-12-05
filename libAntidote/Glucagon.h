//============================================================================
// Name        : Glucagon.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Glucagon Algorithm
//============================================================================


#ifndef __libAntidote__Glucagon__
#define __libAntidote__Glucagon__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Glucagon: public Antidote {
        
    public:
        Glucagon(double age, double height, double weight);
        virtual ~Glucagon();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a, b, c;
        double calcChild();
    
    
    };
}

#endif /* defined(__libAntidote__Glucagon__) */



