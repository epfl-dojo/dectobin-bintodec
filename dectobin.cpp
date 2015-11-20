// dectobin.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int dectobin(int, int[16]);

void main(void)
{
	int input;
	int binVal[16] = { 0 };
	int decVal;

	cout << "Tappez 1 pour convertir un dec en bin ou tappez 0 pour convertir un bin en dec" << endl;
	cin >> input;
	switch (input)
	{
		case 0: 
			cout << "Tappez un binaire a convertir en dec: " << endl;
			cin >> input;
			break;
		case 1:
			cout << "Tappez un dec a convertir en binaire: " << endl;
			cin >> input;
			cout << dectobin(input, binVal);
			break;
		default:
			cout << "AARRRGGGHH!" << endl;
			break;
	}
	system("pause");
}

int dectobin(int input, int binVal[])
{
	int index = 0;
	cout << input;
	while (input > 0)
	{
		int bit = input % 2;
		binVal[index] = 1;
		input /= 2;
		index++;
		cout << sizeof(binVal)/sizeof(int) << endl;
	}
	cout << binVal[0];
	return input;
}
