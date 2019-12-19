package hendricks.rational;

/**
 * This exception is thrown when the denominator of a {@link Rational} is zero.
 */
public class ZeroDenominatorException extends IllegalArgumentException {

    public ZeroDenominatorException() {
        super();
    }

    public ZeroDenominatorException(String message) {
        super(message);
    }

}
