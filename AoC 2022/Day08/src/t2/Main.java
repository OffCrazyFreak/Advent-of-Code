package t2;

import java.util.Scanner;

/**
 * The expedition comes across a peculiar patch of tall trees all planted carefully in a grid.
 * Now, they're curious if this would be a good location for a tree house.
 *
 * The Elves have already launched a quadcopter
 * to generate a map with the height of each tree (your puzzle input).
 *
 * Each tree is represented as a single digit whose value is its height,
 * where 0 is the shortest and 9 is the tallest.
 *
 * Content with the amount of tree cover available,
 * the Elves just need to know the best spot to build their tree house:
 * they would like to be able to see a lot of trees.
 *
 * To measure the viewing distance from a given tree, look up, down, left, and right from that tree;
 * stop if you reach an edge or at the first tree that is the same height
 * or taller than the tree under consideration.
 *
 * A tree's scenic score is found by multiplying together its
 * viewing distance in each of the four directions.
 *
 * Consider each tree on your map. What is the highest scenic score possible for any tree?
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int gridSize = 99; // 5 for example, 99 for input
        int[][] treeGridArray = new int[gridSize][gridSize];

        for (int i = 0; i < gridSize; i++) {
            String input = sc.nextLine();

            String[] treeRowArray = input.split("");
            for (int j = 0; j < treeRowArray.length; j++) {
                treeGridArray[i][j] = Integer.parseInt(treeRowArray[j]);
            }
        }

//        System.out.println(Arrays.deepToString(treeGridArray));

        int maxScenicScore = 0;
        for (int i = 1; i < gridSize - 1; i++) {
            for (int j = 1; j < gridSize - 1; j++) {
//                System.out.printf(String.valueOf(treeGridArray[i][j]));

                int visibleTreesFromHouseUp = 0;
                int visibleTreesFromHouseDown = 0;
                int visibleTreesFromHouseLeft = 0;
                int visibleTreesFromHouseRight = 0;

                for (int k = i - 1; k >= 0; k--) {
                    if (treeGridArray[k][j] >= treeGridArray[i][j]) {
                        visibleTreesFromHouseUp++;
                        break;
                    }
                    visibleTreesFromHouseUp++;
                }
                for (int k = i + 1; k < gridSize; k++) {
                    if (treeGridArray[k][j] >= treeGridArray[i][j]) {
                        visibleTreesFromHouseDown++;
                        break;
                    }
                    visibleTreesFromHouseDown++;
                }
                for (int k = j - 1; k >= 0; k--) {
                    if (treeGridArray[i][k] >= treeGridArray[i][j]) {
                        visibleTreesFromHouseLeft++;
                        break;
                    }
                    visibleTreesFromHouseLeft++;
                }
                for (int k = j + 1; k < gridSize; k++) {
                    if (treeGridArray[i][k] >= treeGridArray[i][j]) {
                        visibleTreesFromHouseRight++;
                        break;
                    }
                    visibleTreesFromHouseRight++;
                }

                int treeScenicScore = visibleTreesFromHouseUp * visibleTreesFromHouseLeft
                        * visibleTreesFromHouseRight * visibleTreesFromHouseDown;

                if (treeScenicScore > maxScenicScore) {
                    maxScenicScore = treeScenicScore;

//                    System.out.println("U:" + visibleTreesFromHouseUp + " L:" + visibleTreesFromHouseLeft
//                            + " R:" + visibleTreesFromHouseRight + " D:" + visibleTreesFromHouseDown);
//                    System.out.println(treeGridArray[i][j] + " | " + treeScenicScore);
                }
            }
//            System.out.println();
        }

        System.out.println("Max scenic score: " + maxScenicScore);
    }
}
