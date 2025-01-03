#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
int main(){
	std::ifstream my_file = std::ifstream("input.txt");
	std::vector<std::vector<char>> matrix;

	std::string buffer;

	while(getline(my_file, buffer)){
		std::vector<char> row;
		for(int i = 0; i < buffer.size(); i++){
			row.push_back(buffer[i]);
		}
		matrix.push_back(row);
	}

	std::cout<<"reached here";
	const std::string target = "MAS";
	int counter = 0;

	std::vector<std::vector<std::pair<int, int>>> directions = {
		{{1, 0}, {2, 0}, {3, 0}},
		{{0, 1}, {0, 2}, {0, 3}},
		{{1, 1}, {2, 2}, {3, 3}},
		{{-1, 0}, {-2, 0}, {-3, 0}},
		{{0, -1}, {0, -2}, {0, -3}},
		{{1, -1}, {2, -2}, {3, -3}},
		{{-1, 1}, {-2, 2}, {-3, 3}},
		{{-1, -1}, {-2, -2}, {-3, -3}}
	};

	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			if(matrix[i][j] == 'X'){
				for(auto direction : directions){
					bool found = true;
					for(int k = 0; k < 3; k++){
						if(i + direction[k].first >= matrix.size() || j + direction[k].second >= matrix[i].size() || i + direction[k].first < 0 || j + direction[k].second < 0){
							found = false;
							break;
						} 
						if(matrix[i + direction[k].first][j + direction[k].second] != target[k]){
							found = false;
							break;
						}
					}
					counter += found;
				}
			}
		}
	}
	std::cout<<counter;	
}
