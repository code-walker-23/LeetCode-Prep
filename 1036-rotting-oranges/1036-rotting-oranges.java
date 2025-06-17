import java.util.AbstractMap.SimpleEntry;
class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        Queue<SimpleEntry<SimpleEntry<Integer,Integer>, Integer>> q = new LinkedList<>();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    SimpleEntry<Integer,Integer> coord = new SimpleEntry<>(i,j);
                    q.add(new SimpleEntry<>(coord, 0)); // add (i,j) with time 0
                }
            }
        }

        int minTime = 0;
        int[][] del = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.isEmpty()){
            SimpleEntry<SimpleEntry<Integer,Integer>, Integer> front = q.remove();
            int i = front.getKey().getKey();
            int j = front.getKey().getValue();
            int time = front.getValue();
            
            minTime = Math.max(minTime, time);

            for(int k = 0; k < 4; k++){
                int nrow = i + del[k][0];
                int ncol = j + del[k][1];

                if(nrow >= m || ncol >= n || nrow < 0 || ncol < 0 || grid[nrow][ncol] != 1) continue;

                grid[nrow][ncol] = 2;
                SimpleEntry<Integer,Integer> coord = new SimpleEntry<>(nrow,ncol);
                q.add(new SimpleEntry<>(coord, time + 1));
            }
        }

        // Check for any remaining fresh oranges
        for(int[] row : grid){
            for(int cell : row){
                if(cell == 1) return -1;
            }
        }

        return minTime;
    }
}





// class Solution {
//     public int orangesRotting(int[][] grid) {
//         int m = grid.length;
//         int n = grid[0].length;

//         Queue<SimpleEntry<SimpleEntry<Integer,Integer>,Integer>>q = new LinkedList<>();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 2){
//                     SimpleEntry<Integer,Integer>s = new SimpleEntry<>(i,j);
//                     SimpleEntry<Integer,Integer>p = new SimpleEntry<>(s,0);
//                     q.add(p);
//                 }
//             }
//         }

//         int minTime = 0;

//         while(!q.isEmpty()){
//             SimpleEntry<SimpleEntry<Integer,Integer>,Integer> front = q.remove();
//             int i = front.getKey().getKey();
//             int j = front.getKey().getValue();
//             int time = front.getValue(); // time at which orange becomes rotten
            
//             minTime = Math.max(minTime,time); // maxtime taken by a orange to rotten -> final time

//             int[][] del = {{0, 1}, {0, -1},{1, 0},{-1, 0}};
//             for(int k = 0; k < 4; k++){
//                 int nrow = i + del[k][0];
//                 int ncol = j + del[k][1];

//                 if(nrow == m || ncol == n || nrow < 0 || ncol < 0 || grid[nrow][ncol] != 1) continue;

//                 grid[nrow][ncol] = 2;
//                 SimpleEntry<Integer,Integer>s = new SimpleEntry<>(nrow,ncol);
//                 SimpleEntry<Integer,Integer>p = new SimpleEntry<>(s,time+1);

//                 q.add(p);
//             }
//         }

//         for(int[] row : grid){
//             for(int cell : row){
//                 if(cell == 1)return -1;
//             }
//         }

//         return minTime;
//     }
// }