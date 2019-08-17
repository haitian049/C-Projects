#include<iostream>
#include"astring.h"

using namespace string;

int main()
{

	astring C = astring();

	astring D = "beast houseace couch";

	//int c = (int)D.Charnum('a');

	int i = D.find("ace");

	//C.getline(std::cin, C, '\0');

	//std::cin >> C;

	//std::cout << C;

	//if(D.insert(D, 2)) 
		//std::cout << D;
	
	std::cout << i;

	//std::cin.ignore().get();

	system("pause");

	return 0;
}