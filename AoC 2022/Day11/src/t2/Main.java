package t2;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * NOT WORKING - numbers get too big, there has to be a way to limit their size (primes?)
 */

public class Main {
    public static void main(String[] args) {
//        example
        int[] mInspectedArray = new int[4];
        LinkedList<Integer> m0Items = new LinkedList<>(List.of(79, 98));
        LinkedList<Integer> m1Items = new LinkedList<>(List.of(54, 65, 75, 74));
        LinkedList<Integer> m2Items = new LinkedList<>(List.of(79, 60, 97));
        LinkedList<Integer> m3Items = new LinkedList<>(List.of(74));

        for (int i = 0; i < 10000; i++) {
            while (!m0Items.isEmpty()) {
                int newItem = m0Items.remove(0);
                newItem *= 19;
                mInspectedArray[0]++;


                if (newItem % 23 == 0) {
                    m2Items.add(newItem);
                } else {
                    m3Items.add(newItem);
                }
            }
            while (!m1Items.isEmpty()) {
                int newItem = m1Items.remove(0);
                newItem += 6;
                mInspectedArray[1]++;


                if (newItem % 19 == 0) {
                    m2Items.add(newItem);
                } else {
                    m0Items.add(newItem);
                }
            }
            while (!m2Items.isEmpty()) {
                int newItem = m2Items.remove(0);
                newItem *= newItem;
                mInspectedArray[2]++;


                if (newItem % 13 == 0) {
                    m1Items.add(newItem);
                } else {
                    m3Items.add(newItem);
                }
            }
            while (!m3Items.isEmpty()) {
                int newItem = m3Items.remove(0);
                newItem += 3;
                mInspectedArray[3]++;


                if (newItem % 17 == 0) {
                    m0Items.add(newItem);
                } else {
                    m1Items.add(newItem);
                }
            }

//            System.out.println(m0Items + " " + m1Items + " " + m2Items + " " + m3Items);
        }


        /*int[] mInspectedArray = new int[8];
        LinkedList<Integer> m0Items = new LinkedList<>(List.of(77, 69, 76, 77, 50, 58));
        LinkedList<Integer> m1Items = new LinkedList<>(List.of(75, 70, 82, 83, 96, 64, 62));
        LinkedList<Integer> m2Items = new LinkedList<>(List.of(53));
        LinkedList<Integer> m3Items = new LinkedList<>(List.of(85, 64, 93, 64, 99));
        LinkedList<Integer> m4Items = new LinkedList<>(List.of(61, 92, 71));
        LinkedList<Integer> m5Items = new LinkedList<>(List.of(79, 73, 50, 90));
        LinkedList<Integer> m6Items = new LinkedList<>(List.of(50, 89));
        LinkedList<Integer> m7Items = new LinkedList<>(List.of(83, 56, 64, 58, 93, 91, 56, 65));

        for (int i = 0; i < 10000; i++) {
            while (!m0Items.isEmpty()) {
                int newItem = m0Items.remove(0);
                newItem *= 11;
                mInspectedArray[0]++;

                if (newItem % 5 == 0) {
                    m1Items.add(newItem);
                } else {
                    m5Items.add(newItem);
                }
            }
            while (!m1Items.isEmpty()) {
                int newItem = m1Items.remove(0);
                newItem += 8;
                mInspectedArray[1]++;

                if (newItem % 17 == 0) {
                    m5Items.add(newItem);
                } else {
                    m6Items.add(newItem);
                }
            }
            while (!m2Items.isEmpty()) {
                int newItem = m2Items.remove(0);
                newItem *= 3;
                mInspectedArray[2]++;

                if (newItem % 2 == 0) {
                    m0Items.add(newItem);
                } else {
                    m7Items.add(newItem);
                }
            }
            while (!m3Items.isEmpty()) {
                int newItem = m3Items.remove(0);
                newItem += 4;
                mInspectedArray[3]++;

                if (newItem % 7 == 0) {
                    m7Items.add(newItem);
                } else {
                    m2Items.add(newItem);
                }
            }
            while (!m4Items.isEmpty()) {
                int newItem = m4Items.remove(0);
                newItem *= newItem;
                mInspectedArray[4]++;
                System.out.println(newItem);

                if (newItem % 3 == 0) {
                    m2Items.add(newItem);
                } else {
                    m3Items.add(newItem);
                }
            }
            while (!m5Items.isEmpty()) {
                int newItem = m5Items.remove(0);
                newItem += 2;
                mInspectedArray[5]++;

                if (newItem % 11 == 0) {
                    m4Items.add(newItem);
                } else {
                    m6Items.add(newItem);
                }
            }
            while (!m6Items.isEmpty()) {
                int newItem = m6Items.remove(0);
                newItem += 3;
                mInspectedArray[6]++;

                if (newItem % 13 == 0) {
                    m4Items.add(newItem);
                } else {
                    m3Items.add(newItem);
                }
            }
            while (!m7Items.isEmpty()) {
                int newItem = m7Items.remove(0);
                newItem += 5;
                mInspectedArray[7]++;

                if (newItem % 19 == 0) {
                    m1Items.add(newItem);
                } else {
                    m0Items.add(newItem);
                }
            }

//            System.out.println(m0Items + " " + m1Items + " " + m2Items + " " + m3Items);
        }*/


        System.out.println(Arrays.toString(mInspectedArray));
    }
}