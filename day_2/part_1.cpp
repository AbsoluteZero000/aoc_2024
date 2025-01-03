#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){
	std::ifstream my_file = std::ifstream("input.txt");
	std::string buffer;
	int count = 0;
	while( getline(my_file, buffer)){
		std::stringstream ss(buffer);
		int a = 0, b = 0;
		bool asc = false;
		ss >> a >> b;
		if(a < b)
			asc = true;

		bool safe = true;
		 do{
			if(abs(a-b) > 3 || abs(a-b) < 1){
				safe = false;
				break;
			}
			if(asc && a > b){
				safe = false;
				break;
			} else if (!asc && a < b){
				safe = false;
				break;
			}
			a = b;
		}while(ss >> b);
		count += safe;
		std::cout << buffer << " " << ((safe)? "Safe" : "Not Safe")<< std::endl;
	}
	std::cout << count <<std::endl; 
	my_file.close();

}
