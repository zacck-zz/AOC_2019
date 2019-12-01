#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int calculate_fuel(int mass);


int main() {
	ifstream input;
	//open the file with the data
	input.open("input.txt");
	string line;

	// total fuel
	int total_fuel = 0;
	while(getline(input, line)){
		int value;
		//read line into input string stream
		istringstream stream(line);
		// input string stream into int
		stream >> value;

		cout << "Mass is: " << value << endl;

		int fuel = calculate_fuel(value);

		cout << "Required fuel is: " << fuel << endl;
		total_fuel += fuel;
	}

	cout  << "Total fuel: " << total_fuel << endl;
	return 0;
}

int calculate_fuel(int mass) {
	int fuel;

	fuel = (mass/3) - 2;

	return fuel;
}
