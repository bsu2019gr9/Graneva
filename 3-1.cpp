//Определить, сколько слов в строке содержат хотя бы одну заданную букву. Вывести такие слова на экран
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
void giveMemory(char*&);
void deleteMemory(char*&);
int calcWords(char*, char);
void printWords(char* str, char sym);
int main()
{
	char* str = nullptr;
	giveMemory(str);
	cout << "Enter the string: ";
	cin.getline(str, 255);
	char sym;
	cout << '\n' << "Enter a symbol for searching:";
	cin >> sym;
	cout << '\n' << calcWords(str, sym) << " words contain the symbol " << sym << '\n';
	printWords(str, sym);
	deleteMemory(str);
	return 0;
}
void giveMemory(char*& str)
{
	str = new(nothrow) char[255];
	if (!str)
	{
		cout << "error" << "\n";
	}
}
void deleteMemory(char*& str) {
	delete[] str;
	str = nullptr;
}
int calcWords(char* str, char sym)
{
	size_t k = 0;
	bool flag = false;
	for (size_t i = 0; i < strlen(str); ++i)
	{
		if (str[i] == sym && !flag)
		{
			++k;
			flag = true;
		}
		if (str[i] == ' ')
			flag = false;
	}
	return k;
}
void printWords(char* str, char sym)
{
	size_t k = 0;
	for (size_t i = 0; i < strlen(str); ++i)
	{
		if (str[i] == sym)
		{
			while (str[k] != ' ' && k < strlen(str))
			{
				cout << str[k];
				++k;
			}
			cout << ' ';
			i = k;
		}
		if (str[i] == ' ')
		{
			k = i + 1;
		}
	}
}
