//============================================================================
// Name        : Question.h
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : The model to present user input
//============================================================================

#ifndef QUESTION_H_
#define QUESTION_H_
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


namespace libAntidote {
using namespace std;

class Question {
public:
    // Methods
	Question(string text);
	virtual ~Question();
	string getText();
	string getType();
	void setType(string type);
	void setType(string type, vector<string> opt);
	void setOptions(vector<string> opt);
    
	void setAnswer(string res);
    
    bool getAnswerBool();
    string getAnswerString();
    float getAnswerFloat();
    int getAnswerInt();


    
    // Properties
	int number;
    string text;
    string type;
    Question* children;
    vector<string> options;
//    string *options;
    

protected:


    int ansOptIndex;
    string ansInputString;
    double ansNumberValue;
    bool ansYesNo;
};

} /* namespace libAntidote */

#endif /* QUESTION_H_ */
