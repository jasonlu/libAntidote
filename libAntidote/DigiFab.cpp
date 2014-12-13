//============================================================================
// Name        : DigiFab.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : DigiFab Algorithm
//============================================================================


#include "DigiFab.h"

namespace libAntidote {
    
    DigiFab::DigiFab(double age, double height, double weight) : Antidote(age, height, weight) {
        
        string a = "Digoxin Immune FAB (digoxin toxicity)Antidote Algorithm \n",
        b = "For the treatement of acute iron toxicity.\n\n",
        c = "\n (BTG International Inc. , 2012)";
        
        string childChronUnk = a + b +
        "Administer 1 vial of DigiFab� IV in infants and children < 20 Kg. Failure to " +
        "respond to this therapy may indicate to physician that digoxin toxicity may " +
        "not be the cause of patient presentation." + c;
        insertToMap("childChronUnk", childChronUnk);
        
        string adultChronUnk = a + b +
        "Administer 6 vials of DigiFab� IV in adults and children � 20 Kg. Failure to " +
        "respond to this therapy may indicate to physician that digoxin toxicity may " +
        "not be the cause of patient presentation." + c;
        insertToMap("adultChronUnk", adultChronUnk);
        
        string adultAcuteUnk = a + b +
        "Administer 20 vials of DigiFab�.  Start with 10 vials followed by an additional 10 vials, " +
        "if needed, to avoid a febrile reaction.  Failure to respond to this therapy may indicate " +
        "to physician 	that digoxin toxicity may not be the cause of patient presentation." + c;
        insertToMap("adultAcuteUnk", adultAcuteUnk);
        
        string childAcuteUnk = a + b +
        "Administer 20 vials of DigiFab�. Monitor for volume overload in small(< 20 Kg) " +
        "children. Start with 10 vials followed by an additional 10 vials, if needed, " +
        "to avoid a febrile reaction.Failure to respond to this therapy may indicate to physician " +
        "that digoxin toxicity may not be the cause of patient presentation." + c;
        insertToMap("childAcuteUnk", childAcuteUnk);
        
        string *digOptions = new string[2]{ "Acute Overdose", "Chronic toxicity" };
        Question *n1 = new Question("Is patient's toxicity caused by acute overdose\nor chronic toxicity?");
        n1->setOptions(digOptions, 2);
        insertToMap("n1", n1);
        
        string *acuOptions = new string[2]{ "Dose Known", "Dose Unknown" };
        Question *na = new Question("Is the amount of digoxin ingested known?");
        na->setOptions(acuOptions, 2);
        insertToMap("na", na);
        
        string *chronOptions = new string[2]{ "Known Digoxin Level", "Level Unknown" };
        Question *nc = new Question("Is the serum digoxin level known?");
        nc->setOptions(chronOptions, 2);
        insertToMap("nc", nc);
        
        Question *inputDose = new Question("Enter dose in milligrams.");
        inputDose->setType("numbers", "milligrams");
        insertToMap("inputDose", inputDose);
        

        Question *inputSerumDigoxinLevels = new Question("Enter serum digoxin levels in ng/ml.");
        inputSerumDigoxinLevels->setType("numbers", "ng/ml");
        insertToMap("inputSerumDigoxinLevels", inputSerumDigoxinLevels);

        
        
    }
    
    DigiFab::~DigiFab() {
        
    }
    
    Question* DigiFab::getNextQuestion(){
        string a = "Digoxin Immune FAB (digoxin toxicity)Antidote Algorithm \n",
        b = "For the treatement of acute iron toxicity.\n\n",
        c = "\n (BTG International Inc. , 2012)";

        int n1 = prompts["n1"]->getAnswerInt();
        if (n1 == 0){
            int na = prompts["na"]->getAnswerInt();
            if(na == 0){
                double dose = prompts["inputDose"]->getAnswerFloat();
                if(dose == -1) {
                    return prompts["inputDose"];
                } else {
                    moreQuestions = false;
                    return new Question(a + b + "Administer " + toStr(dose / 0.5) + " vials of DigiFab@ IV. \n" +
                                        "Based on formula - Dose (in vials) = Amount of digoxin ingested (in mg)/0.5 mg/vial)" +
                                        "Failure to respond to this therapy may indicate to physician that digoxin toxicity may \n" +
                                        "not be the cause of patient presentation." + c);
                }
            }
            if(na == 1){
                if(weightkg >= 20){moreQuestions = false; return prompts["adultAcuteUnk"];}
                else {moreQuestions = false; return prompts["childAcuteUnk"];}
            } else {
                return prompts["na"];
            }
        }
        
        if (n1==1){
            int nc = prompts["nc"]->getAnswerInt();
            if(nc == 0){
                double level = prompts["inputSerumDigoxinLevels"]->getAnswerFloat();
                if(level == -1) {
                    return prompts["inputSerumDigoxinLevels"];
                } else {
                    moreQuestions = false;
                    return new Question(a + b + "Administer " + toStr(level * weightkg / 100) + " vials of DigiFab� IV. \n" +
                                        "Dose (in vials) = (Serum digoxin ng/mL)(weight in kg)/100" + c);
                }
            } else if(nc == 1){
                if(weightkg>=20){moreQuestions = false; return prompts["adultChronUnk"];}
                else {moreQuestions = false; return prompts["childChronUnk"];}
            } else {
                return prompts["nc"];
            }
        } else {
            return prompts["n1"];
        }
    }
    
    
    
    string DigiFab::getRef() {
        return string("References for Digoxamine Immune FAB Algorithm\n\n") +
                      "BTG International Inc. . (2012, January 1). DIGIFAB� DIGOXIN " +
                      "IMMUNE FAB (OVINE) . Package Insert . West Conshohocken , PA, \n" +
                      "U.S.: BTG International Inc.";
    }
}