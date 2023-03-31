public class Matrix {
    private float[][] matrix;
    private int row;
    private int col;

    public Matrix() {
        this.matrix = null;
        this.row = 0;
        this.col = 0;
    }
    public Matrix(int row, int col) {
        this.matrix = new float[row][col];
        this.row = row;
        this.col = col;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                this.matrix[i][j] = 0;
            }
        }
    }

    public Matrix addMatrix(Matrix m) throws Exception {
        if (this.row == m.row && this.col == m.col) {
            Matrix result = new Matrix(this.row, this.col);
            for(int i = 0; i < this.row; i++) {
                for(int j = 0; j < this.col; j++) {
                    result.matrix[i][j] = this.matrix[i][j] + m.matrix[i][j];
                }
            }

            return result;
        }
        else {
            throw new Exception("Rows or Columns are not consistent!");
        }
    }

    public Matrix subMatrix(Matrix m) throws Exception {
        if (this.row == m.row && this.col == m.col) {
            Matrix result = new Matrix(this.row, this.col);
            for(int i = 0; i < this.row; i++) {
                for(int j = 0; j < this.col; j++) {
                    result.matrix[i][j] = this.matrix[i][j] - m.matrix[i][j];
                }
            }

            return result;
        }
        else {
            throw new Exception("Rows or Columns are not consistent!");
        }
    }

    public Matrix multiplyMatrix(Matrix m) throws Exception {
        if (this.col == m.row) {
            Matrix result = new Matrix(this.row, m.col);
            for(int i = 0; i < this.row; i++) {
                for(int j = 0; j < m.col; j++) {
                    result.matrix[i][j] = this.matrix[i][j] - m.matrix[i][j];
                }
            }

            return result;
        }
        else {
            throw new Exception("These matrices cannot multiply!");
        }
    }

    public void printMatrix() {
        for(int i = 0; i < this.row; i++) {
            for(int j = 0; j < this.col; j++) {
                System.out.print(this.matrix[i][j] + " ");
            }

            System.out.println();
        }
    }
}
