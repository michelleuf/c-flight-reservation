#include<iostream>
#include <fstream>
#include<string.h>
#include<iomanip>
#define max 1000

using namespace std;

ifstream myfile;
string line;
int i;

int flight_count()   //we can determine how much the array size is
{
	int fl_count=0;
	myfile.open("flights.txt");
	if (myfile.is_open())
	{
		while (getline(myfile,line))
		{
			if (line.empty())
			{
				fl_count++;
			}
		}
	}
	myfile.close();
	return fl_count;
}

