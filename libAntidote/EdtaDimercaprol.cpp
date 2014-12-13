//============================================================================
// Name        : EdtaDimercaprol.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : EdtaDimercaprol Algorithm
//============================================================================


#include "EdtaDimercaprol.h"

namespace libAntidote {
    
    
    EdtaDimercaprol::EdtaDimercaprol(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Ca-EDTA and Dimercaprol Algorithm \n",
        b = string("For the treatment of lead encephalopathy and toxicity.  ") + FDA + "\n\n",
        c = "";//getRef();
        Question* strEncephalopathy = new Question(a + b + "Administer Dimercaprol "+toStr(weightkg*4)+"mg (4mg/kg)IM for first dose followed by " +
                                                   toStr(weightkg*4)+"mg\n" +
                                                   "(4mg/kg) every 4 hours until acceptable blood levels acheived (up to 5days).  After first dose of \n" +
                                                   "Dimercaprol, administer Ca-EDTA "+toStr(calcAdultEncED())+
                                                   "mg per day (1500mg/m^2/day max 3000mg/day) in 500ml (adults)\n" +
                                                   "of D5W or NS via IVCI for up to 5 days or until acceptable blood levels achieved." + c);
        insertToMap("strEncephalopathy", strEncephalopathy);
        
        Question* strEncPed = new Question(a + b + "Administer Dimercaprol "+toStr(weightkg*4)+"mg (4mg/kg) IM for first dose followed by " +toStr(weightkg*4)+"mg\n" +
                                           "(4mg/kg) every 4 hours until acceptable blood levels acheived (up to 5days).  After first dose of \n" +
                                           "Dimercaprol, administer Ca-EDTA "+toStr(calcPedEncED())+"mg per day (1500mg/m^2/day max 1000mg/day) in D5W or NS\n" +
                                           "(adjust total volume for pediatric dosing) via IVCI for up to 5 days or until \n" +
                                           "acceptable blood levels achieved." + c);
        insertToMap("strEncPed", strEncPed);
        
        Question* strOver70 = new Question("Administer Dimercaprol "+toStr(weightkg*4)+"mg (4mg/kg) IM for first dose followed by " +toStr(weightkg*4)+"mg\n" +
                                           "(4mg/kg)every 4 hours until acceptable blood levels acheived (up to 5days).  After first dose of \n" +
                                           "Dimercaprol, administer Ca-EDTA "+toStr(calcAdultED())+"mg per day (1000mg/m^2/day max 3000mg/day) in 500ml (adults)\n" +
                                           "of D5W or NS  via IVCI for up to 5 days or until acceptable blood levels achieved.");
        insertToMap("strOver70", strOver70);
        
        Question* strOver70Ped = new Question(a + b + "Administer Dimercaprol "+toStr(weightkg*4)+"mg (4mg/kg) IM for first dose followed by " +toStr(weightkg*4)+"mg\n" +
                                              "(4mg/kg) every 4 hours until acceptable blood levels acheived (up to 5days).  After first dose of \n" +
                                              "Dimercaprol, administer Ca-EDTA "+toStr(calcPedED())+"mg per day (1000mg/m^2/day max 1000mg/day) in of D5W or NS \n" +
                                              "(adjust total volume for pediatric dosing) via IVCI for up to 5 days or until acceptable\n" +
                                              "blood levels achieved." + c);
        insertToMap("strOver70Ped", strOver70Ped);
        
        Question* strBetween45and70 = new Question(a + b + "Administer Ca-EDTA "+toStr(calcPedED())+"mg per day (1000mg/m^2/day max 1000mg/day) in D5W or NS \n" +
                                                   "(adjust total volume for pediatric dosing) via IVCI for up to 5 days or " +
                                                   "until acceptable blood levels achieved." + c);
        insertToMap("strBetween45and70", strBetween45and70);
        
        Question* strNoTx = new Question(a + b + "Pharmaceutical intervention is not indicated adult patients with Pb levels\n" +
                                         "less than 70mcg/dl.\n" +
                                         "Please contact Poison Control for further guidance at 1-800-222-1222.\n" + c);
        insertToMap("strNoTx", strNoTx);
        
        Question* strNoTx45 = new Question(a + b + "Pharmaceutical intervention is not indicated patients \n" +
                                           "with Pb levels less than 45mcg/dl.\n" +
                                           "Please contact Poison Control for further guidance at 1-800-222-1222.\n" + c);
        insertToMap("strNoTx45", strNoTx45);
        
        Question* strSymptomatic = new Question("Does this patient exibit signs and symptoms of lead encephalopaty?");
        strSymptomatic->setOptions(new string[2] { "Encephalopathy", "Asypmtomatic" }, 2);
        insertToMap("strSymptomatic", strSymptomatic);
        
        Question *enterBloodLevels = new Question("Please enter patients blood Pb (lead) levels in mcg/dL ");
        enterBloodLevels->setType("numbers", "mcg/dL");
        insertToMap("enterBloodLevels", enterBloodLevels);
        
    }
    
    EdtaDimercaprol::~EdtaDimercaprol() {
        
    }
    
    Question* EdtaDimercaprol::getNextQuestion(){
        int q1 = prompts["strSymptomatic"]->getAnswerInt();
        if (q1 == 0){
            moreQuestions = false;
            if(age <= 12){
                return prompts["strEncPed"];
            } else {
                return prompts["strEncephalopathy"];
            }
        } else if (q1 == 1){
            double pbLevel = prompts["enterBloodLevels"]->getAnswerFloat();
            if(pbLevel >= 70){
                moreQuestions = false;
                if(age > 12) {
                    return prompts["strOver70"];
                } else {
                    return prompts["strOver70Ped"];
                }
            } else if(pbLevel >= 45) {
                moreQuestions = false;
                if(age < 21) {
                    return prompts["strBetween45and70"];
                } else {
                    return prompts["strNoTx"];
                }
            } else if(pbLevel >= 0) {
                moreQuestions = false;
                return prompts["strNoTx45"];
            } else {
                return prompts["enterBloodLevels"];
            }
        } else {
            return prompts["strSymptomatic"];

        }
    }
    

    double EdtaDimercaprol::BSA(){
        return (0.0235)*(pow(heightcm, 0.42246))*(pow(weightkg, 0.51456));
    }
    
    double EdtaDimercaprol::calcAdultEncED(){
        if (BSA() * 1500 >= 3000){
            return 3000;
        } else {
            return BSA() * 1500;
        }
    }
    
    
    double EdtaDimercaprol::calcPedEncED(){
        if (BSA() * 1500 >= 1000) {
            return 1000;
        } else {
            return BSA() * 1500;
        }
    }
    
    double EdtaDimercaprol::calcAdultED(){
        if (BSA()*1000 >= 3000){
            return 3000;
        } else {
            return BSA()*1000;
        }
    }
    
    
    double EdtaDimercaprol::calcPedED(){
        if (BSA() * 1000 >= 1000){
            return 1000;
        } else {
            return BSA() * 1000;
        }
    }
    
    
    
    string EdtaDimercaprol::getRef() {
        return string("\n\nReferences for EDTA/Dimercaprol (lead toxicity) Algorithm: \n\n") +
        "King, A. R. (2012, January 1). Antidote Chart. Antidote Chart . Kansas City," +
        "Kansas, U.S.: Thomas Land Publishers, Inc.\n\n" +
        "Goldfrank, L.R., Flomenbaum, N.E., Lewin, N.A., Howland, M.A., Nelson," +
        "L. S., & Hoffman,R. S. (2007). Goldfrank's Manual of Toxicologic Emergencies." +
        "New York, NY , U.S: McGraw Hill.\n\n" +
        "Lexi-comp, Inc. (2014, January 1). Lexicomp Version: 2.1.0. Edetate Calcium " +
        "Disodium . Hudson, OH, U.S.\n\n"+
        "3M Pharmaceuticals, (2004)CALCIUM DISODIUM VERSENATE- edetate calcium disodium injection." +
        "2004, 3M Pharmaceuticals: Northridge, CA, U.S.\n\n" +
        "Taylor Pharmaceuticals,(2007) DIMERCAPROL INJECTION, USP [package insert], in Package Insert." +
        "2007, Taylor Pharmaceuticals: Decatur, IL, U.S.";
    }
}