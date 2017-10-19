#include <iostream>
#include <vector>
#include <time.h>

int main(){
	
	clock_t start, finish;
	start = clock();
	std::vector<std::vector<unsigned int> > chart(10000);
	for(int i = 0;i < 10000;i++){
		for(int j = 0;j < 10000;j++){
			if(j==0 || i == j){
				chart[i].push_back(1);
			}
			else if(i < j){
				break;
			}
			else{
				chart[i].push_back((chart[i-1][j-1] + chart[i-1][j])%1000000007);
			}
		}
	}
	finish = clock();
	//std::cout << finish - start << std::endl;
	
	int test_num = 0;
	std::cin >> test_num;
	while(test_num--){
		unsigned int a, b, m;
		unsigned long long ans = 1;
		std::cin >> a >> b >> m;
		if(b==0 || a == b){
			std::cout << ans << std::endl;
		}
		else if(a < b){
			std::cout << 0 << std::endl;
		}
		else{
			while(a || b){
				if(a%m < b%m){
					ans = 0;
					break;
				}
				ans = (ans * chart[(a % m)][(b % m)]) % 1000000007;
				if(a){
					a /= m;
				}
				if(b){
					b /= m;
				}
			}
			std::cout << ans << std::endl;
		}
	}
	
	return 0;
}
