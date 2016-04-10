import java.awt.Graphics;
import java.io.IOException;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import javax.swing.Timer;

class Controller implements MouseListener {
	Model model;
	View view;

	Controller() throws IOException, Exception {
		model = new Model();
		view = new View(this);
		new Timer(50, view).start();
	}

	public void update(Graphics g) {
		model.update(g);
	}

	public void mousePressed(MouseEvent e) {
		model.setDestination(e.getX(), e.getY(), view.getWidth(), view.getHeight());
	}

	public void mouseReleased(MouseEvent e) {
	}

	public void mouseEntered(MouseEvent e) {
	}

	public void mouseExited(MouseEvent e) {
	}

	public void mouseClicked(MouseEvent e) {
	}

	public static void main(String[] args) throws Exception {
		new Controller();
	}
}