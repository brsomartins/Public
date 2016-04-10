import java.awt.Graphics;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

class Model {
	private ArrayList<Sprite> sprites;
	private int width;
	private int height;
	Random r;

	Model(int w, int h) throws IOException {
		sprites = new ArrayList<Sprite>();
		width = w;
		height = h;
		r = new Random();
		initialize();
	}

	public ArrayList<Sprite> getSpriteList() {
		return sprites;
	}

	public void initialize() {
		synchronized (sprites) {
			if (sprites.size() > 0) {
				sprites.clear();
			}

			for (int i = 0; i < 50; i++) {
				int newX = r.nextInt(width - 50);
				int newY = r.nextInt(height - 50);
				if (i % 2 == 0) {
					sprites.add(new Razorback(newX, newY, width, height));
				} else {
					sprites.add(new Opponent(newX, newY, width, height));
				}
			}
		}

		System.out.println("Done!");
	}

	public void update(Graphics g) {
		synchronized (sprites) {
			for (Sprite sprite : sprites) {
				sprite.update(g);
			}
		}
	}

	public void forward() {
		Iterator<Sprite> iter = sprites.iterator();

		while (iter.hasNext()) {
			Sprite s = iter.next();
			s.move();

			Iterator<Sprite> iter2 = sprites.iterator();

			while (iter2.hasNext()) {
				Sprite t = iter2.next();

				if (s.overlaps(t) == true) {
					if (s instanceof Razorback && t instanceof Opponent) {
						t.hit();
					} else if (s instanceof Opponent && t instanceof Razorback) {
						s.hit();
					}
				}
			}

			if (s.shouldRemove() == true) {
				iter.remove();
			}
		}
	}
}
