# include "astring.h"
#include  <cassert>


using namespace string;

astring::astring()
{
	nlength = 1;

	this->nstring = new char[nlength];

	nstring[0] = '\0';
}

astring::astring(const char c)
{
	nlength = 2;

	this->nstring = new char[nlength];

	this->nstring[0] = c;

	nstring[1] = '\0';
}

astring::astring(const char *input)
{
	
	nlength = strlen(input) + 1;

	nstring = new char[nlength];

	for (size_t i = 0; i < nlength; i++)
		nstring[i] = input[i];

}


astring::astring(const astring& S)
{
	nlength = S.nlength;  

	nstring = new char[nlength];

	strcpy_s(nstring, nlength, S.nstring);

}


astring::~astring()
{
	
	delete[] nstring; // D

	nstring = NULL;

}

size_t astring::getnlength() const
{

	return nlength;

}

char* astring::getnstring() const
{
	char * temp = nstring;

	return temp;

}

size_t astring::length()
{
	size_t i = 0;
	while (nstring[i] != '\0')
	{
		i++;
	}
	return i;
}

void astring::setlength(size_t newLength)
{

	nlength = newLength;

}

void astring::setnstring(char* newString)
{

	nstring = newString;

}


const size_t astring::find(const astring& word)
{                  
    if (word.nlength > this->nlength)
        return -1; // if the substring is greater then us, there's no way we can have it as a substring
    int i = 0, j = 0;
    for (i = 0; i < this->nlength; i++)
    {
        for (j = 0; j < word.nlength; j++)  
            if ( ((i + j) >= this->nlength) || (nstring[i + j] != word.nstring[j]) ) // if they don't match, offset exceeded Size, break
                break ;
        if (j == word.nlength) // We went through the entire substring, didn't hit break so j == Other.size
            return i; // return index
    }

    return -1; // if we never return anything means, we didn't find it, so return -1
}

const size_t astring::find(const char * word)
{
	if (strlen(word) > nlength)
		return -1; 

	int i = 0, j = 0;

	for (i = 0; i < this->nlength; i++)
	{
		for (j = 0; j < strlen(word); j++)
			if (((i + j) >= this->nlength) || (this->nstring[i + j] != word[j]))
				break;
		
		if (j == strlen(word))
			return i; // return index
	}

	return -1; // if this executes then we didn't find the 
}

size_t astring::Charnum(char c)
{

	size_t i = 0, j = 0;

	while (nstring[i] != '\0')
	{
	
	if (c == nstring[i])
		++j;

	i++;

    }
	return j;

}

const size_t astring::findChar(char c)
{

	size_t i = 0;

	while (c != nstring[i])
		 ++i;

	return i;

}

bool astring::insert(astring s, size_t index)
{

	if(s.nlength != 1)
		if(index < nlength)
		{
			
			size_t size = ((s.nlength - 1) + (this->nlength - 1)) + 1;

			char * temp = new char[size];

			if (index == 0)
			{

				for (size_t i = 0; i < (s.nlength - 1); i++)
					temp[i] = s.nstring[i];

				size_t j = 0;

				for (size_t k = s.nlength - 1, j = 0; k < (size - 1); k++, j++)
					temp[k] = nstring[j];
				

				if (temp[size - 1] != '\0')
					temp[size - 1] = '\0';

				nlength = size;

				delete[] nstring;

				nstring = temp;

				return true;

			}

				else
				{
					--index;

					size_t j = 0;

					for (size_t i = 0; i < index; ++i)
						temp[i] = nstring[i];

					for (size_t k = index, j = 0; k < (size -1); k++, j++)
						temp[k] = s.nstring[j];

					for (size_t l = ((size) - (s.nlength - index)), j = index; l < size; ++l, ++j)
						temp[l] = s.nstring[j];

					temp[size - 1] = '\0';

					nlength = size;

					delete[] nstring;

					nstring = temp;

					return true;

				}
		}

		return false;

}

char& astring::at(const int loc)
{
	return nstring[loc - 1];
}


bool astring::empty()
{
	if (nstring[0] == NULL && nlength == 1){ return true; }
	else { return false; }
}

void astring::swap(astring &from)
{
	size_t lena = nlength;

	size_t lenb = from.nlength;

	char *temp1 = new char[lena];

	char *temp2 = new char[lenb];

	for (size_t i = 0; i < (lena - 1); i++)
		temp1[i] = nstring[i];


	if (temp1[lena - 1] != '\0')
		temp1[lena - 1] = '\0';

	for (size_t j = 0; j < (lenb - 1); j++)
		temp2[j] = from.nstring[j];

	if (temp2[lenb - 1] != '\0')
		temp2[lenb - 1] = '\0';

	delete[] nstring;

	delete[]from.nstring;

	nstring = new char[lenb];

	nlength = lenb;

	from.nstring = new char[lena];

	from.nlength = lena;

	for (size_t k = 0; k < (lenb - 1); k++)
		nstring[k] = temp2[k];

	if (nstring[lenb - 1] != '\0')
		nstring[lenb - 1] = '\0';

	for (size_t l = 0; l < (lena - 1); l++)
		from.nstring[l] = temp1[l];

	if (from.nstring[lena - 1] != '\0')
		from.nstring[lena - 1] = '\0';

	delete[]temp1;

	delete[]temp2;
}

astring astring::substr(size_t index, size_t length)
{
	size_t size = length + 1;

	char* temp = new char[size];

	int j = 0;

	for (size_t i = index, j = 0; i < length; i++, j++)
		temp[j] = nstring[i];

	if (temp[size - 1] != '\0')
		temp[size - 1] = '\0'; 


	astring RET;

	RET.nlength = size;

	delete[]RET.nstring;

	RET.nstring = new char[size];

	for (size_t m = 0; m < (size - 1); m++)
		RET.nstring[m] = temp[m];

	if (RET.nstring[size - 1] != '\0'){ RET.nstring[size - 1] = '\0'; }

	return RET;

	delete[]temp;

}

bool operator == (astring& S1, astring& S2)
{
	if (S1.getnlength() == S2.getnlength())
	{
		size_t counter1 = S1.getnlength();

		size_t counter2 = 0;

		size_t i = 0;

		while (i != counter1)
		{
			if (S1.getnstring()[i] != S2.getnstring()[i])
			{
				counter2++;
			}

			i++;

		}

		std::cout << i << " " << counter2 << std::endl;

		if (counter2 != 0)
		{
			return false;
		}

		else
		{
			return true;
		}

	}

	else
	{
		return false;
	}

}


char& astring::operator [](size_t index) const
{

	assert(index >= 0 && index <= (nlength - 1));
	return nstring[index];

}

astring& astring::operator = (const astring& S)
{
	nlength = S.nlength;

	delete[] nstring;

	nstring = new char[nlength];

	for (size_t i = 0; i < (nlength - 1); i++)
		nstring[i] = S.nstring[i];

	nstring[(nlength - 1)] = '\0';


	return *this;
}

astring operator + (const astring& S1, const astring & S2)
{
	size_t size = (S1.getnlength() - 1) + (S2.getnlength() - 1) + 1;

	char * temp = new char[size];

	for (size_t i = 0; i < (S1.getnlength() - 1); i++)
		temp[i] = S1.getnstring()[i];

	size_t j = 0;

	for (size_t k = S1.getnlength() - 1, j = 0; k < (size - 1); k++, j++)
		temp[k] = S2.getnstring()[j];

	if (temp[size - 1] != '\0')
		temp[size - 1] = '\0';

	astring S3(temp);

	delete[] temp;

	temp = NULL;

	return S3;

}