package hendricks.cookiemonster;

import java.util.Scanner;

/**
 * @author Connor McDermid
 * @date 2019.09.20
 * @lab Monster Checker
 * @extra Implementing interface Comparable
 *
 * Main is the runner class. This code is copy-pasted from the assignment (in effect)
 */
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the first monster's name:");
        String name = input.next();
        System.out.println("Please enter that monster's size.");
        int size = input.nextInt();

        Monster m1 = new Monster(name, size);

        System.out.println("Please enter the second monster's name.");
        name = input.next();
        System.out.println("Now, that monster's size.");
        size = input.nextInt();

        Monster m2 = new Monster(name, size);

        /*
            Monster comparisons. This replaces the monster comparisons in the assignment and instead uses my
            overloaded compareTo method.
         */
        if (m1.compareTo(m2) == 0) {
            System.out.println("The monsters are identical.");
        } else if (m1.compareTo(m2) == 1) {
            System.out.printf("Monster %s is larger than Monster %s.\n", m2.getName(), m1.getName());
        } else if (m1.compareTo(m2) == -1) {
            System.out.printf("Monster %s is larger than Monster %s.\n", m1.getName(), m2.getName());
        }

    }
}

