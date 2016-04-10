package br.com.farmacia.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import br.com.farmacia.entity.Medicamento;
import br.com.farmacia.factory.ConnectionFactory;

public class MedicamentoDAO {
	public Medicamento getMedicamento(int id) {
		ConnectionFactory cf = null;
		Connection c = null;
		PreparedStatement ps = null;
		ResultSet rs = null;

		try {
			cf = new ConnectionFactory();
			c = cf.getConnection();
			ps = c.prepareStatement("select * from tb_medicamento where id = ?");
			ps.setInt(1, id);
			rs = ps.executeQuery();

			while (rs.next()) {
				String nome = rs.getString("nome");
				int preco = rs.getInt("preco");
				Medicamento m = new Medicamento(id, nome, preco);
				return m;
			}

		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				if (rs != null) {
					rs.close();
				}
			} catch (SQLException e) {
				e.printStackTrace();
			} finally {
				try {
					if (ps != null) {
						ps.close();
					}
				} catch (SQLException e) {
					e.printStackTrace();
				} finally {
					try {
						if (c != null) {
							c.close();
						}
					} catch (SQLException e) {
						e.printStackTrace();
					}
				}
			}
		}

		return null;
	}

	public void setMedicamento(int id, String nome, int preco) {
		ConnectionFactory cf = null;
		Connection c = null;
		PreparedStatement ps = null;

		try {
			cf = new ConnectionFactory();
			c = cf.getConnection();
			ps = c.prepareStatement("update tb_medicamento set nome = ?, preco = ? where id = ?");
			ps.setString(1, nome);
			ps.setInt(2, preco);
			ps.setInt(3, id);
			ps.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				if (ps != null) {
					ps.close();
				}
			} catch (SQLException e) {
				e.printStackTrace();
			} finally {
				try {
					if (c != null) {
						c.close();
					}
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
	}

	public static void main(String[] args) {
		new MedicamentoDAO().setMedicamento(1, "Dipirona", 4);
		System.out.println(new MedicamentoDAO().getMedicamento(1).getNome());
	}
}