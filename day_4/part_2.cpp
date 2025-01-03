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

	int counter = 0;


	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			if(matrix[i][j] == 'A'){
				if(i + 1 >= matrix.size() || j + 1 >= matrix[i].size() || i - 1 < 0 || j - 1 < 0){
					continue;
				} 
				if(matrix[i + 1][j+1] == 'M' && matrix[i - 1][j - 1] == 'S' || matrix[i + 1][j + 1] == 'S' && matrix[i - 1][j - 1] == 'M'){
					if(matrix[i - 1][j+1] == 'M' && matrix[i + 1][j - 1] == 'S' || matrix[i - 1][j + 1] == 'S' && matrix[i + 1][j - 1] == 'M'){
						counter++;
					}
				}
			}
		}
	}
	std::cout<<counter;	
}
