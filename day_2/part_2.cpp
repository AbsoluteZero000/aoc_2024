#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>

bool safe1(std::vector<int> buf){ 
	bool asc = false;
	bool safe = true;
	if(buf[0] < buf[1])
		asc = true;
	for(int i = 0; i < buf.size() - 1; i++){
		if(abs(buf[i]-buf[i+1]) > 3 || abs(buf[i]-buf[i+1]) < 1){
			safe = false;
			break;
		}
		if(asc && buf[i] > buf[i+1]){
			safe = false;
			break;
		} else if (!asc && buf[i] < buf[i+1]){
			safe = false;
			break;
		}
	}

	return safe;

}

bool safe2(std::vector<int> buf){
    for (int i = 0; i < buf.size(); i++) {
	std::vector<int> temp(buf);
        temp.erase(temp.begin() + i);
        if (safe1(temp)) return true;
    }
    return false;
}
int main(){
	std::ifstream my_file = std::ifstream("input.txt");
	std::string buffer;
	int count = 0;
	while( getline(my_file, buffer)){
		std::stringstream ss(buffer);
		std::vector<int> buf;
		int a = 0;
		while(ss >> a)
			buf.push_back(a);

		bool safe = safe2(buf);
		count += safe; 
		std::cout << buffer << " " << ((safe)? "Safe" : "Not Safe")<< std::endl;
	}
	std::cout << count <<std::endl; 
	my_file.close();

}
