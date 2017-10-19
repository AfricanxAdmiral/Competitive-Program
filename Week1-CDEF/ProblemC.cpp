#include <iostream> 
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc,char *argv[]){
	
	int data_num;
	std::cin >> data_num;
	for(int i = 0;i < data_num;i ++){
		int line_num;
		std::cin >> line_num;
		
		std::vector<unsigned int> starts(0);
		starts.reserve(line_num);
		std::vector<unsigned int> ends(0);
		ends.reserve(line_num);
		
		for(int j = 0;j < line_num;j ++){
			int a1, b1;
			std::cin >> a1 >> b1;
			starts.push_back(static_cast<unsigned int>(a1));
			ends.push_back(static_cast<unsigned int>(b1));
		}
		
		std::sort(starts.begin(), starts.end());
		std::sort(ends.begin(), ends.end());
		
		//compute the coloring parts
		int max_color = 0;
		int cur_color = 0;
		for(std::vector<unsigned int>::iterator it1 = starts.begin(), it2 = ends.begin(); it1 < starts.end();){
			//std::cout << *it1 << " " << *it2 << std::endl;
			if(*it1 <= *it2){
				cur_color++;
				it1++;
				if(cur_color > max_color){
					max_color = cur_color;
				}
			}
			else{
				cur_color--;
				it2++;
			}
		}
		std::cout << max_color << std::endl;
	}
	
	return 0;
} 
