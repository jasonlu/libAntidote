//============================================================================
// Name        : EdtaDimercaprol.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : EdtaDimercaprol Algorithm
//============================================================================


#ifndef __libAntidote__EdtaDimercaprol__
#define __libAntidote__EdtaDimercaprol__

#include "Antidote.h"

namespace libAntidote {
    
    using namespace std;
    
    class EdtaDimercaprol: public Antidote {
        
    public:
        EdtaDimercaprol(double age, double height, double weight);
        virtual ~EdtaDimercaprol();
        
        // override
        string getRef();
        Question* getNextQuestion();
        
    private:
        string a, b, c;
        double BSA();
        double calcAdultEncED();
        double calcAdultED();
        double calcPedEncED();
        double calcPedED();
    
    };
}

#endif /* defined(__libAntidote__EdtaDimercaprol__) */



