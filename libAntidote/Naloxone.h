//============================================================================
// Name        : Naloxone.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Naloxone Algorithm
//============================================================================


#ifndef __libAntidote__Naloxone__
#define __libAntidote__Naloxone__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Naloxone: public Antidote {
        
    public:
        Naloxone(double age, double height, double weight);
        virtual ~Naloxone();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
        double calcNeoBolus();
    
    };
}

#endif /* defined(__libAntidote__Naloxone__) */



