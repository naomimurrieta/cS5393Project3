//
// Created by MNGal on 10/31/2024.
//

#include "implementation.h"

void implementation::Training(DSString fileName) {

    //create ifstream and open filename

    ifstream takeIn(fileName.c_str());

    if (!takeIn.is_open()) {
        cerr << "Failed to open file" << endl;
        exit(1);
    }

    //create c-string buffer
    char *buffer = new char[1000];


    //read the next 1000 letters until the line break
    //to discard the header
    takeIn.getline(buffer, 1000);


    //now that we delete the unnesacary information we parce

    //loops in the input
    while (!takeIn.eof()) {

        //stop until first column(seperated by commas) or 1000 words
        //replace wtv the buffer had before
        takeIn.getline(buffer, 1000, ',');

        if (strlen(buffer) == 0) {
            break;
        }

        //first char in buffer check if it is a 4
        bool isPositive = buffer[0] == '4';

        //skipped the 4 columns to read the tweet text that is in the end
        for (int i = 0; i < 4; i++) {
            takeIn.getline(buffer, 1000, ',');
        }
        //read in tweet text
        takeIn.getline(buffer, 1000);

        //If they see one of these character we check the word after
        char *token = strtok(buffer, "!,@#$%^&*()<>:;_-+=1234567890\"'{}[]|\\~`?. ");

        //Keep looping in this tweet until there is no points in the tweet
        while (token != nullptr) {

            //calling that function in the other class and make a deep copy to edit it
            //convert the cstring into the dstring
            DSString word = token;

            //if the word has more than two words it will register it and if there if not more than two char
            //there is not much strong sentiment
            if (word.length() > 2) {
                //Decapatalize
                word = word.toLower();
                //saying this word does not exist
                if (mapCount.find(word) == mapCount.end()) {
                    if (isPositive) {
                        mapCount[word] = make_pair(1, 0);
                    } else {
                        mapCount[word] = make_pair(0, 1);
                    }

                } else {
                    //if you have seen this word before
                    if (isPositive) {
                        mapCount[word].first++;
                    }
                        //
                    else {
                        mapCount[word].second++;
                    }
                }

            }
            //While we do have the other characters we need to check the token once more
            token = strtok(nullptr, "!,@#$%^&*()<>:;_-+=1234567890\"'{}[]|\\~`?. ");
        }


    }

    //only way to traverse the
    for (pair<DSString, pair<int, int>> itr: mapCount) {
        //hyparameter tunning
        //discard the words that count has less than the desired accountability could have in our accuracy
        int total = itr.second.first + itr.second.second;
        //           positive count         negative count

        //5 to 50 is the disregarding count of a word... reasonable word to use


        //YOU CAN CHANGE THIS TO SEE WHAT WORKS BEST!!!
        if (total > 8) {
            double prob = (double) (itr.second.first) / (total);

            //will see if the word is positve and negative
            if (prob > 0.6) {
                mapTest[itr.first] = true;

            }
                //
            else if (prob < 0.4) {
                mapTest[itr.first] = false;
            }
        }
    }
//CECKPOINT
//    for (pair<DSString, bool> itr:mapTest){
//        cout << itr.first<< ' ' << itr.second<<endl;
//    }
}


//Testing


void implementation::Testing(DSString fileName) {

    //create ifstream and open filename

    ifstream takeIn (fileName.c_str());

    if (!takeIn.is_open()) {
        cerr << "Failed to open file" << endl;
        exit(1);
    }

    //create c-string buffer
    char* buffer = new char[1000];


    //read the next 1000 letters until the line break
    //to discard the header
    takeIn.getline(buffer, 1000);


    //now that we delete the unnesacary information we parce

    //loops in the input
    while(!takeIn.eof()){

        //stop until first column(seperated by commas) or 1000 words
        //replace wtv the buffer had before
        takeIn.getline(buffer, 1000, ',');

        if (strlen(buffer) == 0){
            break;
        }

        DSString iD = buffer;

        //skipped the 3 columns to read the tweet text that is in the end
        for(int i = 0; i < 3; i++){
            takeIn.getline(buffer, 1000, ',');
        }
        //read in tweet text
        takeIn.getline(buffer, 1000);

        //If they see one of these character we check the word after
        char* token = strtok(buffer,"!,@#$%^&*()<>:;_-+=1234567890\"'{}[]|\\~`?. ");

        int netSenti = 0;

        //Keep looping in this tweet until there is no points in the tweet
        while (token != nullptr){

            //calling that function in the other class and make a deep copy to edit it
            //convert the cstring into the dstring
            DSString word = token;

            //if the word has more than two words it will register it and if there if not more than two char
            //there is not much strong sentiment
            if(word.length()>2){
                //Decapatalize
                word = word.toLower();
                //saying this word does exist
                if(mapTest.find(word) != mapTest.end()){
                    //If the word is positive incresse our netSenti
                    if (mapTest[word]) {
                        netSenti++;
                        //else subtract from the netSenti
                    } else {
                        netSenti--;
                    }
                }

            }
            //While we do have the other characters we need to check the token once more
            token = strtok(nullptr,"!,@#$%^&*()<>:;_-+=1234567890\"'{}[]|\\~`?. ");
        }

    //if the sentiment count is 0 you do not really know if it is positive or negative
    //So we make it so that it would be positive

    //CHECKPOINTTTTT
        mapSen[iD] = netSenti >= 0;
    }

    //CHECKINGGG


}

void implementation::Checking(DSString file1, DSString file2, DSString file3) {
    //create ifstream and open filename

    ifstream takeIn(file1.c_str());

    if (!takeIn.is_open()) {
        cerr << "Failed to open file" << endl;
        exit(1);
    }

    //create c-string buffer
    char *buffer = new char[1000];


    //read the next 1000 letters until the line break
    //to discard the header
    takeIn.getline(buffer, 1000);


    //now that we delete the unnesacary information we parce

    //loops in the input
    while (!takeIn.eof()) {

        //stop until first column(seperated by commas) or 1000 words
        //replace wtv the buffer had before
        takeIn.getline(buffer, 1000, ',');

        if (strlen(buffer) == 0) {
            break;
        }

        //first char in buffer check if it is a 4
        bool isPositive = buffer[0] == '4';

        takeIn.getline(buffer, 1000);
        DSString iD = buffer;

        //If it is not positive
        if (mapSen[iD] != isPositive) {

            //we use the vector that will store the Ids that have the sentiments that are not positives
            wrongID.push_back(iD);
        }
    }
    ofstream res1 (file2.c_str());


    for (pair<DSString, bool> itr:mapSen){
        //If the word is positive
        if (itr.second) {
            //Print out a 4 to indicate it
            res1 << "4," << itr.first << endl;
        } else {
            //Print out 0 if it is negative
            res1 << "0," << itr.first << endl;
        }
    }
    res1.close();

    ofstream res2 (file3.c_str());

    //Converting into a double that initially returns the wrong percentage and if subtracted 1 will give
    //the right percentage.
    double accuracy = 1 - ((double)(wrongID.size()) / (mapSen.size()));

    //Outputs the number to 3 decimals
    res2 << setprecision(3) << accuracy << endl;

    for (int i =0; i < wrongID.size(); i++){
        //Will get the ID from the vector it will get it through the mapSen
        if (mapSen[wrongID[i]]) {
            //It will print the right order if it was postive then should be negative(0)
            //Else then if we put negative we would say it was positve(4)
            res2 << "4,0,";
        } else {
            res2 << "0,4,";
        }
        res2 << wrongID[i] << endl;
    }
    res2.close();
}