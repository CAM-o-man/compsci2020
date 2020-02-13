package org.mcdermid;

import org.apache.commons.lang3.ArrayUtils;

import java.lang.reflect.MalformedParametersException;
import java.nio.ByteBuffer;

public class Hexadecimal {
    final int trueval;
    final String val;
    final byte[] bits;

    public Hexadecimal(String val) {
        if (!val.matches("0-9a-fA-F")) {
            throw new MalformedParametersException("That's *not* properly formatted hexadecimal.");
        }
        this.val = val;
        this.trueval = Integer.parseInt(val, 16);
        this.bits = ByteBuffer.allocate(Integer.SIZE / 8).putInt(this.trueval).array();
    }

    public static Hexadecimal parseHex(Decimal d) {
        int dec = d.getNumber();
        int[] rems = new int[Integer.toString(dec).length()];
        for (int i = 0; i < Integer.toString(dec).length(); i++) {
            rems[i] = dec % 16;
            dec /= 16;
        }
        ArrayUtils.reverse(rems);
        StringBuilder sB = new StringBuilder();
        for (int x : rems) {
            sB.append(x);
        }
        return new Hexadecimal(sB.toString());
    }
}
