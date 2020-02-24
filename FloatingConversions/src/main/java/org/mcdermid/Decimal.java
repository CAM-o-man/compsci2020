package org.mcdermid;

import java.security.InvalidParameterException;

public class Decimal {
    private final float number;

    public Decimal(int n) {
        this.number = n;
    }

    public float getNumber() {
        return number;
    }

    public static Decimal parseDecimal(Binary b) {
        int radix = 2;
        String s = b.getNumber();
        if (s == null) {
            throw new NumberFormatException("null");
        } else {
            boolean negative = false;
            int i = 0;
            int len = s.length();
            int limit = -2147483647;
            if (len <= 0) {
                throw new NumberFormatException("Length 0");
            } else {
                char firstChar = s.charAt(0);
                if (firstChar < '0') {
                    if (firstChar == '-') {
                        negative = true;
                        limit = -2147483648;
                    } else if (firstChar != '+') {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    if (len == 1) {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    ++i;
                }

                @SuppressWarnings("SpellCheckingInspection") int multmin = limit / radix;

                int result;
                int digit;
                for(result = 0; i < len; result -= digit) {
                    digit = Character.digit(s.charAt(i++), radix); //wait
                    if (digit < 0 || result < multmin) {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    result *= radix;
                    if (result < limit + digit) {
                        throw new InvalidParameterException("Number not valid.");
                    }
                }

                return new Decimal(negative ? result : -result);
            }
        }
    }

    public static Decimal parseDecimal(BCD b) {
        StringBuilder stringBuilder = new StringBuilder();
        int fin = 0;
        String localrep = b.getNumber();
        while (localrep.length() % 4 != 0) {
            //noinspection StringConcatenationInLoop
            localrep = "0" + localrep; //prepend zeroes until can be divided into nibbles
        }
        for (int i = 0; i < localrep.length(); i += 4) {
            int x =  Character.getNumericValue(localrep.charAt(i)) * 8;
            x += Character.getNumericValue(localrep.charAt(i + 1)) * 4;
            x += Character.getNumericValue(localrep.charAt(i + 2)) * 2;
            x += Character.getNumericValue(localrep.charAt(i + 3)) * 1;
            stringBuilder.append(x);
        }
        fin = Integer.parseInt(stringBuilder.toString());
        return new Decimal(fin);
    }

    public static Decimal parseDecimal(Octal o) {
        int radix = 8;
        String s = o.val;
        if (s == null) {
            throw new NumberFormatException("null");
        } else {
            boolean negative = false;
            int i = 0;
            int len = s.length();
            int limit = -2147483647;
            if (len <= 0) {
                throw new NumberFormatException("Length 0");
            } else {
                char firstChar = s.charAt(0);
                if (firstChar < '0') {
                    if (firstChar == '-') {
                        negative = true;
                        limit = -2147483648;
                    } else if (firstChar != '+') {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    if (len == 1) {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    ++i;
                }

                @SuppressWarnings("SpellCheckingInspection") int multmin = limit / radix;

                int result;
                int digit;
                for(result = 0; i < len; result -= digit) {
                    digit = Character.digit(s.charAt(i++), radix); //wait
                    if (digit < 0 || result < multmin) {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    result *= radix;
                    if (result < limit + digit) {
                        throw new InvalidParameterException("Number not valid.");
                    }
                }

                return new Decimal(negative ? result : -result);
            }
        }
    }

    public static Decimal parseDecimal(Hexadecimal h) {
        int radix = 16;
        String s = h.val;
        if (s == null) {
            throw new NumberFormatException("null");
        } else {
            boolean negative = false;
            int i = 0;
            int len = s.length();
            int limit = -2147483647;
            if (len <= 0) {
                throw new NumberFormatException("Length 0");
            } else {
                char firstChar = s.charAt(0);
                if (firstChar < '0') {
                    if (firstChar == '-') {
                        negative = true;
                        limit = -2147483648;
                    } else if (firstChar != '+') {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    if (len == 1) {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    ++i;
                }

                @SuppressWarnings("SpellCheckingInspection") int multmin = limit / radix;

                int result;
                int digit;
                for(result = 0; i < len; result -= digit) {
                    digit = Character.digit(s.charAt(i++), radix); //wait
                    if (digit < 0 || result < multmin) {
                        throw new InvalidParameterException("Number not valid.");
                    }

                    result *= radix;
                    if (result < limit + digit) {
                        throw new InvalidParameterException("Number not valid.");
                    }
                }

                return new Decimal(negative ? result : -result);
            }
        }
    }
}

