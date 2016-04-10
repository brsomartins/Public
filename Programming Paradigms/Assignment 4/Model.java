import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;

class Model {
	private ArrayList<Sprite> sprites = new ArrayList<Sprite>();
	private boolean isTurtle = true;

	public void update(Graphics g) {
		for (int i = 0; i < sprites.size(); i++) {
			sprites.get(i).update(g);
		}
	}

	public void setDestination(int x, int y, int width, int height) {
		Random random = new Random();

		if (isTurtle == true) {
			sprites.add(new Turtle(random.nextInt(width), random.nextInt(height)));
			Turtle.setDest(x, y);

			isTurtle = false;
		} else {
			sprites.add(new Razorback(x, y, width, height));

			isTurtle = true;
		}
	}
}