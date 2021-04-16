/*
    we have m task and n processor 
    certain task can be perform in either of specified processor only
    in processor only one task can be done 
    we need to find how many maximum task can be completed at a time
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int bipartiteMatch(int **arr,int m,int n,int task,vector<int>&visited,vector<int>&alloted) // returns 1 if match is possible else 0
{
    // checking each processor for task 
    for (int i = 0; i < n; i++)
    {
        // if task is compatible with processor and no one is currently visiting that processor
        if (arr[task][i]==1 && visited[i]==0)
        {
            // task will visit processor
            visited[i] = 1;
            // if processor is not allocated to any task or
            // that task which is allocated to processor can be done in another processor which is free
            // that means for that task if we are able to find some other bipartite match
            if (alloted[i]<0 || bipartiteMatch(arr,m,n,alloted[i],visited,alloted)==1)
            {
                // that processor will link to given task and as we find processor for the task so we return 1
                alloted[i] = task;
                return 1;
            }
            
        }
        
    }
    return 0;
}

int maxMatch(int **arr,int m,int n)
{
    // mainting an array which links task to allocated processor
    // it can be changes arrording to maximum allocation so initializing it with -1 for all values as processor is not link to any task at beginning
    vector<int> alloted(n,-1);
    int maxtask=0;
    for (int i = 0; i < m; i++) // traversing in all task and allocting it to processor if possible
    {
        // for each processor every task can visit as no restricted or no given specification
        // so creating a vector and making all values to 0 as unvisited for all tasks
        vector<int>visited(n,0);
        // for given task if we are able to find bipartite match then that task can be executed in certine processor 
        if (bipartiteMatch(arr,m,n,i,visited,alloted)==1)
        {
            // so if condition is true then maximim task will be increase by 1
            maxtask+=1;
        }
        
    }
    return maxtask;
}

int main()
{
    int m= 6,n= 6;
    int **taskProcessorCompatibility = new int*[m];
    for (int i = 0; i < m; i++)
    {
        taskProcessorCompatibility[i] = new int[n];
    }
    cout<< "Please enter data: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> taskProcessorCompatibility[i][j];
        }
        
    }
    cout << "Thanks for entering data" << endl;
    
    
    int maxTask = maxMatch(taskProcessorCompatibility,m,n);

    cout << "Maximum task can be allocat is: " << maxTask << endl;
    return 0;
}