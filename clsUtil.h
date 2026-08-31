#pragma once

#include<iostream>
#include"clsDate.h";
using namespace std;

class clsUtil
{
public:

	enum enCharType { SmallLetter = 1, CapitalLetter, Digit, MixChars, SpecialChar,};

	static void Srand() {

		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To) {

		int Number = rand() % (To - From + 1) + From;

		return Number;
	}

	static char GetRandomCharecter(enCharType CharType) {

		if (CharType == enCharType::MixChars) {

			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType) {

		case(enCharType::SmallLetter):
			return char(RandomNumber(97, 122));

		case(enCharType::CapitalLetter):
			return char(RandomNumber(65, 90));

		case(enCharType::SpecialChar):
			return char(RandomNumber(33, 47));

		case(enCharType::Digit):
			return char(RandomNumber(48, 57));
		}

		return '\0';
	}

	static string GenerateWord(enCharType CharType, short Length) {

		string Word = "";

		for (int i = 1; i <= 4; i++) {

			Word += GetRandomCharecter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType) {

		string Key = "";

		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;
	}

	static void GenerateKeys(enCharType CharType, short NumberOfKeys) {

		for (int i = 1; i <= NumberOfKeys; i++) {

			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void  Swap(clsDate& Date1, clsDate& Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static void ShuffleArray(int Arr[100], int arrlength) {

		for (int i = 0; i < arrlength; i++) {

			Swap(Arr[RandomNumber(1, arrlength) - 1], Arr[RandomNumber(1, arrlength) - 1]);
		}

	}

	static void ShuffleArray(string Arr[100], int arrlength) {

		for (int i = 0; i < arrlength; i++) {

			Swap(Arr[RandomNumber(1, arrlength) - 1], Arr[RandomNumber(1, arrlength) - 1]);
		}

	}

	static void FillArrayWithRandomNumbers(int Arr[100], int arrlength, int From = 1, int To = 100) {


		for (int i = 0; i < arrlength; i++) {

			Arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string Arr[100], int arrlength, enCharType CharType, short Length) {

		for (int i = 0; i < arrlength; i++) {

			Arr[i] = GenerateWord(CharType, Length);
		}
	}

	static void FillArrayWithRandomKeys(string Arr[100], int arrlength, enCharType CharType) {

		for (int i = 0; i < arrlength; i++) {

			Arr[i] = GenerateKey(CharType);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string EncryptText(string Text, short EncryptionKey = 2) {

		for (int i = 0; i <= Text.length(); i++) {

			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2) {

		for (int i = 0; i <= Text.length(); i++) {

			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	static string NumberToText(long Number) {

		if (Number == 0) {
			return "";
		}
		if (Number >= 1 && Number <= 19) {

			string Arr[] = {
				"", "One ", "Two ", "Three ", "Four ",
				"Five ", "Six ", "Seven ", "Eight ", "Nine ",
				"Ten ","Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
				"Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ",
				"Nineteen "
			};

			return Arr[Number];
		}

		if (Number >= 20 && Number <= 99) {
			string Arr[] = {
				" ", " ", "Twenty ", "Thirty ", "Fourty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety "
			};

			return Arr[Number / 10] + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {

			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {

			string Arr[] = {
				"", "One ", "Two ", "Three ", "Four ",
				"Five ", "Six ", "Seven ", "Eight ", "Nine ",
				"Ten"
			};

			return Arr[Number / 100] + "Hundreds " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {

			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999) {

			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999) {

			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999) {

			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999) {

			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else {

			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}


};

