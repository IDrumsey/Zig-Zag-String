//Purpose : Draw any given string in a zig-zag manner given a specified number of rows
//Date : April 14, 2020

//Libraries
#include <iostream>
#include <string>

using namespace std;

//Functions
string getString() {
	string temp;
	cout << "String : ";
	
	getline(cin, temp);
	
	return temp;
}

int getRows(string mystring) {
	cout << "string length : " << mystring.length() << endl;
	int temp;
	do {
		cout << "Rows : ";
		cin >> temp;

		if (temp > mystring.length())cout << "NumRows is too large! There are only " << mystring.length() << " characters!\n";
	} while ( temp > mystring.length());
	
	return temp;
}

void DrawZigZagStyle(string myString, int Rows) {
	int size = myString.length();
	int n = Rows;

	int verticalIterations = Rows;

	int HorizontalIterations = ((size - 1) - ((size - 1) % (2 * (n - 1)))) / (2 * (n - 1)) * (n - 1) + 1 + ((((size - 1) % (2 * (n - 1))) / n) * ((size - 1) % (n - 1)));


	for (int i = 0; i < verticalIterations; i++) {
		for (int j = 0; j < HorizontalIterations; j++) {
			
			if (((j%(n-1) == 0) && (j < ((size-1)/(2*(n-1)))*(n-1))) || ((j == ((size-1)/(2*(n-1)))*(n-1)) && i <= ((size-1)%(2*(n-1)))) || ((((j+i)%(n-1)) == 0) && ((i <= (size-1)%(2*(n-1))) || (j < ((size-1)/(2*(n-1)))*(n-1))))) {
				float x = (2 * (n - 1)) * (j + i) / (n - 1);
				int pos = x - i;
				cout << myString[pos];
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}



//Driver
int main() {
	
		
		string myString = getString();
		
		int rows = getRows(myString);

		 
		cout << "======================================================\n";
		if (rows == 1)cout << myString << endl;
		else
		DrawZigZagStyle(myString, rows);
		cout << "======================================================\n";

		system("pause");
	
	return 0;
}