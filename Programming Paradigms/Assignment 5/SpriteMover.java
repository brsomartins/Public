import java.util.ArrayList;
import java.util.Iterator;

public class SpriteMover implements Runnable {
	private Controller controller;
	private View view;

	SpriteMover(Controller controller, View view) {
		this.controller = controller;
		this.view = view;
	}

	@Override
	public void run() {
		while (true) {
			ArrayList<Sprite> sprites = controller.getModel().getSpriteList();

			synchronized (sprites) {
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

			try {
				Thread.sleep(25);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			view.repaint();
		}
	}
}