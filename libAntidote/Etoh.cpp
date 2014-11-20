//============================================================================
// Name        : Etoh.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Etoh Algorithm
//============================================================================


#include "Etoh.h"

namespace libAntidote {
    
    
    Etoh::Etoh(double age, double height, double weight) : Antidote(age, height, weight) {
        
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
    
    Etoh::~Etoh() {
        
    }
    
    Question* Etoh::getNextQuestion(){
        if( age < 1 ) {
            return prompts["end1"];
        } else {
            return prompts["end2"];
        }
    }
    
    
    string Etoh::calculateBIG() {
        return toStr( 50 * weightkg );
    }
    
    string Etoh::rateBIG15() {
        return toStr( 0.5 * weightkg );
    }
    
    string Etoh::rateBIGDuration() {
        return toStr( 1 *  weightkg );
        
    }
    
    
    string Etoh::getRef() {
        return string("References for Etoh Algorithm\n\n")+
                      "Baxter Healthcare Corporation. (2011, October 1). Etoh [Botulism Immune \n" +
                      "Globulin Intravenous (Human) (BIG-IV)]. Package Insert. Westlake Village, \n" +
                      "California, U.S.: Baxter Healthcare Corporation.";
    }
}