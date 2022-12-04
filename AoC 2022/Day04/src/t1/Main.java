package t1;

import java.util.LinkedList;
import java.util.Scanner;

/**
 * Every section has a unique ID number, and each Elf is assigned a range of section IDs.
 * However, as some of the Elves compare their section assignments with each other,
 * they've noticed that many of the assignments overlap.
 * To try to quickly find overlaps and reduce duplicated effort,
 * the Elves pair up and make a big list of the section assignments for each pair (your puzzle input).
 * Some of the pairs have noticed that one of their assignments fully contains the other.
 * For example, 2-8 fully contains 3-7, and 6-6 is fully contained by 4-6.
 *
 * In how many assignment pairs does one range fully contain the other?
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        int fullOverlapPairs = 0;

        while (sc.hasNextLine()) {
            input = sc.nextLine();
            if (input == "")
                break;

            String sections0 = input.split(",")[0];
            String sections1 = input.split(",")[1];

            LinkedList<Integer> sections0List = new LinkedList<>();
            LinkedList<Integer> sections1List = new LinkedList<>();

            for (int i = Integer.parseInt(sections0.split("-")[0]); i <= Integer.parseInt(sections0.split("-")[1]); i++) {
                sections0List.add(i);
            }
            for (int i = Integer.parseInt(sections1.split("-")[0]); i <= Integer.parseInt(sections1.split("-")[1]); i++) {
                sections1List.add(i);
            }

            if (sections0List.containsAll(sections1List) || sections1List.containsAll(sections0List)) {
                fullOverlapPairs++;
            }

        }

        System.out.println(fullOverlapPairs);
    }
}