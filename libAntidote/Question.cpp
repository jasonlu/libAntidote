//============================================================================
// Name        : Question.cpp
// Author      : Jon Long & Jason Lu
// Version     :
// Copyright   : 2014 BU MET HiLab. All rights reserved.
// Description : The model to present user input
//============================================================================

#include "Question.h"

using namespace std;

libAntidote::Question::Question(string text) {
    // TODO Auto-generated constructor stub
    this->options = NULL;
    this->text = text;
    this->type = "end";
    this->ansOptIndex = -1;
    this->ansNumberValue = -1;
    this->ansInputString = "-1";
    this->optionsCount = 0;
    this->currentOptIndex = 0;
}

libAntidote::Question::~Question() {
    // TODO Auto-generated destructor stub
    delete this->options;
}

string libAntidote::Question::getText() {
    return this->text;
}

string libAntidote::Question::getType() {
    return this->type;
}

void libAntidote::Question::setType(string type) {
    if(type == "yesno") {
        this->options = new string[2];
        this->options[0] = "No";
        this->options[1] = "Yes";
        this->optionsCount = 2;
    } else {
        this->optionsCount = 0;
    }
    this->type = type;
}


void libAntidote::Question::setOptions(string *opt, int count) {
    this->type = "options";
    this->options = opt;
    this->setOptionsCount(count);
}

void libAntidote::Question::setOption(int index, string opt) {
    this->type = "options";
    this->options[index] = opt;
    if(index >= this->optionsCount) {
        this->setOptionsCount(index + 1);
    }
}

void libAntidote::Question::setOptionsCount(int count) {
    this->optionsCount = count;
}

int libAntidote::Question::getOptionsCount() {
    return this->optionsCount;
}

string *libAntidote::Question::getOptions() {
    return this->options;
}

string libAntidote::Question::getOption(int index) {
    if(index >= optionsCount) {
        return NULL;
    }
    return this->options[index];
}

string libAntidote::Question::getNextOption() {
    if(hasMoreOptions()) {
        int index = currentOptIndex;
        currentOptIndex++;
        return this->options[index];
    } else {
        return "";
    }
}

bool libAntidote::Question::hasMoreOptions() {
    return (this->currentOptIndex < this->optionsCount);
}


void libAntidote::Question::setAnswer(string res) {
    stringstream convert(res);
    if(this->type == "input" || this->type == "string") {
        this->ansInputString = res;
    } else if(this->type == "yesno" || this->type == "options" || this->type == "option" || this->type == "int") {
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

