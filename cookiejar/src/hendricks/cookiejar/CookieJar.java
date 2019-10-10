package hendricks.cookiejar;

/**
 * @author Connor McDermid
 * @date 2019.09.24
 * @lab Cookie Jar
 * @extra checkFull() running to sync full
 */
public class CookieJar {

    public final int capacity;

    public int cookies;

    public boolean full;

    public CookieJar(int cap) {
        this.capacity = cap;
    }

    public int getCapacity() {
        return capacity;
    }

    public int getCookies() {
        return cookies;
    }

    public void setCookies(int cookies) {
        this.cookies = cookies;
        checkFull();
    }

    public int addCookies(int add) {
        if (getCookies() == getCapacity()) {
            checkFull();
            return add;
        } else if ((getCookies() + add) > getCapacity()) {
            setCookies(getCapacity());
            checkFull();
            return add - (getCapacity() - getCookies());
        } else {
            setCookies(getCookies() + add);
            checkFull();
            return 0;
        }
    }

    public int removeCookies(int rem) {
        if (rem > getCookies()) {
            int temp = getCookies();
            setCookies(0);
            checkFull();
            return temp;
        } else {
            setCookies(getCookies() - rem);
            checkFull();
            return rem;
        }
    }

    public boolean isFull() {
        return full;
    }

    public void setFull(boolean full) {
        this.full = full;
    }

    public void checkFull() {
        if (this.getCookies() >= this.getCapacity()) {
            this.setFull(true);
        }
    }

    public int spaceLeft() {
        return this.getCapacity() - this.getCookies();
    }
}
