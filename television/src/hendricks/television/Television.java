package hendricks.television;

/**
 * @author Connor McDermid
 * @date 2019.09.23
 * @lab Television
 * @extra Ternaries
 */
public class Television {
    private final String manufacturer;
    private final int screenSize;
    private boolean power = false;
    private int channel;
    private int volume = 22;

    /**
     * Constructor. Defines the final fields and builds a Television
     * @param manufacturer The person who made the television.
     * @param screenSize How large the screen is.
     */
    public Television(String manufacturer, int screenSize) {
        this.manufacturer = manufacturer;
        this.screenSize = screenSize;
    }

    /**
     * Displays the TV channel
     * @return channel
     */
    public int getChannel() {
        return channel;
    }

    /**
     * Sets the channel directly
     * @param channel the channel to go to
     */
    public void setChannel(int channel) {
        this.channel = channel;
    }

    /**
     * Returns the volume
     * @return volume
     */
    public int getVolume() {
        return volume;
    }

    /**
     * Sets the volume to the provided number.
     * @param volume The volume to set.
     */
    public void setVolume(int volume) {
        this.volume = volume;
    }

    /**
     * Increases the volume by 1, unless the volume is at 100
     */
    public void increaseVolume() {
        volume = volume < 100
                ? volume + 1
                : volume;
    }

    /**
     * Returns the Manufacturer provided in the constructor
     * @return
     */
    public String getManufacturer() {
        return manufacturer.toString();
    }

    /**
     * Returns the screen size provided in the constructor
     * @return
     */
    public int getScreenSize() {
        return screenSize;
    }

    /**
     * Returns the state of the TV power switch.
     * @return
     */
    public boolean isPowered() {
        return power;
    }

    /**
     * Decreases the volume by 1 unless it is already at 0
     */
    public void decreaseVolume() {
        volume = volume > 0
                ? volume -1
                : volume;
    }

    /**
     * Increases the channel by 1 unless it is at 1000
     */
    public void increaseChannel() {
        channel = channel < 1000
                ? channel + 1
                : channel;
    }

    /**
     * Decreases the channel by 1 unless it is 0.
     */
    public void decreaseChannel() {
        channel = channel > 0
                ? channel - 1
                : channel;
    }

    /**
     * Toggles the power.
     */
    public void togglePower() {
        power = !power;
    }

    public void power() {
        power = true;
    }
}
