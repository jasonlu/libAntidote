//============================================================================
// Name        : Physostigmine.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Physostigmine Algorithm
//============================================================================


#include "Physostigmine.h"

namespace libAntidote {
    
    
    Physostigmine::Physostigmine(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Physostigmine Antidote Algorithm \n",
        b = string("As a secondary treatment of anticholinergic syndrome.  ") + FDA + "\n\n",
        c = "";//getRef();
        
    }
    
    Physostigmine::~Physostigmine() {
        Question *physWarning = new Question(a+b+
        "Warning: Physostigmine Salicylate Injection should not be used in the \n" +
        "presence of asthma, gangrene, diabetes, cardiovascular disease, mechanical \n" +
        "obstruction of the intestine or urogenital tract or any vagotonic state, \n" +
        "and in patients receiving choline esters and depolarizing neuromuscular \n" +
        "blocking agents (decamethonium, succinylcholine).Patient must have normal \n" +
        "QRS on ECG to receive physostigmine.");
        physWarning->setType("warning");
        insertToMap("physWarning", physWarning);
        
        Question *physChildWarning = new Question(a+b+
        "Administration of physostigmine in children should reserved for \n" +
        "life-threatening conditions.");
        physChildWarning->setType("warning");
        insertToMap("physChildWarning", physChildWarning);
        
        string physChild = a+b+
        "Recommended dosage is "+toStr(physCalcChild())+"mg (0.02 mg/kg max 2mg) of physostigmine intramuscularly or by\n" +
        "slow intravenous injection, no more than 0.5 mg per minute. If the toxic \n" +
        "effects persist, and there is no sign of cholinergic effects, the dosage may \n" +
        "be repeated at 5 to 10 minute intervals until a therapeutic effect is \n" +
        "obtained or a maximum of 2 mg dosage is attained."+c;
        insertToMap("physChild", physChild);
        
        string physAdult = a+b+
        "Adult dosing: When administering IV give no faster than 1mg/minute to avoid \n" +
        "adverse events.  Recommended dosage 0.5-2mg IV,IM.  May repeat every 10-30 \n" +
        "minutes until desired response."+c;
        insertToMap("physAdult", physAdult);
        
        
    }
    
    Question* Physostigmine::getNextQuestion(){
        if(age<=18){
            if(prompts["physChildWarning"]->getAnswerInt() == -1) {
                return prompts["physChildWarning"];
            }
            moreQuestions = false;
            return prompts["physChild"];
        } else {
            if(prompts["physWarning"]->getAnswerInt() == -1) {
                return prompts["physWarning"];
            }
            moreQuestions = false;
            return prompts["physAdult"];
        }
    }
    
    double Physostigmine::physCalcChild(){
        if(weightkg*0.02 < 2){return weightkg * 0.02;}
        else{return 2;}
    }
    
    
    string Physostigmine::getRef() {
        return string("\n\nReferences for Physostigmine Algorithm: \n\n") +
        "Akorn, Inc. (2008, November 1). Physostigmine salicylate. \n" +
        "Package Insert . Lake Forest, IL, U.S.: Akorn, Inc.\n\n" +
        "Derinoz, O., & Emeksiz, H. C. (2012). Use of Physostigmine for \n" +
        "Cyclopentolate Overdose in an Infant. Pediatrics , 130, e703-e705.\n\n" +
        "Krenzelok, E. P. (2010, January 18). Aspects of Datura poisoning and \n" +
        "treatment. Clinical Toxicology , 104-110.";
    }
}