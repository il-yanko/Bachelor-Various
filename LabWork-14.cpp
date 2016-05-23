#include <iostream>
#include <conio.h>
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

bool InputCheck()
{
	bool logTry, reply;
	cin >> reply;
	while ((reply!=0)&&(reply!=1))
	{
		cin.clear();
		cout << "Incorrect answer was entered. Please, try again."<<endl;
		cin >> reply;	
	}
	logTry=reply;
	return logTry;
}

void Work()
{
	FILE *F1, *F2, *F3;
	char *ar1, *ar2;
	long size1, size2, size3;
	F1 = fopen("D:\\TEST\\Test.txt", "r+b");
		char name[20],fnew[20], text[50];
	cout << "Please, enter file name: ";
	cin >> name;
	if (fopen(name, "r+b") == NULL)
	{
		cout << "There is not such file in the memory.\n" << "Creating new file..." << endl;
		F2 = fopen (name, "w+b");
	}
	else
		cout << "Old file was entered..."<< endl;
	cout << "Do u want to record an old file with other name?\n\n"<<"1 - agreed"<< endl <<"0 - disagreed\n"<< endl;

	if (InputCheck()==1)
	{
		F2 = fopen (name, "r+b");
		cout << "Renaming of old <"<< name <<"> is executing now..."<< endl;
		cout << "Enter new name: "; cin >> fnew;
		F3 = fopen (fnew, "w+b");
		size3 = FindSize (F2); //size of file for rewriting
		fseek(F2, 0, SEEK_SET); 
		ar2 = new char [size3];
		Load(ar2,F2,size3); //recording content of file on array
		fwrite(ar2, sizeof(char), size3, F3);
		delete[]ar2;
		fclose(F3);
		fclose(F2);
		F2 = fopen (name, "wb");		
		cout << "Enter the new text for file: "; cin >> text;
		size2 = (int) strlen(text);
		fwrite(text, sizeof(char), size2, F2);
	}
	else
	{
		remove (name);
		F2 = fopen (name, "wb");
		cout << "Old <"<< name <<"> has been deleted"<< endl; 
		cout << "Enter the new text for file: "; cin >> text;
		size2 = (int) strlen(text);
		fwrite(text, sizeof(char), size2, F2);
		cout << "Old file was completely rewrited." << endl; 
	}
	
	size1 = FindSize (F1);
	cout << "size of the 1st file is " << size1 << endl;
	cout << "size of the 2nd file is " << size2 << endl;
	fseek(F1, 0, SEEK_SET); // moving pointer to the origin of the file
	ar1 = new char [size1];
	Load(ar1,F1,size1);
	GreatPrint (ar1, size1, ar2, size2);
	cout << endl << "Executive process is running now ..."<< endl;
	_getch();
	fclose(F1);
	fclose(F2);
	F1 = fopen("D:\\TEST\\Test.txt", "w+b");
	F2 = fopen(name, "w+b");
	fwrite(ar1, sizeof(char), size1, F2);
	fwrite(text, sizeof(char), size2, F1);
	delete []ar1;
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
