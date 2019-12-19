package hendricks.employee;

public class Main {

    public static void main(String[] args) {
        Employee harry = new Employee("Hacker, Harry", 100000);

        System.out.printf("Employee: %s Salary: %s\n", harry.getName(), harry.getSalary());
        harry.raiseSalary(35);
        System.out.printf("Employee: %s Salary: %s\n", harry.getName(), harry.getSalary());
        harry.decreaseSalary(10);
        System.out.printf("Employee: %s Salary: %s\n", harry.getName(), harry.getSalary());
    }
}
