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
        "Dosing in  children 0-2 years of age has not been established.  However, \n" +
        "the U.S. Department of Health and Human Services� Biomedical Advanced \n" +
        "Research and Development Authority has awarded a contract to Heyltex \n" +
        "Corp., Katy, Texas, for advanced development of a safe and effective \n" +
        "way to administer Prussian Blue to infants ages newborn to two years \n" +
        "old who may have ingested radioactive material as a result of a dirty \n" +
        "bomb or nuclear fallout."+c;
        insertToMap("upto2YO", upto2YO);
        
        string between3and12 = ""+a+b+
        "The recommended dose of Prussian blue insoluble in children 2-12 years \n" +
        "old is  is 1 gram orally three times a day."+c;
        insertToMap("between3and12", between3and12);
        
        string adoAdult = ""+a+b+
        "The recommended dose of Prussian blue insoluble in adults and adolescents  \n" +
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
        return string("\n\nReferences for Prussian Blue Algorithm: \n\n")+
        "Altagracia-Mart�nez, M., Kravzov-Jinich, J., N��ez, J. M., \n" +
        "R�os-Casta�eda, C., & L�pez-Naranjo, F. (2012, June 7). Prussian \n" +
        "blue as an antidote for radioactive thallium and cesium poisoning.\n" +
        "Orphan Drugs: Research and Reviews , 13-21.\n\n" +
        "HEYL Chem.-pharm. (2008, March 1). RADIOGARDASE - ferric \n" +
        "hexacyanoferrate(ii) capsule . Package Insert . Berlin, \n" +
        "Berlin, Germany: HEYL Chem.-pharm.\n\n" +
        "U.S. Department of Health and Human Services  . (2011, March 9). \n" +
        "BARDA awards contract to develop Prussian blue for pediatric \n" +
        "use Contract supports advanced development of Prussian blue for \n" +
        "infants ages newborn to two years . Retrieved June 4, 2014, from \n" +
        "HHS News: http://www.phe.gov/Preparedness/news/Pages/Prussianblue.aspx";    }
}