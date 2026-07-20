//https://www.naukri.com/code360/problems/path-with-maximum-and-minimum-value_1281861?leftPanelTabValue=PROBLEM


#include <bits/stdc++.h> 
using namespace std;

vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
int pathWithMaxMinValue(vector<vector<int>> &arr)
{
	// Write your code here.
	int r=arr.size();
	int c=arr[0].size();
	priority_queue<vector<int>> pq;
	pq.push({arr[0][0],0,0});
	vector<vector<int>> vis(r, vector<int>(c, 0));
	vis[0][0] = 1;
	while(!pq.empty()){
		auto top=pq.top();
		pq.pop();
		if(top[1]==r-1 && top[2]==c-1) return top[0];
		for(auto &[x,y]:dir){
			int nx=top[1]+x, ny=top[2]+y;
			if(nx<0 || ny<0 || nx>=r || ny>=c || vis[nx][ny])
				continue;

			vis[nx][ny] = 1;
			pq.push({min(top[0],arr[nx][ny]),nx,ny});
		}
	}
	return 0;

}

