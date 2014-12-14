//============================================================================
// Name        : Pyridoxine.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Pyridoxine Algorithm
//============================================================================


#include "Pyridoxine.h"

namespace libAntidote {
    
    
    Pyridoxine::Pyridoxine(double age, double height, double weight) : Antidote(age, height, weight) {
        
        
        a = "Pyridoxine Antidote Algorithm \n",
        b = string("For the treatment of isonizide and hydrazine/gyromitrin toxicity.  ")+FDA+"\n\n",
        c = "";//getRef();
        
        string childUnknown = ""+a+b+
        "Administer "+toStr(weightkg*70)+" mg (70mg/kg, max 5000 mg) at a " +
        "rate of 500-1000 mg/minute may repeat dose Q5-10 minutes as needed to control seizure."+c;
        insertToMap("childUnknown", childUnknown);
        
        string adultUnknown = ""+a+b+
        "Administer 5000mg IV at a rate of 500-1000mg/min.  May repeat Q5-10min as needed to " +
        "control seizures."+c;
        insertToMap("adultUnknown", adultUnknown);
        
        string hydrazines = ""+a+b+
        "Administer "+toStr(weightkg*25)+" mg IV (25mg/kg in children and adults ) " +
        "over 15-30min.  May repeat dose as necessary to control seizures (max 15g/day) "+c;
        insertToMap("hydrazines", hydrazines);
        
        Question * isoHyd = new Question("Treatment for isoniazid or hydrazines/gyromitrin?");
        isoHyd->setOptions(new string[2] { "Isoniazid", "Hydrazines" }, 2);
        insertToMap("isoHyd", isoHyd);
        
        Question *isDoseKnown = new Question("Is the dose of isoniazid known?");
        isDoseKnown->setOptions(new string[2] { "Known", "Unknown" }, 2);
        insertToMap("isDoseKnown", isDoseKnown);
        
        Question *enterDose = new Question("Please enter dose of isoniazid in milligrams.");
        enterDose->setType("numbers", "milligrams");
        insertToMap("enterDose", enterDose);

    }
    
    Pyridoxine::~Pyridoxine() {
        
    }
    
    Question* Pyridoxine::getNextQuestion(){
        int n1 = prompts["isoHyd"]->getAnswerInt();
        if (n1==0){
            
            if(weightkg>71 || age>18){
                int na = prompts["isDoseKnown"]->getAnswerInt();
                if(na==0){
                    double dose = prompts["enterDose"]->getAnswerFloat();
                    moreQuestions = false;
                    return new Question(a+b+pyrAdultKnown(dose)+c);
                } else if(na==1){
                    moreQuestions = false;
                    return prompts["adultUnknown"];
                } else {
                    return prompts["isDoseKnown"];
                }
            } else {
                int na = prompts["isDoseKnown"]->getAnswerInt();
                if(na==0){
                    double dose = prompts["enterDose"]->getAnswerFloat();
                    moreQuestions = false;
                    return new Question(a+b+pyrChildKnown(dose)+c);
                } else if(na==1){
                    moreQuestions = false;
                    return prompts["childUnknown"];
                } else {
                    return prompts["isDoseKnown"];
                }
            }
        } else if (n1 == 1){
            moreQuestions = false;
            return prompts["hydrazines"];
        } else {
            return prompts["isoHyd"];
        }
        
    }
    
    
    string Pyridoxine::pyrAdultKnown(double dose){
        if(dose>5000){
            return string("Administer doses of 5000 mg pyridoxine IV at a rate of 500-1000 mg/minute ") +
            "every 5-10 minutes to control seizures.  Do not exceed a total dose of "+toStr(dose)+" mg.\n" +
            "If seizures subside before total dose of "+toStr(dose)+" mg is given, remainder of dose " +
            "may be given via IV infusion over 4-6 hours";
        } else {
            return string("Give a total dose of "+toStr(dose)+" mg pyridoxine IV in one single dose or in ") +
            "multiple divided doses.";
        }
    }
    
    string Pyridoxine::pyrChildKnown(double dose){
        
        if(dose>weightkg*70){
            return
            "Administer doses of "+toStr(weightkg*70)+" mg pyridoxine IV at a rate of 500-1000 mg/minute " +
            "every 5-10 minutes to control seizures.  Do not exceed a total dose of "+toStr(dose)+" mg.\n" +
            "If seizures subside before total dose of "+toStr(dose)+" mg is given, remainder of dose " +
            "may be given via IV infusion over 4-6 hours";
        }else {
            return
            "Give a total dose of "+toStr(dose)+" mg pyridoxine IV in one single dose or in " +
            "multiple divided doses.";
        }
    }
    
    
    string Pyridoxine::getRef() {
        return string("") +
                      "APP Pharmaceuticals, LLC . (2011, August 1).PYRIDOXINE " +
                      "HYDROCHLORIDE . Package Insert . Schaumburg,IL, U.S. " +
                      "APP Pharmaceuticals, LLC .\n\n" +
                      "Goldfrank, LR; Flomenbaum, NE; Lewin, NA; Howland, MA;" +
                      "Nelson, LS, & Hoffman R S (2007). Goldfrank's Manual of " +
                      "Toxicologic Emergencies. New York, NY , U.S: McGraw Hill .\n\n" +
                      "King, A. R. (2012, January 1). Antidote Chart. Antidote " +
                      "Chart. Kansas City, Kansas, U.S.: Thomas Land Publishers, Inc.";
    }
}