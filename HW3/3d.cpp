class Solution {
public:
    //do dfs for first island and fill island positions with '2'
    void dfs(int x, int y, int xMax, int yMax, vector<vector<int>>& grid)
    {
        //replase pos with '2'
        grid[x][y] = 2;
        //return if dfs going out of the grid
        if ((x < 0 && y < 0) && (x >= xMax && y >= yMax))
        {
            return;
        }
        //check island on up position
        if ((y + 1) < yMax)
        {
            //call bfs for up position
            if (grid[x][y + 1] == 1)
            {
                dfs(x, y + 1, xMax, yMax, grid);
            }
        }
        //check island on down position
        if ((y - 1) >= 0)
        {
            //call bfs for down position
            if (grid[x][y - 1] == 1)
            {
                dfs(x, y - 1, xMax, yMax, grid);
            }
        }
        //check island on right position
        if ((x + 1) < xMax)
        {
            //call bfs for the right position
            if (grid[x + 1][y] == 1)
            {
                dfs(x + 1, y, xMax, yMax, grid);
            }
        }
        //check island on left position
        if ((x - 1) >= 0)
        {
            //call bfs for the left position
            if (grid[x - 1][y] == 1)
            {
                dfs(x - 1, y, xMax, yMax, grid);
            }
        }
    }

    //looking for first island and runing dfs on it
    int firstIsland(vector<vector<int>>& grid, int xMax, int yMax) {
        //coordinates
        int x = 0;
        int y = 0;
        //going through all of the grid positions
        for (vector<int>& row : grid)
        {
            for (int& col : row)
            {
                //call dfs when find the first island
                if (col == 1)
                {
                    dfs(x, y, xMax, yMax, grid);
                    return 0;
                }
                y++;
            }
            y = 0;
            x++;
        }

        return 0;
    }

    //get codinates positions on the first island that are conected with the water
    int getCordinates(vector<vector<int>>& grid, 
        vector<vector<int>>& firstIlandCord, int xMax, int yMax)
    {
        //coordinates
        int x = 0;
        int y = 0;
        //going through all of the grid posits looking for first island
        //if found firs island postion, check if it is close to water
        //if it is close to water, put position in to the firstIlandCord vector
        for (vector<int>& row : grid)
        {
            for (int& col : row)
            {
                if (col == 2)
                {
                    bool closeToWater = false;

                    if ((y + 1) < yMax)
                    {
                        if (grid[y + 1][x] == 0)
                        {
                            closeToWater = true;
                        }
                    }
                    if ((y - 1) >= 0)
                    {
                        if (grid[y - 1][x] == 0)
                        {
                            closeToWater = true;
                        }
                    }
                    if ((x + 1) < xMax)
                    {
                        if (grid[y][x + 1] == 0)
                        {
                            closeToWater = true;
                        }
                    }
                    if ((x - 1) >= 0)
                    {
                        if (grid[y][x - 1] == 0)
                        {
                            closeToWater = true;
                        }
                    }

                    if (closeToWater)
                    {
                        vector<int> cordin = { x, y };
                        firstIlandCord.push_back(cordin);
                    }
                }
                x++;
            }
            x = 0;
            y++;
        }
        return 0;
    }

    //bfs increases the first island in all of the directions
    //untill it is connected with the second island
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& firstIlandCord, int xMax, int yMax)
    {
        //coordinates
        int x = 0;
        int y = 0;
        //counter that counts increases
        int counter = 0;
        //contains positions for increases
        queue<vector<int>> q;
        //put all of the first island positions that are close to the water 
        //to the queue 
        for (vector<int> pos : firstIlandCord)
        {
            q.push(pos);
        }
        //going untill the queue will not be empty
        while (!q.empty())
        {
            //number of interactions for this increase 
            int qSize = q.size();
            //do one increase of the island in all directions
            for (int i = 0; i < qSize; i++)
            {
                vector<int> cur = q.front();
                q.pop();

                x = cur[0];
                y = cur[1];

                if ((y + 1) < yMax)
                {
                    if (grid[y + 1][x] == 1)
                    {
                        return counter;
                    }

                    if (grid[y + 1][x] == 0)
                    {
                        grid[y + 1][x] = 2;
                        q.push({ x, (y + 1) });
                    }
                }
                if ((y - 1) >= 0)
                {
                    if (grid[y - 1][x] == 1)
                    {
                        return counter;
                    }

                    if (grid[y - 1][x] == 0)
                    {
                        grid[y - 1][x] = 2;
                        q.push({ x, (y - 1) });
                    }
                }
                if ((x + 1) < xMax)
                {
                    if (grid[y][x + 1] == 1)
                    {
                        return counter;
                    }

                    if (grid[y][x + 1] == 0)
                    {
                        grid[y][x + 1] = 2;
                        q.push({ (x + 1), y });
                    }
                }
                if ((x - 1) >= 0)
                {
                    if (grid[y][x - 1] == 1)
                    {
                        return counter;
                    }

                    if (grid[y][x - 1] == 0)
                    {
                        grid[y][x - 1] = 2;
                        q.push({ (x - 1), y });
                    }
                }
            }
            counter++;
        }
        return counter;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        //grid high and width
        int xMax = 0;
        int yMax = 0;
        //find grid hight
        for (vector<int> row : grid)
        {
            yMax++;
        }
        //find grid width
        for (int col : grid[0])
        {
            xMax++;
        }
        //vector with fist island codinates
        vector<vector<int>> firstIlandCord;
        //replase all first island coordinates with '2'
        firstIsland(grid, xMax, yMax);
        //fill vector with first island coordinates that are close to water
        getCordinates(grid, firstIlandCord, xMax, yMax);
        //get the shortest distance from first to second island
        int dist = bfs(grid, firstIlandCord, xMax, yMax);
        //return shortest distance
        return dist;
    }
};