import java.util.*;

public class Main {
    static boolean exitMenu = false;
    static boolean remakeMatrix = true;

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

    public static void main(String[] args) {
        System.out.println("Welcome to the MATRIX CALCULATOR!");
        String input;
        do {
            try {
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

                Matrix matrix1 = new Matrix(firstRow, firstCol);
                fillMatrix(matrix1);

                System.out.println("Let's build the SECOND MATRIX!");

                System.out.print("\tEnter row #: ");
                int secondRow = matrixInput.nextInt();
                matrixInput.nextLine();

                System.out.print("\tEnter column #: ");
                int secondCol = matrixInput.nextInt();
                matrixInput.nextLine();

                Matrix matrix2 = new Matrix(secondRow, secondCol);
                fillMatrix(matrix2);

                do {
                    try {
                        Scanner menuInput = new Scanner(System.in);
                        System.out.println("Please Select the Following:");
                        System.out.println("\t1. Add Matrices");
                        System.out.println("\t2. Subtract Matrices");
                        System.out.println("\t3. Multiply Matrices");
                        System.out.println("\t4. Change Matrices");
                        System.out.println("\t5. Quit");

                        input = menuInput.nextLine();
                        int choice = Integer.parseInt(input);
//                        menuInput.nextLine();
                        Matrix resultMatrix;
                        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
                            throw new Exception("Not a valid Option! Please Try again!");
                        } else {
                            switch (choice) {
                                case 1:
                                    resultMatrix = matrix1.addMatrix(matrix2);
                                    System.out.println("\nSum:");
                                    resultMatrix.printMatrix();
                                    break;
                                case 2:
                                    resultMatrix = matrix1.subMatrix(matrix2);
                                    System.out.println("\nDifference:");
                                    resultMatrix.printMatrix();
                                    break;
                                case 3:
                                    resultMatrix = matrix1.multiplyMatrix(matrix2);
                                    System.out.println("\nProduct:");
                                    resultMatrix.printMatrix();
                                    break;
                                case 4:
                                    remakeMatrix = true;
                                    exitMenu = true;
                                    break;
                                case 5:
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
