package hendricks.blackjack;

public class BlackJackCard extends Card {
    private int value = checkValue();

    public BlackJackCard(Suit s, Face f) {
        super(s, f);
    }

    public BlackJackCard(String s, int f) {
        super(s, f);
    }

    private int checkValue() {
        switch (super.getFace()) {
            case ACE:
                return 11;
            case TWO:
                return 2;
            case THREE:
                return 3;
            case FOUR:
                return 4;
            case FIVE:
                return 5;
            case SIX:
                return 6;
            case SEVEN:
                return 7;
            case EIGHT:
                return 8;
            case NINE:
                return 9;
            case TEN:
            case JACK:
            case QUEEN:
            case KING:
                return 10;
            default:
                return 0;
        }
    }

    public int getValue() {
        return value;
    }

    @Override
    public String toString() {
        return String.format()
    }

}
