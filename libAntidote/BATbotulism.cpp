//============================================================================
// Name        : BATbotulism.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : BATbotulism Algorithm
//============================================================================


#include "BATbotulism.h"

namespace libAntidote {
    
    
    BATbotulism::BATbotulism(double age, double height, double weight) : Antidote(age, height, weight) {
        
        //Infant Dosing
        string stringInfant = a + b +
        "**This product is for use in children and adults.  Please refer to Baby-BIG Antidote Algorithm.**\n\n" +
        "If Baby-BIG is unavailable, withdraw 10% of one vial (final volume of " +
        "reconstituted vial varies from lot to lot) Botulism equine heptavalent antitoxin " +
        "and administer via IV infusion (in a 1:10 dilution with 0.9% NaCl) at a rate of " + calculateInfantRate() + "ml/min not " +
        "doubling every 30 minutes to a rate not to exceed " + toStr(weightkg * 0.03) + "ml/min" + c;
        //Children's dosing
        string stringChildren = a + b + "Children's dosing: " +
        "Give " + toStr(SalisburyRule() * 100) + "% of one vial of Botulism equine heptavalent antitoxin given " +
        "single dose  administered as an IV infusion (1:10 dilution in NaCl) at an initial rate of " + toStr(calculateDripRate()) + "ml/kg/min  " +
        "(not to exceed 0.5 ml/min). Monitor vital signs throughout infusion. If tolerated,  " +
        "increase the infusion rate by " + toStr(calculateDripRate()) + "ml/kg/min every 30 minutes not to exceed 2 ml/min. " +
        "Decrease rate if patient experiences discomfort or infusion-related adverse events.  " +
        "Dose is based on the Salisbury Rule." + c;
        //Adult dosing
        string stringAdult = a + b +
        "Adults 17 years and older: 1 vial administered via IV infusion (1:10 dilution in NaCl) at an initial rate of " +
        "0.5 ml/min.  Monitor vital signs throughout the infusion. If tolerated, the infusion rate may be doubled every " +
        "30 minutes to a maximum rate of 2 ml/min. Decrease the infusion rate if the patient experience discomfort or  " +
        "infusion-related adverse events." + c;
        //Sensitivity Infant Dosing
        string stringSensitiveInfant = a + b +
        "**Administer BAT in a setting with appropriate equipment, medication, and personnel trained in the  " +
        "trained in the management of hypersensitivity, anaphylaxis, and shock. " +
        "**This product is for use in children and adults.  Please refer to Infant Botulism Immune Globulin (Baby-BIG) " +
        "Antidote Algorithm.**\n\n" +
        "If Baby-BIG is unavailable, withdraw 10% of one vial (final volume of reconstituted vial varies from " +
        "lot to lot) Botulism equine heptavalent antitoxin and administer via IV infusion in a 1:10 dilution  " +
        "with 0.9% NaCl.  For patients at risk for hypersensitivity reaction, begin BAT administration at the  " +
        "lowest rate achievable (<0.01 mL/min)." + c;
        //Sensitivity Child Dosing
        string stringSensitiveChild = a + b + "Children's dosing: " +
        "Withdraw " + toStr(SalisburyRule() * 100) + "% of one vial of Botulism equine heptavalent " +
        "antitoxin and give as a " +
        "single dose  administered as an IV infusion in a 1:10 dilution in 0.9% NaCl. " +
        "For patients at risk for hypersensitivity reaction, begin BAT administration at the lowest rate  " +
        "achievable (<0.01 mL/min). Dose based on Salisbury Rule." + c;
        //Sensitivity Adult Dosing
        string stringSensitiveAdult = a + b +
        "Adults 17 years and older: 1 vial administered via IV infusion (1:10 dilution in NaCl)\n\n"+
        "For patients at risk for hypersensitivity reaction, begin BAT administration at the lowest rate  " +
        "achievable (<0.01 mL/min)." + c;
        //Skin test description
        string stringSkinTest = string("Skin Sensitivity Test:\n\n") +
        "This is a horse derived serum product.  Please perform the following skin sensitivity test.\n\n" +
        "Administer of 0.02 milliliters of 1:1000 saline-diluted BAT (enough to raise a small "+
        "wheal) intradermally on the volar surface of the forearm. If the test is negative, repeat "+
        "the test using a 1:100 dilution. Perform concurrent positive (histamine) and negative (saline) " +
        "control tests. A positive test is a wheal with surrounding erythema at least 3 millimeters " +
        "larger than the negative control test; read at 15-20 minutes. The histamine control must " +
        "be positive for valid interpretation." + c + "\n\n"+
        "After test please click appropriate button to proceed";

        Question *skinTest = new Question(stringSkinTest);
        string *antitoxinOptions = new string[2];
        antitoxinOptions[0] = "No Sensitivity";
        antitoxinOptions[1] = "Sensitivity";
        skinTest->setType("options");
        skinTest->setOptions(antitoxinOptions, 2);
        
        Question *Infant = new Question(stringInfant);
        Question *Children = new Question(stringChildren);
        Question *Adult = new Question(stringAdult);
        Question *SensitiveInfant = new Question(stringSensitiveInfant);
        Question *SensitiveChild = new Question(stringSensitiveChild);
        Question *SensitiveAdult = new Question(stringSensitiveAdult);
        
        prompts.insert(strQuestionMapPair("skinTest", skinTest));
        prompts.insert(strQuestionMapPair("Infant", Infant));
        prompts.insert(strQuestionMapPair("Children", Children));
        prompts.insert(strQuestionMapPair("Adult", Adult));
        prompts.insert(strQuestionMapPair("SensitiveInfant", SensitiveInfant));
        prompts.insert(strQuestionMapPair("SensitiveChild", SensitiveChild));
        prompts.insert(strQuestionMapPair("SensitiveAdult", SensitiveAdult));
    }
    
    BATbotulism::~BATbotulism() {
        
    }
    
    Question* BATbotulism::getNextQuestion(){
        int n1 = prompts["skinTest"]->getAnswerInt();
        if (n1==0){
            if(age < 1) {
                moreQuestions = false;
                return prompts["Infant"];
            } else if(age >= 1 && age < 17) {
                moreQuestions = false;
                return prompts["Children"];
            } else {
                moreQuestions = false;
                return prompts["Adult"];
            }
        } else if (n1 == 1) {
            if(age < 1) {
                moreQuestions = false;
                return prompts["SensitiveInfant"];
            } else if(age >= 1 && age < 17) {
                moreQuestions = false;
                return prompts["SensitiveChild"];
            } else {
                moreQuestions = false;
                return prompts["SensitiveAdult"];
            }
        } else {
            return prompts["skinTest"];
        }
    }
    
    
    double BATbotulism::calculateDripRate() {
        double maxRate = 0.5;
        if((weightkg * 0.01) > 0.5){
            return maxRate;
        } else {
            return weightkg * 0.01;
        }
    }
    
    string BATbotulism::calculateInfantRate() {
        double maxRate = 0.03 * weightkg;
        if((weightkg * 0.01) >  0.5) {
            return toStr(maxRate);
        } else {
            return toStr(weightkg * 0.01);
        }
    }
    
    double BATbotulism::SalisburyRule() {
        if (weightkg<=30) {
            if(((2 * weightkg) / 100) < 0.1) {
                return 0.1;
            } else {
                return (2 * weightkg) / 100;
            }
        } else {
            if(((weightkg + 30) / 100) > 1) {
                return 1;
            } else {
                return (weightkg + 30) / 100;
            }
        }
    }
    
    string BATbotulism::getRef() {
        return string("References for Botulism Antitoxin Algorithm\n\n") +
        "Cangene Corporation. (2013, March 1). Botulism Antitoxin Heptavalent � (EQUINE).\n" +
        "Package Insert . Winnipeg, Manitoba, Canada: Cangene Corporation.\n";
    }
}