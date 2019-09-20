package hendricks.cookiemonster;


import java.util.Arrays;
import java.util.Collections;

/**
 * @author Connor McDermid
 * This class creates a Monster with a name and a size.
 * Since this class implements Comparable, it can be compared and sorted by {@link Collections}
 * and {@link Arrays}.
 * @see java.lang.Comparable
 */
public class Monster implements Comparable {
    private final String name;

    private final int size;

    public Monster(String nm, int sz) {
        this.name = nm;
        this.size = sz;
    }

    public String getName() {
        return name;
    }

    public int getSize() {
        return size;
    }

    /**
     * This compareTo method overloads {@link #compareTo(Object o)}
     * @param m The Monster for this object to be compared to
     * @return Returns 0 if the objects are equal, 1 if m is larger than this, and -1 if this is larger than m.
     */
    public int compareTo(Monster m) {
        return Integer.compare(m.getSize(), this.getSize());
    }
    @Override
    public int compareTo(Object o) {
        return -15; //It's not a bloody monster
    }
}
