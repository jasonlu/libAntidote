//============================================================================
// Name        : CoralSnake.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CoralSnake Algorithm
//============================================================================


#include "CoralSnake.h"

namespace libAntidote {
    
    
    CoralSnake::CoralSnake(double age, double height, double weight) : Antidote(age, height, weight) {
        
        string a = "Coral Snake Envenomation Algorithm. ",
        b = string("For the treatement of Coral Snake (Micrurus fulvius) envenomation. ") +
        "Effective against all North American Coral Snake envenomation except " +
        "Arizona(sonoran) coral snake. ",
        c = " (Wyeth� , 2001)";
        string stringSystemicReaction = string("Systemic Reaction: ") +
        "If a systemic reaction occurs after any injection, place a tourniquet  " +
        "proximal to the site of injections and administer an appropriate dose  " +
        "of epinephrine, 1:1000, proximal to the tourniquet or into another extremity.  " +
        "Wait at least 30 minutes before injecting another dose."+c;
        
        string stringSkinTest = string("Skin Test: This product is an equine (horse) derivative. ") +
        "Patients allergic to equine products may have a severe reaction. " +
        "It is recommended that you perform a sensitivity test before proceeding\n\n" +
        "Using a tuberculin-type syringe, inject 0.02�0.03 ml of a 1:10 dilution  " +
        "(1:100 for patients with history of equine sensitivity)of Antivenin  " +
        "intradermally. Perform a control test with NS on the opposite " +
        "side of the body as a control.  If there is any (even if very mild) reaction " +
        " within 5 to 30 minutes, this indicates sensitivity." +c+
        "\n\nPlease click appropriate button after test is complete.";
        string stringIVDose = string("IV Dosing: Start an intravenous drip of 250 to 500 ml of Sodium Chloride Injection, USP.  Administer the ") +
        "contents of 3 to 5 vials (30 to 50 ml) INTRAVENOUSLY by slow injection directly into the intravenous tubing " +
        "or by adding to the intravenous drip.  In either case, the first 1 or 2 ml should be injected over a 3- to  " +
        "5-minute period with careful observation of the patient for evidence of allergic reaction. If no signs or  " +
        "symptoms of anaphylaxis appear, continue the injection or intravenous infusion.  Until the equivalent of  " +
        "30 to 50 ml of undiluted Antivenin has been given, administer at the maximum safe rate for intravenous fluids. " +
        "If given by intravenous drip to a previously healthy adult, allow 250 or 500 ml to run in within 30 minutes. " +
        "Response to treatment may be rapid and dramatic. Observe the patient carefully and administer additional  " +
        "Antivenin intravenously as required."+c;
        string stringIVDoseChildren = string("Start an intravenous drip of 250ml of Sodium Chloride Injection (volume may be adjusted for infants - consult ") +
        "neonatologist), USP.  Administer the contents of 3 to 5 vials (30 to 50 ml) INTRAVENOUSLY by slow injection  " +
        "directly into the intravenous tubing or by adding to the intravenous drip.  In either case, the first 1 or 2 ml  " +
        "should be injected over a 3- to 5-minute period with careful observation of the patient for evidence of allergic  " +
        "reaction. If no signs or symptoms of anaphylaxis appear, continue the injection or intravenous infusion.  Until the  " +
        "equivalent of 30 to 50 ml of undiluted Antivenin has been given, administer at the maximum safe rate for intravenous  " +
        "fluids.  If given by intravenous drip in small children, allow the first 100 ml to run in rapidly but then decrease  " +
        "to a rate not to exceed 4 ml per minute. Response to treatment may be rapid and dramatic. Observe the patient carefully  " +
        "and administer additional Antivenin intravenously as required."+c;
        string stringIMDose = string("IM Dosing: ") +
        "At first inject SUBCUTANEOUSLY, using a tuberculin-type syringe, 0.1, 0.2, and 0.5 ml of the 1:100 dilution  " +
        "at 15-minute intervals; repeat with the 1:10 dilution, and finally undiluted Antivenin. If a systemic  " +
        "reaction occurs after any injection, place a tourniquet proximal to the site of injections and administer " +
        "an appropriate dose of epinephrine, 1:1000, proximal to the tourniquet or into another extremity. Wait at  " +
        "least 30 minutes before injecting another dose. The amount of the next dose should be the same as the last  " +
        "that did not evoke a reaction.  If no reaction occurs after 0.5 ml of undiluted Antivenin has been  " +
        "administered, switch to the intramuscular route. After 0.5ml dose continue doubling the dose at 15-minute " +
        "intervals until the entire dose (3 to 5 vials) has been injected intramuscularly (maximum IM volume is 2ml per injection). " +
        "Administer additional antivenin as required"+c;
        string stringDesensitization = string("Inject subcutaneously, using a tuberculin-type syringe, 0.1, 0.2, and 0.5 ml of the 1:100 dilution of ") +
        "antivenin at 15-minute intervals; repeat with the 1:10 dilution, and finally undiluted Antivenin. If a  " +
        "systemic reaction occurs after any injection, place a tourniquet proximal to the site of injections and " +
        "administer an appropriate dose of epinephrine, 1:1000, proximal to the tourniquet or into another extremity. " +
        "Wait at least 30 minutes before injecting another dose. The amount of the next dose should be the same as " +
        "the last that did not evoke a reaction.  If no reaction occurs after 0.5 ml of undiluted Antivenin has been " +
        "administered, switch to the intramuscular route or IV route.\n\n" +
        "IM Route: After 0.5ml dose continue doubling the dose at 15-minute intervals until the entire dose (3-5 vials) " +
        "has been injected intramuscularly (maximum IM volume is 2ml per injection).\n\n" + stringIVDose;
        string stringDesensitizationChildren = string("Inject subcutaneously, using a tuberculin-type syringe, 0.1, 0.2, and 0.5 ml of the 1:100 dilution of ") +
        "antivenin at 15-minute intervals; repeat with the 1:10 dilution, and finally undiluted Antivenin. If a  " +
        "systemic reaction occurs after any injection, place a tourniquet proximal to the site of injections and " +
        "administer an appropriate dose of epinephrine, 1:1000, proximal to the tourniquet or into another extremity. " +
        "Wait at least 30 minutes before injecting another dose. The amount of the next dose should be the same as " +
        "the last that did not evoke a reaction.  If no reaction occurs after 0.5 ml of undiluted Antivenin has been " +
        "administered, switch to the intramuscular route or IV route.\n\n" +
        "IM Route (not recommended in infants): After 0.5ml dose continue doubling the dose at 15-minute intervals  " +
        "until the entire dose (3-5 vials) has been injected intramuscularly (maximum IM volume is 2ml per injection).\n\n" + stringIVDoseChildren;
        
        string stringInfant = string("Infants: Use not established.  Consult pediatrician and children's dosing regimen. ");
        string stringChildren = string("Children's Dosing: ");
        string stringAdult = string("Adult Dosing: ");
        string stringIVOrIM = string("Preferred method of administration is IV. However, IM dosing is ") +
        "available.  Please click IV or IM to view respective dose recommendations.";
        
        
        //Algorithm message
        Question *AlgorithmMessage = new Question(a + b);
        AlgorithmMessage->setType("info");
        prompts.insert(strQuestionMapPair("AlgorithmMessage", AlgorithmMessage));

        //Systemic reaction warning
        Question *SystemicReactionWarning = new Question(stringSystemicReaction);
        SystemicReactionWarning->setType("warning");
        prompts.insert(strQuestionMapPair("SystemicReactionWarning", SystemicReactionWarning));

        string *antiveninOptions = new string[2];
        antiveninOptions[0] = "No Sensitivity";
        antiveninOptions[1] = "Sensitivity";
        
        string *administrationOptions = new string[2];
        administrationOptions[0] = "IV";
        administrationOptions[1] = "IM";


        Question *SkinTestInfant = new Question(stringInfant + stringChildren + stringSkinTest);
        SkinTestInfant->setOptions(antiveninOptions, 2);
        prompts.insert(strQuestionMapPair("SkinTestInfant", SkinTestInfant));
        
        Question *SkinTestChildren = new Question(stringChildren + stringSkinTest);
        SkinTestChildren->setOptions(antiveninOptions, 2);
        prompts.insert(strQuestionMapPair("SkinTestChildren", SkinTestChildren));

        Question *SkinTestAdult = new Question(stringAdult + stringSkinTest);
        SkinTestAdult->setOptions(antiveninOptions, 2);
        prompts.insert(strQuestionMapPair("SkinTestAdult", SkinTestAdult));


        Question *IVOrIM = new Question(stringIVOrIM);
        IVOrIM->setOptions(administrationOptions, 2);
        prompts.insert(strQuestionMapPair("IVOrIM", IVOrIM));
        
        //End nodes:
        Question *InfantIVDose = new Question(stringInfant + stringChildren + stringIVDoseChildren);
        prompts.insert(strQuestionMapPair("InfantIVDose", InfantIVDose));
        Question *InfantDesensitization = new Question(stringInfant + stringChildren + stringDesensitizationChildren);
        prompts.insert(strQuestionMapPair("InfantDesensitization", InfantDesensitization));
        
        Question *ChildrenIVDose = new Question(stringChildren + stringIVDoseChildren);
        prompts.insert(strQuestionMapPair("ChildrenIVDose", ChildrenIVDose));
        Question *ChildrenIMDose = new Question(stringChildren + stringIMDose);
        prompts.insert(strQuestionMapPair("ChildrenIMDose", ChildrenIMDose));
        Question *ChildrenDesensitization = new Question(stringChildren + stringDesensitizationChildren);
        prompts.insert(strQuestionMapPair("ChildrenDesensitization", ChildrenDesensitization));
        
        Question *AdultIVDose = new Question(stringAdult + stringIVDose);
        prompts.insert(strQuestionMapPair("AdultIVDose", AdultIVDose));
        Question *AdultIMDose = new Question(stringAdult + stringIMDose);
        prompts.insert(strQuestionMapPair("AdultIMDose", AdultIMDose));
        Question *AdultDesensitization = new Question(stringAdult + stringDesensitization);
        prompts.insert(strQuestionMapPair("AdultDesensitization", AdultDesensitization));
        
    }
    
    CoralSnake::~CoralSnake() {
        
    }
    
    Question* CoralSnake::getNextQuestion() {
        
        if(prompts["AlgorithmMessage"]->getAnswerInt() == -1) {
            return prompts["AlgorithmMessage"];
        }
        if(prompts["SystemicReactionWarning"]->getAnswerInt() == -1) {
            return prompts["SystemicReactionWarning"];
        }

        //neonate and infant dosing
        if(age < 1){
            int n1 = prompts["SkinTestInfant"]->getAnswerInt();
            if (n1 == 0) {
                moreQuestions = false;
                return prompts["InfantIVDose"];
            } else if (n1 == 1) {
                moreQuestions = false;
                return prompts["InfantDesensitization"];
            } else {
                return prompts["SkinTestInfant"];
            }
        }
        
        //children's dosing
        else if(age >= 1 && age <= 21) {
            int n1 = prompts["SkinTestChildren"]->getAnswerInt();

            if (n1 == 0) {
                int n2 = prompts["IVOrIM"]->getAnswerInt();
                if(n2 == 0){
                    moreQuestions = false;
                    return prompts["ChildrenIVDose"];
                } else if(n2 == 1){
                    moreQuestions = false;
                    return prompts["ChildrenIMDose"];
                } else {
                    return prompts["IVOrIM"];
                }
            } else if (n1 == 1) {
                moreQuestions = false;
                return prompts["ChildrenDesensitization"];
            } else {
                return prompts["SkinTestChildren"];
            }
        }
        
        //adult dosing
        else {
            int n1 = prompts["SkinTestAdult"]->getAnswerInt();
            if (n1 == 0) {
                int n2 = prompts["IVOrIM"]->getAnswerInt();
                if(n2 == 0){
                    moreQuestions = false;
                    return prompts["AdultIVDose"];
                } else if(n2 == 1){
                    moreQuestions = false;
                    return prompts["AdultIMDose"];
                } else {
                    return prompts["IVOrIM"];
                }
            } else if (n1==1){
                moreQuestions = false;
                return prompts["AdultDesensitization"];
            } else {
                return prompts["SkinTestAdult"];
            }
        }
    }
    
    
    string CoralSnake::getRef() {
        return string("References for North American Coral Snake Antivenin Algorithm\n\n") +
        "Wyeth� . (2001, August 31). Antivenin (Micrurus fulvius) (Equine Origin) "+
        "North American Coral Snake Antivenin . Package Insert . Marietta, Pennsylvania, "+
        "U.S.: Wyeth�.";
    }
}