package hendricks.carlab;

public class Main {

    public static void main(String[] args) {
        Car car = new Car(50);
        car.addFuel(50);
        if (car.drive(500)) {
            System.out.println("successfully driven");
        } else {
            System.out.println("failed to drive; not enough fuel");
        }
    }
}


class Car {
    private int fuel = 0;
    private final int maxfuel = 70;
    private int mpg;
    private int mileage;

    public int getMileage() {
        return mileage;
    }

    public void setMileage(int mileage) {
        this.mileage = mileage;
    }

    public Car(int mpg) {
        this.mpg = mpg;
    }

    public int getFuel() {
        return fuel;
    }

    public void setFuel(int fuel) {
        this.fuel = fuel;
    }

    public int getMaxfuel() {
        return maxfuel;
    }

    public int getMpg() {
        return mpg;
    }

    @Override
    public String toString() {
        return "Car{" +
                "fuel=" + fuel +
                ", maxfuel=" + maxfuel +
                ", mpg=" + mpg +
                '}';
    }
    public void addFuel(int added) {
        int totalFuel = this.getFuel() + added;
        if (totalFuel > this.getMaxfuel()) {
            System.out.println("That's more fuel than your car can hold. You might want to rethink this.");
        } else {
            this.setFuel(totalFuel);
            System.out.printf("Added %s gallons of fuel\n", added);
        }
    }
    public boolean drive(int miles) {
        int pergallon = this.getMpg();
        int fuel = this.getFuel();
        int mileage = this.getMileage();
        if (miles/pergallon <= fuel) {
            fuel -= miles/pergallon;
            mileage += miles;
            return true;
        } else {
            return false;
        }
    }
}
