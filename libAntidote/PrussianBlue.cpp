//============================================================================
// Name        : PrussianBlue.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : PrussianBlue Algorithm
//============================================================================


#include "PrussianBlue.h"

namespace libAntidote {
    
    
    PrussianBlue::PrussianBlue(double age, double height, double weight) : Antidote(age, height, weight) {
        a = "Prussian Blue Antidote Algorithm \n",
        b = string("For the treatment of radioactive Cs-137 and thallium toxicity.  ")+FDA+"\n\n",
        c = "";//getRef();
        
        string upto2YO = ""+a+b+
        "Dosing in  children 0-2 years of age has not been established.  However, " +
        "the U.S. Department of Health and Human Services Biomedical Advanced " +
        "Research and Development Authority has awarded a contract to Heyltex " +
        "Corp., Katy, Texas, for advanced development of a safe and effective " +
        "way to administer Prussian Blue to infants ages newborn to two years " +
        "old who may have ingested radioactive material as a result of a dirty " +
        "bomb or nuclear fallout."+c;
        insertToMap("upto2YO", upto2YO);
        
        string between3and12 = ""+a+b+
        "The recommended dose of Prussian blue insoluble in children 2-12 years " +
        "old is  is 1 gram orally three times a day."+c;
        insertToMap("between3and12", between3and12);
        
        string adoAdult = ""+a+b+
        "The recommended dose of Prussian blue insoluble in adults and adolescents " +
        "greater than 12 years of age is 3 grams orally three times a day."+c;
        insertToMap("adoAdult", adoAdult);
        

    }
    
    PrussianBlue::~PrussianBlue() {
        
    }
    
    Question* PrussianBlue::getNextQuestion(){
        moreQuestions = false;
        if(age<=2){return prompts["upto2YO"];}
        else if(age>2&&age<=12){return prompts["between3and12"];}
        else{return prompts["adoAdult"];}
    }
    
    
    
    
    string PrussianBlue::getRef() {
        return string("Altagracia-Martínez, M., Kravzov-Jinich, J., Núñez, J. M., Ríos-Castañeda, C., & López-Naranjo, F. (2012, June 7). Prussian blue as an antidote for radioactive thallium and cesium poisoning. Orphan Drugs: Research and Reviews , 13-21.") + "\n" +
        
        "HEYL Chem.-pharm. (2008, March 1). RADIOGARDASE - ferric hexacyanoferrate(ii) capsule . Package Insert . Berlin, Berlin, Germany: HEYL Chem.-pharm."+ "\n" +
        
        "U.S. Department of Health and Human Services . (2011, March 9). BARDA awards contract to develop Prussian blue for pediatric use Contract supports advanced development of Prussian blue for infants ages newborn to two years . Retrieved June 4, 2014, from HHS News: http://www.phe.gov/Preparedness/news/Pages/Prussianblue.aspx";
    }
}