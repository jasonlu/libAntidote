//============================================================================
// Name        : CaDTPA.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CaDTPA Algorithm
//============================================================================


#include "CaDTPA.h"

namespace libAntidote {
    
    
    CaDTPA::CaDTPA(double age, double height, double weight) : Antidote(age, height, weight) {
        
        string a = "Ca-DTPA/Zn-DTPA Algorithm  ",
        b = "For the treatement of plutonium, americium, and curium exposure/toxicity.\n\n",
        c = " (Akorn Inc., 2005)";
        string input;
        string stringAdultCaD = a + b + "Adult Dosing:\n\n"  +
        "Administer 1gram Ca-DTPA via slow IVP or via oral nebulization inhalation as soon "  +
        "as possible after initial exposure.  There is limited effectiveness after 24 hours have "  +
        "lapsed since exposure.  Zn-DTPA can be used if Ca-DTPA is not available.  Ca-DTPA is the "  +
        "preferred agent." + c;
        string stringChildCaD = a + b + "Children's Dosing:\n\n"  +
        "Administer " + toStr(calcDtpaChild()) + " mg (14mg/kg) via slow IVP or via oral nebulization "  +
        "as soon as possible after initial exposure.  There is limited effectiveness after 24 hours have "  +
        "lapsed since initial exposure.  Zn-DTPA can be used if Ca-DTPA is not available.  Ca-DTPA is the "  +
        "preferred agent." + c;
        
        Question *AdultCaD = new Question(stringAdultCaD);
        prompts.insert(strQuestionMapPair("AdultCaD", AdultCaD));
        
        Question *ChildCaD = new Question(stringChildCaD);
        prompts.insert(strQuestionMapPair("ChildCaD", ChildCaD));
        
    }
    
    CaDTPA::~CaDTPA() {
        
    }
    
    Question* CaDTPA::getNextQuestion(){
        moreQuestions = false;
        if(age < 12) {
            return prompts["ChildCaD"];
        } else {
            return prompts["AdultCaD"];
        }
    }
    
    
    double CaDTPA::calcDtpaChild(){
        if(weightkg*14 < 1000) {return weightkg*14;}
        if(weightkg*14  >=1000) {return 1000;}
        return 0;
    }
    
    
    string CaDTPA::getRef() {
        return string("References Calcium/Zinc DTPA Algorithm\n\n")  +
                      "Akorn Inc. (2005, January 1). Pentetate Trisodium Calcium Injection. Pentetate  "  +
                      "Trisodium Calcium Injection (package insert) . Buffalo Grove, ILL, U.S.: Akorn Inc.";
    }
}