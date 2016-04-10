public class StudentTest
{
	public static void main(String args[])
	{
		Student s1 = new Student("Matt", "Patitz");
		s1.setMidterm(78, "B");
		s1.setFinal(70, "C");
		s1.addGradedHomework(90);
		s1.addGradedHomework(95);
		
		s1.addGradedActivity(100);
		s1.addGradedActivity(70);
		s1.printGrade();
		

		s1 = new Student("John", "Johnson");
		s1.setMidterm(90, "B");
		s1.setFinal(70, "B");
		s1.addGradedHomework(60);
		s1.addGradedHomework(70);
		s1.addGradedHomework(40);
		
		s1.addGradedActivity(80);
		s1.addGradedActivity(50);
		s1.printGrade();
		
		
		s1 = new Student("Foo", "Fooson");
		s1.setMidterm(60, "G");
		s1.setFinal(70, "B");
		s1.addGradedHomework(60);
		s1.addGradedHomework(70);
		s1.addGradedHomework(40);
		
		s1.addGradedActivity(80);
		s1.addGradedActivity(50);
		s1.printGrade();
		
		
		s1 = new Student("Fake", "Student");
		s1.setMidterm(90, "B");
		s1.setFinal(70, "B");
		s1.addGradedHomework(-30);
		s1.addGradedHomework(70);
		s1.addGradedHomework(40);
		
		s1.addGradedActivity(110);
		s1.addGradedActivity(50);
		s1.printGrade();
	}
}