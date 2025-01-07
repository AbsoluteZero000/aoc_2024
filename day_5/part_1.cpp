#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>

int main(){
	std::ifstream my_file = std::ifstream("input.txt");
	std::string buff;
	std::map<int, std::vector<int>> btf, ftb;
	while(getline(my_file, buff)){
		if(buff.empty()) break;
		int first, second;
		first = (buff[0] - '0')*10 + buff[1] - '0';
		second = (buff[3] - '0')*10 + buff[4] - '0';
		btf[first].push_back(second);
		ftb[second].push_back(first);
	}

	int res = 0;
	while(my_file >> buff){
		std::vector<int> temp;
		for(int i = 0; i < buff.size(); i+=3){
			temp.push_back((buff[i] - '0')*10 + buff[i+1] - '0');
		}

		for(int i = 0; i < temp.size(); i++){
			std::cout<<temp[i]<<" ";
		}
		std::cout<<std::endl;
		bool correct = true;
		for(int i = 0; i < temp.size(); i++){

			for(int j = 0; j < i; j++){
				if(std::find(ftb[temp[j]].begin(), ftb[temp[j]].end(), temp[i]) != ftb[temp[j]].end()){
					correct = false;
					break;
				}
			}
			std::cout<<"after first loop";
			std::cout<<std::endl;

			if(!correct) break;
	

			for(int j = i+1; j < temp.size(); j++){
				std::cout<<"temp[i]: " <<temp[i]<< ", "<<temp[j]<< " btf: ";
				for(int k = 0; k < btf[temp[j]].size(); k++){
					std::cout<<btf[temp[j]][k]<<" ";
				}
				std::cout<<std::endl;
				if(std::find(btf[temp[j]].begin(), btf[temp[j]].end(), temp[i]) != btf[temp[j]].end()){
					correct = false;
					break;
				}
			}
			
			std::cout<<"after second loop";
			std::cout<<std::endl;
			if(!correct) break;
		}
		if(correct) res += temp[temp.size()/2];
	}

	std::cout << res << std::endl;	
	

	
}
