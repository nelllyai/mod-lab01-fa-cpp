// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>

unsigned int faStr1(const char *str) {
    bool inWordWithoutNumbers = false;
    unsigned int result = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWordWithoutNumbers) {
                result = result + 1;
                inWordWithoutNumbers = false;
        }
        else if (!inWordWithoutNumbers && str[i] != ' ' && !isdigit(str[i]) && (i == 0 || str[i - 1] == ' ')) {
                inWordWithoutNumbers = true;
        }
        else if (inWordWithoutNumbers && isdigit(str[i])) {
                inWordWithoutNumbers = false;
        }
    }

    return result;
}

unsigned int faStr2(const char *str) {
    bool inWordWithCapitalFirstLetter = false;
    unsigned int result = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWordWithCapitalFirstLetter) {
                result = result + 1;
                inWordWithCapitalFirstLetter = false;
        }
        else if (!inWordWithCapitalFirstLetter && !islower(str[i]) && str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
                inWordWithCapitalFirstLetter = true;
        }
        else if (inWordWithCapitalFirstLetter && !islower(str[i])) {
                inWordWithCapitalFirstLetter = false;
        }
    }

    return result;
}

unsigned int faStr3(const char *str) {
    bool inWord = false;
    unsigned int summaryWordsLength = 0;
    unsigned int thisWordLength = 0;
    unsigned int wordCounter = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWord) {
                if (str[i] != ' ') {
                        thisWordLength = thisWordLength + 1;
                }
                summaryWordsLength = summaryWordsLength + thisWordLength;
                thisWordLength = 0;
                inWord = false;
        }
        else if (!inWord && str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
                inWord = true;
                wordCounter = wordCounter + 1;
                thisWordLength = thisWordLength + 1;
        }
        else if (inWord) { //находимся в слове
                thisWordLength = thisWordLength + 1;
        }
    }

    return summaryWordsLength / wordCounter;
}
