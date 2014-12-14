//============================================================================
// Name        : Acetylcysteine.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Acetylcysteine Algorithm
//============================================================================


#include "Acetylcysteine.h"

namespace libAntidote {
    
    
    Acetylcysteine::Acetylcysteine(double age, double height, double weight) : Antidote(age, height, weight) {
        
        this->sampleHoursAfterExposure = 0;
        this->toxinLevel = 0;
        
        string a = "Acetylcysteine Antidote Algorithm\n";
        string b = string("For the treatment of acetaminophen toxicity.  ") + FDA + "\n\n";
        
        
        
        Question *timeOfOverDoseKnown = new Question("Is the time of overdose and blood level of acetaminophen known reliably?");
        timeOfOverDoseKnown->setType("yesno");
        prompts.insert(strQuestionMapPair("timeOfOverDoseKnown", timeOfOverDoseKnown));
        
        Question *howLongSinceOverDose = new Question("How long has it been since the overdose?");
        string *howLongSinceOverDoseOpt = new string[3];
        howLongSinceOverDoseOpt[0] = "Less than 4 hours ago";
        howLongSinceOverDoseOpt[1] = "4 to 24 hours ago";
        howLongSinceOverDoseOpt[2] = "More than 24 hours ago";
        howLongSinceOverDose->setOptions(howLongSinceOverDoseOpt, 3);
        
        prompts.insert(strQuestionMapPair("howLongSinceOverDose", howLongSinceOverDose));
        
        Question *whenWasBloodSampleTaken = new Question("How long after the overdose was the blood sample for acetaminophen level taken?");
        string *whenWasBloodSampleTakenOpt = new string[2];
        whenWasBloodSampleTakenOpt[0] = "Blood level taken >= 4hours post exposure";
        whenWasBloodSampleTakenOpt[1] = "Blood level taken < 4hours post exposure";
        whenWasBloodSampleTaken->setOptions(whenWasBloodSampleTakenOpt, 2);
        prompts.insert(strQuestionMapPair("whenWasBloodSampleTaken", whenWasBloodSampleTaken));
        
        Question *timeOfOverdoseUnknown = new Question(a + b + "If the time of overdose is unknown or the blood level is unknown, empirical acetaminophen "
                                                       + "overdose therapy is recommended until a reliable time can be estimated and acetaminophen "
                                                       + "blood levels are assesed. The following recommendations suggest doses of activated charcoal  "
                                                       + "and acetylcysteine based on the patient's weight.  Suggested times to draw blood samples  "
                                                       + "are given as well.\n\n"
                                                       + calculateActivatedCharcoal() + " "
                                                       + calculateAcetylcysteine() + " "
                                                       + bloodSampleSuggestions());
        prompts.insert(strQuestionMapPair("timeOfOverdoseUnknown", timeOfOverdoseUnknown));
        
        Question *timeOfOverdoseLessThenFourHours = new Question(a + b + "The following recommendations are for acetaminophen poisoned patients where the known time "
                                                                 + "of overdose is less than four hours ago.  No blood samples should be taken until 4 hours "
                                                                 + "after overdose.\n\n" + bloodSampleSuggestions() + "\n\n"
                                                                 + calculateAcetylcysteine() + "\n\n"
                                                                 + calculateActivatedCharcoal());
        prompts.insert(strQuestionMapPair("timeOfOverdoseLessThenFourHours", timeOfOverdoseLessThenFourHours));
        
        Question *timeOfOverdoseMoreThenTwentyFourHours = new Question(a + b + "Though little benefit is seen with acetylcysteine treatment "
                                                                       + "more than 24 hours after acetaminophen overdose, it is recommended "
                                                                       + "that acetylcysteine therapy be administered regardless of the minimal "
                                                                       + "potential benefit.\n\n"
                                                                       + calculateAcetylcysteine());
        prompts.insert(strQuestionMapPair("timeOfOverdoseMoreThenTwentyFourHours", timeOfOverdoseMoreThenTwentyFourHours));
        
        Question *bloodsampleTakenGreaterThenFourHours = new Question(calculateAcetylcysteine() + " "+ bloodSampleSuggestions());
        prompts.insert(strQuestionMapPair("bloodsampleTakenGreaterThenFourHours", bloodsampleTakenGreaterThenFourHours));
        
        Question *bloodsampleTakenLessThenFourHours = new Question(a + b + "The following recommendations are for acetaminophen poisoned patients "
                                                                   + "where the known time of overdose is between 4 and 24 hours ago.\n\n"
                                                                   + "If the acetaminophen blood level is known and the sample was taken "
                                                                   + "at least 4 hours after the time of overdose, you will be given the option "
                                                                   + "to determine if the acetaminophen level exceeds the treatment threshold.\n\n"
                                                                   + bloodSampleSuggestions() + " "
                                                                   + calculateActivatedCharcoal() + " "
                                                                   + calculateAcetylcysteine());
        prompts.insert(strQuestionMapPair("bloodsampleTakenLessThenFourHours", bloodsampleTakenLessThenFourHours));
        
        Question *blookdSampleTakenAfter = new Question("How many hours after overdose was the blood sample taken?");
        blookdSampleTakenAfter->setType("numbers", "hrs");
        blookdSampleTakenAfter->setMin(4);
        blookdSampleTakenAfter->setMax(24);
        prompts.insert(strQuestionMapPair("blookdSampleTakenAfter", blookdSampleTakenAfter));
        
        Question *bloodPlasmaLevel = new Question("What is the acetaminophen blood plasma level?");
        bloodPlasmaLevel->setType("numbers", "microgram/ml");
        prompts.insert(strQuestionMapPair("bloodPlasmaLevel", bloodPlasmaLevel));
        
        Question *bloodSampleMustTakenFourHoursAfterOverdose = new Question(a + b + "Blood sample must be taken four hours or more after acetaminophen overdose to determine toxicity.");
        prompts.insert(strQuestionMapPair("bloodSampleMustTakenFourHoursAfterOverdose", bloodSampleMustTakenFourHoursAfterOverdose));
        
        
    }
    
    Acetylcysteine::~Acetylcysteine() {
        // TODO Auto-generated destructor stub
    }
    
    Question* Acetylcysteine::getNextQuestion(){
        this->moreQuestions = true;
        int q1Ans = prompts["timeOfOverDoseKnown"]->getAnswerInt();
        if(q1Ans == 1) { // known time of overdose
            int q2Ans = prompts["howLongSinceOverDose"]->getAnswerInt();
            switch(q2Ans) {
                case 0:{ // Less than 4 hours ago
                    this->moreQuestions = false;
                    return prompts["timeOfOverdoseLessThenFourHours"];
                } case 1:{ // 4 to 24 hours ago
                    int q3Ans = prompts["whenWasBloodSampleTaken"]->getAnswerInt();
                    switch (q3Ans) {
                        case 0:{
                            
                            sampleHoursAfterExposure = prompts["blookdSampleTakenAfter"]->getAnswerFloat();
                            if(sampleHoursAfterExposure == -1) {
                                return prompts["blookdSampleTakenAfter"];
                            } else if (sampleHoursAfterExposure < 4) {
                                moreQuestions = false;
                                return prompts["bloodSampleMustTakenFourHoursAfterOverdose"];
                            }
                            
                            toxinLevel = prompts["bloodPlasmaLevel"]->getAnswerFloat();
                            //prompts["bloodsampleTakenGreaterThenFourHours"] = new Question(calculateAcetylcysteine() + " " + bloodSampleSuggestions());
                            if(toxinLevel == -1) {
                                return prompts["bloodPlasmaLevel"];
                            } else if (toxinLevel >= treatmentThreshold()) {
                                
                                this->moreQuestions = false;
                                return new Question("Treatment Threshold at " + toStr(sampleHoursAfterExposure)
                                                    + " hours after overdose =\n\n" + toStr(treatmentThreshold())
                                                    + " micrograms/ml\n\n Acetylcysteine treatment is recommended.\n\n"
                                                    + calculateAcetylcysteine() + " " + bloodSampleSuggestions());
                                
                            } else {
                                this->moreQuestions = false;
                                return new Question("Treatment Threshold at " + toStr(sampleHoursAfterExposure)
                                                    + " hours after overdose =\n\n" + toStr(treatmentThreshold())
                                                    + " micrograms/ml\n\n Antidote treatment is not indicated.");
                            }
                            
                            return prompts["bloodsampleTakenGreaterThenFourHours"];
                        } case 1: {
                            this->moreQuestions = false;
                            //bloodsampleTakenLessThenFourHours
                            return prompts["bloodsampleTakenLessThenFourHours"];
                        } case -1:
                        default:
                            return prompts["whenWasBloodSampleTaken"];
                    }
                } case 2: {
                    this->moreQuestions = false;
                    return prompts["timeOfOverdoseMoreThenTwentyFourHours"];
                } case -1:
                default:
                    return prompts["howLongSinceOverDose"];
            }
        } else if(q1Ans == 0){
            this->moreQuestions = false;
            return prompts["timeOfOverdoseUnknown"];
        } else {
            return prompts["timeOfOverDoseKnown"];
        }
    }
    
    string Acetylcysteine::calculateActivatedCharcoal() {
        string res = "";
        if (weightkg > 40) {
            res = string("Patients > 40 kg: Administer 25 to 100 grams ")
            + "of activated charcoal PO as tolerated as soon as possible "
            + "after overdose (Humco 2013).\n\n";
        } else if (20 < weightkg && weightkg <= 40) {
            res = string("Patients 21-40kg: Administer 25 to 50 grams of ")
            + "activated charcoal PO as tolerated as soon as possible "
            + "after overdose (Humco 2013).\n\n";
        } else if (5 <= weightkg && weightkg <= 20) {
            res = string("Patients 5-20kg: Administer 10 to 25 grams of ")
            + "activated charcoal PO as tolerated as soon as possible "
            + "after overdose (Humco 2013).\n\n";
        } else {
            res = string("Neonates and Premature infants:  Limited data available. ")
            + "Please consult with Neonatologist for activated charcoal dose. ";
        }
        return res;
    }
    
    string Acetylcysteine::calculateAcetylcysteine() {
        string res = "";
        
        if (weightkg >= 100) {
            res = string("Acetylcysteine may be dosed intravenously (IV) or orally (PO).\n\n")
            + "IV Dosing: 15000mg IV in 200 ml D5W over 60 min "
            + "followed by 5000mg IV in 500 ml D5W or NS over 4 hours "
            + "followed by a final dose of 10000mg in 1000 ml D5W over 16 hours.\n\n"
            + "Oral Dosing:  "
            + toStr(140 * weightkg)
            + " mg PO initially, followed by "
            + toStr(70 * weightkg)
            + " mg PO every  "
            + "4 hours for 17 doses.  Any dose vomited within one hour of administration must  "
            + "be repeated. (Cumberland Pharmaceuticals 2013)\n\n";
        } else if (5 <= weightkg && weightkg < 100) {
            res = string("Acetylcysteine may be dosed intravenously (IV) or orally (PO).\n\n")
            + "IV Dosing:  "
            + toStr(150 * weightkg)
            + " mg (not to exceed 15000 mg) "
            + "IV in 200 ml D5W over 60 min followed by "
            + toStr(50 * weightkg) + "mg  "
            + "IV in 500 ml D5W or NS over 4 hours followed by a final dose of "
            + toStr(100 * weightkg) + " mg "
            + "(not to exceed 10000 mg) in 1000 ml D5W over 16 hours.\n\n"
            + "Oral Dosing: "
            + toStr(140 * weightkg)
            + " mg PO initially, followed by "
            + toStr(70 * weightkg)
            + " mg PO every  "
            + "4 hours for 17 doses.  Any dose vomited within one hour of administration must  "
            + "be repeated. (Cumberland Pharmaceuticals 2013) ";
            
        } else {
            res = string("Limited data available.  Please consult with Neonatologist.  Premature infants ")
            + "(gestational age 25-31 weeks) have received 4.2 mg/kg/hr IV infusion over 24 hours "
            + " with no adverse affects.\n\n"
            + "In another study premature infants (gestational age 26-30 weeks) received  "
            + "0.1-1.3mg/kg/hour for 6 days with no adverse effects. (Cumberland Pharmaceuticals 2013) ";
            
        }
        return res;
    }
    
    string Acetylcysteine::bloodSampleSuggestions() {
        return string("Blood samples to determine acetaminophen levels should be taken no less than ")
        + "4 hours after acetaminophen overdose for immediate release preparations. "
        + "Samples taken before this time may not indicate when liver toxicity is present.\n\n"
        + "For extended release preparations, another sample should be taken at 8 hours after "
        + "acetaminophen overdose as these preparations can delay the appearance of toxicity.";
    }
    
    string Acetylcysteine::getRef() {
        return string("Humco. (2013, August 1). Activated charcoal powder for oral solution product label. ")
        + "Activated charcoal powder for oral solution. Texarkana, Texas, U.S.\n\n"
        + "Cumberland Pharmaceuticals. (2013, June 1). Acetadote (N-acetylcysteine) injection.  "
        + "Acetadote package insert. Nashville, Tennessee, U.S.: Cumberland Pharmaceuticals.\n\n"
        + "Elsevier. (2014, January 1). Acetylcysteine. Retrieved March 18, 2014, from Clinical "
        + "Pharmacology: http://www.clinicalpharmacology.com\n\n"
        + "A. R. Temple, J.S.Baggish. (2005). Guidelines for the Management of Acetaminophen Overdose, "
        + "McNeil Consumer & Specialty Pharmaceuticals.\n\n";
    }
    
    bool Acetylcysteine::apapToxicityTest() {
        
        string res = "";
        
        if (toxinLevel >= treatmentThreshold() && sampleHoursAfterExposure >= 4) {
            res = string("Treatment Threshold at ") + toStr(sampleHoursAfterExposure) + ""
            + " hours after overdose =\n\n" + toStr(treatmentThreshold())
            + " micrograms/ml\n\n Acetylcysteine treatment is recommended.";
        } else if (toxinLevel < treatmentThreshold() && sampleHoursAfterExposure >= 4) {
            res = string("Treatment Threshold at ") + toStr(sampleHoursAfterExposure) + ""
            + " hours after overdose =\n\n" + toStr(treatmentThreshold())
            + " micrograms/ml\n\n Antidote treatment is not indicated.";
        }
        if (toxinLevel >= treatmentThreshold() && sampleHoursAfterExposure >= 4)
            return true;
        else
            return false;
    }
    
    double Acetylcysteine::treatmentThreshold() {
        return (150) * (pow((M_E), ((-1) * (0.1732868) * (sampleHoursAfterExposure - 4))));
    }
    
}
