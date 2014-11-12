//============================================================================
// Name        : CyanideToxicity.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : CyanideToxicity Algorithm
//============================================================================


#include "CyanideToxicity.h"

namespace libAntidote {
    
    
    CyanideToxicity::CyanideToxicity(double age, double height, double weight) : Antidote(age, height, weight) {
        
        
        string strCyanideAlgorithmWarning1 = string("Hydroxocobalamin is considered first line treatment for cyanaide toxicity. ") +
        "Amyl nitrite and sodium nitrite are no longer available on the U.S. market. " +
        "Sodium thiosulfate is included in this algorithm as second line therapy. " +
        "Amyl nitrite and sodium nitrite dosing are also included as an adjunct agent " +
        "for international users of this program.";
        string strCyanideAlgorithmWarning2 = string("Warning: In addition to hydroxocobalamin, treatment of cyanide toxicity must ") +
        "include aggressive supportive care and immediate attention to airway patency, " +
        "adequacy of oxygenation and hydration, cardiovascular support, and management of " +
        "any seizure activity. Consideration should be given to decontamination measures " +
        "based on the route of exposure. It is important to start treatment early in patients " +
        "with cyanide poisoning; thus, hydroxocobalamin therapy should be initiated prior to " +
        "obtaining cyanide blood assay results. " +
        "Cyanokit (hydroxocobalamin) package insert. " +
        "Columbia, MD: Meridian Medical Technologies, Inc.; 2011 Apr";
        
        string strAgeLessThenOne = string("For the treatment of known or suspected cyanide toxicity or poisoning:\n\n") +
        "First Line Therapy - hydroxocobalamin " +
        "Neonates and Infants: Safety and efficacy have not been established.\n\n" +
        "Cyanokit (hydroxocobalamin) package insert. Please contact a Neonatologist immediately. " +
        "Columbia, MD: Meridian Medical Technologies, Inc.; 2011 Apr\n\n" +
        "***Cyanide Antidote Package (amyl nitrite, sodium nitrite, sodium thiosulfate)" +
        "is no longer available in the U.S.*** " +
        "Safety and efficacy in newborns and infants has not been established." ;
        
        string strAgeBetweenOneAndTwentyOne = string("For the treatment of known or suspected cyanide toxicity or poisoning:\n\n")+
        "First Line Therapy - hydroxocobalamin " +
        "Intravenous infusion dosage of hydroxocobalamin: " +
        "Children� and Adolescents�: Safety and efficacy have not been established; however, " +
        "70 mg/kg IV has been used in pediatric patients in non-U.S. marketing experience. " +
        "This patient should receive "+calculateHydroxoDose()+"mg IV. " +
        "Pleasecontact a Posion Control and a peditrician for administration of dose.  " +
        "Cyanokit (hydroxocobalamin) package insert.Columbia, MD: Meridian Medical Technologies,  " +
        "Inc.; 2011 Apr. �Un-approved indication\n\n" +
        "***Cyanide Antidote Package (amyl nitrite, sodium nitrite, sodium thiosulfate)" +
        "is no longer available in the U.S.*** " +
        "Second line therapy for the management of cyanide toxicity: (amyl nitrite, sodium nitrite, " +
        "sodium thiosulfate) Children: Break amyl nitrite vial and inhale the contents of 1 ampule (0.18�0.3 mL) " +
        "for 15�30 seconds.Repeat 1 ampule dose every minute until sodium nitrite IV infusion " +
        "is available. NOTE: Children should be carefully monitored during treatment with amyl  " +
        "nitrite to avoid formation of excessive methemoglobin; the smallest effective dosage should be used. " +
        "Sodium Nitrite Intravenous dosage:  Children: 0.15�0.33 ml/kg or 6�8 ml/m2 of a 3% solution. " +
        determinePediatricDoseSodiumNitrite()+
        "Do not to exceed 10 ml. Then, immediately administer sodium thiosulfate. " +
        "Sodium thiosulfate Intravenous dosage Children and Adolescents: The usual dosage of sodium  " +
        "thiosulfate is 7 grams/m2 of body surface area (BSA). " +
        determinePediatricDoseSodiumThiosulfate()+"administered IV over a period of  " +
        "approximately 10 minutes; do not exceed 12.5grams IV.  NOTE: If symptoms of cyanide toxicity  " +
        "recur, one half of each dose of sodium nitrite and sodium thiosulfate may be repeated after  " +
        "30 minutes.(ABO Pharmaceuticals, 2013)";
        
        string strAgeGreaterThenTwentyOne = string("For the treatment of known or suspected cyanide toxicity or poisoning:\n\n")+
        "First Line Therapy - hydroxocobalamin " +
        "Intravenous infusion dosage of hydroxocobalamin: " +
        "Adults: Initially, 5 g IV infused over 15 minutes (approximately 15 ml/minute). " +
        "A second 5 g dose infused over 15 minutes to 2 hours (depending on patient status), " +
        "for a total to 10 g, may be administered based on clinical response and severity" +
        "of cyanide poisoning. " +
        "Cyanokit (hydroxocobalamin) package insert." +
        "Columbia, MD: Meridian Medical Technologies, Inc.; 2011 Apr\n\n" +
        "***Cyanide Antidote Package (amyl nitrite, sodium nitrite, sodium thiosulfate)" +
        "is no longer available in the U.S.*** " +
        "Adults: Break vial and inhale the contents of 1 ampule (0.18�0.3 mL)" +
        "for 15�30 seconds. Repeat 1 ampule dose every minute until sodium nitrite IV infusion is available. " +
        "Sodium nitrite intravenous dosage: Adults: 300 mg (10 ml of a 3% solution) IV at a rate of 2.5 to 5 ml/minute. " +
        "Sodium thiosulfate Intravenous dosage Adults: " +
        "Whether used alone or in combination with other cyanide antidotes, the usual dosage of sodium thiosulfate " +
        "is 12.5g given IV over a period of approximately 10 minutes " +
        "NOTE: If symptoms of cyanide toxicity recur, one half of each dose of sodium nitrite and sodium thiosulfate " +
        "may be repeated after 30 minutes.  Elderly patients may be more sensitive to the hypotensive effects of  " +
        "nitrates.(ABO Pharmaceuticals, 2013)";
        
        Question *cyanideAlgorithmWarning1 = new Question(strCyanideAlgorithmWarning1);
        cyanideAlgorithmWarning1->setType("warning");
        Question *cyanideAlgorithmWarning2 = new Question(strCyanideAlgorithmWarning2);
        cyanideAlgorithmWarning2->setType("warning");
        Question *ageLessThenOne = new Question(strAgeLessThenOne);
        Question *ageBetweenOneAndTwentyOne = new Question(strAgeBetweenOneAndTwentyOne);
        Question *ageGreaterThenTwentyOne = new Question(strAgeGreaterThenTwentyOne);
        
        prompts.insert(strQuestionMapPair("cyanideAlgorithmWarning1", cyanideAlgorithmWarning1));
        prompts.insert(strQuestionMapPair("cyanideAlgorithmWarning2", cyanideAlgorithmWarning2));
        prompts.insert(strQuestionMapPair("ageLessThenOne", ageLessThenOne));
        prompts.insert(strQuestionMapPair("ageBetweenOneAndTwentyOne", ageBetweenOneAndTwentyOne));
        prompts.insert(strQuestionMapPair("ageGreaterThenTwentyOne", ageGreaterThenTwentyOne));
        
    }
    
    CyanideToxicity::~CyanideToxicity() {
        
    }
    
    Question* CyanideToxicity::getNextQuestion(){
        
        if(prompts["cyanideAlgorithmWarning1"]->getAnswerInt() == -1 ) {
            return prompts["cyanideAlgorithmWarning1"];
        }

        if(prompts["cyanideAlgorithmWarning2"]->getAnswerInt() == -1 ) {
            return prompts["cyanideAlgorithmWarning2"];
        }

        if(age < 1){
            moreQuestions = false;
            return prompts["ageLessThenOne"];
        } else if (age >= 1 && age < 21) {
            moreQuestions = false;
            return prompts["ageBetweenOneAndTwentyOne"];
        } else {
            moreQuestions = false;
            return prompts["ageGreaterThenTwentyOne"];
        }
    }
    
    double CyanideToxicity::calculateBSAGehanGeorge() {
        return (0.0235) * (pow(heightcm, 0.42246)) * (pow(weightkg, 0.51456));
    }
    

    
    string CyanideToxicity::determinePediatricDoseSodiumNitrite(){
        if(calculateBSAGehanGeorge() * 6 > 10||calculateBSAGehanGeorge() * 8 > 10) {
            return "Calculated dose is the maximum 10ml sodium nitrite. ";
        } else {
            return string("The calculated dose for this patient is ") + toStr(calculateBSAGehanGeorge() * 6)+"ml to " + toStr(calculateBSAGehanGeorge() * 8)+"ml sodium nitrite. ";
        }
    }
    string CyanideToxicity::calculateHydroxoDose(){
        if (weightkg * 70 >= 5000){
            return "5000";
        } else  {
            return toStr(weightkg * 70);
        }
    }
    
    string CyanideToxicity::determinePediatricDoseSodiumThiosulfate(){
        if(calculateBSAGehanGeorge() * 7 > 12.5) {
            return "Calculated dose is the maximum 12.5 grams sodium thiosulfate ";
        } else {
            return "The calculated dose for this patient is " + toStr(calculateBSAGehanGeorge() * 7) + " grams sodium thiosulfate";
        }
    }
    
    string CyanideToxicity::getRef() {
        return string("References for Cyanide Toxicity Algorithm\n\n") +
        "ABO Pharmaceuticals. (2013, January 1). CYANIDE ANTIDOTE PACKAGE. CYANIDE ANTIDOTE  " +
        "PACKAGE. San Clemente, California, U.S.: ABO Pharmaceuticals.\n\n" +
        "Meridian Medical Technologies�, Inc. (2011, April 1). Cyanokit� Package Insert.  " +
        "Cyanokit� Package Insert . Columbia, Maryland, U.S.: Meridian Medical Technologies�, " +
        "Inc. ";
    }
}