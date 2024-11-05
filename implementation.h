//
// Created by MNGal on 10/31/2024.
//

//Paragraph on how tokenization works in data structures



#include <map>
#include "DSString.h"
#include <vector>
#include <fstream>
//"strtok()" is the same as the library below
#include <string.h>
#include <utility>
#include <iomanip>

using namespace std;

#ifndef ASSIGNMENT2_SENTIMENT_IMPLEMENTATION_H
#define ASSIGNMENT2_SENTIMENT_IMPLEMENTATION_H


class implementation {
private:
    //Training

    //Takes in the unique words and the positive and negative count
    map<DSString, pair<int, int>>  mapCount;



    //final decision to see if it is positive or negative
    map <DSString, bool> mapTest;



    //Testing

    //tweet in and sentiment in positive or negative
    map <DSString, bool> mapSen;




    //Validation

    //ID's of wrong guesses
    vector <DSString> wrongID;




public:
    void Training(DSString);

    void Testing(DSString);

    void Checking (DSString, DSString, DSString);




};


#endif //ASSIGNMENT2_SENTIMENT_IMPLEMENTATION_H
