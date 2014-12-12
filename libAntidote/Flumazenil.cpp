//============================================================================
// Name        : Flumazenil.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Flumazenil Algorithm
//============================================================================


#include "Flumazenil.h"

namespace libAntidote {
    
    
    Flumazenil::Flumazenil(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Flumazenil Antidote Algorithm. \n",
        b = string("For the treatment of benzodiazepine toxicity.  ") + FDA + "\n\n",
        c = "";//getRef();
        
        string flumWarning = string("\n\n") +
        "If a patient has not responded 5 minutes after receiving a cumulative maximum dose\n" +
        "of flumazenil injection, the major cause of sedation is likely not to be due to \n" +
        "benzodiazepines, and additional flumazenil injection is likely to have no effect.";
        string flumAdult = a+b+
        "The recommended initial dose of flumazenil injection is 0.2 mg (2 mL) administered \n" +
        "intravenously over 30 seconds. If the desired level of consciousness is not obtained \n" +
        "after waiting 30 seconds, a further dose of 0.3 mg (3 mL) can be administered over \n" +
        "another 30 seconds. Further doses of 0.5 mg (5 mL) can be administered over 30 seconds \n" +
        "at 1-minute intervals up to a cumulative dose of 3 mg."+flumWarning+c;
        insertToMap("flumAdult", flumAdult);
        
        string flumChild = a+b+
        "In infants and pediatric patients , the recommended initial dose is "+toStr( calcFlum())+" micrograms (10 mcg/kg, up to 200 mcg) \n" +
        "flumazenil administered intravenously over 15 seconds. If the desired level of consciousness is not \n" +
        "obtained after waiting an additional 45 seconds, further injections of "+toStr( calcFlum())+" micrograms  (10 mcg/kg up to 200 mcg) \n" +
        "can be administered and repeated at 50-second intervals where necessary (up to a maximum of 4 additional \n" +
        "times) to a maximum total dose of 50 mcg/kg or 1 mg, whichever is lower. " +flumWarning+c;
        insertToMap("flumChild", flumChild);

    }
    
    Flumazenil::~Flumazenil() {
        
    }
    
    Question* Flumazenil::getNextQuestion(){
        if (age>18){
            return prompts["flumAdult"];
        } else {
            return prompts["flumChild"];
        }
    }
    
    
    double Flumazenil::calcFlum(){
        double maxDose = 200;
        if (10 * weightkg > 200) {
            return maxDose;
        }
        else return 10 * weightkg;
    }
    
    string Flumazenil::getRef() {
        return string("\n\nReferences for Flumazenil Algorithm: \n\n") +
        "Westward Pharmaceuticals. (2011, July 1). Flumazenil Injection, USP. Package Insert.\n" +
        "Eastontown, NJ, U.S.: Westward Pharmaceuticals."+
        "Hegenbarth, M. A. (2008). Preparing for Pediatric Emergencies: \n" +
        "Drugs to Consider. Pediatrics , 121 (2), 433-443.\n";
    }
}