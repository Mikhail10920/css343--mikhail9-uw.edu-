class Solution {
public:
    bool exist(vector<vector<char>>& grid, string word) {
        //coordinates
        int x = 0;
        int y = 0;
        //grid height and width
        int xMax = 0;
        int yMax = 0;
        //counter that keeps track of the letter in the word 
        int counter = 0;
        //if word was found in the grid
        bool wordFound = false;
        //hight
        for (vector<char> row : grid)
        {
            yMax++;
        }
        //width
        for (char col : grid[0])
        {
            xMax++;
        }
        //going through the grid and looking for the firs latter of the word
        //if find firs letter of the word, calls dfs
        for (vector<char>& row : grid)
        {
            for (char& col : row)
            {
                if (col == word.at(0))
                {
                    dfs(grid, word, x, y, xMax, yMax, counter, wordFound);
                }
                x++;
            }
            x = 0;
            y++;
        }
        return wordFound;
    }

    //dfs, search for the word
    bool dfs(vector<vector<char>>& grid, string word, int x, int y, int xMax,
        int yMax, int& counter, bool& wordFound)
    {
        //base case
        if (counter == (word.size() - 1))
        {
            wordFound = true;
            return wordFound;
        }
        //save current letter
        char c = grid[y][x];
        //mark current letter as visited
        grid[y][x] = '*';
        //check up, down, right, left positions for the next letter
        if ((y + 1) < yMax)
        {
            if (grid[y + 1][x] == word.at(counter + 1))
            {
                counter++;
                dfs(grid, word, x, y + 1, xMax, yMax, counter, wordFound);
                counter--;
            }
        }
        if ((y - 1) >= 0)
        {
            if (grid[y - 1][x] == word.at(counter + 1))
            {
                counter++;
                dfs(grid, word, x, y - 1, xMax, yMax, counter, wordFound);
                counter--;
            }
        }
        if ((x + 1) < xMax)
        {
            if (grid[y][x + 1] == word.at(counter + 1))
            {
                counter++;
                dfs(grid, word, x + 1, y, xMax, yMax, counter, wordFound);
                counter--;
            }
        }
        if ((x - 1) >= 0)
        {
            if (grid[y][x - 1] == word.at(counter + 1))
            {
                counter++;
                dfs(grid, word, x - 1, y, xMax, yMax, counter, wordFound);
                counter--;
            }
        }
        //turn current letter back as unvisited
        grid[y][x] = c;
        return (wordFound);
    }
};