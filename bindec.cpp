#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#define DEBUG 0

using namespace std;

bool dectobin(string, bool[16]);
int bintodec(string);
bool is_binary(string);
bool is_decimal(string);

void main(void)
{
	string input;
	bool binVal[16] = {0};
	int decVal = 0;

	cout << "[0] Bin to Dec" << endl;
	cout << "[1] Dec to Bin" << endl;
	cin >> input;
	if (input == "0")
	{
		cout << "Tapez un binaire a convertir en dec: " << endl;
		cin >> input;
		if (is_binary(input)) {
			cout << input << " en binaire vaut : " << bintodec(input) << endl;
		}
		else {
			cout << input << " n'est pas un nombre en binaire !" << endl;
		}
	}
	else if (input == "1")
	{
		cout << "Tapez un dec a convertir en binaire: " << endl;
		cin >> input;
		if (is_decimal(input)) {
			dectobin(input, binVal);
		}
		else {
			cout << input << " n'est pas un nombre decimal !" << endl;
		}
	}
	else
	{
		cout << "AARRRGGGHH!" << endl;
	}
	system("pause");
}

bool dectobin(string inputstr, bool binVal[])
{
	int input = std::stoi(inputstr);
	int input2 = input;
	int index = 0;
	while (input != 0)
	{
		int bit = input % 2;
		binVal[index] = bit;
		input /= 2;
		index++;
	}
	index--;
	cout << input2 << " en decimal vaut : ";
	while (index >= 0)
	{
		cout << binVal[index];
		index--;
	}
	cout << " en binaire" << endl;
	return binVal[index];
}

int bintodec(string input)
{
	int somme = 0;
	
	for (int i = input.size()-1 ; i>=0 ; i--)
	{
#if DEBUG
		cout << "--------" << endl;
		cout << "i" << i << endl;
		cout << input[i] - '0' << endl;
#endif // DEBUG


		somme += (input[i] - '0') * pow(2, i);
#if DEBUG
		cout << somme << endl;
#endif // DEBUG
	}
#if DEBUG
	cout << somme << endl;
#endif // DEBUG
	
	return somme;
}

bool is_binary(string input) {
	for (int i = input.size() - 1; i >= 0; i--)
	{
		if (!((input[i] == '0') || (input[i] == '1'))) {
			return false;
		}
	}
	return true;

}

bool is_decimal(string input) {
	for (int i = input.size() - 1; i >= 0; i--)
	{
		if (!(input[i] >= 0) && (input[i] <= 9)) {
			return false;
		}
		/*if (!(input[i] == 1,2,3,4,5,6,7,8,9,0)) {
			return false;
		}*/
	}
	return true;

}
