#include<vector>
#include<iostream>
#include<queue>
#include<math.h>

std::vector<std::pair<int,int>> kClosestPoints(int k, std::vector<std::pair<int,int>> coord){
	std::vector<std::pair<int,int>> kClosest;
	auto cmp = [](std::pair<double,int> left, std::pair<double,int> right)->bool{return left.first > right.first;};
	std::priority_queue<std::pair<double,int>, std::vector<std::pair<double,int>>, decltype(cmp)> distances(cmp);
	for(int i = 0; i < coord.size(); ++i){
		double distance = sqrt(coord[i].first*coord[i].first + coord[i].second*coord[i].second);
		distances.push(std::pair<double,int>(distance, i));
	}
	for(int i = 0; i < k ; ++i){
		kClosest.push_back(coord[distances.top().second]);
		distances.pop();
	}
	return kClosest;
}

int main(){
	int k = 3;
	std::vector<std::pair<int,int>> coordinates;
	coordinates.push_back(std::pair<int,int>(1,2));
	coordinates.push_back(std::pair<int,int>(5,6));
	coordinates.push_back(std::pair<int,int>(2,3));
	coordinates.push_back(std::pair<int,int>(-2,5));
	coordinates.push_back(std::pair<int,int>(-1,-7));
	std::vector<std::pair<int,int>> kClosest = kClosestPoints(k, coordinates);
	std::cout << "The closest " << k << " points to the origin are:" << std::endl;
	for(int i = 0; i < kClosest.size(); ++i){
		std::cout << "(" << kClosest[i].first << "," << kClosest[i].second << ")" << std::endl;
	}
	return 0;
}

/**
 * Analysis:
 * 	Time: O(nlongn) Priority queue takes O(logn) for insert, this needs to be done to all n elements
 * 	Space: O(n) Priority Queue: O(n), return vector O(n)
 * */
