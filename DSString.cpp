#include "DSString.h"

/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings don's store an explicit length but use `\0` as the terminator symbol
 * but your class should store its length in a member variable. 
 * DDO NOT USE C-STRING FUNCTIONS <string.h> or <cstring>.
 */
//creat the default to the heap strings
DSString::DSString() {
    data = new char[1];
    data[0] = '\0';
    len = 0;
}

//create a space for the terminator operator
DSString::DSString(const char *str) {
    len = strlen(str);
    data = new char[len + 1];
    for (int i = 0; i < len; i++) {
        data[i] = str[i];
    }
    data[len] = '\0';
}

//will sub
DSString::DSString(const DSString &str) {
    len = str.len;
    data = new char[len + 1];
    for (int i = 0; i < len; i++) {
        data[i] = str.data[i];
    }
    data[len] = '\0';
}

//*this points to the new object that points to a new string(heap)
DSString &DSString::operator=(const DSString &str) {
    delete[] data;
    len = str.len;
    data = new char[len + 1];
    for (int i = 0; i < len; i++) {
        data[i] = str.data[i];
    }
    data[len] = '\0';
    return *this;
}

//deletes the string and pointer (comes as is) [prevents memory leak]
DSString::~DSString() {
    delete[] data;
}

//return the length of the string
size_t DSString::length() const {
    return len;
}

//Will return a character from the data array
char &DSString::operator[](size_t in) {
    return data[in];
}

//concatanate the words
DSString DSString::operator+(const DSString &str) const {
    //creating a function for rearraging the characters
    char* cstr = new char[len+str.len+1];
    cstr[len+str.len] = '\0';

    //
    for (int i = 0; i < len; i++) {
        cstr[i] = data[i];
    }

    for (int i = 0; i < str.len; i++) {
        cstr[len+i] = str.data[i];
    }

    DSString concat = cstr;
    delete[] cstr;
    //return the ds string
    return concat;
}


//Is checking if the strings are the same to each other
bool DSString::operator==(const DSString &str) const {
    if (len != str.len){
        return false;
    }
    //will check if the characters are the same
    for (int i = 0; i < len; i++) {
        if (data[i] != str.data[i]){
            return false;
        }
    }
    return true;
}

//check the alphabetic order
bool DSString::operator<(const DSString &str) const {
    //declare our index
    int i = 0;
    //loop so that if the length is shorter for left than right then we check the characters
    while(i < len&&i<str.len){

        //if the string in the left has a letter in the alphabet earlier than the right it will be true
        if(data[i] < str.data[i]){
            return true;
        }
        //else the left does not have a letter before the alphabet of the right string it will return false
        else if(str.data[i] < data[i]){
            return false;
        }
        //move to the next character
        i++;
    }
    if (len < str.len){
        return true;
    }
    else{
        return false;
    }




}

//parameters to see where the length of the data starts and how many characters the
DSString DSString::substring(size_t start, size_t numChars) const {
    //creating a function for rearraging the characters
    char* substr = new char[numChars+1];
    substr[numChars] = '\0';

    for (int i = 0; i < numChars; i++) {
        substr[i] = data[start + i];
    }

   DSString str = substr;
    delete[] substr;
    //return the
    return str;
}

//The ACSI Table has the lower cases be 32 more so we would have to add 32 to go from upper case letters to
//lower case letters.
DSString DSString::toLower() const {
    DSString str = data;
    for (int i = 0; i < str.len; i++) {
        if (str.data[i] >= 'A' && str.data[i] <= 'Z') {
            str.data[i] = str.data[i] + 32;
        }
    }
    return str;
}

const char *DSString::c_str() const {
    return data;
}

//makes it so that the cout could be used in the code put the datat outward.
std::ostream &operator<<(std::ostream &out, const DSString &str) {
    out << str.data;
    return out;
}

