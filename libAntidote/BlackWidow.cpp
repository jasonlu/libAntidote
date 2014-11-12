//============================================================================
// Name        : BlackWidow.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : BlackWidow Algorithm
//============================================================================


#include "BlackWidow.h"

namespace libAntidote {
    
    
    BlackWidow::BlackWidow(double age, double height, double weight) : Antidote(age, height, weight) {
        string a = "Black Widow envenomation Algorithm.\n",
        b = "For the treatement of Black Widow (Latrodectus mactans) envenomation.\n\n",
        c = "\n(Merck & Co., Inc. , 2014)";
        
        string stringSystemicReaction = string(" As with any administration of serum products, support for ") +
        "systemic reaction should be made ready prior to administration";
        string stringSerumSickness = string(" Patients should be observed for serum sickness for an average ") +
        "of 8 to 12 days following administration of antivenin.";
        string stringNeonate = a + b + string("Safety and efficacy has not been established in neonates. ") +
        "Please consult neonatologist for dosing instructions.";
        string stringInfantChildren = a + b +
        string("Prior to therapeutic administration a skin test should be performed ") +
        "to determine sensitivity to antivenin serum.  Inject a 1:10 dilution of  " +
        "antivenin serum intradermally.  If there is no reaction after 10 minutes, " +
        "proceed with antivenin administration.\n\nAntivenin administration in children:\n\n" +
        "Intravenous administration is preferred method in children.  Administer " +
        "entire reconstituted vial (2.5 ml) of antivenin in 10ml to 50ml of Normal Saline " +
        "over 15 minutes.  Symptoms should subside in 1 to 3 hours.";
        string stringAdolescent = a + b +
        string("Prior to therapeutic administration a skin test should be performed ") +
        "to determine sensitivity to antivenin serum.  Inject a 1:10 dilution of  " +
        "antivenin serum intradermally.  If there is no reaction after 10 minutes, " +
        "proceed with antivenin administration.\n\nAntivenin administration in adolescents:\n\n" +
        "Intravenous administration is preferred method in children.  Administer " +
        "entire reconstituted vial (2.5 ml) of antivenin in 10ml to 50ml of Normal Saline " +
        "over 15 minutes.  Symptoms should subside in 1 to 3 hours.";
        string stringElderly = a + b +
        string("Prior to therapeutic administration a skin test should be performed ") +
        "to determine sensitivity to antivenin serum.  Inject a 1:10 dilution of  " +
        "antivenin serum intradermally.  If there is no reaction after 10 minutes, " +
        "proceed with antivenin administration.\n\nAntivenin administration in adolescents:\n\n" +
        "Intravenous administration is preferred method in the elderly.  Administer " +
        "entire reconstituted vial (2.5 ml) of antivenin in 10ml to 50ml of Normal Saline " +
        "over 15 minutes.  Symptoms should subside in 1 to 3 hours.";
        string stringAdultNatural = a + b +
        string("For a healthy patient aged 16 to 60, it is recommended that the patient not receive ") +
        "antivenin serum and only pain symptoms should be treated.  Healthly patients aged " +
        "16 to 60 should receive antivenin only when envenomation symptoms are moderate to severe.";
        string stringAdult = a + b +
        string("Prior to therapeutic administration a skin test should be performed ") +
        "to determine sensitivity to antivenin serum.  Inject a 1:10 dilution of  " +
        "antivenin serum intradermally.  If there is no reaction after 10 minutes, " +
        "proceed with antivenin administration.\n\n" +
        "Intravenous administration adults: " +
        "Administer entire reconstituted vial (2.5 ml) of antivenin in 10ml to 50ml of " +
        "Normal Saline over 15 minutes.  Symptoms should subside in 1 to 3 hours. " +
        "Intramuscular administration adults: " +
        "Reconstitute antivenin vial with diluent supplied in kit.  Administer " +
        "intramuscularly to the anterolateral thigh.  Placement of dose allows tourniquet " +
        "to be applied in the event of systemic reaction.";
        
        string stringSeverity = "Describe the severity of bite. ";
        string *antiveninOptions = new string[2];
        antiveninOptions[0] = "Severe";
        antiveninOptions[1] = "Mild";
        
        Question *severity = new Question(stringSeverity);
        severity->setType("options");
        severity->setOptions(antiveninOptions, 2);
        prompts.insert(strQuestionMapPair("severity", severity));
        
        Question *age0 = new Question(stringNeonate + stringSystemicReaction + stringSerumSickness + c);
        prompts.insert(strQuestionMapPair("age0", age0));
        
        Question *ageLessThen12 = new Question(stringInfantChildren + stringSystemicReaction + stringSerumSickness + c);
        prompts.insert(strQuestionMapPair("ageLessThen12", ageLessThen12));
        
        Question *age12To16 = new Question(stringAdolescent + stringSystemicReaction + stringSerumSickness + c);
        prompts.insert(strQuestionMapPair("age12To16", age12To16));
        
        Question *ageGreaterThen60 = new Question(b + stringElderly + stringSystemicReaction + stringSerumSickness + c);
        prompts.insert(strQuestionMapPair("ageGreaterThen60", ageGreaterThen60));
        
        Question *age16To60Severe = new Question(stringAdult + stringSystemicReaction + stringSerumSickness + c);
        prompts.insert(strQuestionMapPair("age16To60Severe", age16To60Severe));
        
        Question *age16To60Mild = new Question(stringAdultNatural + c);
        prompts.insert(strQuestionMapPair("age16To60Mild", age16To60Mild));

        
    }
    
    BlackWidow::~BlackWidow() {
        
    }
    
    Question* BlackWidow::getNextQuestion(){
        if (age == 0) {
            moreQuestions = false;
            return prompts["age0"];
        } else if (age < 12) {
            moreQuestions = false;
            return prompts["ageLessThen12"];
        } else if (age >= 12 && age < 16) {
            moreQuestions = false;
            return prompts["age12To16"];
        } else if (age > 60) {
            moreQuestions = false;
            return prompts["ageGreaterThen60"];
        } else {//if (age >= 16 && age <= 60){
            int n1 = prompts["severity"]->getAnswerInt();
            if (n1==0) {
                moreQuestions = false;
                return prompts["age16To60Severe"];
            } else if (n1 == 1) {
                moreQuestions = false;
                return prompts["age16To60Mild"];
            } else {
                return prompts["severity"];
            }
        }
        
    }
    
    
    
    
    string BlackWidow::getRef() {
        return string("References for Black Widow Antitoxin Algorithm\n\n") +
        "Merck & Co., Inc.(2014, February 1). ANTIVENIN (LATRODECTUS MACTANS) " +
        "(Black Widow Spider Antivenin) Equine Origin Package Insert. " +
        "Whitehouse Station, New Jersey, U.S.: Merck & Co., Inc. ";
    }
}