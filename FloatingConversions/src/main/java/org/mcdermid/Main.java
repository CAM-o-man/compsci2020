package org.mcdermid;

import java.util.Scanner;
/**
 * Hello world!
 *
 */
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); //scanner for stdin
        System.out.println("Radix Calculator");
        System.out.println("Please enter your conversion below.");
        System.out.println("For help, type help.");
        boolean SIGSTOP = false;
        do {
            System.out.print("$ ");
            String s = input.nextLine();

        } while (!SIGSTOP);
    }

    public static void parseCommand(String cmd) {
        switch (cmd) {
            case "help":
                System.out.println("Type numbers ");
        }
    }
}

