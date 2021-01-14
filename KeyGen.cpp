#include "stdafx.h"

void KeyGen(char*);
void KeyGen2(char*);
char Alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char Numberz[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int main()
{
	int menuChoice = 0;
	char key[15];
	char key2[17];
	memset(key, '\0', sizeof(key));
	memset(key2, '\0', sizeof(key2));

	cout << "*****Shinra Energy Company KeyGen 1337*****" << endl;
	cout << "1) Generate type-1 key\n"  << "2) Generate type-2 key\n" << "3) Exit keygen\n";
	cin >> menuChoice;

	if (menuChoice == 1)
	{
		cout << "Generating type-1 key..." << endl;
		KeyGen(key);
		cout << "Key: ";
		for (int i = 0; i < 15; i++)
			cout << key[i];
		cout << endl;
		cout << "Key generated successfully, terminating keygen." << endl;
	}
	else if (menuChoice == 2)
	{
		cout << "Generating type-2 key..." << endl;
		KeyGen2(key2);
		cout << "Key: ";
		for (int i = 0; i < 17; i++)
			cout << key2[i];
		cout << endl;
		cout << "Key generated successfully, terminating keygen." << endl;
	}
	else if (menuChoice == 3)
	{
		cout << "Terminating key generator." << endl;
	}
	system("pause");
}

void KeyGen(char* key)
{
	char templetters[8];
	char tempnumbers[7];
	char tempkey[15];

	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		int rand1 = rand() % 25;
		templetters[i] = Alphabet[rand1];
	}
	for (int i = 0; i < 7; i++)
	{
		int rand2 = rand() % 9;
		tempnumbers[i] = Numberz[rand2];
	}

	char tk1[15];
	char tk2[15];
	memset(tk1, ' ', sizeof(tk1));
	memset(tk2, ' ', sizeof(tk2));
	int k = 0;
	int j = 0;
	for (int i = 0; i < 15; i = i + 2)
	{
		tk1[i] = templetters[k];
		k = k + 1;
	}
	for (int i = 1; i < 15; i = i + 2)
	{
		tk2[i] = tempnumbers[j];
		j = j + 1;
	}
	k = 0;
	j = 1;
	for (int i = 0; i < 15; i++)
	{
		if ((i / 2) * 2 == i)
		{
			tempkey[i] = tk1[k];
			k = k + 2;
		}
		else if ((i / 2) * 2 != i)
		{
			tempkey[i] = tk2[j];
			j = j + 2;
		}
	}
	for (int i = 0; i < 15; i++)
		key[i] = tempkey[i];
}
void KeyGen2(char* key)
{
	char templetters[8];
	char tempnumbers[7];
	char tempkey[17];
	memset(tempkey, ' ', 17);

	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		int rand1 = rand() % 25;
		templetters[i] = Alphabet[rand1];
	}
	for (int i = 0; i < 7; i++)
	{
		int rand2 = rand() % 9;
		tempnumbers[i] = Numberz[rand2];
	}
	tempkey[5] = '-';
	tempkey[11] = '-';
	int k = 0;
	int j = 0;
	for (int i = 0; i < 17; i++)
	{
		if (i == 0 || i == 2 || i == 3 || i == 6 || i == 7 || i == 10 || i == 14 || i == 15)
		{
			tempkey[i] = templetters[k];
			k++;
		}
		else if (i == 1 || i == 4 || i == 8 || i == 9 || i == 12 || i == 13 || i == 16)
		{
			tempkey[i] = tempnumbers[j];
			j++;
		}
	}
	for (int i = 0; i < 17; i++)
		key[i] = tempkey[i];
	

}
