#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Задача 1
Напишете програма за четене на файл, наречен "input.txt", записваща в нов файл, наречен "output.txt" и направете някаква операция и текста.
transfer()

Задача 2
Напишете програма за четене на два файла "input1.txt" и "input2.txt", която изкарва на екрана редовете,
които са различни в 2та файла, като добавя "<", ако редът е от "input1.txt", или ">", ако редът е от "input2.txt".
compare()

Additional tasks
Задача 3
Имплементирайте функция с прототип void printLastLines(int numLastLines, char* filename).

Задача 4
Намерете размерът на текстов файл в байтове.
findSize()
*/


const unsigned short SIZE = 100;

void transfer(const char* source, const char* destination)
{
	ifstream input(source);
	ofstream output(destination);

	if (input.is_open() && !input.fail() && !output.fail())
	{
		char buffer;
		while (!input.eof())
		{
			buffer = (char)input.get();

			if ((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z'))
			{
				output << buffer;
			}
		}

		/*string buffer;
		char* str = nullptr;
		while (!input.eof())
		{
		input.getline(str, SIZE);
		output << str;
		}*/
	}

	input.close();
	output.close();
}

void compare(const char* first, const char* second)
{
	bool diff1 = true, diff2 = true;
	ifstream firstFile(first);
	ifstream secFile(second);
	if (firstFile.is_open() && secFile.is_open())
	{
		char buf1[SIZE] = { '\0' };
		char buf2[SIZE] = { '\0' };
		while (!firstFile.eof() && !firstFile.fail() && !secFile.fail())
		{
			firstFile.getline(buf1, SIZE);
			//bool different = true;
			secFile.seekg(ios::beg);
			while (!secFile.eof())
			{
				secFile.getline(buf2, SIZE);
				if (strcmp(buf1, buf2) == 0)
				{
					diff1 = false;
				}
			}
			if (diff1)
			{
				cout << "< " << buf1 << "\n";
				cout << "Buffer 1 is different\n";
			}
		}

		secFile.seekg(ios::beg);
		bool end = secFile.eof();
		while (!secFile.eof() && !secFile.fail() && !firstFile.fail())
		{
			secFile.getline(buf2, SIZE);
			//bool different = true;
			firstFile.seekg(ios::beg);
			while (!firstFile.eof())
			{
				firstFile.getline(buf1, SIZE);
				if (strcmp(buf2, buf1) == 0)
				{
					diff2 = false;
				}
			}
			if (diff2)
			{
				cout << "> " << buf2 << "\n";
				cout << "Buffer 2 is different\n";
			}
		}
	}

	if (!diff1 && !diff2)
	{
		cout << "=\n";
		cout << "The 2 buffers are the same\n";
	}

	firstFile.close();
	secFile.close();
}

void printLastLines(int numLastLines, char* filename)
{
	ifstream inputStream(filename);
	if (inputStream.is_open())
	{
		int countLines = 0;
		char line[SIZE];
		// Get count of lines
		while (!inputStream.eof())  //eof = end of file
		{
			inputStream.getline(line, SIZE);
			countLines++;
		}
		inputStream.seekg(ios::beg); //beg = pointer at the beggining of the file
		// read until remaining *numLastLines*, then read and print
		while (!inputStream.eof())
		{
			inputStream.getline(line, SIZE);
			if (countLines <= numLastLines)
			{
				cout << line << '\n';
			}
			countLines--;
		}
		inputStream.close();
	}
}

void findSize(char* filename)
{
	std::ifstream stream(filename, std::ios::in | std::ios::ate); //ate = pointer after the last char of the file
	if (!stream) //if stream isn't open, display error and quit
	{
		std::cout << "Error file : " << filename << " didn't load!" << std::endl;
		return;
	}
	std::cout << "Lenght of file in bytes : " << stream.tellg() << std::endl; //get current position of get pointer, int txt files every symbol is char. 1 char = 1 byte
	stream.close();
}

int main()
{
	//transfer("input.txt", "output.txt");
	//compare("input1.txt", "input2.txt");
	//printLastLines(3, "input1.txt");
	//findSize("file.txt");

	string name = "Pesho";
	string address = "Varna, Tsar Osvoboditel Str. 23";

	cout << "name: " << name << " ";
	cout << "address: " << address << "\n";

	ofstream output("testOut.txt");
	output << "name: " << name << " " << "address: " << address << "\n";
	output.close();

	return 0;
}

