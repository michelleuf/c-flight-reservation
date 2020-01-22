#include<iostream>
using namespace std;
int main()
{
string row="ABCD";
cout<<row<<endl;
int i;	
char seatno;
cin>>seatno;
	
for (i=0;i<row.size();i++)
{
	if(seatno==row[i])
	{
	row.erase(i,1);                      
	cout << row << '\n';
	break;	
	}
	
}
}
