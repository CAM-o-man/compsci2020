
package hendricks.blackjack;

import static java.lang.System.*;
import java.awt.Color;

/**
 * @author Connor McDermid
 * @lab BlackJackCard
 * @date 2019.10.03
 * @extra super
 */
public class CardRunner
{
    public static void main(String args[]) {

		Card one = new Card("SPADES", 9);
		out.println(one.getSuit());
		out.println(one.getFace());

		Card two = new Card("DIAMONDS", 1);
		out.println(two);
		two.setFace(3);
		out.println(two);

		Card three = new Card("CLUBS", 4);
		out.println(three);

		Card four = new BlackJackCard("SPADES", 12);
		out.println(four);

		Card five = new BlackJackCard("HEARTS", 12);
		out.println(five);

		Card six = new BlackJackCard("CLUBS", 12);
		out.println(six);

    }
}