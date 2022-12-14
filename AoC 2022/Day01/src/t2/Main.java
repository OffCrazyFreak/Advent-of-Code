package t2;

import java.util.*;

/**
 * The Elves take turns writing down the number of Calories contained by the various meals, snacks, rations, etc.
 * that they've brought with them, one item per line.
 * Each Elf separates their own inventory from the previous Elf's inventory (if any) by a blank line.
 *
 * Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        HashMap<Integer, Integer> caloriesSumMap = new LinkedHashMap<>();
        int key = 0;
        int sum = 0;

        while (sc.hasNextLine()) {
            input = sc.nextLine();

//            input must end with empty line follow by string "EXIT" in a new line (because of the empty lines in input)
            if (Objects.equals(input, "EXIT")) {
                break;
            }

            if (input != "") {
                sum += Integer.parseInt(input);
            } else {
                caloriesSumMap.put(key, sum);
                key++;
                sum = 0;
            }

        }

        List<Integer> sortedValues = caloriesSumMap.entrySet().stream().sorted(Map.Entry.<Integer, Integer>comparingByValue().reversed()).limit(3).map(Map.Entry::getValue).toList();

        System.out.println("Sum of top 3: " + (sortedValues.get(0) + sortedValues.get(1) + sortedValues.get(2)));
    }
}
