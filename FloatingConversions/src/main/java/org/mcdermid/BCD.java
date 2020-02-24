package org.mcdermid;

public class BCD extends Binary {

    public BCD(String number) {
        super(number);
    }

    public static BCD parseBCD(Decimal d) {
        //BCD is individual digits, so it's a little different
        StringBuilder master = new StringBuilder();
        StringBuilder nibble = new StringBuilder("0000");
        float dec = d.getNumber();
        int[] digits = new int[Float.toString(dec).length()];
        for (int i = 0; i < Float.toString(dec).length(); i++) {
            digits[i] = Character.getNumericValue(Float.toString(dec).charAt(i));
        }
        for (int i : digits) {
            do {
                //Using else-if because that way only one block executes per loop
                if (i >= 8) {
                    nibble.setCharAt(0, '1');
                    i -= 8;
                } else if (i >= 4) {
                    nibble.setCharAt(1, '1');
                    i -= 4;
                } else if (i >= 2) {
                    nibble.setCharAt(2, '1');
                    i -= 2;
                } else if (i >= 1) {
                    nibble.setCharAt(3, '1');
                    i--;
                }
            } while (i > 0);
            master.append(nibble);
            nibble.setCharAt(0, '0');
            nibble.setCharAt(1, '0');
            nibble.setCharAt(2, '0');
            nibble.setCharAt(3, '0');
            //next loop
        }
        return new BCD(master.toString());
    }
}
