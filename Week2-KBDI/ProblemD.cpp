#include <iostream>
#include <algorithm>

int main(){
	int test = 0;
	std::cin >> test;
	while(test--){
		char c;
		std::cin >> c;
		int l=0,o=0,v=0,e=0,ans1=0,ans2=0,ans=0;
		while(c != '\n'){
			if(c == 'L'){
				l++;
			}
			else if(c == 'O'){
				if(l){
					ans1++;
					l--;
				}
			}
			else if(c == 'V'){
				if(ans1){
					ans2++;
					ans1--;
				}
			}
			else if(c == 'E'){
				if(ans2){
					ans++;
					ans2--;
					o--;
					v--;
				}
			}
			c = std::cin.get();
		}
		//std::cout << std::min(l, std::min(o, std::min(v, e))) << std::endl;
		std::cout << ans << std::endl;
	}
	return 0;
}
