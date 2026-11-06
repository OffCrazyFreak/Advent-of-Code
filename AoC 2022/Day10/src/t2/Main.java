package t2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int cycleCounter = 0;
        int commandCyclesLeft = 0;
        int registerValue = 1;
        String display = "";

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

            if (cycleCounter % 40 == registerValue || cycleCounter % 40 == registerValue - 1 || cycleCounter % 40 == registerValue + 1){
                display += "#";
            } else {
                display += ".";
            }

            cycleCounter++;
            commandCyclesLeft--;

            if (cycleCounter % 40 == 0) {
                display += "\n";
            }
        }

        System.out.println(display);
    }
}