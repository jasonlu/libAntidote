//============================================================================
// Name        : Question.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : The model to present user input
//============================================================================

#include "Question.h"

namespace libAntidote {

Question::Question(string text) {
	// TODO Auto-generated constructor stub
	this->text = text;
	this->type = "input";
    this->ansOptIndex = -1;
    this->ansNumberValue = -1;
    this->ansInputString = "-1";

}

Question::~Question() {
	// TODO Auto-generated destructor stub
}

} /* namespace libAntidote */
using namespace std;

string libAntidote::Question::getText() {
	return this->text;
}

string libAntidote::Question::getType() {
	return this->type;
}

void libAntidote::Question::setType(string type) {
    if(type == "yesno") {
        this->options.clear();
        this->options.push_back("yes");
        this->options.push_back("no");
    }
	this->type = type;
}

void libAntidote::Question::setType(string type, vector<string> opt) {
	this->type = type;
	this->options = opt;
}

void libAntidote::Question::setOptions(vector<string> opt) {
	this->type = "options";
    this->options = opt;
}

void libAntidote::Question::setAnswer(string res) {
    stringstream convert(res);
    if(this->type == "input" || this->type == "string") {
        this->ansInputString = res;
    } else if(this->type == "yesno" || this->type == "options") {
        if (!(convert >> this->ansOptIndex)) {
            this->ansOptIndex = -1;
        }
    } else if(this->type == "numbers" || this->type == "float") {
        if (!(convert >> this->ansNumberValue)) {
            this->ansNumberValue = -1;
        }
    }

}

bool libAntidote::Question::getAnswerBool() {
    return ansYesNo;
}

string libAntidote::Question::getAnswerString() {
    return ansInputString;
}

float libAntidote::Question::getAnswerFloat() {
    return ansNumberValue;
}

int libAntidote::Question::getAnswerInt() {
    return ansOptIndex;
}

