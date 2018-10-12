#include<utility>
#include<iostream>

std::pair<int, int> homerSimpson(int m, int n, int t){
	int napSack[t+1];
	napSack[0] = 0;
	if (n < m)
		std::swap(m,n);
	for(int i = 1; i < t+1; ++i){
		if(i >= m){
			if(napSack[i - m] != -1)
				napSack[i] = napSack[i-m] + 1;
			else if(i >= n){
				if(napSack[i-n] != -1)
					napSack[i] = napSack[i-n] + 1;
				else 
					napSack[i] = -1;
			} else
				napSack[i] = -1;
		} else
			napSack[i] = -1;
	}
	if(napSack[t] == -1){
		for(int i = t-1; i >= 0; --i){
			if(napSack[i] != -1){
				return std::pair<int,int>(napSack[i], t-i);
			}
		}
	} else
		return std::pair<int,int>(napSack[t], 0);
}

int main(){
	std::pair<int,int> returnVal = homerSimpson(435, 159, 4568);
	if(returnVal.second == 0)
		std::cout << returnVal.first << std::endl;
	else
		std::cout << returnVal.first << " " << returnVal.second <<  std::endl;
	return 0;
}
