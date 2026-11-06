package t1;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int gridSize = 1500; // can be defined by counting U-D or L-R but just big number is simpler
        int startingPos = gridSize / 2;

        boolean[][] visitedGridFields = new boolean[gridSize][gridSize];
//        System.out.println(Arrays.deepToString(visitedGridFields));
        visitedGridFields[startingPos][startingPos] = true;
        int fieldsVisited = 0;

        int[] H = {startingPos, startingPos};
        int[] T = {startingPos, startingPos};
//        System.out.println(Arrays.toString(H) + "    " + Arrays.toString(T));

        Scanner sc = new Scanner(System.in);

        while(sc.hasNextLine()) {
            String input = sc.nextLine();

            if (input == "")
                break;

            String direction = input.split(" ")[0];
            int distance = Integer.parseInt(input.split(" ")[1]);
//            System.out.println(direction + " " + distance);

            for (int i = 0; i < distance; i++) {
                if (direction.equals("U")) {
                    H[0] = H[0] - 1; // move head in direction

                    // if head and tail more than 1 space apart
                    if (T[0] - H[0] > 1) {
                        T[0] = T[0] - 1; // move tail in direction
                        T[1] = H[1]; // move tail diagonally if needed

                        visitedGridFields[T[0]][T[1]] = true;
                    }
                } else if (direction.equals("D")) {
                    H[0]++; // move head in direction

                    // if head and tail more than 1 space apart
                    if (H[0] - T[0] > 1) {
                        T[0]++; // move tail in direction
                        T[1] = H[1]; // move tail diagonally if needed

                        visitedGridFields[T[0]][T[1]] = true;
                    }
                } else if (direction.equals("L")) {
                    H[1]--; // move head in direction

                    // if head and tail more than 1 space apart
                    if (T[1] - H[1] > 1) {
                        T[1]--; // move tail in direction
                        T[0] = H[0]; // move tail diagonally if needed

                        visitedGridFields[T[0]][T[1]] = true;
                    }
                } else if (direction.equals("R")) {
                    H[1]++; // move head in direction

                    // if head and tail more than 1 space apart
                    if (H[1] - T[1] > 1) {
                        T[1]++; // move tail in direction
                        T[0] = H[0]; // move tail diagonally if needed

                        visitedGridFields[T[0]][T[1]] = true;
                    }
                }
            }
        }

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (visitedGridFields[i][j]) {
                    fieldsVisited++;
//                    System.out.printf("#");
                } else {
//                    System.out.printf(".");
                }
            }
//            System.out.println();
        }
        System.out.println("Fields visited: " + fieldsVisited);
    }
}