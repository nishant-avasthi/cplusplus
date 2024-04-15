#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool cycle(int s,vector<vector<int>> &adj,vector<bool> &visited, vector<bool> &dfsVisited )
    {
        visited[s]=true;
        dfsVisited[s]=true;

        for(auto x: adj[s])
        {
            if(!visited[x])
            {
                if(cycle(x,adj,visited,dfsVisited))
                {
                    return true;
                }
            }
            else if(visited[x]&&dfsVisited[x])
            {
                return true;
            }
        }
        dfsVisited[s]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites )
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(numCourses,false),dfsVisited(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i]&&cycle(i,adj,visited,dfsVisited))
            {
                return false;
            }
        }
        return true;

    }
};


int main(){
    int number=2;

    vector<vector<int>> v={{1,0}};

    Solution Solution;


    cout<<(Solution.canFinish(number,v)?"true":"false");

    return 0;
}