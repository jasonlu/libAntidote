//============================================================================
// Name        : BabyBIG.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : BabyBIG Algorithm
//============================================================================


#include "BabyBIG.h"

namespace libAntidote {
    
    
    BabyBIG::BabyBIG(double age, double height, double weight) : Antidote(age, height, weight) {
        
        string a = "Baby BIG (Botulism Immune Globulin - Infant) Antidote Algorithm \n",
        b = string("For the treatment of infant exposure to botulism neurotoxins ") + "A and B.  " + FDA + "\n\n";
        
        string strEnd1 = a + b + calculateBIG()+"mg of Baby-BIG via IV infusion in microbore " +
        "tubing passing through an 18 micron filter at a rate of " + rateBIG15() +
        "ml/hr for 15 minutes. If no untoward reaction in 15 minutes rate may " +
        "be increased to " + rateBIGDuration() + "ml/hr for the duration of the infusion.\n" +
        "Use a separate IV line for infusion and flush with NS for complete administration.";
        
        string strEnd2 = a + b + "Not indicated in patients aged 1 year and older.  Please refer to " +
        "Botulism Antitoxin (non-infant).";

        Question *end1 = new Question(strEnd1);
        end1->setType("end");
        prompts.insert(strQuestionMapPair("end1", end1));
        
        Question *end2 = new Question(strEnd2);
        end2->setType("end");
        prompts.insert(strQuestionMapPair("end2", end2));
        
    }
    
    BabyBIG::~BabyBIG() {
        
    }
    
    Question* BabyBIG::getNextQuestion(){
        if( age < 1 ) {
            return prompts["end1"];
        } else {
            return prompts["end2"];
        }
    }
    
    
    string BabyBIG::calculateBIG() {
        return toStr( 50 * weightkg );
    }
    
    string BabyBIG::rateBIG15() {
        return toStr( 0.5 * weightkg );
    }
    
    string BabyBIG::rateBIGDuration() {
        return toStr( 1 *  weightkg );
        
    }
    
    
    string BabyBIG::getRef() {
        return string("Baxter Healthcare Corporation. (2011, October 1). BabyBIG [Botulism Immune ") +
                      "Globulin Intravenous (Human) (BIG-IV)]. Package Insert. Westlake Village, " +
                      "California, U.S.: Baxter Healthcare Corporation.";
    }
}