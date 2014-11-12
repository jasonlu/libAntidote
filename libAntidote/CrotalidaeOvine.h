//============================================================================
// Name        : CrotalidaeOvine.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CrotalidaeOvine Algorithm
//============================================================================


#ifndef __libAntidote__CrotalidaeOvine__
#define __libAntidote__CrotalidaeOvine__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class CrotalidaeOvine: public Antidote {
        
    public:
        CrotalidaeOvine(double age, double height, double weight);
        virtual ~CrotalidaeOvine();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
            
    
    
    };
}

#endif /* defined(__libAntidote__CrotalidaeOvine__) */



