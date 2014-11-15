//============================================================================
// Name        : EdtaDimercaprol.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : EdtaDimercaprol Algorithm
//============================================================================


#include "EdtaDimercaprol.h"

namespace libAntidote {
    
    
    EdtaDimercaprol::EdtaDimercaprol(double age, double height, double weight) : Antidote(age, height, weight) {
        
        string strEnd1 = string("Give ") + calculateBIG()+"mg of Baby-BIG via IV infusion in microbore \n" +
        "tubing passing through an 18 micron filter at a rate of\n" + rateBIG15() +
        "ml/hr for 15 minutes. If no untoward reaction in 15 minutes rate may\n" +
        "be increased to " + rateBIGDuration() + "ml/hr for the duration of the infusion.\n" +
        "Use a separate IV line for infusion and flush with NS for complete administration.";
        
        string strEnd2 = string("Not indicated in patients aged 1 year and older.  Please refer to\n") +
        "Botulism Antitoxin (non-infant).";

        Question *end1 = new Question(strEnd1);
        end1->setType("end");
        prompts.insert(strQuestionMapPair("end1", end1));
        
        Question *end2 = new Question(strEnd2);
        end2->setType("end");
        prompts.insert(strQuestionMapPair("end2", end2));
        
    }
    
    EdtaDimercaprol::~EdtaDimercaprol() {
        
    }
    
    Question* EdtaDimercaprol::getNextQuestion(){
        if( age < 1 ) {
            return prompts["end1"];
        } else {
            return prompts["end2"];
        }
    }
    
    
    string EdtaDimercaprol::calculateBIG() {
        return toStr( 50 * weightkg );
    }
    
    string EdtaDimercaprol::rateBIG15() {
        return toStr( 0.5 * weightkg );
    }
    
    string EdtaDimercaprol::rateBIGDuration() {
        return toStr( 1 *  weightkg );
        
    }
    
    
    string EdtaDimercaprol::getRef() {
        return string("References for EdtaDimercaprol Algorithm\n\n")+
                      "Baxter Healthcare Corporation. (2011, October 1). EdtaDimercaprol [Botulism Immune \n" +
                      "Globulin Intravenous (Human) (BIG-IV)]. Package Insert. Westlake Village, \n" +
                      "California, U.S.: Baxter Healthcare Corporation.";
    }
}