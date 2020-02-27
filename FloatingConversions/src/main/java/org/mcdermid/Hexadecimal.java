package org.mcdermid;

import org.apache.commons.lang3.ArrayUtils;

import java.lang.reflect.MalformedParametersException;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Collections;

public class Hexadecimal {
    final int trueval;
    final String val;
    final byte[] bits;

    public Hexadecimal(String val) {
        for (char c : val.toCharArray()) {
            if (!Character.toString(c).matches("^[0-9a-fA-F]$")) {
                throw new MalformedParametersException("Not a valid hexadecimal number.");
            }
        }
        this.val = val;
        this.trueval = Integer.parseInt(val, 16);
        this.bits = ByteBuffer.allocate(Integer.SIZE / 8).putInt(this.trueval).array();
    }

    public static Hexadecimal parseHex(Decimal d) {
        int dec = (int) d.getNumber();
        ArrayList<Integer> rems = new ArrayList<>();
        for (int i = 0; dec > 0; i++) {
            rems.add(dec % 16);
            dec /= 16;
        }
        Collections.reverse(rems);
        StringBuilder sB = new StringBuilder();
        for (int x : rems) {
            if (x == 10) {
                sB.append('A');
            } else if (x == 11) {
                sB.append('B');
            } else if (x == 12) {
                sB.append('C');
            } else if (x == 13) {
                sB.append('D');
            } else if (x == 14) {
                sB.append('E');
            } else if (x == 15) {
                sB.append('F');
            } else {
                sB.append(x);
            }
        }
        return new Hexadecimal(sB.toString());
    }
}
