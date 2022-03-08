// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool inWordWithoutNumbers = false; //флаг ("находимся внутри слова без цифр")
	unsigned int result = 0; //количество слов без цифр в строке
	int i;

	for (i = 0; i < strlen(str); i++) {
		if ((str[i] == ' ' || i == strlen(str) - 1) && inWordWithoutNumbers) { //вышли из очередного слова без цифры
			result++;
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
    return 0;
}

unsigned int faStr3(const char *str) {
    return 0;
}
