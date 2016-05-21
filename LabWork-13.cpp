#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int GoodSize()
{
	int size;
	cout << "Input size of matrix for array:" << endl;
	cin.clear(); cin >> size;
	if (size<=1)
		size = 1;
	float mod = 500 % size;
	while (!(mod==0) || (size==1) )
	{
		cin.clear();
		cout<<"Incorrect size was entered. Please, try again."<<endl;
		cin>>size;
		mod = (float) (500 % size);
	}
	return size;
}
int Print(int* a, int hgt)
{
	int wdt;
	if (hgt==1)
		hgt = GoodSize();
	wdt = 500 / hgt;
	for (int h=0; h<hgt; h++)
	{
		for (int w=0; w<wdt; w++)
			cout << a[wdt*h+w] << " ";
		cout << endl;
	}
	return hgt;	
}
bool Check(int*arr)
{
	const int size = 500;
	bool check;
	for (int i=0; i<(size-1); i++)
	{
		if (arr[i]<=arr[i+1])
			check = 1;
		else
		{
			check = 0;
			break;
		}
	}
	return check;
}
double QSort (int*a, int b, int e, int hgt, bool inception)
{ //b - base ptr; e - end ptr; inception - fact of being called during the other call
  int l = b, r = e;
  int cur = a[(l + r) / 2];
  while (l <= r)
  {
    while (a[l] < cur)
      l++;
    while (a[r] > cur)
      r--;
    if (l <= r)
      swap (a[l++], a[r--]);
  }
  if (b < r)
    QSort (a, b, r, hgt, 1);
  if (e > l)
    QSort (a, l, e, hgt, 1);
  double time = 0;
  if (Check(a) && (inception==0))
  {
	  Print(a,hgt); //hgt - amount of lines in our matrix
	  cout << "Array is already sorted "<< endl;
	  time = clock();
  }
  return time;
}
void ReWork (int* str)
{
	int hgt = Print(str,1); //given array
	const int size = 500;
	Check (str);
	double startTime = clock();
	double endTime	= QSort (str, 0, size-1, hgt, 0); // function return absolute time when sort stops
	double time = endTime - startTime;
	cout << "Runtime of sorting procedure is " << time / (double)CLOCKS_PER_SEC << " seconds";
}
void Work()
{
	const int size = 50;
	int str[size] = {};
	cout << "RECORDING array with RANDOM numerics..." << endl;
	srand (time(0));
	for (int i=0; i<size; i++)
	{
		str[i] = rand() % 51; //recording numerics from 0 to 50
		cout << (i+1) << " element is " << str[i] << "\n";
	}
	ReWork (str);
}
int main()
{
	Work();
	_getch();
	return 0;
}
