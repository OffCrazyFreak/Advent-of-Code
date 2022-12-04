package t1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        int score = 0;

        while (sc.hasNextLine()) {
            input = sc.nextLine();
            if (input == "")
                break;

            String comp1 = input.substring(0, input.length() / 2);
            String comp2 = input.substring(input.length() / 2);

            for (int i = 0; i < comp1.length(); i++) {
                if (comp2.contains(comp1.substring(i, i + 1))) {
                    score += (comp1.charAt(i) - 38);

                    if(Character.isLowerCase(comp1.charAt(i)))
                        score -= 58;

                    break;
                }
            }

        }

        System.out.println(score);
    }
}