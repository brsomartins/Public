package br.com.farmacia.factory;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {
	private Connection conn = null;

	public Connection getConnection() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

		try {
			// conn =
			// DriverManager.getConnection("jdbc:mysql://192.168.10.210:3307/bd_farmacia",
			// "aluno", "aluno");
			conn = DriverManager.getConnection(
					"jdbc:mysql://localhost:3306/psw", "root", "root");
		} catch (SQLException e) {
			e.printStackTrace();
		}

		return conn;
	}

	public static void main(String[] args) {
		System.out.println(new ConnectionFactory().getConnection());
	}
}