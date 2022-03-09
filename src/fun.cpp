// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>

unsigned int faStr1(const char *str) {
    bool inWordNoNum = false;
    unsigned int result = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWordNoNum) {
                result++;
                inWordNoNum = false;
        } else if (!inWordNoNum && str[i] != ' ' && !isdigit(str[i])) {
            if (i == 0 || str[i - 1] == ' ') {
                inWordNoNum = true;
            }
        } else if (inWordNoNum && isdigit(str[i])) {
                inWordNoNum = false;
        }
    }

    return result;
}

unsigned int faStr2(const char *str) {
    bool inWordCapital = false;
    unsigned int result = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWordCapital) {
                result++;
                inWordCapital = false;
        } else if (!inWordCapital && !islower(str[i]) && str[i] != ' ') {
            if (i == 0 || str[i - 1] == ' ') {
                inWordCapital = true;
            }
        } else if (inWordCapital && !islower(str[i])) {
                inWordCapital = false;
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
                        thisWordLength++;
                }
                summaryWordsLength = summaryWordsLength + thisWordLength;
                thisWordLength = 0;
                inWord = false;
        } else if (!inWord && str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
                inWord = true;
                wordCounter++;
                thisWordLength++;
        } else if (inWord) {
                thisWordLength++;
        }
    }

    return summaryWordsLength / wordCounter;
}
