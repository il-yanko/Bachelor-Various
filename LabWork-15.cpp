#include <iostream>
#include <conio.h>
using namespace std;
const int amount=5;
struct Flight
{
	int Number,Date,Space,Price;
	char *Type;
};
Flight plane[amount] = {{9,15,10,300,"Hawk"},{4,20,5,450,"Nightingale"},{27,10,20,210,"Dream"},{12,25,40,150,"Hawk"},{8,5,20,800,"Dream"}};
void outputNormal(int id)
{
	cout << "Number of plane: "<< plane[id].Number << endl;
	cout << "Date of flight: "<< plane[id].Date << endl;
	cout << "There are: " << plane[id].Space << " empty seats there" << endl;
	cout << "The price of flight is  "<<plane[id].Price <<" dollars"<< endl;
	cout << "This is plane of the type " << plane[id].Type << endl;
	cout << endl;
}
void outputSorted()
{
	int date, used=0;
	int permitted[amount] = {}, sorted[amount] = {};

	cout << "Please, enter date of flight" << endl;
	cin >> date;
	for (int i=0; i<amount; i++)
	{
		if (plane[i].Date > date)
		{
			permitted [used] = i;
			used++;
		}
	}
	int max = 10000, min, anchor;
	
	for (int j=0; j<used; j++)
	{
		min = max;
		for (int i=0; i<used; i++)
			if (plane[permitted [i]].Date < min)
			{
				min = plane[permitted [i]].Date;
				anchor = i;
			}
		outputNormal (permitted [anchor] );
		plane[permitted [anchor] ].Date = max;
	}
}
void main (void)
{
	outputSorted();
	_getch();
}
