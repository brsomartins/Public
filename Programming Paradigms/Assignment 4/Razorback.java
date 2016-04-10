import java.awt.Graphics;
import java.util.Random;

public class Razorback extends Sprite {
	private int xSlope;
	private int ySlope;
	private int width;
	private int height;

	Razorback(int x, int y, int width, int height) {
		super(x, y, "razorback.png");

		this.width = width;
		this.height = height;

		Random random = new Random();

		xSlope = random.nextInt(11) - 5;
		ySlope = random.nextInt(11) - 5;
	}

	@Override
	public void update(Graphics g) {
		// Move the Razorback
		if (x < 0) {
			x = width;
		} else if (x > width) {
			x = 0;
		} else {
			x += xSlope;
		}

		if (y < 0) {
			y = height;
		} else if (y > height) {
			y = 0;
		} else {
			y += ySlope;
		}

		// Draw the Razorback
		g.drawImage(getImage(), x, y, 100, 100, null);
	}
}