#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,s1;
	getline(cin,s);
	getline(cin,s1);
	int answer = 0;
	vector<int> p;
	for(auto i:s){
		p.push_back((int)i);
	}
	sort(p.begin(),p.end());
	int result = 0;
	int prev = (int) s1[0];
	for(auto i:s1){
		int x = (int) i;
		int l = 0,r = p.size()-1;
		int answer = INT_MAX;
		int cur = -1;
		while(l<=r){
			int mid = (l+r)/2;
			if(p[mid] == x){
				cur = prev;
				answer = 0;
				break;
			}
			else if(p[mid] < x){
				if(abs(p[mid] -x ) < answer) {
					answer = abs(p[mid] - x);
					cur = p[mid];
				}
				else if(abs(p[mid]-x) == answer){
					if(abs(cur-prev) > abs(p[mid]-prev)){
						cur = p[mid];
						answer = abs(p[mid]-prev);
					}
				else{
					answer = abs(cur-prev);
				}
			}
		
			l = mid + 1;
		}
		else {
			if(abs(p[mid]-x) < answer){
				answer = abs(p[mid]-x);
				cur = p[mid];
			}
			else if(abs(p[mid]-x) == answer){
				if(abs(cur-prev) > abs (p[mid] - prev)){
					cur = p[mid];
					answer = abs(p[mid]-prev);
				}
				else {
					answer = abs(cur-prev);
				}
			}
			r = mid - 1;
		}
	}
	prev = cur;
	result += answer;
	}
	cout << result;
	}
	