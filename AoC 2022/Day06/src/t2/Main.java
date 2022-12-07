package t2;

import java.util.Scanner;

/**
 * To fix the communication system, you need to add a subroutine to the device
 * that detects a start-of-packet marker in the datastream.
 * In the protocol being used by the Elves, the start of a packet is indicated
 * by a sequence of four characters that are all different.
 *
 * The device will send your subroutine a datastream buffer (your puzzle input);
 * your subroutine needs to identify the first position
 * where the 14 most recently received characters were all different.
 * Specifically, it needs to report the number of characters from the beginning of the buffer
 * to the end of the first such 14-character marker.
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        int markerLength = 14;

        for (int i = 0; i < input.length() - markerLength; i++) {
            boolean foundMarker = true;
            String subInput = input.substring(i, i + markerLength);
//            System.out.println(subInput);

            for (int j = 0; j < markerLength; j++) {
                char testChar = input.charAt(i + j);
                long count = subInput.chars().filter(ch -> ch == testChar).count();

                if (count > 1) {
                    foundMarker = false;
                    break;
                }

            }

            if (foundMarker) {
                System.out.println(subInput + " found at " + (i + markerLength));
                break;
            }
        }
    }
}
