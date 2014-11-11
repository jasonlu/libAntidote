//============================================================================
// Name        : CaChloride.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CaChloride Algorithm
//============================================================================


#ifndef __libAntidote__CaChloride__
#define __libAntidote__CaChloride__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class CaChloride: public Antidote {
        
    public:
        CaChloride(double age, double height, double weight);
        virtual ~CaChloride();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        double childMaxGl();
        double childMaxCl();
        double adultGl();
        double adultCl();
        string a = "Calcium Salts -",
        b = "For the treatement of calcium channel blocker and fluoride overdose.\n\n",
        c = "  (Hung YM, 2007) (Haddad, 1996) (Buckley N, 1993) (Sim MT, 2008)  (Kleinman, 2010) (Kerns, 2007) (Hegenbarth, 2008)";
        
    };
}

#endif /* defined(__libAntidote__CaChloride__) */



