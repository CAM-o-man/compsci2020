package org.mcdermid;

import org.apache.commons.lang3.ArrayUtils;

import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Collections;

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
        float dec = d.getNumber();
        ArrayList<Float> rems = new ArrayList<>();
        int tally = 0;
        for (int i = 0; dec != 0; i++) {
            rems.add(dec % 8);
            dec /= 8;
            tally = i;
        }
        StringBuilder sb = new StringBuilder();
        Collections.reverse(rems);
        for (int i = 0; i <= tally; i++) {
            sb.append(rems.get(i));
        }
        return new Octal(sb.toString());
    }
}

