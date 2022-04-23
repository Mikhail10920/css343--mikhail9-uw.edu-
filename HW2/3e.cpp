#include <queue>

//overload compare operator
struct Compare
{
    bool operator()(vector<int> p1, vector<int> p2)
    {
        return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //Priority queue
        priority_queue<vector<int>, vector<vector<int>>, Compare> que;
        //Going though all of the points
        for (int i = 0; i < points.size(); i++)
        {
            vector<int> vect = points[i];
            //Add to the queue
            if (que.size() < k)
            {
                que.push(points[i]);
            }
            //Replace in the point in the queue if a new point is closer to 
            //the origin
            else
            {
                vector<int> cur = que.top();
                int dist1 = cur[0] * cur[0] + cur[1] * cur[1];
                int dist2 = vect[0] * vect[0] + vect[1] * vect[1];
                if (dist1 > dist2)
                {
                    que.pop();
                    que.push(points[i]);
                }
            }
        }
        //Creates a new vector for a sorted points 
        vector<vector<int>> sortedQue;
        while (!que.empty())
        {
            sortedQue.push_back(que.top());
            que.pop();
        }
        return sortedQue;
    }
};