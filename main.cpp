#include <iostream>
#include "implementation.h"


int main(int argc, char** argv) {
    if (argc != 6) {
        cerr << "Invalid number of command line arguments" << endl;
        exit(1);
    }

    implementation i;
    i.Training(argv[1]);
    i.Testing(argv[2]);
    i.Checking(argv[3], argv[4], argv[5]);

    return 0;
}