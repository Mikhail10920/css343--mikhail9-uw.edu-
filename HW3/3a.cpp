class Solution {
public:
    bool dfs(int courNumb, vector<vector<int>>& adjList, vector<int>& stack, vector<int>& visited)
    {
        //mark course as visited
        visited[courNumb] = 1;
        //going through all of the adjacencies
        for (int v : adjList[courNumb])
        {
            if (visited[v] == 1)
            {
                return true;
            }
            if (visited[v] == 0 && dfs(v, adjList, stack, visited))
            {
                return true;
            }
        }
        //mark vertex as visited and indicate that we are done with it
        visited[courNumb] = 2;
        stack.push_back(courNumb);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //adjacencies for every vertex
        vector<vector<int>> adjList(numCourses);
        //visited vertexes
        vector<int> visited(numCourses, 0);
        //stack for final courses order
        vector<int> stack;
        //input adjacencies for every vertex
        for (vector<int>& course : prerequisites)
        {
            adjList[course[1]].push_back(course[0]);
        }
        //run dfs for all curses
        for (int courNumb = 0; courNumb < numCourses; courNumb++)
        {
            if (visited[courNumb] == 0 && dfs(courNumb, adjList, stack, visited))
            {
                return {};
            }
        }
        //reverse the stack and return it in the right order
        reverse(stack.begin(), stack.end());
        return stack;
    }
};