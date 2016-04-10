public class Coursework {
	private double sum;
	private int number;
	
	public void addScore(int score) {
		if (score < 0) {
			sum += 0;
		} else if (score > 100) {
			sum += 100;
		} else {
			sum += score;
		}
		
		number++;
	}
	
	public double getScoresAvg() {
		return sum / number;
	}
}