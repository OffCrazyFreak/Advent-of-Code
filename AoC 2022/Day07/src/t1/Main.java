package t1;

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
 * Find all of the directories with a total size of at most 100000.
 * What is the sum of the total sizes of those directories?
 */

public class Main {
    public static int sum = 0;

    public static int calcFolder(Scanner sc) {
        String input;

        int dirSum = 0;

        while (true) {
            input = sc.nextLine();

            if (input == "")
                return dirSum;

            if (input.split(" ")[0].equals("$")) {
                if (input.split(" ")[1].equals("cd")) {

                    if (input.split(" ")[2].equals("..")) {
                        if (dirSum <= 100000) {
                            sum += dirSum;
                        }

                        return dirSum;
                    }

                    dirSum += calcFolder(sc);
                }
            } else if (!input.split(" ")[0].equals("dir")) {
                dirSum += Integer.parseInt(input.split(" ")[0]);
            }

        }

    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int subDirSum = calcFolder(sc);
        if (subDirSum <= 100000) {
            sum += subDirSum;
        }

        System.out.println(sum);

    }
}
