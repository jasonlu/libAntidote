//============================================================================
// Name        : CrotalidaeOvine.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CrotalidaeOvine Algorithm
//============================================================================


#include "CrotalidaeOvine.h"

namespace libAntidote {
    
    
    CrotalidaeOvine::CrotalidaeOvine(double age, double height, double weight) : Antidote(age, height, weight) {
        
        string a = "Crotalidae or pit viper envenomation", b = "For the treatment of Crotalidae or pit viper envenomation.",
        c = " (Protherics Inc., 2008)";

        string stringInfantsChildren = b + " Dosing for infants and children:\n\n" +
        "The dose of antivenin to be administered to infants and children is expected to be the same. " +
        "Initially 4-6 vials of crotalidae antivenin ovine should be administered at a rate " +
        "of 25-50 ml/hr for the first 10 minutes with careful observation of any signs of allergic " +
        "reaction.  If no signs exist, increase the rate to 250ml/hr.  After administration of " +
        "antivenin, observe for 1 hour.  If control of envenomation syndrome is not achieved, another " +
        "vials of antivenin may be administered until symptoms have resolved.  Additional doses of 2 vials " +
        "every 6 hours for up to 18 hours as needed.  To date no dose over 18 vials has been used." + c;
        string stringAdolescentAdult = b + " Dosing for adolescents and adults\n\n" +
        "Initially 4-6 vials of crotalidae antivenin ovine should be administered at a rate " +
        "of 25-50 ml/hr for the first 10 minutes with careful observation of any signs of allergic " +
        "reaction.  If no signs exist, increase the rate to 250ml/hr.  After administration of " +
        "antivenin, observe for 1 hour.  If control of envenomation syndrome is not achieved, another " +
        "vials of antivenin may be administered until symptoms have resolved.  Additional doses of 2 vials " +
        "every 6 hours for up to 18 hours as needed.  To date no dose over 18 vials has been used." + c;
        
        string reconsider = string("Please re-consider the use of crotalidae antiventin (ovine) as the equine ") +
        "derived antidote is no longer available in the U.S.";
        
        string *antiveninOptions = new string[2];
        antiveninOptions[0] = "Proceed";
        antiveninOptions[1] = "Exit";
        
        string stringProceedOrExit = string("This product is an ovine (sheep) derivative. ") +
        "Patients allergic to ovine products may have a severe reaction. " +
        "It is recommended that you proceed with Antivenin Crotalidae Ovine therapy " +
        "if the wound is life or limb threatening and provide care for anaphylaxis " +
        "if necessary." + c;
        
        Question *InfantsChildren = new Question(stringInfantsChildren);
        Question *AdolescentAdult = new Question(stringAdolescentAdult);
        Question *ProceedOrExit = new Question(stringProceedOrExit);
        Question *Exit = new Question("");
        ProceedOrExit->setOptions(antiveninOptions, 2);
        
        prompts.insert(strQuestionMapPair("InfantsChildren", InfantsChildren));
        prompts.insert(strQuestionMapPair("AdolescentAdult", AdolescentAdult));
        prompts.insert(strQuestionMapPair("ProceedOrExit", ProceedOrExit));
        prompts.insert(strQuestionMapPair("Exit", Exit));
        
    }
    
    CrotalidaeOvine::~CrotalidaeOvine() {
        
    }
    
    Question* CrotalidaeOvine::getNextQuestion(){

        int n1 = prompts["ProceedOrExit"]->getAnswerInt();
       
        if (n1==0) {
            if ( age >= 0 && age <= 12) {
                moreQuestions = false;
                return prompts["InfantsChildren"];
            } else  {
                moreQuestions = false;
                return prompts["AdolescentAdult"];
            }
        } else if(n1 == 1) {
            moreQuestions = false;
            return prompts["Exit"];
        } else {
            return prompts["ProceedOrExit"];
        }
    }
    
    
    
    string CrotalidaeOvine::getRef() {
        return string("References for Rattlesnake Antivenin Algorithm\n\n") +
        "Protherics Inc.(2008, June 1) CROFAB� CROTALIDAE POLYVALENT IMMUNE FAB (OVINE).   " +
        "Package Insert . Brentwood, Tennessee, U.S.";
    }
}