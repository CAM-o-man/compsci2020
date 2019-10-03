package hendricks.blackjack;

/**
 * @author Connor McDemid
 * @date 2019.09.26
 * @lab Card Lab
 * @extra Enums
 */
public class Card {
    private Face face;
    private Suit suit;

    public Card(Suit s, Face f) {
        this.face = f;
        this.suit = s;
    }
    public Card(String s, int f) {
        switch(f) {
            case 1:
                this.face = Face.ACE;
                break;
            case 2:
                this.face = Face.TWO;
                break;
            case 3:
                this.face = Face.THREE;
                break;
            case 4:
                this.face = Face.FOUR;
                break;
            case 5:
                this.face = Face.FIVE;
                break;
            case 6:
                this.face = Face.SIX;
                break;
            case 7:
                this.face = Face.SEVEN;
                break;
            case 8:
                this.face = Face.EIGHT;
                break;
            case 9:
                this.face = Face.NINE;
                break;
            case 10:
                this.face = Face.TEN;
                break;
            case 11:
                this.face = Face.JACK;
                break;
            case 12:
                this.face = Face.QUEEN;
                break;
            case 13:
                this.face = Face.KING;
                break;
            default:
                System.out.println("That's not a legal face or number.");
        }

        switch (s) {
            case "SPADES":
                this.suit = Suit.SPADES;
                break;
            case "HEARTS":
                this.suit = Suit.HEARTS;
                break;
            case "CLUBS":
                this.suit = Suit.CLUBS;
                break;
            case "DIAMONDS":
                this.suit = Suit.DIAMONDS;
                break;
            default:
                System.out.println("That's not a legal suit.");
        }
    }

    public void setFace(Face f) {
        this.face = f;
    }

    public void setFace(int f) {
        switch(f) {
            case 1:
                this.face = Face.ACE;
                break;
            case 2:
                this.face = Face.TWO;
                break;
            case 3:
                this.face = Face.THREE;
                break;
            case 4:
                this.face = Face.FOUR;
                break;
            case 5:
                this.face = Face.FIVE;
                break;
            case 6:
                this.face = Face.SIX;
                break;
            case 7:
                this.face = Face.SEVEN;
                break;
            case 8:
                this.face = Face.EIGHT;
                break;
            case 9:
                this.face = Face.NINE;
                break;
            case 10:
                this.face = Face.TEN;
                break;
            case 11:
                this.face = Face.JACK;
                break;
            case 12:
                this.face = Face.QUEEN;
                break;
            case 13:
                this.face = Face.KING;
                break;
            default:
                System.out.println("That's not a legal face or number.");
        }
    }

    public void setSuit(Suit s) {
        this.suit = s;
    }

    public void setSuit(String s) {
        switch (s) {
            case "SPADES":
                this.suit = Suit.SPADES;
                break;
            case "HEARTS":
                this.suit = Suit.HEARTS;
                break;
            case "CLUBS":
                this.suit = Suit.CLUBS;
                break;
            case "DIAMONDS":
                this.suit = Suit.DIAMONDS;
                break;
            default:
                System.out.println("That's not a legal suit.");
        }
    }

    public Suit getSuit() {
        return this.suit;
    }

    public Face getFace() {
        return this.face;
    }

    public String toString() {
        return String.format("A %s of %s", this.face, this.suit);
    }
}
