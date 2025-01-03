#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>


int main(){
	
	std::ifstream myfile("input.txt");
	std::string puzzle_input;
	std::vector<int> set_1, set_2;	
	if(myfile.is_open()){
		while(myfile.good()){
			myfile >> puzzle_input;
			set_1.push_back(stoi(puzzle_input));

			myfile >> puzzle_input;
			set_2.push_back(stoi(puzzle_input));
		}
	}

	std::sort(set_1.begin(), set_1.end());
	std::sort(set_2.begin(), set_2.end());


	long long result = 0;
	std::vector<int>::iterator p1 = set_1.begin();
	for(std::vector<int>::iterator p2 = set_2.begin(); p2 <set_2.end(); p1++, p2++){
		result += abs(*p1-*p2);
	}

	std::cout<<result;
	return 0;
}
