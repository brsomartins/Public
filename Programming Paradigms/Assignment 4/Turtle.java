import java.awt.Graphics;

class Turtle extends Sprite {
	private static int dest_x;
	private static int dest_y;

	Turtle(int x, int y) {
		super(x, y, "turtle.png");
	}

	@Override
	public void update(Graphics g) {
		// Move the turtle
		if (x < dest_x) {
			x += 1;
		} else if (x > dest_x) {
			x -= 1;
		}

		if (y < dest_y) {
			y += 1;
		} else if (y > dest_y) {
			y -= 1;
		}

		// Draw the turtle
		g.drawImage(getImage(), x, y, 100, 100, null);
	}

	public static void setDest(int x, int y) {
		dest_x = x;
		dest_y = y;
	}
}