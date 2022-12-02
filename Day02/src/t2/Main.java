package t2;

import java.util.Scanner;

/**
 * "The first column is what your opponent is going to play: A for Rock, B for Paper, and C for Scissors."
 * The Elf finishes helping with the tent and sneaks back over to you.
 * "Anyway, the second column says how the round needs to end:
 * X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win. Good luck!"
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
            // X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win

            String oppPlay = input.split(" ")[0];
            String outcome = input.split(" ")[1];

            String response = null;
            switch (outcome) {
                case "Z" -> {
                    // win
                    score += 6;

                    if (oppPlay.equals("A"))
                        response = "Y";
                    if (oppPlay.equals("B"))
                        response = "Z";
                    if (oppPlay.equals("C"))
                        response = "X";
                }
                case "Y" -> {
                    // draw
                    score += 3;

                    if (oppPlay.equals("A"))
                        response = "X";
                    if (oppPlay.equals("B"))
                        response = "Y";
                    if (oppPlay.equals("C"))
                        response = "Z";
                }
                case "X" -> {
                    // lose

                    if (oppPlay.equals("A"))
                        response = "Z";
                    if (oppPlay.equals("B"))
                        response = "X";
                    if (oppPlay.equals("C"))
                        response = "Y";
                }
            }

            switch (response) {
                case "X" -> score += 1;
                case "Y" -> score += 2;
                case "Z" -> score += 3;
            }
        }

        System.out.println("Final score: " + score);
    }
}
