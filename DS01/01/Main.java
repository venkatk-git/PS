public class Main {
    public static void main(String[] args) {
        int[][] mat = new int[][]{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        System.out.println(searchMatrix(mat,11));
    }
    public static  boolean searchMatrix(int[][] matrix, int target) {
        int rs = 0;
        int re = matrix.length - 1;
        int cs = 0;
        int ce = matrix[0].length - 1;

        while (rs <= re) {
            int m1 = (rs + re) / 2;
            if (target >= matrix[m1][cs] && target <= matrix[m1][ce]) {
                int s = 0;
                int e = ce;
                while (s <= e) {
                    int m2 = (e + s) / 2;
                    if (matrix[m1][m2] == target) {
                        return true;
                    } else if (target < matrix[m1][m2]) {
                        e = m2 - 1;
                    } else if (target > matrix[m1][m2]) {
                        s = m2 + 1;
                    }
                }
                return false;
            } else if (target < matrix[m1][0]) {
                re = m1 - 1;
            } else if (target > matrix[m1][matrix[0].length - 1]) {
                rs = m1 + 1;
            }
        }
        return false;
    }
}
