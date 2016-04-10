public class Exam {
	private int score;
	private String grade;

	public Exam(int score, String grade) {
		if (score < 0) {
			this.score = 0;
		} else if (score > 100) {
			this.score = 100;
		} else {
			this.score = score;
		}

		if (grade.equals("A") || grade.equals("B") || grade.equals("C") || grade.equals("D") || grade.equals("F")) {
			this.grade = grade;
		} else {
			this.grade = "F";
			System.out.printf("You have submitted a bad grade for an Exam, value of: %s\n", grade);
		}
	}

	public int getScore() {
		return score;
	}

	public String getGrade() {
		return grade;
	}
}