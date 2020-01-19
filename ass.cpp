#include<iostream>
#include <fstream>
#include<string.h>
#include<ass.h>
#include<iomanip>
#define max 1000

using namespace std;

// functions may use --------------------
void display_avail_flights();
void view_a_flight(string flight_no);
void file_read();

int flight_count();

//void view_flight();

//---------------------------------------
int fl_count;

ifstream myfile;
string line;
int i;

struct row
{
	char type;
	int seat_letter[6];
};


class flight
{
	private:
		string flight_no;
		string date_time;
		string dept_airport;
		string arrive_airport;
		row seat_location[60];
	
	public:
		void view_a_flight(string flight_no);
		void getdata ()
		{
			//read the file line by line and get data---- file should convert to an array------******
			flight_no=line;
			getline(myfile,line);
			date_time=line;
			getline(myfile,line);
			dept_airport=line;
			getline(myfile,line);
			arrive_airport=line;
			
			for (i=0;i<60;i++)		//if a row is missing it should be written as 0 in the seat_location array
			{
				getline(myfile,line);
	//			if (seats)
				seat_location[i].type=line[0];			//how this should be done
			//	seat_location[i].seat_letter[0];
			}
			
		}
		


};


flight flarray[fl_count];

void file_read()
{
	myfile.open("flights.txt");
	if (myfile.is_open())
	{
		while (getline(myfile,line))
		{
			for (int i=0; i<max;i++)
			{
				flarray[i].getdata();
			}
		}
	}
}

int main()
{
	//myfile.open("flights.txt");
	
	int f=flight_count(); 
	//cout<<"flcount is "<<f<<endl;
	
	
	int opt,no_of_seats;
	string flight_no,seat_loc;
	while (1)
	{
		cout<<"-------------------------------------"<<endl<<"Virgin Airline seat reservation system"<<endl<<"-------------------------------------"<<endl<<"welcome customer !"<<endl<<endl;
		
		cout<<"1>> Display availablle flights"<<endl<<"2>> View flight"<<endl<<"3>> Seat Availability"<<endl<<"4>> Seat booking"<<endl<<"5>> Exit"<<endl<<endl;
		
		cout<<"Enter choice : "<<endl;
		cin>>opt;
		
  		
  		
  		
		switch (opt)
		{
		case 1: 
		//	display_avail_flights();
			break;
		case 2: 
			cout<<"enter the flight_no : ";
			cin>>flight_no;
			//if flight no match with avail flights
				//	--------read the file
				//then show avail seat numbers with classes 
				//view_flight();
				
			// else if 
				//cout<<"Error!! No available seats in this flight"<<endl;
			break;
		case 3:
			cout<<"enter the flight_no : ";
			cin>>flight_no;
			cout<<"no.of seats required: "  ;
			cin>>no_of_seats;
 		break;
 		case 4:
		 	cout<<"enter the flight_no : ";
			cin>>flight_no;
			cout<<"enter the seat location: "  ;
			cin>>seat_loc;
 		break;
 		case 5: return 0;
 		break;
		default:"error again enter key between 1-4";
		}
		
	}
	
	return 0;
}
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

void display_avail_flights()
{
	//read first line of each paragraph and detect the flight numbers
	// then display it 
}
void flight::view_a_flight(string flight_no)
{
	//find the corresponding data set
	for (i=0;i<1000;i++)
	{
		if (flarray[i].flight_no==flight_no)
		{
			cout<<"total no of avail seats must display here";
			cout<<flarray[i].dept_airport;
			cout<<flarray[i].arrive_airport;
			cout<<flarray[i].date_time;
		}
	}
	cout<<endl;
}
