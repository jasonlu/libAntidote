//============================================================================
// Name        : Deferoxamine.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Deferoxamine Algorithm
//============================================================================


#include "Deferoxamine.h"

namespace libAntidote {
    
    
    Deferoxamine::Deferoxamine(double age, double height, double weight) : Antidote(age, height, weight) {
        string a = "Deferoxamine (iron toxicity) Antidote Algorithm ",
        b = string("For the treatment of acute iron toxicity.  ") + FDA + "\n\n",
        c = "\n (Mills KC, 1994) (Anderson, 1994) (Novartis, 2011)";
        insertToMap("ageLessThanThree", new Question(a + b + "Safety and effectiveness in pediatric patients under the age of " +
                                                     "3 years have not been established." + c));
        string *defOptions = new string[2];
        defOptions[0] =  "CV shock";
        defOptions[1] = "No CV complications";
        Question *isPatientCVShock = new Question("Is this patient in cardiovascular (CV) shock?");
        isPatientCVShock->setOptions(defOptions, 2);
        insertToMap("isPatientCVShock?", isPatientCVShock);
        insertToMap("give1GramIV", new Question(a + b + "Give 1gram IV every 4-8 hours if needed up to 6grams in 24 hours." + c));
        insertToMap("giveIVUpTo1", new Question(a + b + "Give " + toStr(weightkg * 40) + " mg to 1000mg IV every 4-8 hours if needed, up to " +
                                                "6 grams in 24 hours." + c));
        insertToMap("giveIVMore", new Question(a + b + "Give " + toStr(weightkg * 40) + " mg to " + toStr(weightkg * 90) + " mg IV every 4-8 hours if needed," +
                                               "up to 6 grams in 24 hours." + c));
        
        insertToMap("give1GramIM", new Question(a + b + "Give 1gram IM every 4-8 hours if needed up to 6grams in 24 hours." + c));
        insertToMap("giveIMUpTo1", new Question(a + b + "Give " + toStr(weightkg * 40) + " mg to 1000mg IM every 4-8 hours if needed, up to " +
                                                "6 grams in 24 hours." + c));
        insertToMap("giveIMMore", new Question(a + b + "Give " + toStr(weightkg * 40) + " mg to " + toStr(weightkg * 90) + " mg IM every 4-8 hours if needed, " +
                                               "up to 6 grams in 24 hours." + c));
        
        insertToMap("giveIV1Gram", new Question(a + b + "Initially, 1 g IV. Follow with 500 mg IM every 4 hours for 2 doses, " +
                                                "then 500 mg IM every 4 to 12 hours if needed up to a maximum of 6 grams " +
                                                "in 24 hours." + c));
        insertToMap("giveIM1Gram", new Question(a + b + "Initially, 1 g IM. Follow with 500 mg IM every 4 hours for 2 doses, " +
                                                "then 500 mg IM every 4 to 12 hours if needed up to a maximum of 6 grams " +
                                                "in 24 hours." + c));

        
    }
    
    Deferoxamine::~Deferoxamine() {
        
    }
    
    Question* Deferoxamine::getNextQuestion(){
        
        if(age < 3){
            moreQuestions = false;
            return prompts["ageLessThanThree"];
        } else if(age >= 3 && age < 18){
            int n1 = prompts["isPatientCVShock?"]->getAnswerInt();
            if (n1==0){
                if(weightkg * 40 >= 1000){
                    moreQuestions = false;
                    return prompts["give1GramIV"];
                } else {
                    if(weightkg * 90 >= 1000){
                        moreQuestions = false;
                        return prompts["giveIVUpTo1"];
                    }
                    else {
                        moreQuestions = false;
                        return prompts["giveIVMore"];
                    }
                }
            } else if (n1==1){
                if(weightkg * 40 >= 1000){
                    moreQuestions = false;
                    return prompts["give1GramIM"];
                } else {
                    if(weightkg * 90 >= 1000){
                        moreQuestions = false;
                        return prompts["giveIMUpTo1"];
                    } else {
                        moreQuestions = false;
                        return prompts["giveIMMore"];
                    }
                }
            } else {
                return prompts["isPatientCVShock?"];
            }
        } else {
            int n1 = prompts["isPatientCVShock?"]->getAnswerInt();
            if (n1==0){
                moreQuestions = false;
                return prompts["giveIV1Gram"];
            } else if (n1 == 1){
                moreQuestions = false;
                return prompts["giveIM1Gram"];
            } else {
                return prompts["isPatientCVShock?"];
            }
        }
    }
    
    
    string Deferoxamine::getRef() {
        return string("References for Deferoxamine Algorithm\n\n")+
                      "Mills KC, C. S. (1994). Acute iron poisoning. Emerg Med Clin North Am , 12, 397-413.\n\n" +
                      "Anderson, A. (1994). Iron poisoning in children. Curr Opin Pediatr , 6, 289-294.\n\n" +
                      "Novartis. (2011, December 1) Desferal(R) deferoxamine mesylate for injection USP. Package Insert.\n" +
                      "East Hanover, New Jersey, U.S.: Novartis.";
    }
}