//============================================================================
// Name        : Fomepizole.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Fomepizole Algorithm
//============================================================================


#include "Fomepizole.h"

namespace libAntidote {
    
    
    Fomepizole::Fomepizole(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Fomepizole Antidote Algorithm \n",
        b = string("For the treatment of methanol and ethylene glycol toxicity.  ") + FDA + "\n\n",
        c = "";//getRef();
        
        string fomeWarn = a+b+
        "Antizol�(fomepizole) should not be given undiluted or \n" +
        "by bolus injection.  All doses should be administered \n" +
        "as a slow intravenous infusion over 30 minutes";
        insertToMap("fomeWarn", fomeWarn);
        
        string noFome = a+b+
        "Do not administer fomepizole.  Fomepizole treatment is not indicated in patients\n" +
        "with serum concentrations of methanol or ethylene glycol below 20mg/dL.  Monitor \n" +
        "serum concentrations and symptoms.";
        insertToMap("noFome", noFome);
        
        string fomeDose = a+b+
        "A loading dose of "+toStr( weightkg*15)+" mg (15 mg/kg) fomepizole should be administered, \n" +
        "followed by doses of "+toStr( weightkg*10)+" mg (10 mg/kg) every 12 hours for 4 doses, then \n" +
        toStr( weightkg*15)+" mg (15 mg/kg) every 12 hours thereafter until ethylene glycol or methanol \n" +
        "concentrations are undetectable or have been reduced below 20 mg/dL, \n" +
        "and the patient is asymptomatic with normal pH."+c;
        insertToMap("fomeDose", fomeDose);
        
        string fomeDialysis = a+b+
        "Consider including dialysis to lower concentrations to <50mg/dL.\n\n" +
        "A loading dose of "+toStr( weightkg*15)+" mg (15 mg/kg) fomepizole should be administered, \n" +
        "followed by doses of "+toStr( weightkg*10)+" mg (10 mg/kg) every 4 hours for 4 doses, then \n" +
        toStr( weightkg*15)+" mg (15 mg/kg) every 4 hours thereafter until ethylene glycol or methanol \n" +
        "concentrations are undetectable or have been reduced below 20 mg/dL, \n" +
        "and the patient is asymptomatic with normal pH."+c;
        insertToMap("fomeDialysis", fomeDialysis);
        
        
        Question *isGlycolKnown = new Question("Is the serum concentration of methanol/ethylene glycol known?");
        isGlycolKnown->setOptions(new string[2]{ "Known", "Unknown" }, 2);
        insertToMap("isGlycolKnown", isGlycolKnown);
        
        Question *enterConcentration = new Question("Please enter methanol or ethylene glycol serum \nconcentration in mg/dL.");
        enterConcentration->setType("numbers");
        insertToMap("enterConcentration", enterConcentration);
        
        
    }
    
    Fomepizole::~Fomepizole() {
        
    }
    
    Question* Fomepizole::getNextQuestion(){
        int n1 = prompts["isGlycolKnown"]->getAnswerInt();
        if (n1==0){
            double conc = prompts["enterConcentration"]->getAnswerFloat();
            moreQuestions = false;
            if(conc>=50){
                return prompts["fomeDialysis"];
            } else if(conc >= 20){
                return prompts["fomeDose"];
            } else if(conc > 0) {
               return prompts["noFome"];
            } else {
                moreQuestions = true;
                return prompts["enterConcentration"];
            }
            
        } else if (n1 == 1){
            moreQuestions = false;
            return prompts["fomeDose"];
        } else {
            return prompts["isGlycolKnown"];
        }
    }
    
    
    
    string Fomepizole::getRef() {
        return string("\n\nReferences for Fomepizole Algorithm: \n\n") +
        "Paladin Labs (USA) Inc. (2009, April 1). ANTIZOL- fomepizole injection.\n" +
        "Dover, Delaware, U.S.: Paladin Labs (USA) Inc.";    }
}