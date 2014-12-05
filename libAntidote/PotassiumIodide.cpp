//============================================================================
// Name        : PotassiumIodide.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : PotassiumIodide Algorithm
//============================================================================


#include "PotassiumIodide.h"

namespace libAntidote {
    
    
    PotassiumIodide::PotassiumIodide(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Potassium Iodide Antidote Algorithm \n",
        b = string("For the treatment of radioactive I-131 exposure.  ")+FDA+"\n\n",
        c = getRef();
        Question* potContra = new Question(a+b+
        "Contraindicated in patients that are hypersensitive to Iodide, \n" +
        "iodine; dermatitis herpetiformis; hypocomplementemic vasculitis; \n" +
        "nodular thyroid condition with heart disease."+c);
        potContra->setType("warning");
        insertToMap("potContra", potContra);
        
        Question *isPregnant = new Question("Is the patient pregnant?");
        isPregnant->setOptions(new string[2]{"Pregnant", "Not Pregnant"}, 2);
        insertToMap("isPregnant", isPregnant);
        
        string potInfant = a+b+
        "Administer 16.5mg potassium iodide PO daily for patients with thyroid exposure\n" +
        "greater than or equal to 5 cGy."+c;
        insertToMap("potInfant", potInfant);
        
        string potToddler = a+b+
        "Administer 32.5 mg potassium iodide PO daily for patients with thyroid exposure \n" +
        "greater than or equal to 5 cGy."+c;
        insertToMap("potToddler", potToddler);
        
        string potPregnant = a+b+
        "Administer 130 mg potassium iodide PO Daily for any pregnant or breast-feeding \n" +
        "female with thyroid exposure greater than or equal to 5 cGy"+c;
        insertToMap("potPregnant", potPregnant);
        
        string potChild = a+b+
        "Administer 65 mg potassium iodide PO daily for patients with thyroid exposure \n" +
        "greater than 5 cGy."+c;
        insertToMap("potChild", potChild);
        
        string potLessThan68 = a+b+
        "Administer 65 mg potassium iodide PO daily for patients with thyroid exposure \n" +
        "greater than or equal to 5 cGy."+c;
        insertToMap("potLessThan68", potLessThan68);
        
        string pot68AndGreater = a+b+
        "Administer 130 mg potassium iodide PO daily for patients with thyroid exposure \n" +
        "greater than or equal to 5 cGy."+c;
        insertToMap("pot68AndGreater", pot68AndGreater);
        
        string potAdultUnder40 = a+b+
        "Administer 130 mg potassium iodide PO daily for patients with thyroid exposure \n" +
        "greater than or equal to 10 cGy."+c;
        insertToMap("potAdultUnder40", potAdultUnder40);
        
        string potAdultOver40 = a+b+
        "Administer 130 mg potassium iodide PO daily for patients with thyroid exposure \n" +
        "greater than or equal to 500 cGy."+c;
        insertToMap("potAdultOver40", potAdultOver40);
    }
    
    PotassiumIodide::~PotassiumIodide() {
        
    }
    
    Question* PotassiumIodide::getNextQuestion(){
        
        if(prompts["potContra"]->getAnswerInt() == -1) {
            return prompts["potContra"];
        }
        
        moreQuestions = false;
        
        int n1 = prompts["isPregnant"]->getAnswerInt();
        if(age <= 0.084){return prompts["potInfant"];}
        else if(age<=3){return prompts["potToddler"]; }
        else if(age<=12){
            if (n1==0){return prompts["potPregnant"];}
            else if (n1==1){return prompts["potChild"];}
            else {
                moreQuestions = true;
                return prompts["isPregnant"];
            }
        }
        else if(age<=18){
            if (n1==0){return prompts["potPregnant"];}
            else if (n1==1){
                if(weightkg<68){return prompts["potLessThan68"];}
                else{return prompts["pot68AndGreater"];}
            }
            else {
                moreQuestions = true;
                return prompts["isPregnant"];
            }
        }
        else if(age <= 40){
            if (n1==0){return prompts["potPregnant"];}
            if (n1==1){return prompts["potAdultUnder40"];}
            else {
                moreQuestions = true;
                return prompts["isPregnant"];
            }
        }
        else{
            if (n1==0){return prompts["potPregnant"];}
            if (n1==1){return prompts["potAdultOver40"];}
            else {
                moreQuestions = true;
                return prompts["isPregnant"];
            }
        }
    }
    
    
    
    string PotassiumIodide::getRef() {
        return string("\n\nReferences for Potassium Iodide Algorithm: \n\n") +
        "REMM. (2012, January 1). Radiation Countermeasures for Treatment of \n" +
        "Internal Contamination. Retrieved May 27, 2014, from Radiation \n" +
        "Emergency Medical Management";
    }
}