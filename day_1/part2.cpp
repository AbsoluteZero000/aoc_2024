#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

int main(){
	
	std::ifstream myfile("input.txt");
	std::string puzzle_input;
	std::vector<int> set_1;
	std::map<int,int> m;
	while(myfile >> puzzle_input){
		std::cout<<puzzle_input<<" ";
		set_1.push_back(stoi(puzzle_input));

		myfile >> puzzle_input;
		std::cout<<puzzle_input<<std::endl;
		m[stoi(puzzle_input)]++;
	}

	long long result = 0;
	for(std::vector<int>::iterator p1 = set_1.begin(); p1 < set_1.end(); p1++){
		result += m[*p1]* *p1;
		std::cout<< "number: "<< *p1<< " count: "<< m[*p1]<<std::endl;
	}

	std::cout<<result;
	return 0;
}
