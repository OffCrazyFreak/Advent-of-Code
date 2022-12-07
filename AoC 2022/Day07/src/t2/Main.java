package t2;

import java.util.LinkedList;
import java.util.Scanner;

/**
 * You browse around the filesystem to assess the situation
 * and save the resulting terminal output (your puzzle input).
 * Within the terminal output, lines that begin with $ are commands you executed.
 *
 * Since the disk is full, your first step should probably be
 * to find directories that are good candidates for deletion.
 * To do this, you need to determine the total size of each directory.
 * The total size of a directory is the sum of the sizes of the files it contains,
 * directly or indirectly. (Directories themselves do not count as having any intrinsic size.)
 *
 * The total disk space available to the filesystem is 70000000.
 * To run the update, you need unused space of at least 30000000.
 *
 * Find the smallest directory that, if deleted,
 * would free up enough space on the filesystem to run the update.
 * What is the total size of that directory?
 */

public class Main {
    public static int minValidFolderSize = Integer.MAX_VALUE;
    public static int currentLine = 0;

    public static int calcFolder(LinkedList<String> inputList, int spaceNeeded) {
        int dirSum = 0;

        while (currentLine < inputList.size()) {
            String input = inputList.get(currentLine);
            currentLine++;

            if (input.split(" ")[0].equals("$")) {
                if (input.split(" ")[1].equals("cd")) {

                    if (input.split(" ")[2].equals("..")) {
                        if (dirSum >= spaceNeeded && dirSum < minValidFolderSize) {
                            minValidFolderSize = dirSum;
                        }

                        return dirSum;
                    }

                    dirSum += calcFolder(inputList, spaceNeeded);
                }
            } else if (!input.split(" ")[0].equals("dir")) {
                dirSum += Integer.parseInt(input.split(" ")[0]);
            }
        }

        return dirSum;
    }

    public static void main(String[] args) {

        int totalSpace = 70000000;
        int spaceNeededForUpdate = 30000000;

        Scanner sc = new Scanner(System.in);
        LinkedList<String> inputList = new LinkedList<>();

        while (sc.hasNextLine()) {
            String input = sc.nextLine();

            if (input == "")
                break;

            inputList.add(input);
        }

        int filledSpace = 0;
        for (String input : inputList) {
            if (!input.split(" ")[0].equals("$") && !input.split(" ")[0].equals("dir")) {
                filledSpace += Integer.parseInt(input.split(" ")[0]);
            }
        }

        int spaceNeeded = spaceNeededForUpdate - (totalSpace - filledSpace);

//        System.out.println("Filled up: " + filledSpace);
//        System.out.println("Available: " + (totalSpace - filledSpace));
//        System.out.println("Need: " + spaceNeeded);

        int dirSum = calcFolder(inputList, spaceNeeded);
        if (dirSum >= spaceNeeded && dirSum < minValidFolderSize) {
            minValidFolderSize = dirSum;
        }

        System.out.println("minValidFolderSize: " + minValidFolderSize);
    }
}
