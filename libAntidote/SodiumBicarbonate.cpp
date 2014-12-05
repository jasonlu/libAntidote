//============================================================================
// Name        : SodiumBicarbonate.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : SodiumBicarbonate Algorithm
//============================================================================


#include "SodiumBicarbonate.h"

namespace libAntidote {
    
    
    SodiumBicarbonate::SodiumBicarbonate(double age, double height, double weight) : Antidote(age, height, weight) {
        
        a = "Sodium Bicarbonate Antidote Algorithm \n",
        b = string("For the treatment of sodium channel blocker toxicity.  ")+FDA+"\n\n",
        c = getRef();
        
        Question *bicMess = new Question(a+b+
        "Sodium Bicarbonate is used to reverse the cardiotoxic effects of \n" +
        "tricyclic antidepressants and other type IA and IC antidysrythmics.\n" +
        "Sodium Bicarbonate is also useful in treating the cardiotoxic effects \n" +
        "caused by other sodium channel blockers.");
        bicMess->setType("warning");
        insertToMap("bicMess", bicMess);
        
        string QRSYes = a+b+
        "Administer Sodium Bicarbonate "+toStr(weightkg)+"-"+toStr(weightkg*2)+" mEq IVP (1-2mEq/kg) over\n" +
        "1-2 minutes. Sodium Bicarb. can be repeated as necessary to achieve \n" +
        "blood pH of 7.50-7.55.  The treatment endpoint is narrowing of the QRS.  \n" +
        "Continuous infusion of Sodium Bicarb. is often needed after initial \n" +
        "bolus to maintain effect - 150 mEq Na Bicarb/liter D5W at twice maintenance.\n" +
        "Monitor QRS, pH, and Na level. \n" +
        ""+c;
        insertToMap("QRSYes", QRSYes);
        
        string QRSNo = a + b + "Sodium Bicarbonate not indicated."+c;
        insertToMap("QRSNo", QRSNo);
    
        Question *isQrsGreaterThan = new Question("Is the QRS duration greater than 0.1 seconds?");
        isQrsGreaterThan->setType("yesno");
        insertToMap("isQrsGreaterThan", isQrsGreaterThan);

    }
    
    SodiumBicarbonate::~SodiumBicarbonate() {
        
    }
    
    Question* SodiumBicarbonate::getNextQuestion(){
        if(prompts["bicMess"]->getAnswerInt() == -1) {
            return prompts["bicMess"];
        }
        
        int na = prompts["isQrsGreaterThan"]->getAnswerInt();
        if(na==0){moreQuestions = false; return prompts["QRSYes"];}
        if(na==1){moreQuestions = false; return prompts["QRSNo"];}
        else {return prompts["isQrsGreaterThan"];}
    }
    

    
    
    string SodiumBicarbonate::getRef() {
        return string("\n\nReferences for Sodium Bicarbonate Algorithm: \n\n") +
        "Dart, R. C., Borron, S. W., Caravati, E. M., Cobaugh, \n" +
        "D. J., Curry, S. C., Falk, J. L., et al. (2009). Expert \n" +
        "Consensus Guidelines for Stocking of Antidotes in Hospitals \n" +
        "That Provide Emergency Care. Annals of Emergency Medicine,\n" +
        "54 (3), 386-394.\n\n" +
        "Goldfrank, L. R., Flomenbaum, N. E., Lewin, N. A., Howland, \n" +
        "M. A., Nelson, L. S., & Hoffman, R. S. (2007). Goldfrank's \n" +
        "Manual of Toxicologic Emergencies. New York, NY, U.S: McGraw Hill.";
    }
}