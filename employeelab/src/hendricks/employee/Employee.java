
package hendricks.employee;

/**
 * The Employee class encodes the entire life of any employee which is an instance of this class.
 * @author Connor McDermid
 * @date 2019.09.24
 * @lab Employee Lab
 * @extra Allows for ruining your employee's lives by lowering their wage.
 */
public class Employee {
    private final String name;
    private double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }
    public void raiseSalary(int percentage) {
        salary += ((salary / 100) * percentage);
    }

    public void decreaseSalary(int percentage) {
        salary -= ((salary / 100) * percentage);
    }
    
}
