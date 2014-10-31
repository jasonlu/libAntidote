//============================================================================
// Name        : AntidoteLibrary.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : Testor
//============================================================================

#include <iostream>
#include "Acetylcysteine.h"
using namespace std;
using namespace libAntidote;

void showDialog(Question *q);

int main() {
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    Antidote *dote;
    dote = new Acetylcysteine(20, 80, 180);
    
    while(dote->hasMoreQuestions()) {
        Question *q = dote->getNextQuestion();
        showDialog(q);
    }
    
    return 0;
}

void showDialog(Question *q) {
    cout << "************ prompt type:(" << q->getType() << ") ************" << endl;
    cout << "\t" << q->getText() << "( " << q->getType() << " )" << endl;
    for(int i = 0; i < q->options.size(); i++) {
        cout << "\t" << i << ") " << q->options[i] << ", ";
    }

    if( q->getType() == "input" || q->getType() == "options" || q->getType() == "numbers" || q->getType() == "yesno") {
        cout << endl << "\t";
        string input;
        cin >> input;
        q->setAnswer(input);
    }
    cout << "************ end of prompt:(" << q->getType() << ") ************" << endl << endl;
    return;
}
