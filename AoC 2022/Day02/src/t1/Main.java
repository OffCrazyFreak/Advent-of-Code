package t1;

import java.util.Scanner;

/**
 * "The first column is what your opponent is going to play: A for Rock, B for Paper, and C for Scissors.
 * The second column--" Suddenly, the Elf is called away to help with someone's tent.
 *
 * The second column, you reason, must be what you should play in response:
 * X for Rock, Y for Paper, and Z for Scissors.
 * Winning every time would be suspicious, so the responses must have been carefully chosen.
 *
 * The winner of the whole tournament is the player with the highest score.
 * Your total score is the sum of your scores for each round.
 * The score for a single round is the score for the shape you selected
 * (1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round
 * (0 if you lost, 3 if the round was a draw, and 6 if you won).
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        int score = 0;

        while (sc.hasNextLine()) {
            input = sc.nextLine();
            if (input == "")
                break;

            // A for Rock, B for Paper, and C for Scissors
            // X for Rock, Y for Paper, and Z for Scissors

            String oppPlay = input.split(" ")[0];
            String response = input.split(" ")[1];

            switch (response) {
                case "X" -> score += 1;
                case "Y" -> score += 2;
                case "Z" -> score += 3;
            }

            if ((oppPlay.equals("A") && response.equals("Y")) ||
                    (oppPlay.equals("B") && response.equals("Z")) ||
                    (oppPlay.equals("C") && response.equals("X"))) {
                // win
                score += 6;
            } else if ((oppPlay.equals("A") && response.equals("X")) ||
                    (oppPlay.equals("B") && response.equals("Y")) ||
                    (oppPlay.equals("C") && response.equals("Z"))) {
                // draw
                score += 3;
            }
        }

        System.out.println("Final score: " + score);
    }
}
