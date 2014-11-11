//============================================================================
// Name        : BlackWidow.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : BlackWidow Algorithm
//============================================================================


#ifndef __libAntidote__BlackWidow__
#define __libAntidote__BlackWidow__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class BlackWidow: public Antidote {
        
    public:
        BlackWidow(double age, double height, double weight);
        virtual ~BlackWidow();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a = "Black Widow envenomation Algorithm.\n",
        b = "For the treatement of Black Widow (Latrodectus mactans) envenomation.\n\n",
        c = "\n(Merck & Co., Inc. , 2014)";
        
    };
}

#endif /* defined(__libAntidote__BlackWidow__) */



