#include <vector>

int islandPerimeter(std::vector<std::vector<int>>& grid) {
    std::size_t row = grid.size();
    std::size_t columns = grid[0].size();
    int perm = 0;
    for(std::size_t i = 0; i < row; i++){
        for(std::size_t j = 0; j < columns; j++){
            if(grid[i][j] == 1){
                if(i == 0 || grid[i-1][j] == 0){
                    perm++;
                }
                if(i == row-1 || grid[i+1][j] == 0){
                    perm++;
                }
                if(j == columns-1 || grid[i][j+1] == 0){
                    perm++;
                }
                if(j == 0 || grid[i][j-1] == 0){
                    perm++;
                }
            }
        }
    }
    return perm;
    
}