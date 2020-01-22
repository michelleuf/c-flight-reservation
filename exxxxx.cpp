#include <iostream>

#include <string>

using namespace std;

int main()
{
    string line= "5 b ABCD";
    istringstream iss(line);

    do
    {
        iss >>seat_location[i].row_no>>seat_location[i].type;
        //seat_location[i].row_no << "Substring: " << subs << endl;
    } while (line);
}
