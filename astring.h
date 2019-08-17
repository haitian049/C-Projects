#ifndef ASTRING_H
#define ASTRING_H

#include <iostream>
//#include <cassert>
#include<cstdlib>

namespace string
{


	class astring
	{

	public:
		astring(void);//default sets string to NULL

		astring(char c);

		astring(const char* input);//Takes in a string and creates an object

		astring(const astring & S);//Copy constructor

		~astring(void);//Destructor deletes the nstring at the end

		size_t length();//displays length of string excluding null

		size_t getnlength()const;

		char* getnstring() const;

		char& at(int loc);// returns a chracter at specified loc-1

		size_t Charnum(char c);// Finds the number of occurances a character shows up in a string

		const size_t findChar(char c);// Finds the first occurance of a character and returns its position

		bool insert(astring s, size_t index);// Inserts a string into a astring object at a specified position

		bool empty();// if string is empty returns true else it returns false

		void swap(astring& from);// swaps the contents of two strings

		const size_t find(const astring& word);

		const size_t astring::find(const char * word);

		void setlength(size_t newLength);

		void setnstring(char * newString);

		astring substr(size_t index, size_t length);// returns an object which is the substring of the object that calls it

		//astring& operator +=(const char*);

		//astring& operator +=(const astring&);

		//astring& operator +=(const char);

		astring& operator = (const astring& S);//if A and B are object B is "neil", the A =B therefore A is "neil"

		char& operator [](size_t index) const;

		friend bool operator == (astring& S1, astring& S2);// checks if both strings are equal

		friend astring operator + (const astring& S1, const astring & S2);//still buggy

		friend std::istream& operator >>(std::istream & IS, astring& S)
		{

			char * X = new char[250];

			std::streamsize count = 250;

			size_t i = 0;

			IS.getline(X, count, ' ');

			i = (size_t)IS.gcount();

			S.nlength = i + 1;

			delete[] S.nstring;

			S.nstring = new char[S.nlength];

			for (size_t j = 0; j < S.nlength - 1; j++)
			{
				S.nstring[j] = X[j];
			}

			S.nstring[S.nlength - 1] = '\0';

			//for (size_t j = S.nlength; X[j] != '\0'; j++)
			//IS.putback(X[j]);

			delete[] X;

			X = NULL;

			return IS;

		}

		friend std::ostream& operator <<(std::ostream & OS, astring& S)
		{



			for (size_t j = 0; S.nstring[j] != '\0'; ++j)
			{
				OS << S.nstring[j];


			}

			return OS;
		}

		std::istream& getline(std::istream& IS, astring& S, const char c = '\0')
		{

			char * input = new char[250];

			std::streamsize count = 250;

			IS.getline(input, count);

			size_t i = 0;

			i = (size_t)IS.gcount();

			S.nlength = i + 1;

			delete[] S.nstring;

			S.nstring = new char[S.nlength];

			for (size_t j = 0; j < S.nlength - 1; j++)
			{
				S.nstring[j] = input[j];
			}

			S.nstring[S.nlength - 1] = '\0';

			delete[] input;

			return IS;

		}

		char* nstring;

		size_t nlength;

	};

}

#endif;