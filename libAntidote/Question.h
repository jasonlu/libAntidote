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
    
    string* getOptions();
    void setOptions(string *opt, int count);
    
    string getOption(int index);
    void setOption(int index, string opt);

    
    string getNextOption();
    bool hasMoreOptions();
    
    int getOptionsCount();
    void setOptionsCount(int count);

    bool getAnswerBool();
    string getAnswerString();
    float getAnswerFloat();
    int getAnswerInt();
    void setAnswer(string res);


protected:
    
    string text;
    string type;
    Question* children;
    
    //vector<string> options;
    string *options;
    //array<string, 10> options;
    int optionsCount;
    int currentOptIndex;

    int ansOptIndex;
    string ansInputString;
    double ansNumberValue;
    bool ansYesNo;
};

} /* namespace libAntidote */

#endif /* QUESTION_H_ */
