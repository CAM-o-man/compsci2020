package org.mcdermid;

import org.apache.commons.lang3.ArrayUtils;

public class Decimal {
    private final int number;

    public Decimal(int n) {
        this.number = n;
    }

    public int getNumber() {
        return number;
    }

    public static Decimal parseDecimal(Binary b) {
        int fin = 0;
        byte[] bin = b.getBits();
        ArrayUtils.reverse(bin);
        for (int i = 0; i < bin.length; i++) {
            fin += bin[i] * Math.pow(2, i);
        }
        return new Decimal(fin);
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
            int x = (int) (Character.getNumericValue(localrep.charAt(i)) * Math.pow(2, 8));
            x += Character.getNumericValue(localrep.charAt(i + 1)) * Math.pow(2, 4);
            x += Character.getNumericValue(localrep.charAt(i + 2)) * Math.pow(2, 2);
            x += Character.getNumericValue(localrep.charAt(i + 3)) * Math.pow(2, 1);
            stringBuilder.append(x);
        }
        fin = Integer.parseInt(stringBuilder.toString());
        return new Decimal(fin);
    }

    public static Decimal parseDecimal(Hexadecimal h) {
        int fin = 0;
        StringBuilder num = new StringBuilder();
        num.append(h.val);
        num.reverse();
        for (char c : num.toString().toUpperCase().toCharArray()) {
            if (Character.toString(c).matches("[a-zA-Z]")) {
                switch(Character.toString(c).toUpperCase().toCharArray()[0]) {
                    case 'A':
                        fin += 10;
                        break;
                    case 'B':
                        fin += 11;
                        break;
                    case 'C':
                        fin += 12;
                        break;
                    case 'D':
                        fin += 13;
                        break;
                    case 'E':
                        fin += 14;
                        break;
                    case 'F':
                        fin += 15;
                        break;
                    default: break;
                }
            } else {
                fin += Character.getNumericValue(c);
            }
        }
        return new Decimal(fin);
    }

    public static Decimal parseDecimal(Octal o) {
        int fin = 0;
        int x;
        for (int i = 0; i < o.val.length(); i++) {
            fin += (int) (Character.getNumericValue(o.val.charAt(i)) * Math.pow(8, i));
        }
        return new Decimal(fin);
    }
}

