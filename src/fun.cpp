// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>

unsigned int faStr1(const char *str) {
    bool inWordWithoutNumbers = false; //флаг ("находимся внутри слова без цифр")
    unsigned int result = 0; //количество слов без цифр в строке
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWordWithoutNumbers) { //вышли из очередного слова без цифры
                result = result + 1;
                inWordWithoutNumbers = false;
        }
        else if (!inWordWithoutNumbers && str[i] != ' ' && !isdigit(str[i]) && (i == 0 || str[i - 1] == ' ')) { //вошли в слово
                inWordWithoutNumbers = true;
        }
        else if (inWordWithoutNumbers && isdigit(str[i])) { //в слове наткнулись на цифру
                inWordWithoutNumbers = false;
        }
    }

    return result;
}

unsigned int faStr2(const char *str) {
    bool inWordWithCapitalFirstLetter = false; //флаг ("находимся внутри слова с одной (первой) заглавной буквой")
    unsigned int result = 0; //количество слов с первой заглавной буквой
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWordWithCapitalFirstLetter) { //вышли из очередного слова с первой заглавной буквой
                result = result + 1;
                inWordWithCapitalFirstLetter = false;
        }
        else if (!inWordWithCapitalFirstLetter && !islower(str[i]) && str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) { //вошли в слово
                inWordWithCapitalFirstLetter = true;
        }
        else if (inWordWithCapitalFirstLetter && !islower(str[i])) { //в слове наткнулись на вторую заглавную букву
                inWordWithCapitalFirstLetter = false;
        }
    }

    return result;
}

unsigned int faStr3(const char *str) {
    bool inWord = false; //флаг ("находимся внутри слова")
    unsigned int summaryWordsLength = 0; //количество букв в сумме (у всех слов)
    unsigned int thisWordLength = 0; //количество букв в текущем слове
    unsigned int wordCounter = 0; //счетчик слов
    int i;

    for (i = 0; i < strlen(str); i++) {
        if ((str[i] == ' ' || i == strlen(str) - 1) && inWord) { //вышли из слова
                if (str[i] != ' ') {
                        thisWordLength = thisWordLength + 1;
                }
                summaryWordsLength = summaryWordsLength + thisWordLength;
                thisWordLength = 0;
                inWord = false;
        }
        else if (!inWord && str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) { //вошли в слово
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
