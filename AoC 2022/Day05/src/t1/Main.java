package t1;

import java.util.LinkedList;
import java.util.Scanner;

/**
 * Supplies are stored in stacks of marked crates,
 * but because the needed supplies are buried under many other crates,
 * the crates need to be rearranged.
 *
 * The ship has a giant cargo crane capable of moving crates between stacks.
 *
 * The Elves don't want to interrupt the crane operator during this delicate procedure,
 * but they forgot to ask her which crate will end up where,
 * and they want to be ready to unload them as soon as possible so they can embark.
 * They do, however, have a drawing of the starting stacks of crates and the rearrangement procedure (your puzzle input).
 *
 * In each step of the procedure, a quantity of crates is moved from one stack to a different stack.
 * Crates are moved one at a time.
 *
 * After the rearrangement procedure completes, what crate ends up on top of each stack?
 */
public class Main {
    public static void main(String[] args) {

        LinkedList<String> stacks = new LinkedList<>();

//        example stacks
//        stacks.add("ZN");
//        stacks.add("MCD");
//        stacks.add("P");

//        input stacks
        stacks.add("FHBVRQDP");
        stacks.add("LDZQWV");
        stacks.add("HLZQGRPC");
        stacks.add("RDHFJVB");
        stacks.add("ZWLC");
        stacks.add("JRPNTGVM");
        stacks.add("JRLVMBS");
        stacks.add("DPJ");
        stacks.add("DCNWV");

        Scanner sc = new Scanner(System.in);
        String input;

        while (sc.hasNextLine()) {
            input = sc.nextLine();
            if (input == "")
                break;

            int createsToMove = Integer.parseInt(input.split(" ")[1]);
            int fromStack = Integer.parseInt(input.split(" ")[3]);
            int toStack = Integer.parseInt(input.split(" ")[5]);

//            System.out.println("move " + createsToMove + " from " + fromstacks + " to " + tostacks);


            String stackRemoveFrom;
            String stackAddto;
            if (fromStack > toStack) {
                stackRemoveFrom = stacks.remove(fromStack - 1);
                stackAddto = stacks.remove(toStack - 1);
            } else {
                stackAddto = stacks.remove(toStack - 1);
                stackRemoveFrom = stacks.remove(fromStack - 1);
            }

            for (int i = 0; i < createsToMove; i++) {
                stackAddto = stackAddto + stackRemoveFrom.substring(stackRemoveFrom.length() - 1);
                stackRemoveFrom = stackRemoveFrom.substring(0, stackRemoveFrom.length() - 1);
            }

            if (fromStack > toStack) {
                stacks.add(toStack - 1, stackAddto);
                stacks.add(fromStack - 1, stackRemoveFrom);
            } else {
                stacks.add(fromStack - 1, stackRemoveFrom);
                stacks.add(toStack - 1, stackAddto);
            }

//            System.out.println(stacks);
        }

        String topCrates = "";
        for (int i = 0; i < stacks.size(); i++) {
            if (stacks.get(i).length() > 0)
                topCrates += stacks.get(i).substring(stacks.get(i).length() - 1);
        }
        System.out.println(topCrates);
    }
}
