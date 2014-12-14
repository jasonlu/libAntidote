//============================================================================
// Name        : Atropine.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Atropine Algorithm
//============================================================================


#include "Atropine.h"

namespace libAntidote {
    
    
    Atropine::Atropine(double age, double height, double weight) : Antidote(age, height, weight) {
        
        
        string a = "Atropine Antidote Algorithm.\n",
        b = string("For the treatement of organophosphorus and \n N-methyl carbamate insecticides. ") + FDA + "\n\n",
        c = "\n(Hospira, Inc. , 2009)",
        d = "\n (Meridian Medical TechnologiesTM, Inc., 2005)";
        
        //IV autoinjectors
        string stringVialAutoInject = string("Atropine for injection comes in two forms - vials and ") +
        "auto-injectors.  Click appropriate button to continue";
        Question *q1 = new Question(stringVialAutoInject);
        string *opts1 = new string[2];
        opts1[0] = "Vials";
        opts1[1] = "Autoinjectors";
        q1->setOptions(opts1, 2);
        prompts.insert(strQuestionMapPair("stringVialAutoInject?", q1));
        
        string stringInfant = string("Infants and neonates:\n\n") + toStr(weightkg * 0.01) + " to " + toStr(weightkg * 0.03)+
        "mg IM or IV(0.01-0.03mg/kg) every 10-15 min as needed until symptoms dissipate. \n" +
        "(NeoFax, 2014)"+c;
        Question *end1 = new Question(stringInfant);
        end1->setType("end");
        prompts.insert(strQuestionMapPair("stringInfant", end1));
        
        string stringChild = string("Children and Adolescents:\n\n") +calculateAtropine() + "mg "+
        "IM or IV(0.05mg/kg) every 10-30 min as needed until symptoms dissipate. \n" +
        "In 48% of children (116/240), systemic atropine effects were noted, with 8% experiencing " +
        "severe atropinization. Severity of atropinization was dose-related in a non-linear fashion." + c;
        Question *end2 = new Question(stringChild);
        end2->setType("end");
        prompts.insert(strQuestionMapPair("stringChild", end2));
        
        string stringAdult = string("Initial single doses in adults vary from to 2 to 3 mg (20-30 mL) of the 0.1 mg/mL solution) as an ") +
        "antidote for organophosporous or muscarinic mushroom poisoning. When used as an antidote, the 2 to 3 mg " +
        "dose should be repeated no less often than every 20 to 30 minutes until the signs of poisoning are " +
        "sufficiently lessened or signs of atropine poisoning occur."+c;
        Question *end3 = new Question(stringAdult);
        end3->setType("end");
        prompts.insert(strQuestionMapPair("stringAdult", end3));
        
        string stringDoNotUseAutoInjector = string("Do not use auto-injector.  Refer to dosing with vials.");
        Question *end4 = new Question(stringDoNotUseAutoInjector);
        end4->setType("end");
        prompts.insert(strQuestionMapPair("stringDoNotUseAutoInjector", end4));
        
        string  stringAutoChild = string("If using the atropine auto-injector, the dosage is based on weight as follows: \n") +
        "If weight between 15 and 40 lb, (roughly 7 to 18 kg) give 0.5 mg IM via auto-injector.  When used as an " +
        "antidote, the 0.5 mg dose should be repeated no less often than every 20 to 30 minutes until the signs " +
        "of poisoning are sufficiently lessened or signs of atropine poisoning occur." + d;
        Question *end5 = new Question(stringAutoChild);
        end5->setType("end");
        prompts.insert(strQuestionMapPair("stringAutoChild", end5));
        
        string stringAutoAdolescent = string("If using the atropine auto-injector, the dosage is based on weight as follows: \n") +
        "If weight between 40 and 90 lb, (roughly 18 to 41 kg) give 1 mg IM via auto-injector.  When used as an " +
        "antidote, the 1 mg dose should be repeated no less often than every 20 to 30 minutes until the signs " +
        "of poisoning are sufficiently lessened or signs of atropine poisoning occur." + d;
        Question *end6 = new Question(stringAutoAdolescent);
        end6->setType("end");
        prompts.insert(strQuestionMapPair("stringAutoAdolescent", end6));
        
        
        string stringAutoAdult = string("If using the atropine auto-injector, the dosage is based on weight as follows: \n)") +
        "weight >= 90lb (>= 41 kg) give 2 mg IM via auto-injector. When used as an antidote, the 2 mg " +
        "dose should be repeated no less often than every 20 to 30 minutes until the signs of poisoning are " +
        "sufficiently lessened or signs of atropine poisoning occur." + d;
        Question *end7 = new Question(stringAutoAdult);
        end7->setType("end");
        prompts.insert(strQuestionMapPair("stringAutoAdult", end7));
        
        
    }
    
    
    Atropine::~Atropine() {
        
    }
    
    Question* Atropine::getNextQuestion(){
        int n1 = prompts["stringVialAutoInject?"]->getAnswerInt();
        if (n1 == 0){
            moreQuestions = false;
            //neonates and infant dosing
            if (age < 1){
                return prompts["stringInfant"];
            }
            else {
                if (age >= 1 && age < 21) {
                    return prompts["stringChild"];
                } else { //Adult dosing
                    return prompts["stringAdult"];
                }
            }
        } else if (n1 == 1){
            moreQuestions = false;
            if(weightkg < 7) {
                return prompts["stringDoNotUseAutoInjector"];
            } else if(weightkg >=7 && weightkg < 18) {
                return prompts["stringAutoChild"];
            } else if(weightkg >= 18 && weightkg < 41) {
                return prompts["stringAutoAdolescent"];
            } else {
                return prompts["stringAutoAdult"];
            }
        } else {
            return prompts["stringVialAutoInject?"];
        }
        
    }
    
    
    string Atropine::calculateAtropine(){
        double dose;
        dose = (0.05*(weightkg));
        if(dose > 3){
            return "3";
        } else {
            return toStr(0.05 * (weightkg));
        }
    }
    
    
    string Atropine::getRef() {
        return string("Hospira, Inc. . (2009, November 1). Atropine Sulfate . Atropine Sulfate Package Insert.\n") +
        "Lake Forest, Illinois, U.S.: Hospira, Inc.\n\n" +
        "Meridian Medical TechnologiesTM, Inc. (2005, November 1). ATROPEN AUTO-INJECTOR - atropine " +
        "sulfate injection Package Insert. Columbia, Maryland, U.S. Meridian Medical TechnologiesTM, Inc.\n\n";
    }
    
}