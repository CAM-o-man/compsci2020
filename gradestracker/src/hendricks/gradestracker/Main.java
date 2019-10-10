package hendricks.gradestracker;

import java.util.Scanner;

/**
 * @author Connor McDermid
 * @date 2019.09.12
 * @lab Grades Tracker
 */
public class Main {

    public static void main(String[] args) {
        Student stud1 = new Student("Charlie");
        Student stud2 = new Student("Lauren");

        Scanner input = new Scanner(System.in);

        System.out.println("Input a grade for Student 1");
        int gs1 = input.nextInt();
        int gs2 = input.nextInt();
        System.out.println("Now for Student 2");
        int g2s1 = input.nextInt();
        int g2s2 = input.nextInt();

        if (((gs1 >= 0 && gs1 <= 100) && (gs2 >= 0 && gs2 <= 100))) {
            stud1.inputGrades(gs1, gs2);
        } else {
            System.out.println("Invalid entries");
        }
        if (((gs1 >= 0 && gs2 <= 100) && (g2s2 >= 0 && g2s1 <= 100))) {
            stud2.inputGrades(g2s1, g2s2);
        } else {
            System.out.println("Invalid entries");
        }

        System.out.println("Student 1: " + stud1);
        System.out.println("Student 2: " + stud2);
    }
}
