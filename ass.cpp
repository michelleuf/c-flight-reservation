#include<iostream>
#include <fstream>
#include<string.h>
#include <sstream>
#include<iomanip>


#define max 50

using namespace std;

// functions may use --------------------
void file_read();
int flight_count();

//variables may use ---------------------
ifstream myfile;
string line;
int i;
int fl_count;

// structure of a given seat row --------
struct row
{
	string row_no;
	char type;
	string seat_letters;
};

// flight class -------------------------
class flight
{
	private:
//		string flight_no;
		string date_time;
		string dept_airport;
		string arrive_airport;
		row seat_location[60];
	
	public:
		void view_a_flight(string flight_no);
		friend void display_avail();
		void getdata();
		friend void update_seats(string flight_no, string seat_no);
		friend void avail_seats();
		
};

//creating the array for flight objects
flight flarray[max];



// function set -----------------------------------------

void file_read()		//read the file
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
//-----------------------------------------------------------------



void flight::getdata()
		{
			//read the file line by line and get data---- file should convert to an array------******
			flight_no=line;
			getline(myfile,line);
			date_time=line;
			getline(myfile,line);
			dept_airport=line;
			getline(myfile,line);
			arrive_airport=line;
			getline(myfile,line);
			
			istringstream iss(line);
			for (i=0;i<60;i++)							
			{
				iss >>seat_location[i].row_no>>seat_location[i].type>>seat_location[i].seat_letters;
        	}
						
		}
		
		
//-----------01--------02-------------------------
void display_avail()
{
	//for (i=0;i<fl_count;i++)
	//{
		cout<<"flight_no : "<<flarray[i].flight_no<<endl;
		cout<<"date and time: "<<flarray[i].date_time<<endl;
		cout<<"dept airport: "<<flarray[i].dept_airport<<endl;
		cout<<"arrival airport: "<<flarray[i].arrive_airport<<endl;
		//avail seats with classes
	//}
}

//----------------------------------------------
//----------------03----------------------------
void view_a_flight(string flight_no,int no_of_seats)
{
	//find the corresponding data set
	for (i=0;i<fl_count;i++)
	{
		if (flarray[i].flight_no==flight_no)
		{
			cout<<"total no of avail seats must display here";
			cout<<flarray[i].dept_airport;
			cout<<flarray[i].arrive_airport;
			cout<<flarray[i].date_time;
		break;	
		}
	}
	
	cout<<endl;
}



//---------------------------------------------
//--------04--------------------------------------
void update_seats(string flight_no,string seat_no)
{
	for (i=0;i<fl_count;i++)
	{
		if (flight_no==flarray[i].flight_no)
		{
			/*for (j=0;j<flarray.size();j++)
			{
				if (seat_no[4]==" ")
				{
					//////
				}
			if(seatno[6]==seat_location[i].seat_letters)
			{
				seat_location.seat_letters.erase(i,1);     //in here i have to give only ABC then it delete A    cant give 50 E B             
				cout << row << '\n';
				break;	
			}
			}*/
		
		}
		else if 
		{
			cout<<"Error !!!! Cant find the flight"<<endl;
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
			for (i=0;i<flarray.size();i++)
			{
				display_avail();
			}
			break;
		case 2: 
			file_read();
			cout<<"enter the flight_no : ";									//then show avail seat numbers with classes 
			cin>>flight_no;
			
			if(flight_no==flarray[i].)
			//view_flight();
				
			// else if 
				//cout<<"Error!! No available seats in this flight"<<endl;
			break;
		
		case 3:
			cout<<"enter the flight_no : ";
			cin>>flight_no;
			cout<<"no.of seats required: "  ;
			cin>>no_of_seats;
			// avail_seats();
 		break;
 		
		 case 4:
		 	cout<<"enter the flight_no : ";
			cin>>flight_no;
			cout<<"enter the seat location: "  ;
			cin>>seat_loc;
			//update_seats(flight_no,seat_loc);
 		break;
 		
		 case 5: return 0;
 		break;
		default:"error again enter key between 1-4";
		}
		
	}
	
	return 0;
}

