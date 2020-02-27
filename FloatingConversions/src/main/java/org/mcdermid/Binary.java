package org.mcdermid;

import java.util.ArrayList;

public class Binary {
    private final String number;
    private final byte[] bytenum;

    public Binary(String number) {
        this.number = number;
        byte[] bits = new byte[number.length()];
        for (int i = 0; i < number.length(); i++) {
            bits[i] = (byte) Character.getNumericValue(number.charAt(i)); //yeah, yeah, unsafe. It's always only one digit.
        }
        this.bytenum = bits;
    }

    public String getNumber() {
        return number;
    }

    public byte[] getBits() {
        return bytenum;
    }

    public static Binary parseBinary(Decimal d) {
        float dec = d.getNumber();
        ArrayList<Float> rems = new ArrayList<>();
        for (int i = 0; dec > 0; i++) {
            rems.add(dec % 2);
            dec /= 2;
        }
        StringBuilder sb = new StringBuilder();
        for (float i : rems) {
            sb.append(i);
        }
        return new Binary(sb.toString());
    }
}

