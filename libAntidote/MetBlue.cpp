//============================================================================
// Name        : MetBlue.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : MetBlue Algorithm
//============================================================================


#include "MetBlue.h"

namespace libAntidote {
    
    
    MetBlue::MetBlue(double age, double height, double weight) : Antidote(age, height, weight) {
        
        a = "Methylene Blue Antidote Algorithm \n",
        b = string("For the treatment of methemoglobinemia.  ") + FDA + "\n\n",
        c = "";//getRef();
        
        Question *nitrateQ = new Question("Is the patient's methemoglobinemia nitrate induced as a result of cyanide therapy?");
        nitrateQ->setType("yesno");
        insertToMap("nitrateQ", nitrateQ);
        
        string metBlueNeo = a + b + "Use with caution in infants. Methylene blue an worsen methemoglobinemia paradoxically in infants.\n\n" +
            "Administer "+toStr( weightkg*0.3)+"-"+toStr( weightkg*1)+" mg (0.3-1 mg/kg) of methylene blue slow IVP\n" +
            "over 3-5 minutes and flush line.  " + c;
        insertToMap("metBlueNeo", metBlueNeo);
        
        string metBlueAdult = a + b + "Administer " + toStr(weightkg * 1) + "-" + toStr(weightkg * 2) +
            "mg (1-2mg/kg) of methylene blue slow IVP over 3-5 minutes and flush line." + c;
        insertToMap("metBlueAdult", metBlueAdult);
        
        Question *warning = new Question(string("Use with caution in patients with G6PD deficiency.")  +
        "If treatment is ineffective or condition worsens, exchange " +
        "transfusion may be indicated.");
        warning->setType("warning");
        insertToMap("warning", warning);
        
        
        
        
    }
    
    MetBlue::~MetBlue() {
        
    }
    
    Question* MetBlue::getNextQuestion(){
        int n1 = prompts["nitrateQ"]->getAnswerInt();
        if (n1==0){
            if(prompts["warning"]->getAnswerInt() == -1) {
                return prompts["warning"];
            }
            moreQuestions = false;
            if(age <= 0.0833){
                return prompts["metBlueNeo"];
            } else {
                return prompts["metBlueAdult"];
            }
        } else if (n1==1){
            moreQuestions = false;
            return new Question("Methylene blue is not recommended for treatment of nitrate induced methemogobinemia as a result of cyanide treatment.");
        } else {
            return prompts["nitrateQ"];
        }
    }
    
    
    
    string MetBlue::getRef() {
        return string("\n\nReferences for Methylene Blue Algorithm: \n\n") +
        "Akorn, Inc. (2008, August 1). METHYLENE BLUE. Package Insert. \n" +
        "Lake Forest, Ill, U.S.: Akorn, Inc.\n\n" +
        "King, A. R. (2012, January 1). Antidote Chart. Antidote Chart. \n" +
        "Kansas City, Kansas, U.S.: Thomas Land Publishers, Inc.\n\n" +
        "Hjelt, K., Lund, J., Scherling, B., Bendixen, S., Lundstram, K., \n" +
        "Stovring, S., et al. (1995). Methaemoglobinaemia among neonates in \n" +
        "a neonatal intensive care unit. Acta Paediatrica , 84 (4), 365-370.";
    }
}