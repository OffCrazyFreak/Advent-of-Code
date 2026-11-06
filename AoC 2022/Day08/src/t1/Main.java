package t1;

import java.util.Scanner;

/**
 * The expedition comes across a peculiar patch of tall trees all planted carefully in a grid.
 * Now, they're curious if this would be a good location for a tree house.
 *
 * First, determine whether there is enough tree cover here to keep a tree house hidden.
 * To do this, you need to count the number of trees that are visible
 * from outside the grid when looking directly along a row or column.
 *
 * The Elves have already launched a quadcopter
 * to generate a map with the height of each tree (your puzzle input).
 *
 * Each tree is represented as a single digit whose value is its height,
 * where 0 is the shortest and 9 is the tallest.
 *
 * A tree is visible if all of the other trees between it and an edge of the grid are shorter than it.
 * Only consider trees in the same row or column;
 * that is, only look up, down, left, or right from any given tree.
 *
 * All of the trees around the edge of the grid are visible.
 *
 * Consider your map; how many trees are visible from outside the grid?
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int gridSize = 99; // 5 for example, 99 for input
        int outsideTrees = gridSize * 4 - 2 * 2;
        int[][] treeGridArray = new int[gridSize][gridSize];

        for (int i = 0; i < gridSize; i++) {
            String input = sc.nextLine();

            String[] treeRowArray = input.split("");
            for (int j = 0; j < treeRowArray.length; j++) {
                treeGridArray[i][j] = Integer.parseInt(treeRowArray[j]);
            }
        }

//        System.out.println(Arrays.deepToString(treeGridArray));

        int visibleInsideTrees = 0;
        for (int i = 1; i < gridSize - 1; i++) {
            for (int j = 1; j < gridSize - 1; j++) {
//                System.out.printf(String.valueOf(treeGridArray[i][j]));

                int treeHiddenFromSides = 0;

                for (int k = 0; k < i; k++) {
                    if (treeGridArray[k][j] >= treeGridArray[i][j]) {
                        treeHiddenFromSides++;
                        break;
                    }
                }
                for (int k = i + 1; k < gridSize; k++) {
                    if (treeGridArray[k][j] >= treeGridArray[i][j]) {
                        treeHiddenFromSides++;
                        break;
                    }
                }
                for (int k = 0; k < j; k++) {
                    if (treeGridArray[i][k] >= treeGridArray[i][j]) {
                        treeHiddenFromSides++;
                        break;
                    }
                }
                for (int k = j + 1; k < gridSize; k++) {
                    if (treeGridArray[i][k] >= treeGridArray[i][j]) {
                        treeHiddenFromSides++;
                        break;
                    }
                }

                if (treeHiddenFromSides < 4) {
                    visibleInsideTrees++;
//                    System.out.println(treeGridArray[i][j]);
                }

            }
//            System.out.println();
        }

        System.out.println("Trees visible: " + (outsideTrees + visibleInsideTrees));
    }
}
