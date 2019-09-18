package hendricks.gradestracker;

public class Student {
    private int grade1;
    private int grade2;
    public String name;

    public Student(String name) {
        this.name = name;
    }

    public int getGrade1() {
        return grade1;
    }

    public void setGrade1(int grade1) {
        this.grade1 = grade1;
    }

    public int getGrade2() {
        return grade2;
    }

    public void setGrade2(int grade2) {
        this.grade2 = grade2;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return String.format("Name: %s, Grades: %s, %s, Average, %s", this.name, this.grade1, this.grade2, this.getAverage());
    }

    public int getAverage() {
        return (this.grade1 + this.grade2) / 2;
    }

    public void printName() {
        System.out.println(this.name);
    }

    public void inputGrades(int g1, int g2) {

        if (g1 > 100 || g1 < 0 || g2 > 100 || g2 < 0){
            System.out.println("Invalid grades.");
            return;
        }
        this.grade1 = g1;
        this.grade2 = g2;
    }
}
