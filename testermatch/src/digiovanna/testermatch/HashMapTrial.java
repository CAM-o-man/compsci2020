package digiovanna.testermatch;

import java.io.*;
import java.util.*;

/**
 * @author Connor McDermid
 * @date 2019.09.10
 * @lab Matching Coders/Testers
 * Black Box Test Requirements
 *
 * Read in all coder/tester names
 *
 * Coder/tester (C/T) can’t be the same person
 *
 * Must be able to handle a max of 16 coder/testers
 *
 * Must handle even/odd number of C/T
 *
 * Can sort bt tester
 *
 * Can sort by coder
 *
 * Prove psuedo-randomness
 *
 * Validated user input (list sort type)
 *
 * Program can run more than 1x
 *
 *  No tester can be assigned to more then 1 code
 *
 *
 * Exit Codes:
 *      0: Successful exit
 *      -1: FileNotFoundException - the program was unable to locate the list of coders/testers
 *      -2: Illegal Input
 */
public class HashMapTrial {

    /**
     * Main is where almost all user interaction will take place.
     * @param args N/A
     */
    public static void main(String[] args) {
        //Begin by reading the testers
        ArrayList<String> students;
        try {
            students = readTesters();
        } catch (FileNotFoundException e) {
            System.out.println("The program has encountered a FileNotFoundException.");
            System.exit(-1);
            students = null; //Unreachable statement. However, this has to be here to satisfy the compiler that
                             //the variable students is initialised.
        }
        //Once read, shuffle it.
        students = shuffler(students);
        //Check that we've got an even number
        ArrayList<String> robin = null;
        if (students.size() % 2 != 0) {
            robin = roundRobin(students);
        }
        //Next, split the list and encode it.
        @SuppressWarnings("unchecked") //Compiler should ignore this, but if NetBeans has problems with it it's fine to remove.
        Map pairs = encoder(splitter(students)[0], splitter(students)[1]);

        //Check for how the user wants it printed
        System.out.println("Would you like the list sorted by coders (1) or testers (2)?");
        Scanner input = new Scanner(System.in);
        int usr = input.nextInt();
        if (usr == 1) {
            if (robin != null) {
                try {
                    printer(pairs, robin);
                } catch (IOException e) {
                    e.printStackTrace();
                    System.exit(-1);
                }
            } else {
                try {
                    printer(pairs);
                } catch (IOException e) {
                    e.printStackTrace();
                    System.exit(-1);
                }
            }
        } else if (usr == 2) {
            if (robin != null) {
                try {
                    printer(pairs, robin);
                } catch (IOException e) {
                    e.printStackTrace();
                    System.exit(-1);
                }
            } else {
                try {
                    printer(pairs);
                } catch (IOException e) {
                    e.printStackTrace();
                    System.exit(-1);
                }
            }
        } else {
            System.out.println("I'm afraid that's an illegal input.");
            System.exit(-2);
        }
    }

    /**
     * This method reads the testers from a file coders.txt one directory above the sources root.
     * @return An ArrayList containing the contents of the file.
     * @throws FileNotFoundException If the file cannot be found, this exception will be thrown up, caught, and the program will exit with code -1.
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
     * Simply shuffles the ArrayLists passed to it.
     * @param list The unshuffled list.
     * @return The shuffled list
     */
    public static ArrayList<String> shuffler(ArrayList<String> list) {
        Collections.shuffle(list);
        return list;
    }

    /**
     * Encodes the ArrayLists provided into a {@see Map} of type {@see HashMap}
     * @param keys The ArrayList to be encoded as the keys in the Map's key-value pair.
     * @param values The ArrayList to be encoded as the values in the Map's key-value pair.
     * @return A {@see Map} of type {@see HashMap} encoded with the keys and values provided
     */
    public static Map encoder(ArrayList<String> keys, ArrayList<String> values) {
        Map<String, String> paired = new HashMap<>() {{//For testers: This is known as Double-Brace Initialisation.
            for (int i = 0; i < keys.size(); i++) {   //It allows me to perform several operations on the object at a time during initialisation
                put(keys.get(i), values.get(i));      //that would normally take multiple calls of the object after initialisation.
            }                                         //For example: what was:
        }};                                           //keys.put(x); keys.put(x); etc...
        return paired;                                //becomes Map paired = new HashMap() {{
    }                                                 //put(x); put(x); }} etc...
    /**
     * This splits the ArrayList of students into an ArrayList of coders and an ArrayList of coders and one of testers
     * @param coders The input, larger ArrayList
     * @return An array of ArrayLists, index 0 being the coders and index 1 being the testers
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

    /**
     * Prints the provided {@see Map},
     * @param pairs The map to be printed
     */
    public static void printer(Map pairs) throws IOException {
        TreeMap<String, String> sorted = new TreeMap<String, String>(pairs);
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File("output.txt")));
        for (int i = 0; i < sorted.size(); i++) {
            System.out.println("Coder --------------- Tester");
            writer.write("Coder --------------- Tester\n");
            System.out.printf("%s ------------------- %s\n", sorted.keySet().toArray()[i], sorted.values().toArray()[i]);
            writer.write(String.format("%s ------------------- %s\n", sorted.keySet().toArray()[i], sorted.values().toArray()[i]));

        }
    }

    /**
     * Overloads Printer to print the provided {@see Map}, while allowing for round-robn groups.
     * @param pairs The {@see Map} to be printed
     * @param robin An {@see ArrayList} containing a round-robin group.
     */
    public static void printer(Map pairs, ArrayList<String> robin) throws IOException {
        Object[] temp = pairs.values().toArray();
        Object[] temp2 = pairs.values().toArray();
        TreeMap<Object, Object> sorted = new TreeMap<Object, Object>();
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File("output.txt")));
        for (int i = 0; i < temp.length; i++) {
            sorted.put(temp[i], temp2[i]);
        }
        for (int i = 0; i < sorted.size(); i++) {
            System.out.println("Coder --------------- Tester");
            String out = String.format("%s ------------------ %s\n", sorted.keySet().toArray()[i], sorted.values().toArray()[i]);
            System.out.print(out);
            writer.write("Coder --------------- Tester\n");
            writer.write(out);

        }
        System.out.printf("Round Robin: %s, %s and %s\n", robin.get(0), robin.get(1), robin.get(2));
        writer.write(String.format("Round Robin: %s, %s and %s\n", robin.get(0), robin.get(1), robin.get(2)));
    }

    /**
     *
     * @param coders
     * @return
     */
    public static ArrayList<String> roundRobin(ArrayList<String> coders) {
        ArrayList<String> robin = new ArrayList<>();
        int max = coders.size();
        for (int i = max - 4; i < max; i++) {
            robin.add(coders.get(i));
            coders.remove(coders.get(i));
        }
        return robin;
    }
}
