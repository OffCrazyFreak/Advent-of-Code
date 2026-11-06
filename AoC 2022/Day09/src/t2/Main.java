package t2;

import java.util.*;

/**
 * NOT WORKING
 */

public class Main {
    public static void main(String[] args) {
        int gridSize = 30;
        int startingPos = gridSize / 2;

        boolean[][] visitedGridFields = new boolean[gridSize][gridSize];
//        System.out.println(Arrays.deepToString(visitedGridFields));
        visitedGridFields[startingPos][startingPos] = true;
        int fieldsVisited = 0;

        LinkedHashMap<String, int[]> knotsMap = new LinkedHashMap<>();
        knotsMap.put("H", new int[]{startingPos, startingPos});
        knotsMap.put("1", new int[]{startingPos, startingPos});
        knotsMap.put("2", new int[]{startingPos, startingPos});
        knotsMap.put("3", new int[]{startingPos, startingPos});
        knotsMap.put("4", new int[]{startingPos, startingPos});
        knotsMap.put("5", new int[]{startingPos, startingPos});
        knotsMap.put("6", new int[]{startingPos, startingPos});
        knotsMap.put("7", new int[]{startingPos, startingPos});
        knotsMap.put("8", new int[]{startingPos, startingPos});
        knotsMap.put("9", new int[]{startingPos, startingPos});
//        System.out.println(knotsMap.keySet());
//        System.out.println(Arrays.toString(knotsMap.get("H")));

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
                    knotsMap.put("H", new int[]{knotsMap.get("H")[0]-1, knotsMap.get("H")[1]}); // move head in direction

                    for (int j = 1; j < knotsMap.size(); j++) {
                        String keyAtIndex = (String) knotsMap.keySet().toArray()[j];
                        String keyAtSmallerIndex = (String) knotsMap.keySet().toArray()[j - 1];

                        // if knot before and knot after more than 1 space apart
                        if (knotsMap.get(keyAtIndex)[0] - knotsMap.get(keyAtSmallerIndex)[0] > 1) {
                            knotsMap.put(keyAtIndex, new int[]{knotsMap.get(keyAtIndex)[0]-1,
                                    knotsMap.get(keyAtSmallerIndex)[1]}); // move knot after in direction and diagonally if needed

                            visitedGridFields[knotsMap.get("9")[0]][knotsMap.get("9")[1]] = true;
                        }
                    }
                } else if (direction.equals("D")) {
                    knotsMap.put("H", new int[]{knotsMap.get("H")[0]+1, knotsMap.get("H")[1]}); // move head in direction

                    for (int j = 1; j < knotsMap.size(); j++) {
                        String keyAtIndex = (String) knotsMap.keySet().toArray()[j];
                        String keyAtSmallerIndex = (String) knotsMap.keySet().toArray()[j - 1];

                        // if knot before and knot after more than 1 space apart
                        if (knotsMap.get(keyAtSmallerIndex)[0] - knotsMap.get(keyAtIndex)[0] > 1) {
                            knotsMap.put(keyAtIndex, new int[]{knotsMap.get(keyAtIndex)[0]+1,
                                    knotsMap.get(keyAtSmallerIndex)[1]}); // move knot after in direction and diagonally if needed

                            visitedGridFields[knotsMap.get("9")[0]][knotsMap.get("9")[1]] = true;
                        }
                    }
                } else if (direction.equals("L")) {
                    knotsMap.put("H", new int[]{knotsMap.get("H")[0], knotsMap.get("H")[1]-1}); // move head in direction

                    for (int j = 1; j < knotsMap.size(); j++) {
                        String keyAtIndex = (String) knotsMap.keySet().toArray()[j];
                        String keyAtSmallerIndex = (String) knotsMap.keySet().toArray()[j - 1];

                        // if knot before and knot after more than 1 space apart
                        if (knotsMap.get(keyAtIndex)[1] - knotsMap.get(keyAtSmallerIndex)[1] > 1) {
                            knotsMap.put(keyAtIndex, new int[]{knotsMap.get(keyAtIndex)[0],
                                    knotsMap.get(keyAtIndex)[1]-1}); // move knot after in direction and diagonally if needed

                            visitedGridFields[knotsMap.get("9")[0]][knotsMap.get("9")[1]] = true;
                        }
                    }
                } else if (direction.equals("R")) {
                    knotsMap.put("H", new int[]{knotsMap.get("H")[0], knotsMap.get("H")[1]+1}); // move head in direction

                    for (int j = 1; j < knotsMap.size(); j++) {
                        String keyAtIndex = (String) knotsMap.keySet().toArray()[j];
                        String keyAtSmallerIndex = (String) knotsMap.keySet().toArray()[j - 1];

                        // if knot before and knot after more than 1 space apart
                        if (knotsMap.get(keyAtSmallerIndex)[1] - knotsMap.get(keyAtIndex)[1] > 1) {
                            knotsMap.put(keyAtIndex, new int[]{knotsMap.get(keyAtIndex)[0],
                                    knotsMap.get(keyAtIndex)[1]+1}); // move knot after in direction and diagonally if needed

                            visitedGridFields[knotsMap.get("9")[0]][knotsMap.get("9")[1]] = true;
                        }
                    }
                }

                for (Map.Entry<String, int[]> entry : knotsMap.entrySet()) {
                    System.out.printf(Arrays.toString(entry.getValue()) + " ");
                }
                System.out.println();
            }
        }

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (visitedGridFields[i][j]) {
                    fieldsVisited++;
                    System.out.printf("#");
                } else {
                    System.out.printf(".");
                }
            }
            System.out.println();
        }
        System.out.println("Fields visited: " + fieldsVisited);
    }
}