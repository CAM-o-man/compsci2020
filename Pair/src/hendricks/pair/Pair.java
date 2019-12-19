package hendricks.pair;

public class Pair {
    private double first;
    private double second;

    public Pair(double f, double s) {
        this.first = f;
        this.second = s;
    }

    public double getFirst() {
        return this.first;
    }

    public double getSecond() {
        return second;
    }

    public void setFirst(double first) {
        this.first = first;
    }

    public void setSecond(double second) {
        this.second = second;
    }

    public double getSum() {
        return this.first + this.second;
    }

    public double getDiff() {
        return this.first - this.second;
    }

    public double getProd() {
        return this.first * this.second;
    }

    public double getAvg() {
        double sum = this.first + this.second;
        sum = sum / 2;
        return sum;
    }


}
