package org.mcdermid;

import java.util.Scanner;
/**
 * Conversion Lab
 * Connor McDermid
 * 2020-02-18
 *
 */
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); //scanner for stdin
        System.out.println("Radix Calculator");
        System.out.println("Please enter your conversion below.");
        System.out.println("For help, type help.");
        boolean SIGSTOP = true;
        do {
            System.out.print("* ");
            String s = input.nextLine();
            if (s.equals("stop")) {
                SIGSTOP = false;
                break;
            }
            parseCommand(s);

        } while (SIGSTOP);
    }

    public static void parseCommand(String cmd) {
        Scanner input = new Scanner(System.in);
        if ("help".equals(cmd)) {
            System.out.println("Type numbers with agreed prefixes." +
                    "\n For hex, prefix your number with '0x'\n" +
                    "For binary, prefix your number with '0b'\n" +
                    "For octal, prefix your number with a '0'\n" +
                    "For BCD, please prefix your number with '0c'.");
        } else if (cmd.startsWith("0x")) {
            Hexadecimal hex = new Hexadecimal(cmd.substring(2));
            System.out.println("What would you like to convert your hex number to?");
            System.out.println("Decimal, binary, octal, or BCD?");
            String usr = input.nextLine();
            switch (usr) {
                case "decimal":
                case "Decimal":
                    Decimal d = Decimal.parseDecimal(hex);
                    System.out.println(d.getNumber());
                    break;
                case "binary":
                case "Binary":
                    Binary b = Binary.parseBinary(Decimal.parseDecimal(hex));
                    System.out.println(b.getNumber());
                    break;
                case "octal":
                case "Octal":
                    Octal o = Octal.parseOctal(Decimal.parseDecimal(hex));
                    System.out.println(o.val);
                    break;
                case "bcd":
                case "BCD":
                    BCD c = BCD.parseBCD(Decimal.parseDecimal(hex));
                    System.out.println(c.getNumber());
                    break;
                default:
                    System.out.println("Not a valid input. Sorry.");
                    break;
            }

        } else if (cmd.startsWith("0b")) {
            Binary bin = new Binary(cmd.substring(2));
            System.out.println("What would you like to convert your binary number to?");
            System.out.println("Decimal, hex, octal, or BCD?");
            String usr = input.nextLine();
            switch (usr) {
                case "decimal":
                case "Decimal":
                    Decimal d = Decimal.parseDecimal(bin);
                    System.out.println(d.getNumber());
                    break;
                case "hex":
                case "Hex":
                    Hexadecimal h = Hexadecimal.parseHex(Decimal.parseDecimal(bin));
                    System.out.println(h.val);
                    break;
                case "octal":
                case "Octal":
                    Octal o = Octal.parseOctal(Decimal.parseDecimal(bin));
                    System.out.println(o.val);
                    break;
                case "BCD":
                case "bcd":
                    BCD c = BCD.parseBCD(Decimal.parseDecimal(bin));
                    System.out.println(c.getNumber());
                    break;
                default:
                    System.out.println("That's not valid. Sorry.");
                    break;
            }
        } else if (cmd.startsWith("0c")) {
            BCD bcd = new BCD(cmd.substring(2));
            System.out.println("What would you like to convert your BCD number to?");
            System.out.println("Decimal, hex, binary, or octal?");
            String usr = input.nextLine();
            switch (usr) {
                case "Decimal":
                case "decimal":
                    Decimal d = Decimal.parseDecimal(bcd);
                    System.out.println(d.getNumber());
                    break;
                case "hex":
                case "Hex":
                    Hexadecimal h = Hexadecimal.parseHex(Decimal.parseDecimal(bcd));
                    System.out.println(h.val);
                    break;
                case "binary":
                case "Binary":
                    Binary b = Binary.parseBinary(Decimal.parseDecimal(bcd));
                    System.out.println(b.getNumber());
                    break;
                case "octal":
                case "Octal":
                    Octal o = Octal.parseOctal(Decimal.parseDecimal(bcd));
                    System.out.println(o.val);
                    break;
                default:
                    System.out.println("Sorry, invalid input.");
                    break;
            }
        } else if (cmd.startsWith("0")) { //will only trigger on
            Octal oct = new Octal(cmd.substring(1));
            System.out.println("What would you like to convert your octal number to?");
            System.out.println("Decimal, binary, hex, or BCD?");
            String usr = input.nextLine();
            switch(usr) {
                case "Decimal":
                case "decimal":
                    Decimal d = Decimal.parseDecimal(oct);
                    System.out.println(d.getNumber());
                    break;
                case "binary":
                case "Binary":
                    Binary b = Binary.parseBinary(Decimal.parseDecimal(oct));
                    System.out.println(b.getNumber());
                    break;
                case "hex":
                case "Hex":
                    Hexadecimal h = Hexadecimal.parseHex(Decimal.parseDecimal(oct));
                    System.out.println(h.val);
                    break;
                case "BCD":
                case "bcd":
                    BCD c = BCD.parseBCD(Decimal.parseDecimal(oct));
                    System.out.println(c.getNumber());
                    break;
                default:
                    System.out.println("Sorry, that's not valid.");
                    break;
            }
        }
    }
}

