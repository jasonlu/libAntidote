//============================================================================
// Name        : Fomepizole.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Fomepizole Algorithm
//============================================================================


#ifndef __libAntidote__Fomepizole__
#define __libAntidote__Fomepizole__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Fomepizole: public Antidote {
        
    public:
        Fomepizole(double age, double height, double weight);
        virtual ~Fomepizole();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a, b, c;
    
    
    };
}

#endif /* defined(__libAntidote__Fomepizole__) */



