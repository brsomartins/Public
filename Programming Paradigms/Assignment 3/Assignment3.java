import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Assignment3 {
	public static void main(String[] args) {
		try {
			String firstName = JOptionPane.showInputDialog("Please enter the student's first name");
			String lastName = JOptionPane.showInputDialog("Please enter the student's last name");

			Student s = new Student(firstName, lastName);

			int numberActivities = Integer
					.parseInt(JOptionPane.showInputDialog("Please enter the number of activity grades"));

			for (int i = 0; i < numberActivities; i++) {
				s.addGradedActivity(Integer
						.parseInt(JOptionPane.showInputDialog("Please enter the score for activity #" + (i + 1))));
			}

			int numberHomeworks = Integer
					.parseInt(JOptionPane.showInputDialog("Please enter the number of homework grades"));

			for (int i = 0; i < numberHomeworks; i++) {
				s.addGradedHomework(Integer
						.parseInt(JOptionPane.showInputDialog("Please enter the score for homework #" + (i + 1))));
			}

			int percentMidterm = Integer
					.parseInt(JOptionPane.showInputDialog("Please enter the percentage score on the midterm"));
			String letterMidterm = JOptionPane.showInputDialog("Please entre the letter grade on the midterm");

			s.setMidterm(percentMidterm, letterMidterm);

			int percentFinal = Integer
					.parseInt(JOptionPane.showInputDialog("Please enter the percentage score on the final"));
			String letterFinal = JOptionPane.showInputDialog("Please entre the letter grade on the final");

			s.setFinal(percentFinal, letterFinal);

			GradePanel panel = new GradePanel(s.getGrade());

			JFrame application = new JFrame();

			application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

			application.add(panel);
			application.setSize(250, 250);
			application.setVisible(true);
		} catch (NumberFormatException e) {
			JOptionPane.showMessageDialog(null, "Invalid data entered. Exiting.");
		}
	}
}