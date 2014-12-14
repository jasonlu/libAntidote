//============================================================================
// Name        : Naloxone.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Naloxone Algorithm
//============================================================================


#include "Naloxone.h"

namespace libAntidote {
    
    
    Naloxone::Naloxone(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Naloxone Antidote Algorithm-\n",
        b = string("For the treatment of opioid toxicity.  ")+FDA+"\n\n",
        c = "";//getRef();
        
        Question *IVCI = new Question(string("Caution: Intravenous continuous infusion of naloxone ") +
                                      "is indicated only when patient has failed bolus naloxone " +
                                      "therapy");
        IVCI->setType("warning");
        insertToMap("IVCI", IVCI);
        
        string nalBolusAdult = a+b+ "Administer 0.4-2mg naloxone IVP.  Dose may be repeated every 2-3 minutes up to 10mg."+c;
        insertToMap("nalBolusAdult", nalBolusAdult);
        string nalIVCIAdult = a+b+ "Administer 0.4-0.8mg/hr of naloxone IVCI inititially and titrate to response."+c;
        insertToMap("nalIVCIAdult", nalIVCIAdult);
        string nalBolusChild = a+b+ "Administer 2mg IVP every 2-3 minutes as necessary.  Maximum 10mg total dose"+c;
        insertToMap("nalBolusChild", nalBolusChild);
        string nalIVCIChild = a+b+ "Administer 0.4-0.8mg/hr of naloxone IVCI initially and titrate to response."+c;
        insertToMap("nalIVCIChild", nalIVCIChild);
        string nalBolusNeo = a+b+ "Administer "+toStr(calcNeoBolus() )+" mg (0.1mg/kg) naloxone IVP up to 2mg.  May repeat dose if necessary."+c;
        insertToMap("nalBolusNeo", nalBolusNeo);
        string nalIVCINeo = a+b+ "Administer "+toStr(weightkg*0.04)+"-"+toStr(weightkg*0.16)+" mg/hr (0.04-0.16mg/kg/hr) of naloxone IVCI initially and titrate to response. "+c;
        insertToMap("nalIVCINeo", nalIVCINeo);
        
        Question *chooseIVCI = new Question("Choose Naloxone IV Bolus or IV continuous infusion therapy?");
        chooseIVCI->setOptions(new string[2]{"Bolus", "IVCI"}, 2);
        insertToMap("chooseIVCI", chooseIVCI);
        
        
        
        
        
    }
    
    Naloxone::~Naloxone() {
        
    }
    
    Question* Naloxone::getNextQuestion(){
        int n1 = prompts["chooseIVCI"]->getAnswerInt();
        if(age>18){
            if (n1==0){
                moreQuestions = false;
                return prompts["nalBolusAdult"];
            } else if (n1==1){
                if(prompts["IVCI"]->getAnswerInt() == -1) {
                    return prompts["IVCI"];
                }
                moreQuestions = false;
                return prompts["nalIVCIAdult"];
            } else {
                return prompts["chooseIVCI"];
            }
        } else {
            if(age<=5 || weightkg <= 20){
                if (n1 == 0){
                    moreQuestions = false;
                    return prompts["nalBolusNeo"];
                } else if (n1 == 1){
                    if(prompts["IVCI"]->getAnswerInt() == -1) {
                        return prompts["IVCI"];
                    }
                    moreQuestions = false;
                    return prompts["nalIVCINeo"];
                } else {
                    return prompts["chooseIVCI"];
                }
            } else {
                if (n1 == 0){
                    moreQuestions = false;
                    return prompts["nalBolusChild"];
                } else if (n1 == 1){
                    if(prompts["IVCI"]->getAnswerInt() == -1) {
                        return prompts["IVCI"];
                    }
                    moreQuestions = false;
                    return prompts["nalIVCIChild"];
                } else {
                    return prompts["chooseIVCI"];
                }
            }
            
        }
    }
    
    double Naloxone::calcNeoBolus(){
        double max = 2;
        if(weightkg*0.1>2){
            return max;
        } else {
            return weightkg*0.1;
        }
    }
    
    
    
    
    string Naloxone::getRef() {
        return string("") +
        "Hegenbarth, M. A. (2008). Preparing for Pediatric Emergencies: " +
        "Drugs to Consider. Pediatrics , 121 (2), 433-443.\n\n" +
        "Hospira, Inc. . (2009, November 1). Atropine Sulfate . Atropine " +
        "Sulfate Package Insert . Lake Forest, Illinois, U.S.: Hospira, Inc.\n\n" +
        "King, A. R. (2012, January 1). Antidote Chart. Antidote Chart . Kansas " +
        "City, Kansas, U.S.: Thomas Land Publishers, Inc.\n\n" +
        "Kleinman, M. E., Chameides, L., Schexnayder, S. M., Samson, R. A., " +
        "Hazinski, M. F., Atkins, D. L., et al. (2010, November 10). Part 14: " +
        "Pediatric Advanced Life Support: 2010 American Heart Association Guidelines " +
        "for Cardiopulmonary Resuscitation and Emergency Cardiovascular Care. " +
        "Circulation . Dallas, TX, U.S.: American Heart Association.";
    }
}