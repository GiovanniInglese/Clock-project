#pragma once
#include<ioStream>
#include<string>
#include<cstring>


using namespace std;

unsigned int hour;
unsigned int minute;
unsigned int second;

string twoDigitString(unsigned int n) {
	string digit_str = "";          // Assignes numbers 0-59 to a string
	if (n < 10) {    // If the digit is > 10 or 0 - 9 it will add a 0
		digit_str += "0";

	}
	digit_str += to_string(n);  // the digit is called to append to a 2 digit string 
	return digit_str;   // Returns a two digit string

}

string nCharString(size_t n, char c) {
	string char_str = "";         // initialized a string to make a char string
	for (size_t i = 0; i < n; ++i) {  // Loops to how ever many times the charater is called and prints that many characters
		char_str += c;     // assignes and appends characters to the string
	}
	return char_str;
	

}
void printMenu() {  // Prints the required choice menu using the function nCharString
	cout << nCharString(27, '*') << endl;
	cout << "*" << nCharString(5, ' ') << "1 - Add One Hour" << nCharString(4, ' ') << "*" << endl;
	cout << "*" << nCharString(5, ' ') << "2 - Add One Minute" << nCharString(2, ' ') << "*" << endl;
	cout << "*" << nCharString(5, ' ') << "3 - Add One Second" << nCharString(2, ' ') << "*" << endl;
	cout << "*" << nCharString(5, ' ') << "4 - Quit Program" << nCharString(4, ' ') << "*" << endl;
	cout << nCharString(27, '*') << endl;
	cout << endl;





}
string formatTime24(unsigned int hr, unsigned int min, unsigned int sec) {
	string digit_str = "";    // initialize a string to create the clock string
	digit_str += twoDigitString(hr) + ":" + twoDigitString(min) + ":" + twoDigitString(sec);   //used the twoDigitString function to get hours mins and seconds as two digits and formats it into clock format
	return digit_str;  // Returns the string as clock format
}
string formatTime12(unsigned int hour,unsigned int min, unsigned int sec) {
	string digit_str = "";   // intializes a string for the 12 hour clock
	if (hour == 0) {   // if the hour is 0 the string will append a 12: because 12 hour clocks do nto contain a zero hour
		digit_str += "12:";
	}
	else if (hour <= 12) {  // Checks if the hours are in range and do not excede 12 
		digit_str += twoDigitString(hour) + ":";  // adds the hour to the string
	}
	else {
		digit_str += twoDigitString(hour - 12) + ":";  //Keeps hours printing after 12 and maintains between 1-12
	}
	digit_str += twoDigitString(min) + ":"; // adds the minutes to the string
	digit_str += twoDigitString(sec);     // adds the seconds to the string
	if (hour < 12) {
		digit_str += " AM"; //for input purposes if output is < 12 it is morning time in 24hr format
	}
	else {
		digit_str += " PM";  // 13 and up are afternoon hours 
	}
	return digit_str;
}


unsigned int getMenuChoice(unsigned int maxChoice) {  // Promps the user and obtains user input for the menu loop
	unsigned int choice = 0;
	while (choice < 1|| choice > maxChoice) {
		cout << "Select a number 1 through 4" << endl;
		cin >> choice;


	}
	return choice;
}







void displayClocks(unsigned int hr, unsigned int min, unsigned int sec) {   // Prints out the clock based on the format specifications
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, ' ') << formatTime12(hr, min, sec) << nCharString(7, ' ') << " *" << nCharString(3, ' ');
	cout << "*" << nCharString(8, ' ') << formatTime24(hr, min, sec) << nCharString(8, ' ') << " *" << endl;
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}
unsigned int getHour() { // Accessors for gettinga and setting the hour
	return hour;
}
void setHour(int hr) {  
	hour = hr;
}
unsigned int getMinute() { // Accessors for getting and setting the minute
	return minute;
}
void setMinute(int min) {
	minute = min;

}
unsigned int getSecond() { // Accessors for getting and setting the seconds
	return second;
}
void setSecond(int sec) {
	second = sec;

}
void addOneHour() {   //Function for adding an hour
	if (getHour() < 23) {
		setHour(getHour() + 1);
	}
	else {     //If the hour excedes 23 it reverts back to 0
		setHour(0);
	}
}
void addOneMinute() {    // Function for adding a minute
	if (getMinute() < 59) {   // Checks if the minute is < 59 otherwise it will revert back to 0 like clocks do
		setMinute(getMinute() + 1);
	}
	else {
		setMinute(0); //Reverts minutes back to 0 and adds an hour
		addOneHour();
	}
}
void addOneSecond() {  // Fnction for adding a second
	if (getSecond() < 59) {   //Checks if seconds is < 59 and adds a second 
		setSecond(getSecond() + 1);
	}
	else {
		setSecond(0);  //reverts back to 0 if seconds will excede 59
		addOneMinute(); // Adds a minute to the clock if adding a second excedes 59

	}
}





