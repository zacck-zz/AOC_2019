#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>
using namespace std;

vector< tuple<int, int, int> > plot_ordinates(vector<string> scales);

int main() {
	vector<string> first_scales;
	vector<string> second_scales;

	ifstream input;
	input.open("line_one.txt");
	string line;
	while(getline(input, line, ',')) {
		first_scales.push_back(line);
	}

	ifstream input2;
	input2.open("line_two.txt");
	string line2;
	while(getline(input2, line2, ',')){
		second_scales.push_back(line2);
	}

	cout << "Input Read" << endl;

	vector<tuple<int, int, int>> first_positions = plot_ordinates(first_scales);
	vector<tuple<int, int, int>> second_positions = plot_ordinates(second_scales);

	vector<int> neighbours;
	vector<int> meet_sums;
	vector<tuple<int, int, int>> first_intersections;
	vector<tuple<int, int, int>> second_intersections;
	for(auto f : first_positions){
		for(auto s : second_positions){
			int x1, x2, y1, y2;
			x1 = get<0>(f);
			x2 = get<0>(s);
			y1 = get<1>(f);
			y2 = get<1>(s);
			if(x1 == x2 && y1 == y2){
					neighbours.push_back(abs(x1 + y1));
					first_intersections.push_back(f);
					second_intersections.push_back(s);
			}
		}
	}

	for(int i = 0; i < first_intersections.size(); i++){
		int steps1 = get<2>(first_intersections[i]);
		int steps2 = get<2>(second_intersections[i]);
		meet_sums.push_back(steps1 + steps2);
	}


	sort(meet_sums.begin(), meet_sums.end());
	cout << "Least steps is: " << meet_sums[0] << " steps away" << endl;



	sort(neighbours.begin(), neighbours.end());
	cout << "Closest Neighbour is: " << neighbours[0] << " away" << endl;

	return 0;
}



vector<tuple<int, int, int>> plot_ordinates(vector<string> scales) {
	vector<tuple<int, int, int>> coordinates_and_steps;

	tuple<int, int, int> start_position = make_tuple(0,0,0);

	for(string s :  scales) {
		string direction = s.substr(0,1);
		istringstream stream(s.substr(1, s.size()));
		int magnitude, x, y;
	 	stream >> magnitude;
		int steps = get<2>(start_position);
		if(direction == "R") {
				x = get<0>(start_position);
				y = get<1>(start_position);
				for(int k = 1; k <= magnitude; k++){
					steps += 1;
					start_position = make_tuple(x + k, y, steps);
					coordinates_and_steps.push_back(start_position);
				}
		 } else if (direction == "L") {
				x = get<0>(start_position);
				y = get<1>(start_position);
				for(int k = 1; k <= magnitude; k++) {
					steps +=1;
					start_position = make_tuple(x - k,y,steps);
					coordinates_and_steps.push_back(start_position);
				}
			} else if (direction == "U") {
				x = get<0>(start_position);
				y = get<1>(start_position);
				for(int k = 1; k <= magnitude; k++){
					steps +=1;
					start_position = make_tuple(x, y + k, steps);
					coordinates_and_steps.push_back(start_position);
				}
			} else if (direction == "D") {
				x = get<0>(start_position);
				y = get<1>(start_position);
				for(int k = 1; k <= magnitude; k++){
					steps +=1;
			 	  start_position = make_tuple(x, y - k, steps);
				  coordinates_and_steps.push_back(start_position);
				}
		}

	}
	return coordinates_and_steps;
}




