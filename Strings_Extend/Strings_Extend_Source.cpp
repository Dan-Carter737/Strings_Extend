#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <ctype.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int StringLenth(char str[]);

void to_lower(char str[]);
void to_upper(char str[]);
char* shrink(char str[]);

bool is_palindrome(const char str[]);
char* remove_symbol(char str[], char symbol);

bool is_int_number(const char* str);
void to_int_number(char str[]);

void is_bin_number(char str[]);
void to_bin_number(char str[]);

void is_hex_number(char str[]);
void to_hex_number(char str[]);

void main()
{
	setlocale(LC_ALL, "");

	'\0';
	//char str[] = { 'H','e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	//cout << str << endl;

	const int SIZE = 256;
	char str[SIZE] = "HELLO";
	//cout << "Enter the word by using the CAPITAL letters: "; //cin >> str;
	//SetConsoleCP(1251);
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	//cout << str << endl;
	//cout << "The string's size is: " << StringLenth(str) << endl << endl;
	cout << "The function called \"to_lower\" is done: " << endl;
	to_lower(str);
	cout << str << endl << endl;
	cout << "The function called \"to_upper\" is done: " << endl;
	to_upper(str);
	cout << str << endl << endl;
	cout << shrink(str) << endl;;
	//cout << "Enter the word to know if this word is polindrom : "; cin >> str;
	cout << "Enter the value or text: "; cin >> str;
	is_int_number(str);
	to_int_number(str);
	cout << "Enter the value or text: "; cin >> str;
	is_bin_number(str);
}
int StringLenth(char str[])
{
	int times = 0;
	for (int i = 0; i < str[i]; i++)
	{
		times++;
	}
	return times;
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] += 'A' - 'a';
		}
		else str[i] -= 'A' - 'a';*/
		str[i] = tolower(str[i]);
	}

}
void to_upper(char str[])
{
	for (int i = 0; i < str[i]; i++)
	{
		/*if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'a' - 'A';
		}
	 else str[i] -= 'a' - 'A';*/
		str[i] = toupper(str[i]);
	}
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
	while (str[0] == ' ') for (int i = 0; str[i]; i++) str[i] = str[i + 1];
	return str;
}
char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}

bool is_palindrome(const char str[])
{
	cout << typeid(str).name() << endl;
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i < n / 2; ++i)
	{
		if (buffer[i] != buffer[n - i - 1])
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}

bool is_int_number(const char* str)
{
	int a = 0;
	for (a; str[a]; a++)
	{
		if (str[a] < 48 && str[a] > 57)
		{
			 return true;
		}
		else return false;
	}
		
}
void to_int_number(char str[])// почему-то всегда выдает отрицательный результат, вероятнее всего, не отрабатывает функция is_int_number???!
{
	int n = is_int_number(str);
	if (n == true) { cout << str << endl; }
	else { cout << "Строка не является целым числом" << endl; }
}
void is_bin_number(char str[])
{
	bool check = false;
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '\0') {
			break;
		}
		if (!((str[i] == '1' && str[i] == '0') || (str[i] == '1' || str[i] == '0')))
		{
			check = false;
			break;
		}
		else
		{
			check = true;
		}
	}
	if (check) {
		cout << "Двоичное число";
	}
	else { cout << "Не является двоичным числом"; };
	cout << endl;
}
void to_bin_number(char str[]) //????? 
{
     is_bin_number(str);// видимо некорректно применяю в данной функции, хотел проинтовать к число, не выходит из-за конфликта типа данных!!! 
	int sum = 0; 
	
	for (int i = str[0] - 1; i > -1; i--)
		if (str[i] == '1')   
			sum += pow(2, i);

}
void is_hex_number(char str[])
{
	
}
void to_hex_number(char str[])
{

}