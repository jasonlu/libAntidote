//============================================================================
// Name        : CyanideToxicity.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CyanideToxicity Algorithm
//============================================================================


#ifndef __libAntidote__CyanideToxicity__
#define __libAntidote__CyanideToxicity__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class CyanideToxicity: public Antidote {
        
    public:
        CyanideToxicity(double age, double height, double weight);
        virtual ~CyanideToxicity();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        double calculateBSAGehanGeorge();
        string determinePediatricDoseSodiumNitrite();
        string calculateHydroxoDose();
        string determinePediatricDoseSodiumThiosulfate();
    
    };
}

#endif /* defined(__libAntidote__CrotalidaeOvine__) */



