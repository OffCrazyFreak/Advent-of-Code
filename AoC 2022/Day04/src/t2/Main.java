package t2;

import java.util.LinkedList;
import java.util.Scanner;

/**
 * Every section has a unique ID number, and each Elf is assigned a range of section IDs.
 * However, as some of the Elves compare their section assignments with each other,
 * they've noticed that many of the assignments overlap.
 * To try to quickly find overlaps and reduce duplicated effort,
 * the Elves pair up and make a big list of the section assignments for each pair (your puzzle input).
 * Instead, the Elves would like to know the number of pairs that overlap at all.
 * In the above example, the first two pairs (2-4,6-8 and 2-3,4-5) don't overlap,
 * while the remaining four pairs (5-7,7-9, 2-8,3-7, 6-6,4-6, and 2-6,4-8) do overlap:
 *
 * In how many assignment pairs do the ranges overlap?
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        int anyOverlapPairs = 0;

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

            for (Integer section : sections0List) {
                if (sections1List.contains(section)) {
                    anyOverlapPairs++;
                    break;
                }
            }
        }

        System.out.println(anyOverlapPairs);
    }
}