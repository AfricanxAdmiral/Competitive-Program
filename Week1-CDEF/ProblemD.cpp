#include <iostream>
#include <utility>
#include <vector>

int main(){
	int data_num = 0;
	std::cin >> data_num;
	for(int i = 0;i < data_num; i++){
		int group = 0;
		std::cin >> group;
		
		std::vector<std::pair<char, int>> groups;
		std::vector<std::pair<char, int>> temp;
		temp.push_back(std::make_pair(' ', 0));
		
		for (int j = 0;j < group; j++){
			char c;
			int n;
			std::cin >> c >> n;
			groups.push_back(std::make_pair(c, n));
		}
		

		for(int a = 0;a < groups.size(); a++){
			
			//std::cout << groups[a].first << " " << groups[a].second << " " << temp.back().first << " " << temp.back().second << std::endl;
			
			int total = 0;
			if(groups[a].first == temp.back().first){
				total += temp.back().second;
			}
			
			total += groups[a].second;
			
			if(total / 3 != 0){
				groups.push_back(std::make_pair(groups[a].first, (total / 3)));
				/*
				if(a == groups.size()-1){
	                groups.push_back(std::make_pair(groups[a].first, (groups[a].second / 3)));
				}
				else if(groups[groups.size()-1].first == groups[a].first){
					groups[groups.size()-1].second += (groups[a].second / 3);
				}
				else{
					groups.push_back(std::make_pair(groups[a].first, (groups[a].second / 3)));
				}
				*/
			}
			if(total % 3 != 0){
				if(groups[a].first == temp.back().first){
					temp.back().second = total % 3;
				}
				else{
					temp.push_back(std::make_pair(groups[a].first, (total %3))); 
				}
			}
			else{
				if(groups[a].first == temp.back().first){
					temp.pop_back();
				}
			}
			
			//std::cout << groups[a].first << " " << groups[a].second << " " << temp.back().first << " " << temp.back().second << std::endl;
		}
		
		int coin_num = 0;
		while(temp.size() > 0){
			coin_num += temp.back().second;
			temp.pop_back();
			//std::cout << temp[t].first << " " << temp[t].second << " ";
		}
		std::cout << coin_num << std::endl;
	}
	
	return 0;
} 
