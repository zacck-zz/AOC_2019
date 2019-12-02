#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


vector<int> read_inputs(string filename);
vector<int> compute_code(vector<int> inputs);

int main() {
	//read inputs
	vector <int> inputs = read_inputs("input.txt");
	vector <int> outputs;

	for(int i = 0; i <= 99; i++){
		for(int k = 0; k <= 99; k++) {
			vector<int> inner_puts = inputs;
			inner_puts[1] = i;
			inner_puts[2] = k;
			outputs = compute_code(inner_puts);
			if(outputs[0] == 19690720) {
				cout << i << "," << k << endl;
			}
		}
	}

	outputs = compute_code(inputs);
	return 0;
}

vector<int> compute_code(vector<int> inputs) {
	vector<int> outputs = inputs;
	// init vector
	int tots = 0;
	while(tots < inputs.size()) {
		int opcode = outputs[tots];
		if(opcode != 99) {
			int replace = outputs[tots + 3];
			int first = outputs[tots + 1];
			int second = outputs[tots + 2];

			switch(opcode) {
				case 1:
					outputs[replace] = outputs[first] + outputs[second];
					tots += 4;
					break;
				case 2:
					outputs[replace] = outputs[first] * outputs[second];
					tots += 4;
					break;
			}
		}	else {
				break;
		}
	}

	return outputs;
}

vector<int> read_inputs(string filename) {
	vector<int> inputs;
	string line;
	ifstream input;
	//opem input file
	input.open(filename.c_str());
	while(getline(input, line, ',')) {
		int value;
		istringstream stream(line);
		stream >> value;
		inputs.push_back(value);
	}

	cout << "Values Read " << endl;

	return inputs;
}
