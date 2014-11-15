//============================================================================
// Name        : CaChloride.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CaChloride Algorithm
//============================================================================


#include "CaChloride.h"

namespace libAntidote {
    
    
    CaChloride::CaChloride(double age, double height, double weight) : Antidote(age, height, weight) {
        this->fdaApproved = FDA_QUESTIONABLE;
        string a = "Calcium Salts -",
        b = "For the treatement of calcium channel blocker and fluoride overdose.\n\n",
        c = "  (Hung YM, 2007) (Haddad, 1996) (Buckley N, 1993) (Sim MT, 2008)  (Kleinman, 2010) (Kerns, 2007) (Hegenbarth, 2008)";
        
        string stringChildCaCl = string("")  + a + b +
        "Calcium chloride is used in conjunction with other agents in the treatment "  +
        "of calcium channel blocker and fluoride overdose.  Calcium chloride indicated "  +
        "when patients present with symptomatic hypotension or heart block due to calcium "  +
        "channel blocker or fluoride overdose.\n\n"  +
        "Administer " + toStr(childMaxCl()) + "mg (20mg/kg) slow IVP via central line  "  +
        "over 15 minutes. Dose may be repeated in 10 minutes if necessary. IV contiuous "  +
        "infusion at 20 to 50 mg/kg per hour may be considered if bolus therapy is beneficial. (Kleinman, 2010) " + c;
        Question *ChildCaCl = new Question(stringChildCaCl);
        prompts.insert(strQuestionMapPair("ChildCaCl", ChildCaCl));
        
        string stringAdultCaCl = string("")  + a + b +
        "Calcium chloride is used in conjunction with other agents in the treatment "  +
        "of calcium channel blocker and fluoride overdose.  Calcium chloride indicated "  +
        "when patients present with symptomatic hypotension or heart block due to calcium "  +
        "channel blocker or fluoride overdose.\n\n"  +
        "Administer " + toStr(adultCl()) + "mg (20mg/kg) of calcium chloride "  +
        "slow IVP over 10-15 minutes via central line.  Then begin IV infusion of"  + toStr(adultCl()) + " to " + toStr(2 * adultCl()) + "mg "  +
        "(20 to 50mg/kg) per hour (Kerns, 2007).  Titrate to desired effect.  Dilute in appropriate  "  +
        "vehicle if not given via central line.\n\n" + c;
        Question *AdultCaCl = new Question(stringAdultCaCl);
        prompts.insert(strQuestionMapPair("AdultCaCl", AdultCaCl));
        
        string stringAdultGluconate = string("") + a + b +
        "Calcium gluconate is used in conjunction with other agents in the treatment "  +
        "of calcium channel blocker and fluoride overdose.  Calcium gluconate indicated "  +
        "when patients present with symptomatic hypotension or heart block due to calcium "  +
        "channel blocker or fluoride overdose.\n\n"  +
        "Administer " + toStr(adultGl()) + "mg (60mg/kg) of calcium gluconate "  +
        "slow IVP over 10-15 minutes.  Then begin IV infusion of"  + toStr(adultGl()) + " to " + toStr(2.5 * adultGl()) + "mg "  +
        "(60-150mg/kg) per hour (Kerns 2007).  Titrate to desired effect.\n\n" + c;
        Question *AdultGluconate = new Question(stringAdultGluconate);
        prompts.insert(strQuestionMapPair("AdultGluconate", AdultGluconate));
        
        string stringChildGluconate = string("")  +
        "Calcium gluconate is used in conjunction with other agents in the treatment "  +
        "of calcium channel blocker and fluoride overdose.  Calcium chloride indicated "  +
        "when patients present with symptomatic hypotension or heart block due to calcium "  +
        "channel blocker or fluoride overdose.\n\n"  +
        "Administer " + toStr(childMaxGl()) + "mg (100mg/kg, max 3grams) slow IVP via central line  "  +
        "over 15 minutes. Dose may be repeated in 10 minutes if necessary (Hegenbarth 2008).\n\n";
        Question *ChildGluconate = new Question(stringChildGluconate);
        prompts.insert(strQuestionMapPair("ChildGluconate", ChildGluconate));
        
        string stringChlorideGluconate = string("")  +
        "Both calcium chloride and calcium gluconate are used for the treatment of calcium "  +
        "channel blocker and fluoride overdose.  However, calcium chloride contains "  +
        "3 times the elemental calcium as the gluconate salt. Calcium chloride is the preferred agent. "  +
        "Please click on the agent you are using.";
        Question *ChlorideGluconate = new Question(stringChlorideGluconate);
        string *antitoxinOptions = new string[2];
        antitoxinOptions[0] = "Calcium Chloride";
        antitoxinOptions[1] = "Calcium Gluconate";
        ChlorideGluconate->setType("options");
        ChlorideGluconate->setOptions(antitoxinOptions, 2);
        prompts.insert(strQuestionMapPair("ChlorideGluconate", ChlorideGluconate));
    }
    
    CaChloride::~CaChloride() {
        
    }
    
    Question* CaChloride::getNextQuestion(){
        int n1 = 0;
        n1 = prompts["ChlorideGluconate"]->getAnswerInt();
        if (n1==0){
            moreQuestions = false;
            if(age < 12) {
                return prompts["ChildCaCl"];
            } else {
                return prompts["AdultCaCl"];
            }
            
        } else if (n1==1){
            moreQuestions = false;
            if(age < 12) {
                return prompts["ChildGluconate"];
            } else {
                return prompts["AdultGluconate"];
            }
        } else {
            return prompts["ChlorideGluconate"];
        }
        
    }
    
    double CaChloride::childMaxGl() {
        if(weightkg * 100 > 3000){
            return 3000;
        } else {
            return (weightkg)*100;
        }
    }
    
    double CaChloride::childMaxCl() {
        if (weightkg * 20 > 2000) {
            return 2000;
        } else {
            return weightkg * 20;
        }
    }
    
    double CaChloride::adultGl() {
        return weightkg * 60;
    }
    double CaChloride::adultCl() {
        return weightkg * 20;
    }

    
    string CaChloride::getRef() {
        return string("References for Calcium Chloride Algorithm\n\n") +
        "Buckley N, D. A. (1993). Slow-release verapamil poisoning. Use of polyethylene glycol  "  +
        "whole-bowel lavage and high-dose calcium. Med J Aust. , 158 (2), 202-204.\n\n"  +
        "Haddad, L. (1996). Resuscitation after nifedipine overdose exclusively with intravenous  "  +
        "calcium chloride. Am J Emerg Med , 14 (6), 602-3\n\n"  +
        "Hung YM, O. K. (2007). Acute amlodipine overdose treated by high dose intravenous "  +
        "calcium in a patient with severe renal insufficiency. Clin Toxicol , 45 (3), 301-303.\n\n"  +
        "Sim MT, S. F. (2008). A fatal case of iatrogenic hypercalcemia after calcium channel  "  +
        "blocker overdose. J Med Toxicol. , 4 (1), 25-29.\n\n"  +
        "Kleinman ME, C. L. (2010, November 1). Part 14: Pediatric Advanced Life Support: 2010  "  +
        "American Heart Association Guidelines for Cardiopulmonary Resuscitation and Emergency  "  +
        "Cardiovascular Care. Circulation . Dallas, Texas, U.S.: American Heart Association.\n\n"  +
        "Kerns, W. I. (2007). Management of Beta-Adrenergic Blocker and Calcium Channel Antagonist "  +
        "Toxicity. Emergency Medicine Clinics of North America , 25 (2), 309-331.\n\n"  +
        "Hegenbarth, M. A. (2008). Preparing for Pediatric Emergencies: Drugs to Consider.  "  +
        "Pediatrics 121(2): 433-443.";
    }
}