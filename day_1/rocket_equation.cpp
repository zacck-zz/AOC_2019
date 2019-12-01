#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int calculate_fuel(int mass);
int module_fuel(int mass);

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

		int fuel = module_fuel(value);

		cout << "Required fuel is: " << fuel << endl;
		total_fuel += fuel;
	}

	cout  << "Total fuel: " << total_fuel << endl;
	return 0;
}


/*
 * Find module fuel taking into account fuel mass
 *
 */
int module_fuel(int mass) {
	int module_fuel, intermediate_fuel;

	int fuel_fuel = 0;

	int fuel;

	//find module fuel
	module_fuel = calculate_fuel(mass);

	//find initial intermediate fuel needed
	intermediate_fuel = calculate_fuel(module_fuel);

	//recursively find fuel needed for fuel
	while(true){
		if(intermediate_fuel > 0) {
			fuel_fuel += intermediate_fuel;
			intermediate_fuel = calculate_fuel(intermediate_fuel);
		} else {
			break;
		}
	}

	return module_fuel + fuel_fuel;
}


/*
 * Find fuel needed for a certain amount of mass
 */
int calculate_fuel(int mass) {
	int fuel;

	fuel = (mass/3) - 2;

	return fuel;
}
