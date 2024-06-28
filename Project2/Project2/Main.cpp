#include "header.h"



int main() {

	string userInput = "X";
	int mode;

	LinkedList<int> linkedList;

	cout << "1 - Regular single linked list" << endl;
	cout << "2 - Stack format" << endl << endl;
	cout << "==> ";
	cin >> mode;

	if (mode == 1) {



		while (userInput != "Q") {

			cout << "Pick an option: " << endl << endl;
			cout << "1 - Push front" << endl;
			cout << "2 - Push back" << endl;
			cout << "3 - Pop front" << endl;
			cout << "4 - Pop back" << endl;
			cout << "5 - Return front" << endl;
			cout << "6 - Return back" << endl;
			cout << "7 - Empty list" << endl;
			cout << "8 - Insert value" << endl;
			cout << "9 - Remove value" << endl;
			cout << "10 - Find value" << endl;
			cout << "11 - Print values" << endl;
			cout << "Q - Quit" << endl << endl;

			cout << "==> ";
			cin >> userInput;

			if (userInput == "1") {
				int value = 0;
				cout << endl << "Enter a value to front push ==> ";
				cin >> value;
				linkedList.push_front(value);
				cout << "DEBUG: " << linkedList.front() << endl;
			}

			else if (userInput == "2") {
				int value = 0;
				cout << endl << "Enter a value to back push ==> ";
				cin >> value;
				linkedList.push_back(value);
				cout << "DEBUG: " << linkedList.back() << endl;
			}

			else if (userInput == "3") {
				int value = linkedList.pop_front();
				cout << endl << value << " has been popped." << endl;
			}

			else if (userInput == "4") {
				int value = linkedList.pop_back();
				cout << endl << value << " has been popped." << endl;
			}

			else if (userInput == "5") {
				cout << endl << linkedList.front() << " is the front value." << endl;
			}

			else if (userInput == "6") {
				cout << endl << linkedList.back() << " is the back value." << endl;
			}

			else if (userInput == "7") {
				linkedList.empty();
			}

			else if (userInput == "8") {
				int value, index = 0;
				cout << endl << "Enter a value ==> ";
				cin >> value;
				cout << endl << "Enter an index ==> ";
				cin >> index;
				linkedList.insert(index, value);
			}

			else if (userInput == "9") {
				int value = 0;
				bool wasDeleted;
				cout << endl << "Enter a value to delete ==> ";
				cin >> value;
				wasDeleted = linkedList.remove(value);

				if (wasDeleted == true) {
					cout << endl << "Value was deleted." << endl;
				}
				else {
					cout << endl << "Unable to delete." << endl;
				}
			}

			else if (userInput == "10") {
				int value = 0;
				cout << endl << "Enter a value to find ==> ";
				cin >> value;
				cout << endl << value << " is at index " << linkedList.find(value) << endl;
			}

			else if (userInput == "11") {
				cout << endl;
				linkedList.printValues();
				cout << endl;
			}

			else {
				cout << endl << "Invalid option." << endl;
			}

			cout << endl << endl;

		}
	}

	else if (mode == 2) {

		while (userInput != "Q") {
			cout << "1 - Push front" << endl;
			cout << "2 - Pop front" << endl;
			cout << "3 - Return front" << endl;
			cout << "4 - Return number of values" << endl;
			cout << "5 - Return average" << endl;
			cout << "6 - Print values" << endl;
			cout << "Q - Quit" << endl << endl;

			cout << "==> ";
			cin >> userInput;

			if (userInput == "1") {
				int value = 0;
				cout << endl << "Enter a value to front push ==> ";
				cin >> value;
				linkedList.push_front(value);
				cout << "DEBUG: " << linkedList.front() << endl;
			}

			else if (userInput == "2") {
				int value = linkedList.pop_front();
				cout << endl << value << " has been popped." << endl;
			}

			else if (userInput == "3") {
				cout << endl << linkedList.front() << " is the front value." << endl;
			}

			else if (userInput == "4") {
				int numItems = linkedList.getNumItems();

				if (numItems > 0) {
					cout << endl << "There are " << linkedList.getNumItems() << " items." << endl;
				}

				else {
					cout << endl << "The stack is empty." << endl;
				}
			}

			else if (userInput == "5") {

				linkedList.findAverage();
				
			}

			else if (userInput == "6") {

				linkedList.printValues();
			}
		}
	}

	return 0;
}
