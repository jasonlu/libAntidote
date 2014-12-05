//============================================================================
// Name        : PotassiumIodide.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : PotassiumIodide Algorithm
//============================================================================


#ifndef __libAntidote__PotassiumIodide__
#define __libAntidote__PotassiumIodide__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class PotassiumIodide: public Antidote {
        
    public:
        PotassiumIodide(double age, double height, double weight);
        virtual ~PotassiumIodide();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a,b,c;
    
    
    
    };
}

#endif /* defined(__libAntidote__PotassiumIodide__) */



