package t1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int cycleCounter = 0;
        int commandCyclesLeft = 0;
        int registerValue = 1;
        int sumOfDesiredCyclesValues = 0;

        Scanner sc = new Scanner(System.in);
        String input = "";

        while(sc.hasNextLine()) {
            if (commandCyclesLeft == 0) {
                if (input.split(" ")[0].equals("addx")) {
                    registerValue += Integer.parseInt(input.split(" ")[1]);
                }

//                System.out.println("After cycle " + cycleCounter + " the register value is " + registerValue);

                input = sc.nextLine();

                if (input == "")
                    break;

                if (input.split(" ")[0].equals("addx")) {
                    commandCyclesLeft = 2;
                } else {
                    commandCyclesLeft = 1;
                }
            }


            cycleCounter++;
            commandCyclesLeft--;

            if (cycleCounter == 20 || cycleCounter == 60 || cycleCounter == 100 || cycleCounter == 140 ||
                    cycleCounter == 180 || cycleCounter == 220) {
//                System.out.println("After cycle " + cycleCounter + " the register value is " + registerValue);
                sumOfDesiredCyclesValues += cycleCounter * registerValue;
            }
        }

        System.out.println(sumOfDesiredCyclesValues);
    }
}