class Solution {
    void dfs(int sr,int sc,int[][] image,int orgColor,int color){
        image[sr][sc] = color;
        int[][] del = {{1,0},{-1,0},{0,1},{0,-1}};

        // if we get color == orgColor and there is no condition in floodfill function like this(if(color == image[sr][sc])return image;) then it will only run for 4 times no dfs call will made
        for(int k = 0; k < 4; k++){
            int nrow = sr + del[k][0];
            int ncol = sc + del[k][1];

            if(nrow < 0 || ncol < 0 || nrow == image.length || ncol == image[0].length || image[nrow][ncol] != orgColor || orgColor == color)continue;

            dfs(nrow,ncol,image,orgColor,color);
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        //  we can avoid the condition in the if of dfs function -> orgColor == color by putting if(color == orgColor) return image in this function
        // if(color == image[sr][sc])return image; // it will save only four iterations
        dfs(sr,sc,image,image[sr][sc],color);
        return image;
    }
}