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
        a = "Ethanol Antidote Algorithm \n",
        b = string("For the treatment of methanol and ethylene glycol toxicity. ") + FDO + "\n\n",
        c = getRef();
        Question *chronic = new Question(a+b+
                                         "Administer loading dose of " + toStr(weightkg * 8 ) + " ml (8ml/kg) of 10% ethanol in D5W IV via \n" +
                                         "central line followed by a maintenance dose of " + toStr(weightkg * 2) + " ml/hr (2ml/kg/hr) to achieve a \n" +
                                         "therapeutic BAC level of 100mg/dL.  Continue therapy until methanol or \n" +
                                         "ethylene glycol levels are <20mg/dL." + c);
        insertToMap("chronic", chronic);
        
        Question *etohNaive = new Question(a+b+
                                           "Administer loading dose of " + toStr(weightkg * 8) + " ml (8ml/kg) of 10% ethanol in D5W IV via \n" +
                                           "central line followed by a maintenance dose of " + toStr(weightkg * 0.8) + " ml/hr (0.8ml/kg/hr) to achieve a \n" +
                                           "therapeutic BAC level of 100mg/dL.  Continue therapy until methanol or \n" +
                                           "ethylene glycol levels are <20mg/dL." + c);
        insertToMap("etohNaive", etohNaive);
        
        Question *drinkerOrNot = new Question("Ethanol is 2nd line therapy to be used only in the absence of fomepizole.");
        drinkerOrNot->setOptions(new string[2]{ "Chronic Drinker", "Non-drinker" }, 2);
        insertToMap("drinkerOrNot", drinkerOrNot);
        
    }
    
    Etoh::~Etoh() {
        
    }
    
    Question* Etoh::getNextQuestion(){
        int n1 = prompts["drinkerOrNot"]->getAnswerInt();
        if( n1 == 0 ) {
            moreQuestions = false;
            return prompts["chronic"];
        } else if (n1 == 1){
            moreQuestions = false;
            return prompts["etohNaive"];
        } else {
            return prompts["drinkerOrNot"];
        }
    }
    
    
    string Etoh::getRef() {
        return string("\n\nReferences for Ethanol (methanol/ethylene glycol toxicity) Algorithm: \n\n") +
        "King, A. R. (2012, January 1). Antidote Chart. Antidote Chart . Kansas City,\n" +
        "Kansas, U.S.: Thomas Land Publishers, Inc.";
    }
}