//============================================================================
// Name        : Pralidoxime.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Pralidoxime Algorithm
//============================================================================


#include "Pralidoxime.h"

namespace libAntidote {
    
    
    Pralidoxime::Pralidoxime(double age, double height, double weight) : Antidote(age, height, weight) {
        
        a = "Pralidoxime Antidote Algorithm \n",
        b = string("For the secondary treatment of organophosphate pesticide toxicity.  ")+FDA+"\n\n",
        c = "";//getRef();
        
        string strPraWarning = a+b+
        "Pralidoxime is not to be used alone in organophosphate poisoning. \n" +
        "Response to atropine should be determined first.";
        
        Question *praWarning = new Question(strPraWarning);
        praWarning->setType("warning");
        insertToMap("praWarning", praWarning);
        
        string praAdultIV = a+b+
        "Inject an initial dose of 1000 to 2000 mg of pralidoxime, IVPB in \n" +
        "100 mL of NS, over 15-30 min. If this is not practical or if pulmonary \n" +
        "edema is present, the dose should be given slow IVP (over five minutes or \n" +
        "more),as a 50 mg/mL solution in water (e.g., 1000 mg in 20 mL). A second dose\n" +
        "of 1000 to 2000 mg may be given in about one hour if muscle weakness persists.\n" +
        "Additional doses may be given every 10-12 hours if muscle weakness persists."+c;
        insertToMap("praAdultIV", praAdultIV);
        
        string praAdultIM = a+b+
        "Give 600mg pralidoxime in 2ml IM Q15min PRN (3doses max).If symptoms are \n" +
        "severe give the 3 doses in rapid succession."+c;
        insertToMap("praAdultIM", praAdultIM);
        
        string praChildIV = a+b+
        "Administer "+praCalIV()+"mg (20-50 mg/kg) pralidoxime IV (max  2000 mg/dose) over 15-30 minutes. \n" +
        "May give second dose of "+praCalIV()+"mg (20-50 mg/kg) after about one hour if muscle weakness \n" +
        "persists. Repeat dosing every 10-12 hours as needed.\n" +
        "If IVPB or IVCI is not practical, or if pulmonary edema is present,  give \n" +
        praCalIV()+"mg (20-50 mg/kg) dose slow IVP  (over not less than five minutes) as a 50 mg/mL \n" +
        "solution.. Additional doses may be given every 10-12 hours if muscle weakness \n" +
        "persists."+c;
        insertToMap("praChildIV", praChildIV);
        
        string praChildIM = a+b+
        "Give "+toStr( weightkg*15)+" mg (15mg/kg) pralidoxime IM to anterolateral thigh every 15 minutes PRN (Max 3doses). \n" +
        "If symptoms are severe, give 3 doses in rapid succession." +c;
        insertToMap("praChildIM", praChildIM);
        
        Question *ivOrIm = new Question("Intravenous or Intramuscular dosing?");
        ivOrIm->setOptions(new string[2]{ "IV", "IM" }, 2);
        insertToMap("ivOrIm", ivOrIm);
        
    }
    
    Pralidoxime::~Pralidoxime() {
        
    }
    
    Question* Pralidoxime::getNextQuestion(){
        if(prompts["praWarning"]->getAnswerInt() == -1) {
            return prompts["praWarning"];
        }
        
        int n1 = prompts["ivOrIm"]->getAnswerInt();
        moreQuestions = false;
        if (weightkg<40 && age<=16){
            if (n1==0){return prompts["praChildIV"];}
            else if (n1==1){return prompts["praChildIM"];}
            else { moreQuestions = true; return prompts["ivOrIm"];}
        } else {
            if (n1==0){return prompts["praAdultIV"];}
            else if (n1==1){return prompts["praAdultIM"];}
            else { moreQuestions = true; return prompts["ivOrIm"];}
        }
        
    }
    
    
    string Pralidoxime::praCalIV() {
        return toStr( weightkg*20)+"-"+toStr( weightkg*50);
    }
    
    string Pralidoxime::getRef() {
        return string("\n\nPralidoxime Antidote Algorithm: \n\n") +
                      "Baxter Healthcare Corporation.(2010, December1). PROTOPAM CHLORIDE- \n" +
                      "pralidoxime chloride injection, powder, lyophilized, for solution. \n," +
                      "Package Insert . Deerfield, IL, U.S.: Baxter Healthcare Corporation .";
    }
}