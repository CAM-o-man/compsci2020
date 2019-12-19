package hendricks.rational;

/**
 * @author Connor McDermid
 * @date 2019.09.20
 * @lab Rational
 * @extra Custom Exceptions
 */
public class Rational implements Comparable<Rational> {
    private int numerator;
    private int denominator;

    public Rational(int num, int den) throws ZeroDenominatorException {
        this.numerator = num;
        if (den == 0) {
            throw new ZeroDenominatorException("Denominator cannot be zero."); //While the denominator is assigned past this point,
                                                                               //method execution will cease.
        }
        this.denominator = den;
    }

    public String toString() {
        return String.format("%d/%d", this.numerator, this.denominator);
    }

    public int getNum() {
        return this.numerator;
    }

    public int getDenom() {
        return this.denominator;
    }

    public Rational(int num) {
        this(num, 1);
    }

    @Override
    public int compareTo(Rational r) {
        return Integer.compare((this.numerator / this.denominator), (r.numerator / r.denominator));
    }

    public boolean isBigger(Rational r) {
        return compareTo(r) > 0;
    }

    public void setRational(int num, int den) {
        this.numerator = num;
        this.denominator = den;
    }

    public Rational add(Rational r) {
        int num1 = this.getNum();
        int num2 = r.getNum();
        int den1 = this.getDenom();
        int den2 = r.getDenom();

        int addednum = num1 + num2;
        int addedden = den1 + den2;
        if (addedden == 0) {
            throw new ZeroDenominatorException("Denominators can't be zero.");
        }

        return new Rational(addednum, addedden);
    }
}

