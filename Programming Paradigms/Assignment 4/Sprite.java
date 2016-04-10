import java.awt.Graphics;
import java.awt.Image;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

abstract class Sprite {
	protected int x;
	protected int y;
	private Image image;

	Sprite(int x, int y, String file) {
		this.x = x;
		this.y = y;

		try {
			image = ImageIO.read(new File(file));
		} catch (IOException ioe) {
			System.out.println("Unable to load image file.");
		}
	}

	public Image getImage() {
		return image;
	}

	public abstract void update(Graphics g);
}