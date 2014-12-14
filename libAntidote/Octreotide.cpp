//============================================================================
// Name        : Octreotide.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Octreotide Algorithm
//============================================================================


#include "Octreotide.h"

namespace libAntidote {
    
    
    Octreotide::Octreotide(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Octreotide Antidote Algorithm \n",
        b = string("As a secondary agent for the treatment of sulfonylurea induced hypoglycemia.  ")+FDO+"\n\n",
        c = "";//getRef();
        
        string octIVCI = string("In the event of persistent hypoglycemia continuous infusion ") +
        "of octreotide titrated to response may be necessary.  Doses up " +
        "to 125 micrograms/hr have been reported in adults.";
        
        string octUnderSixChild = a+b+
        "Monitor carefully in ICU with children 6 YO and under as adverse events " +
        "have been reported in this group.\n" +
        "Administer "+octCalcChild()+" micrograms (1-2 micrograms/kg up to 50 micrograms) " +
        "octreotide SubQ (preferred) or IV every 6-12 hours as necessary based " +
        "on SBG levels."+octIVCI+c;
        insertToMap("octUnderSixChild", octUnderSixChild);
        
        string octOverSixChild = a+b+
        "Administer "+octCalcChild()+" micrograms (1-2 micrograms/kg up to 50 micrograms) " +
        "octreotide SubQ (preferred) or IV every 6-12 hours as necessary based " +
        "on SBG levels."+octIVCI+c;
        insertToMap("octOverSixChild", octOverSixChild);
        
        string octAdult = a+b+
        "Administer 50-100 micrograms octreotide SubQ (preferred) or IV Q6-12hr as necessary " +
        "based on SBG levels."+octIVCI+c;
        insertToMap("octAdult", octAdult);
    }
    
    Octreotide::~Octreotide() {
        
    }
    
    Question* Octreotide::getNextQuestion(){
        moreQuestions = false;
        if(age <= 6){
            return prompts["octUnderSixChild"];
        } else if(age <= 18){
            return prompts["octOverSixChild"];
        } else {
            return prompts["octAdult"];
        }
    }
    
    
    string Octreotide::octCalcChild(){
        double max = 50;
        if(weightkg <= 50 && weightkg * 2 <= 50){
            return toStr(weightkg) + " - " + toStr(weightkg * 2);
        } else if(weightkg <= 50 && weightkg * 2 > 50){
            return toStr(weightkg) + " - " + toStr(max);
        } else{
            return toStr(max);
        }
    }
    
    string Octreotide::getRef() {
        return string("Klein-Schwartz, P. P. (2010, March 30). Octreotide(R)s Role in the ") +
        "Management of Sulfonylurea-Induced Hypoglycemia. J. Med. Toxicol., 199-206.\n\n" +
        "Glatstein, M., Garcia(R)Bournissen, F., Scolnik, D., & Koren, G. (2010). SULFONYLUREA " +
        "INTOXICATION AT A TERTIARY CARE PAEDIATRIC HOSPITAL. Can J Clin Pharmacol, 17 (1), " +
        "e51-e56.\n\n" +
        "McLaughlin, S. A., Crandall, C. S., & McKinney, P. E. (2000, August 1). Octreotide: " +
        "An Antidote for Sulfonylurea- Induced Hypoglycemia. ANNALS OF EMERGENCY MEDICINE, " +
        "133-138.";
    }
}