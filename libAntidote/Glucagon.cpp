//============================================================================
// Name        : Glucagon.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Glucagon Algorithm
//============================================================================


#include "Glucagon.h"

namespace libAntidote {
    
    
    Glucagon::Glucagon(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Glucagon Antidote Algorithm \n",
        b = string("For the treatment of beta blocker and Ca channel blocker toxicity.  ")+FDO+"\n\n",
        c = getRef();
        Question *warning = new Question(string("Glucagon is used for Ca-channel blocker and beta blocker induced myocardial depression.\n") +
                                      "Glucagon alone is not an antidote for Ca-channel blocker and beta blocker toxicity.\n" +
                                      "Please refer to the Calcium Salts algorithm.");
        warning->setType("warning");
        insertToMap("warning", warning);
        
        string titrate = "\nTitrate to desired response.  Glucagon is compatible with D5W or NS.";
        string glucChild = a + b + "Initial bolus of " + toStr(weightkg*30) +
        " mcg to " + toStr(weightkg*150) + " mcg (30 to 150 mcg/kg) of glucagon followed by \n" +
        toStr(weightkg * 10) + " mcg to " + toStr( calcChild() ) + " mcg IVCI (10 to 70mcg/kg up to max 5000 mcg/hr) " +
        titrate + c;
        insertToMap("glucChild", glucChild);
        
        string glucAdolescent = a + b + "Initial 5 to 10 mg IV bolus of glucagon followed by IVCI of 1 to 5mg/hr. "+titrate+c;
        insertToMap("glucAdolescent", glucAdolescent);
        
        string glucAdult = a + b + "Initial 3 to 10 mg IV bolus of glucagon followed by IVCI of 3 to 5mg/hr. "+titrate+c;
        insertToMap("glucAdult", glucAdult);
        
        
        
        
    }
    
    Glucagon::~Glucagon() {
        
    }
    
    Question* Glucagon::getNextQuestion(){
        int n1 = prompts["warning"]->getAnswerInt();
        if(n1 == -1) {
            return prompts["warning"];
        } else {
            moreQuestions = false;
        }
        
        if(age >= 0 && age <= 12) {
            return prompts["glucChild"];
        } else if(age>12&&age<=18){
            return prompts["glucAdolescent"];
        } else {
            return prompts["glucAdult"];
        }
    }
    
    
    double Glucagon::calcChild(){
        double max = 5000;
        if(weightkg*70<=5000){
            return weightkg*70;
        } else {
            return max;
        }
    }
    
    string Glucagon::getRef() {
        return string("\n\nReferences for Glucagon Algorithm:\n\n") +
        "Hegenbarth, M. A. (2008). Preparing for Pediatric Emergencies: Drugs to Consider. \n" +
        "Pediatrics , 121 (2), 433-443.\n\n" +
        "King, A. R. (2012, January 1). Antidote Chart. Antidote Chart . Kansas City, \n" +
        "Kansas, U.S.: Thomas Land Publishers, Inc.";
    }
}