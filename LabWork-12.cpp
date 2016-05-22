#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using std::cout;
using std::cin;
using std::endl;

void CreateSpace(int size)
{
	char *part =" ";
	char rez[60]="";
	for (int i=0; i<(size+1); i++)
	{
		int c = i + 1;
		rez[c] = part[0];
	}
	for (int b=0; b<size; b++)
		cout<<rez[b];
}
void ReWork (char* txt)
{
	char *space = " ";
	int count = 0;
	int length = strlen(txt);
	cout << "The length of the string is "<< length << endl;
	for (int i=0; i<length; i++)
	{
		if (txt[i]==space[0])
			count++;
	}
	int WordsSize = length - count;
	int WordsAmount = count + 1;
	int SpaceSize=1;
	for (; (WordsSize+count*SpaceSize)<60; SpaceSize++);
	cout << "The amount of words in text is " << WordsAmount << endl;
	cout << "We need " << SpaceSize << " symbols of gap between each word\n" << endl;
	for (int z=0; z<(count+1); z++)
	{
		if (z < (count))
		{
			if (z == 0)
				cout << strtok(txt,space);
			else
				cout << strtok(NULL,space);
			CreateSpace(SpaceSize);
		}
		else
			cout << strtok(NULL,space);
	}
}

void Work (void)
{
	char source[60] = {};
	cout << "\tPlease, enter your text: ";
	gets(source);
	ReWork(source);
}
void main(void)
{
	Work();
	_getch();
}
