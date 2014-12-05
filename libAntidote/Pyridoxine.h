//============================================================================
// Name        : Pyridoxine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Pyridoxine Algorithm
//============================================================================


#ifndef __libAntidote__Pyridoxine__
#define __libAntidote__Pyridoxine__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class Pyridoxine: public Antidote {
        
    public:
        Pyridoxine(double age, double height, double weight);
        virtual ~Pyridoxine();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
        string pyrAdultKnown(double dose);
        string pyrChildKnown(double dose);
    
    
    
    };
}

#endif /* defined(__libAntidote__Pyridoxine__) */



