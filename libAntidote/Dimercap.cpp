//============================================================================
// Name        : Dimercap.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Dimercap Algorithm
//============================================================================


#include "Dimercap.h"

namespace libAntidote {

    
    Dimercap::Dimercap(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Dimercaprol (Heavy metal toxicity) Antidote Algorithm \n";
        b = string("For the treatment of heavy metal toxicity (arsenic, gold, mercury).  ") + FDA + "\n\n",
        c = "";//getRef();
        
        insertToMap("arsenicMild", a + b + "For mild arsenic poisoning, administer " + toStr(2.5 * weightkg) +
                    " mg of dimercaprol (2.5 mg/kg of body weight) " +
                    "deep IM four times daily for two days, two times on the third day, and once " +
                    "daily thereafter for ten days." + c);
        insertToMap("arsenicSevere", a + b + "For severe arsenic poisoning, " + toStr(3 * weightkg) +
                    " mg of dimercaprol(3 mg/kg) deep IM every " +
                    "four hours for two-days, four times on the third day, then twice daily " +
                    "thereafter for ten days." + c);
        
        insertToMap("goldMild", a + b + "For mild gold poisoning, administer " + toStr(2.5 * weightkg) +
                    " mg of dimercaprol(2.5 mg/kg of body weight) " +
                    "deep IM four times daily for two days, two times on the third day, and once " +
                    "daily thereafter for ten days," + c);
                    
        insertToMap("goldSevere", a + b + "For severe gold poisoning, " + toStr(3 * weightkg) +
                    " mg of dimercaprol (3 mg/kg) deep IM every " +
                    "four hours for two-days, four times on the third day, then twice daily " +
                    "thereafter for ten days."+c);
        insertToMap("mercury", a + b + "For mercury poisoning, " + toStr(5 * weightkg) +
                    " mg of dimercaprol deep IM (5 mg/kg) deep IM initially, followed by " +
                    toStr(2.5 * weightkg) +
                    "mg of dimercaprol deep IM (2.5 mg/kg) one or two times daily for ten days." + c);

        Question *whichHeavyMetal = new Question("Click on the heavy metal toxin.");
        string *heavyMetals = new string[3]{"Arsenic", "Gold","Mercury" };
        whichHeavyMetal->setOptions(heavyMetals, 3);
        insertToMap("whichHeavyMetal", whichHeavyMetal);

        Question *isArsenicMileOrSevere = new Question("Is the arsenic toxicity mild or severe?");
        string *arsenicMileOrSevere = new string[2]{"Mild Arsenic Toxicity", "Severe Arsenic Toxicity"};
        isArsenicMileOrSevere->setOptions(arsenicMileOrSevere, 2);
        insertToMap("isArsenicMileOrSevere", isArsenicMileOrSevere);

        Question *isGoldMileOrSevere = new Question("Is the gole toxicity mild or severe?");
        string *goldMileOrSevere = new string[2]{"Mild Gold Toxicity", "Severe Gold Toxicity"};
        isGoldMileOrSevere->setOptions(goldMileOrSevere, 2);
        insertToMap("isArsenicMileOrSevere", isGoldMileOrSevere);
        
    }
    
    Dimercap::~Dimercap() {
        
    }
    
    Question* Dimercap::getNextQuestion(){
        int n1 = prompts["whichHeavyMetal"]->getAnswerInt();
        if (n1 == 0){
            int na = prompts["isArsenicMileOrSevere"]->getAnswerInt();
            if(na==0){
                moreQuestions = false;
                return prompts["arsenicMild"];
            } else if(na==1){
                moreQuestions = false;
                return prompts["arsenicSevere"];
            } else {
                return prompts["isArsenicMileOrSevere"];
            }
        } else if(n1 == 1){
            int na = prompts["isGoldMileOrSevere"]->getAnswerInt();
            if(na==0){
                moreQuestions = false;
                return prompts["goldMild"];
            } else if(na==1){
                moreQuestions = false;
                return prompts["goldSevere"];
            } else {
                return prompts["isGoldMileOrSevere"];
            }
        } else if(n1 == 2){
            return prompts["mercury"];
        } else {
            return prompts["whichHeavyMetal"];
        }
    }
    
    
    string Dimercap::getRef() {
        return string("Taylor Pharmaceuticals . (2007, August 1). DIMERCAPROL INJECTION, USP. \n") +
                      "Package Insert . Decatur, IL, U.S.: Taylor Pharmaceuticals .";
    }
}