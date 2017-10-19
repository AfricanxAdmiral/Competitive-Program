#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int test_num;
	cin >> test_num;
	while(test_num--){
		int data_num, ans = 0;
		cin >> data_num;
		vector<int> data(data_num);
		for(int i = 0;i < data_num; i++){
			int floor;
			cin >> floor;
			data[i] = floor;
		}
		sort(data.begin(),data.end());
		data.erase(unique(data.begin(),data.end()),data.end());
		for(int i = 0;i < data.size(); i++){
			//cout << data[i];
			if (data[i] == 1) continue;
			if (data[i] == 2){
				if ( data[i+1] != 3){
					ans++;
					data[i]--;
				}
			}
			else if (data[i] == data[i-1] + 1){
				ans++;
				data[i]--;
			}
			else if(i != data.size()-1){
				if(data[i] != data[i+1] - 1)ans++;
			}
			else{
				if (data[i] != data[i-1]){
					ans++;
				}
			}
			//cout << data[i] << " " << ans << " ";
		}
		cout << ans <<endl;
	}
	return 0;
}
