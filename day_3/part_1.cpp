#include<fstream>
#include <iostream>
#include<string>
int main(){
	std::ifstream file = std::ifstream("input.txt");
	std::string buf;
	int result = 0;
	while(std::getline(file, buf)){
		for(int i = 0; i < buf.size(); i++){
			int x = 0, y = 0;
			if(buf[i] == 'm'){
				std::cout<<"first check Passed\n";
				if(buf[i+1] == 'u' && buf[i+2] == 'l' && buf[i+3] == '('){
					std::cout<<"second check Passed\n";
					int j;
					i += 4;
					for(j = 0; j < 3; j++){
						if(buf[i+j] < '0' || buf[i+j] > '9')
							break;
						std::cout<<buf[i+j];
						x = x*10 + buf[i+j] - '0';
					}

					std::cout<<"third check Passed\n";

					if(buf[i+j] != ',')
						continue;
					i += j+1;

					std::cout<<"fourth check Passed\n";

					for(j = 0; j < 3; j++){
						if(buf[i+j] < '0' || buf[i+j] > '9')
							break;
						std::cout<<buf[i+j];
						y = y*10 + buf[i+j] - '0';
					}
 
					std::cout<<"fifth check Passed\n";

					if(buf[i+j] != ')')
						continue;

					std::cout<<"sixth and final check Passed\n";

					std::cout<<"first operand: "<<x<<std::endl;
					std::cout<<"second operand: "<<y<<std::endl;
					result += x*y;
					std::cout<<"result: "<<result<<std::endl<<std::endl;


				}
			}
		}
	}

	std::cout<<"result: "<<result<<std::endl;
}
