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

using namespace std;
using namespace libAntidote;

void showDialog(Question *q);

int main() {
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    Antidote *dote;
    //dote = new Acetylcysteine(20, 80, 180);
    dote = new Atropine(30, 80, 180);
    while(dote->hasMoreQuestions()) {
        Question *q = dote->getNextQuestion();
        showDialog(q);
    }
    
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
    
    if( q->getType() == "input" || q->getType() == "options" || q->getType() == "numbers" || q->getType() == "yesno") {
        cout << endl << "Response: \t";
        string input;
        cin >> input;
        q->setAnswer(input);
    }
    cout << "\n************ end of prompt:(" << q->getType() << ") ************" << endl ;
    return;
}
