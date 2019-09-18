package hendricks.television;

public class Television {
    private final String manufacturer;
    private final String screenSize;
    private boolean power;
    private int channel;
    private int volume;

    public Television(String manufacturer, String screenSize) {
        this.manufacturer = manufacturer;
        this.screenSize = screenSize;
    }

    public int getChannel() {
        return channel;
    }

    public void setChannel(int channel) {
        this.channel = channel;
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public void increaseVolume() {
        volume = volume < 100
                ? volume + 1
                : volume;
    }

    public String getManufacturer() {
        return manufacturer.toString();
    }

    public String getScreenSize() {
        return screenSize;
    }

    public boolean isPowered() {
        return power;
    }

    public void decreaseVolume() {
        volume = volume > 0
                ? volume -1
                : volume;
    }

    public void increaseChannel() {
        channel = channel < 1000
                ? channel + 1
                : channel;
    }

    public void decreaseChannel() {
        channel = channel > 0
                ? channel - 1
                : channel;
    }

    public void togglePower() {
        power = !power;
    }


}
