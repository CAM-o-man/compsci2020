package digiovanna.testermatch;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * @author Connor McDermid
 * @date 2019.09.09
 * @lab Random Code/Tester Partners
 * Testing Requirements:
 *      **TO BE FILLED OUT**
 *
 * Exit and Error Codes:
 *      0: Program completed successfully
 *      -1: Program was unable to locate the text file containing the coders.
 */
public class Main {

    public static int number;
    public static String[] coders;

    /**
     * The main method runs the program and deals with user input, such as the proper way to output the results of the program.
     * @param args
     */
    public static void main(String[] args) {
        //Acquire coders/testers list
        ArrayList<String> coders;
        try {
            coders = readTesters();
        } catch (FileNotFoundException e) {
            System.out.println("readTesters() threw a FileNotFoundException. Terminating.");
            coders = null;
            System.exit(-1);
        }
        //Randomise the list
        coders = randomiser(coders);

        //Split the list
        ArrayList<String> codersHalf1;
        ArrayList<String> codersHalf2;
        //noinspection unchecked
        codersHalf1 = splitter(coders)[0]; //Ignored unchecked warning; I'm certain the types will match.
        //noinspection unchecked
        codersHalf2 = splitter(coders)[1]; //See above

        //Randomise the lists again; can't be too sure
        codersHalf1 = randomiser(codersHalf1);
        codersHalf2 = randomiser(codersHalf2);

        //Match the coders and testers from the lists
        ArrayList<String> testers = codersHalf2;
        coders = codersHalf1;
        //Ask user how they'd like it to be sorted
        System.out.println("If you'd like the arrays to be sorted by coders, input 1.");
        System.out.println("If you'd like the arrays to be sorted by testers, input 2.");
        Scanner input = new Scanner(System.in);
        int usr = input.nextInt();
        if (usr == 1) {
            //Execute
        } else if (usr == 2) {
            //Execute
        } else {
            //TODO: Error trap
        }
    }

    /**
     * Reads the coders/testers from a file and passes them back as an ArrayList
     * @return ArrayList of coders/testers read from the text file.
     * @throws FileNotFoundException If the file is not present, this will throw a FileNotFoundException
     */
    public static ArrayList<String> readTesters() throws FileNotFoundException {
        File people = new File("coders.txt");
        Scanner reader = new Scanner(people);
        ArrayList<String> coders = new ArrayList<>();
        while (reader.hasNextLine()) {
            coders.add(reader.nextLine());
        }
        reader.close();
        return coders;
    }

    /**
     * Splits the provided ArrayList into 2 pieces at the halfway point. Uses integer division to determine the halfway point in cases of an odd
     * number of coders.
     * @param coders The ArrayList to be split
     * @return An array of the two halves of the passed ArrayList
     */
    public static ArrayList[] splitter(ArrayList<String> coders) {
        int size = coders.size();
        int cutoff = size / 2;
        ArrayList<String> half1 = new ArrayList<>();
        for (int i = 0; i < cutoff; i++) {
            half1.add(coders.get(i));
        }
        ArrayList<String> half2 = new ArrayList<>();
        for (int i = cutoff; i < size; i++) {
            half2.add(coders.get(i));
        }
        ArrayList[] halves = new ArrayList[]{half1, half2};
        return halves;
    }

    public static ArrayList<String> randomiser(ArrayList<String> list) {
        Collections.shuffle(list); //Simply shuffles the list and returns it.
        return list;
    }

    public static void matcher(ArrayList<String> coders, ArrayList<String> testers, boolean byCoders) {
        System.out.println("Coders ------------ Testers");
        for (int i = 0; i < coders.size(); i++) {
            System.out.printf("%s ------------- %s", coders.get(i), testers.get(i)); //Use formatted strings to match coders with testers
        }
    }
    @SuppressWarnings("Duplicates")
    public static void unevenMatcher(ArrayList<String> coders, ArrayList<String> testers, boolean byCoders) {
        ArrayList<String> groupOfThree = new ArrayList<>();
        if (coders.size() > testers.size()) {
            groupOfThree.add(coders.get(coders.size() - 1));
            groupOfThree.add(coders.get(coders.size() - 2));
            groupOfThree.add(testers.get(testers.size() - 1));
            coders.remove(coders.size() - 1);
            coders.remove(coders.size() - 2);
            testers.remove(testers.size() - 1);
        } else {
            groupOfThree.add(coders.get(coders.size() - 1));
            groupOfThree.add(testers.get(testers.size() - 1));
            groupOfThree.add(testers.get(testers.size() - 2));
            coders.remove(coders.size() - 1);
            testers.remove(testers.size() - 1);
            testers.remove(testers.size() - 2);
        }
        System.out.println("Coders ------------- Testers");
        for (int i = 0; i < coders.size(); i++) {
            System.out.printf("%s ------------- %s", coders.get(i), testers.get(i)); //Use formatted strings to match coders with testers
        }
        System.out.println("Group of 3:");
        System.out.printf("%s, %s, %s", groupOfThree.get(1), groupOfThree.get(2), groupOfThree.get(3));
    }
}
