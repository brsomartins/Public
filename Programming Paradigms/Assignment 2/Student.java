public class Student {
	private String firstName;
	private String lastName;
	private Exam midtermExam;
	private Exam finalExam;
	private Coursework homework = new Coursework();
	private Coursework inClass = new Coursework();

	public Student(String firstName, String lastName) {
		this.firstName = firstName;
		this.lastName = lastName;
	}

	public void setMidterm(int score, String grade) {
		midtermExam = new Exam(score, grade);
	}

	public void setFinal(int score, String grade) {
		finalExam = new Exam(score, grade);
	}

	public void addGradedHomework(int score) {
		homework.addScore(score);
	}

	public void addGradedActivity(int score) {
		inClass.addScore(score);
	}

	public void printGrade() {
		double percentage = inClass.getScoresAvg() * 0.15 + homework.getScoresAvg() * 0.25
				+ midtermExam.getScore() * 0.25 + finalExam.getScore() * 0.35;
		String lowest = (midtermExam.getGrade().compareTo(finalExam.getGrade()) > 0 ? midtermExam.getGrade()
				: finalExam.getGrade());
		String grade;

		if (percentage < 60) {
			grade = "F";
		} else if (percentage >= 60 && percentage < 70) {
			grade = "D";
		} else if (percentage >= 70 && percentage < 80) {
			grade = "C";
		} else if (percentage >= 80 && percentage < 90) {
			grade = "B";
		} else {
			grade = "A";
		}

		System.out.printf("Final course grade for %s %s %s %.2f%%\n", firstName, lastName,
				(grade.compareTo(lowest) > 0 ? lowest : grade), percentage);
	}
}