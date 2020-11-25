//Напишите функцию поиска первого вхождения шаблона в текст. 
//
//В качестве первого параметра функция принимает текст (C-style строка), в которой нужно искать шаблон.
//В качестве второго параметра строку - шаблон (C-style строка), которую нужно найти.
//Функция возвращает позицию первого вхождения строки - шаблона, если он присутствует в строке, и - 1, если шаблона в тексте нет.
//
//Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.

#include <iostream>

using namespace std;

int StrStr(const char* text, const char* pattern)
{
	if (!*pattern) return 0;
	int pos = 0;
	while (*text) {
		auto t = text;
		auto p = pattern;
		while (*p && *t == *p) { ++p; ++t; }
		if (!*p) return pos;
		++pos;
		++text;
	}
	return -1;
}

int main() {
	const char text[] = "baaaaaaababaaazbbbbabaazbaaazbaaz";
	const char pattern[] = "baaz";
	int r = StrStr(text, pattern);
	cout << r << endl;
	return 0;
}

/* 
////Вариант 1
int StrLen(const char* s)
{
	int count = 0;
	while (*s) {
		++count;
		++s;
	}
	return count;
}

int StrStr(const char* text, const char* pattern)
{
	if (*pattern == '\0') return 0;
	int l_t = StrLen(text);
	int l_p = StrLen(pattern);
	int count = -1;
	for (int i = 0; i < l_t; i++) {
		int count_p = 0;
		for (int j = 0; j < l_p; j++) {
			if (text[i + j] == pattern[j]) {
				++count_p;
			}
			else break;
		}
		if (count_p == l_p) {
			count = i;
			break;
		}
	}
	return count;
}
*/


/*
////Вариант 2
int StrStr(const char* text, const char* pattern)
{
	if (*pattern == '\0') return 0;
	int count = 0;
	for (; *text != '\0'; text++) {
		auto t = text;
		auto p = pattern;
		for (; *p != '\0'; p++) {
			if (*t == *p) ++t;
			else break;
		}
		if (*p == '\0') return count;
		++count;
	}
	return -1;
}
*/

/*
////Вариант 3
int StrStr(const char* text, const char* pattern)
{
	if (*pattern == '\0') return 0;
	int count = -1;
	while (*text) {
		const char* pat = pattern;
		while (*pat) {
			if (*text == *pat) {
				++count;
				++pat;
				++text;
			}
			else {
				--count;
				--text;
				break;
			}
		}
		if (*pat == '\0') {
			break;
		}
		++text;
	}
	return count;
}
*/
