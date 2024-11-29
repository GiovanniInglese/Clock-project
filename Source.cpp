#include "Header.h"
#include <iostream>
using namespace std;

int main() {                            // Gets input on the current time
	cout << "What is the hour?" << endl;
	cin >> hour;
	cout << "What is the minute?" << endl;
	cin >> minute;
	cout << "What is the second?" << endl;
	cin >> second;

	displayClocks(getHour(), getMinute(), getSecond());  // Dispays both clocks on the screen
	unsigned int choice = 0;
	while (choice != 4) {  // While the choice does not equal 4 or quit you can change the time to your specifications
		printMenu();
		choice = getMenuChoice(4);
		switch (choice) {
		case 1:                // will add one hour to the clock
			addOneHour();
			break;

		case 2: // Will add one minute to the clock
			addOneMinute();
			break;
		case 3: // Will add one second to the clock
			addOneSecond();
			break;
		case 4:  // Will quit the program
			break;
		}
		displayClocks(getHour(), getMinute(), getSecond()); // displays the updated clock
	}
	



}
