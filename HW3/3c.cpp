class Solution {
public:
    //dfs for islands
    void dfs(int x, int y, int xMax, int yMax, vector<vector<char>>& grid)
    {
        //mark island position as visited
        grid[x][y] = '2';
        //return if bfs going out of the grid
        if ((x < 0 && y < 0) && (x >= xMax && y >= yMax))
        {
            return;
        }
        //check island on up position
        if ((y + 1) < yMax)
        {
            //call bfs for up position
            if (grid[x][y + 1] == '1')
            {
                dfs(x, y + 1, xMax, yMax, grid);
            }
        }
        //check island on down position
        if ((y - 1) >= 0)
        {
            //call bfs for down position
            if (grid[x][y - 1] == '1')
            {
                dfs(x, y - 1, xMax, yMax, grid);
            }
        }
        //check island on right position
        if ((x + 1) < xMax)
        {
            //call bfs for the right position
            if (grid[x + 1][y] == '1')
            {
                dfs(x + 1, y, xMax, yMax, grid);
            }
        }
        //check island on left position
        if ((x - 1) >= 0)
        {
            //call bfs for the left position
            if (grid[x - 1][y] == '1')
            {
                dfs(x - 1, y, xMax, yMax, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        //codtinates
        int x = 0;
        int y = 0;
        //grid high and width
        int xMax = 0;
        int yMax = 0;
        //number of islands
        int numIsl = 0;
        //width
        for (vector<char> row : grid)
        {
            xMax++;
        }
        //hight
        for (char col : grid[0])
        {
            yMax++;
        }
        //going through all of the positions and looking for islands
        for (vector<char>& row : grid)
        {
            for (char& col : row)
            {
                if (col == '1')
                {
                    dfs(x, y, xMax, yMax, grid);
                    numIsl++;
                }
                y++;
            }
            y = 0;
            x++;
        }
        //return number of islands
        return numIsl;
    }
};