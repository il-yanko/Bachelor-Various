#include <iostream>
#include <conio.h>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

int FindSize (FILE* A)
{
	fseek(A, 0, SEEK_END); // moving pointer to the end
	int size = ftell(A);
	return size;
}

void Load (char *ar, FILE* F, int size)
{
	for (int i = 0; i<size; i++)
		ar[i] = fgetc(F);
}

void PrintArray (char* ar, const char* number, int size)
{
	cout << endl;
	cout << "Content of the "<< number <<" binary file: " << endl;
	for(int i=0; i<size; i++)
		cout << ar[i];
	cout<<endl;
}

void DeleteTwo (char *fir,char *sec)
{
	delete[]fir;
	delete[]sec;
}
void GreatPrint (char* fir, int size1, char* sec, int size2)
{
	const char* one ="first";
	const char* two ="second";
	PrintArray (fir, one, size1);
	PrintArray (sec, two, size2);
}

void Work()
{
	FILE *F1, *F2;
	char *ar1, *ar2;
	long size1, size2;
	F1 = fopen("D:\\TEST\\First.txt", "r+b");
	F2 = fopen("D:\\TEST\\Second.txt", "r+b");
	size1 = FindSize (F1);
	size2 = FindSize (F2);
	cout << "size of the 1st file is " << size1 << endl;
	cout << "size of the 2nd file is " << size2 << endl;
	fseek(F1, 0, SEEK_SET); // moving pointer to the origin of the file
	fseek(F2, 0, SEEK_SET);
	ar1 = new char [size1];
	ar2 = new char [size2];
	Load(ar1,F1,size1);
	Load(ar2,F2,size2);
	GreatPrint (ar1, size1, ar2, size2);
	cout << endl << "Executive process is running now ..."<< endl;
	_getch();
	fclose(F1);
	fclose(F2);
	F1 = fopen("D:\\TEST\\First.txt", "w+b");
	F2 = fopen("D:\\TEST\\Second.txt", "w+b");
	fwrite(ar1, sizeof(char), size1, F2);
	fwrite(ar2, sizeof(char), size2, F1);
	DeleteTwo(ar1,ar2);
	ar1 = new char [size2];
	ar2 = new char [size1];
	fseek(F1, 0, SEEK_SET);
	fseek(F2, 0, SEEK_SET);
	Load(ar1,F1,size2);
	Load(ar2,F2,size1);
	GreatPrint (ar1, size2, ar2, size1);
	DeleteTwo(ar1,ar2);
	fclose(F1);
	fclose(F2);
}
void main()
{
	Work();
	_getch();
}
