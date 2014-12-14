//============================================================================
// Name        : AntidoteLibrary.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Testor
//============================================================================

#include <iostream>
#include "Acetylcysteine.h"
#include "Atropine.h"
#include "BATbotulism.h"
#include "BlackWidow.h"
#include "CaChloride.h"
#include "CoralSnake.h"
#include "CrotalidaeOvine.h"
#include "CyanideToxicity.h"
#include "Dimercap.h"
#include "EdtaDimercaprol.h"
#include "Etoh.h"
#include "PrussianBlue.h"
#include "Naloxone.h"

using namespace std;
using namespace libAntidote;

void showDialog(Question *q);

int main() {
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    Antidote *dote;
    dote = new CoralSnake(20, 80, 180);
    //dote = new CyanideToxicity(30, 80, 180);
    while(dote->hasMoreQuestions()) {
        Question *q = dote->getNextQuestion();
        showDialog(q);
    }
    cout << dote->getRef();
    
    return 0;
}

void showDialog(Question *q) {
    cout << "************ prompt type:(" << q->getType() << ") ************" << endl;
    cout << "\t" << q->getText() << "( " << q->getType() << " )" << endl;

    int i = 0;
    while(q->hasMoreOptions()) {
        cout << "\t" << i << ") " ;
        cout << q->getNextOption() << ", ";
        i++;
    }
    
    if( q->getType() == "input" ||
       q->getType() == "options" ||
       q->getType() == "numbers" ||
       q->getType() == "yesno" ||
       q->getType() == "info" ||
       q->getType() == "warning") {
        cout << endl << "Response: \t";
        string input;
        cin >> input;
        cin.ignore();
        q->setAnswer(input);
    }
    cout << "\n************ end of prompt:(" << q->getType() << ") ************" << endl ;
    return;
}
