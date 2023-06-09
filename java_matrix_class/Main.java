import java.util.*;

public class Main {
    // Global loop Flags
    static boolean exitMenu = false;
    static boolean remakeMatrix = true;

    // Asks user to input values row by row
    public static void fillMatrix(Matrix m) {
        Scanner elementInput = new Scanner(System.in);
        System.out.println("\nNow Enter the values of of each row (separate with spaces)!");
        for(int i = 0; i < m.getRow(); i++) {
            System.out.print("\tRow " + i + ": ");
            String rows = elementInput.nextLine();
            String[] rowElements = rows.split(" ", 0);
            int elementCount = 0;
            while(elementCount < rowElements.length || elementCount < m.getCol()) {
                if(elementCount < rowElements.length) {
                    m.setElement(i, elementCount, Integer.parseInt(rowElements[elementCount]));
                } else {
                    m.setElement(i, elementCount, 0);
                }
                elementCount++;
            }

        }
    }


    // Will fill a matrix with random values
    private static void randomMatrix(Matrix m, int matrixSize) {
        Random rand = new Random(System.currentTimeMillis());
        for(int i = 0; i < matrixSize; i++) {
            for(int j = 0; j < matrixSize; j++) {
                m.setElement(i, j, rand.nextFloat());
            }
        }
    }

    // Measures the matrix multiplication function via
    private static void measureMultiplication() throws Exception {
        System.out.print("Please Enter a matrix size (The Matrices will be square): ");
        Scanner anotherOne = new Scanner(System.in);
        String input = anotherOne.nextLine();
        int matrixSize = Integer.parseInt(input);
        Matrix m1 = new Matrix(matrixSize, matrixSize);
        Matrix m2 = new Matrix(matrixSize, matrixSize);

        randomMatrix(m1, matrixSize);
        randomMatrix(m2, matrixSize);
        System.out.println("Measuring Multiplication...\n");
        long start = System.nanoTime();
        Matrix result = m1.multiplyMatrix(m2);
        long end = System.nanoTime();
        System.out.println("\nProgrammed ran for " + (end - start) + "ns\n");

    }

    public static void main(String[] args) {
        System.out.println("Welcome to the MATRIX CALCULATOR!");
        String input;
        do {
            try {
                // Asks for values
                System.out.println("Let's build the FIRST MATRIX!");
                Scanner matrixInput = new Scanner(System.in);

                System.out.print("\tEnter row #: ");
                input = matrixInput.nextLine();
                int firstRow = Integer.parseInt(input);
//                matrixInput.nextLine();

                System.out.print("\tEnter column #: ");
                input = matrixInput.nextLine();
                int firstCol = Integer.parseInt(input);
//                matrixInput.nextLine();

                // Fill matrix
                Matrix matrix1 = new Matrix(firstRow, firstCol);
                fillMatrix(matrix1);

                System.out.println("Let's build the SECOND MATRIX!");

                System.out.print("\tEnter row #: ");
                int secondRow = matrixInput.nextInt();
                matrixInput.nextLine();

                System.out.print("\tEnter column #: ");
                int secondCol = matrixInput.nextInt();
                matrixInput.nextLine();

                // Fill Matrix
                Matrix matrix2 = new Matrix(secondRow, secondCol);
                fillMatrix(matrix2);

                do {
                    try {
                        // Display Menu
                        Scanner menuInput = new Scanner(System.in);
                        System.out.println("Please Select the Following:");
                        System.out.println("\t1. Add Matrices");
                        System.out.println("\t2. Subtract Matrices");
                        System.out.println("\t3. Multiply Matrices");
                        System.out.println("\t4. Change Matrices");
                        System.out.println("\t5. Measure Multiplication");
                        System.out.println("\t6. Quit");

                        input = menuInput.nextLine();
                        int choice = Integer.parseInt(input);
//                        menuInput.nextLine();
                        Matrix resultMatrix;
                        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {
                            throw new Exception("Not a valid Option! Please Try again!");
                        } else {
                            switch (choice) {
                                case 1: // Add
                                    resultMatrix = matrix1.addMatrix(matrix2);
                                    System.out.println("\nSum:");
                                    resultMatrix.printMatrix();
                                    break;
                                case 2: // Subtract
                                    resultMatrix = matrix1.subMatrix(matrix2);
                                    System.out.println("\nDifference:");
                                    resultMatrix.printMatrix();
                                    break;
                                case 3: // Multiply
                                    resultMatrix = matrix1.multiplyMatrix(matrix2);
                                    System.out.println("\nProduct:");
                                    resultMatrix.printMatrix();
                                    break;
                                case 4:
                                    // Set flags to only break out of inner loop
                                    remakeMatrix = true;
                                    exitMenu = true;
                                    break;
                                case 5: // Measure multiplication
                                    measureMultiplication();
                                    break;
                                case 6:
                                    // Set flags to break out of all loops
                                    exitMenu = true;
                                    remakeMatrix = false;
                                    break;
                            }
                        }
                    } catch (Exception e) {
                        System.out.println("ERROR: " + e.getMessage());
                        exitMenu = false;
                    }
                } while(!exitMenu);
            } catch(Exception e) {
                System.out.println("ERROR: " + e.getMessage());
                remakeMatrix = true;
            }

        } while(remakeMatrix);
    }
}
