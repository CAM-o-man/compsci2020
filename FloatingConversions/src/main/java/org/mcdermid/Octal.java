package org.mcdermid;

import java.nio.ByteBuffer;

public class Octal {
    final int trueval;
    final String val;
    final byte[] bits;

    public Octal(String oct) {
        this.trueval = Integer.parseInt(oct, 8);
        this.val = oct;
        this.bits = ByteBuffer.allocate(Integer.SIZE / 8).putInt(this.trueval).array();
    }

    public static Octal parseOctal(Decimal d) {
        int dec = d.getNumber();
        int[] rems = new int[Integer.toString(dec).length()];
        for (int i = 0; i < rems.length; i++) {
            rems[i] = dec % 8;
            dec /= 8;
        }
        StringBuilder sb = new StringBuilder();
        for (int i : rems) {
            sb.append(i);
        }
        return new Octal(sb.toString());
    }
}

