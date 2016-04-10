import java.io.PrintWriter;

public class Main {
	public static void main(String[] args) throws Exception {
		PrintWriter out = System.console().writer();
		for(int i = 0; i < 100; i++) {
			out.println(i);
		}
	}
}