import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class GradePanel extends JPanel {
	String letter;

	GradePanel(String letter) {
		this.letter = letter;
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		int width = getWidth();
		int height = getHeight();

		if (letter.compareTo("A") == 0) {
			g.drawLine(0, height, width / 2, 0);
			g.drawLine(width / 2, 0, width, height);
			g.drawLine(width / 4, height / 2, width / 2 + width / 4, height / 2);
		} else {
			g.setFont(new Font("TimesRoman", Font.PLAIN, 100));
			g.setColor(Color.GREEN);
			g.drawString(letter, width / 2, height / 2);
		}
	}
}