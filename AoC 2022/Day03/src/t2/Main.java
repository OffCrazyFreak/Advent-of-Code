package t2;

import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        int score = 0;

        LinkedList<String> groupBackpacksList = new LinkedList<>();

        while (sc.hasNextLine()) {
            input = sc.nextLine();

            if (input == "")
                break;

            groupBackpacksList.add(input);

            for (int i = 0; i < 2; i++) {
                input = sc.nextLine();

                groupBackpacksList.add(input);
            }

            String backpack0 = groupBackpacksList.get(0);
            String backpack1 = groupBackpacksList.get(1);
            String backpack2 = groupBackpacksList.get(2);

            for (int i = 0; i < backpack0.length(); i++) {
                if (backpack1.contains(backpack0.substring(i, i + 1)) &&
                        backpack2.contains(backpack0.substring(i, i + 1))) {
                    score += (backpack0.charAt(i) - 38);

                    if(Character.isLowerCase(backpack0.charAt(i)))
                        score -= 58;

                    break;
                }
            }
            groupBackpacksList.clear();
        }

        System.out.println(score);
    }
}