#include <sstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

vector< tuple<int, int> > plot_ordinates(vector<string> scales);

int main() {
	vector<string> scales{"R8","U5","L5","D3"};

	vector<tuple<int, int>> positions = plot_ordinates(scales);

	for(auto x : positions)
			cout << get<0>(x) << "," << get<1>(x) << endl;
	return 0;
}

vector<tuple<int, int>> plot_ordinates(vector<string> scales) {
	vector<tuple<int, int>> coordinates;

	tuple<int, int> start_position = make_tuple(0,0);

	for(string s :  scales) {
		string direction = s.substr(0,1);
		istringstream stream(s.substr(1, s.size()));
		int magnitude, x, y;
	 	stream >> magnitude;
		if(direction == "R") {
				x = get<0>(start_position) + magnitude;
				y = get<1>(start_position);
				start_position = make_tuple(x, y);
				coordinates.push_back(start_position);
		 } else if (direction == "L") {
				x = get<0>(start_position) - magnitude;
				y = get<1>(start_position);
				start_position = make_tuple(x,y);
				coordinates.push_back(start_position);
			} else if (direction == "U") {
				x = get<0>(start_position);
				y = get<1>(start_position)	+ magnitude;
				start_position = make_tuple(x, y);
				coordinates.push_back(start_position);
			} else if (direction == "D") {
				x = get<0>(start_position);
				y = get<1>(start_position) - magnitude;
			 	start_position = make_tuple(x,y);
				coordinates.push_back(start_position);
		}
	}
	return coordinates;
}




