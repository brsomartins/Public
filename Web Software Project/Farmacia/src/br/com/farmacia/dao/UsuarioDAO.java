package br.com.farmacia.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import br.com.farmacia.entity.Usuario;
import br.com.farmacia.factory.ConnectionFactory;

public class UsuarioDAO {
	public Usuario logar(String nome, String senha) {
		ConnectionFactory cf = null;
		Connection c = null;
		PreparedStatement ps = null;
		ResultSet rs = null;

		try {
			cf = new ConnectionFactory();
			c = cf.getConnection();
			ps = c.prepareStatement("select * from tb_usuario");
			rs = ps.executeQuery();

			while (rs.next()) {
				String nomeBanco = rs.getString("nome");
				String senhaBanco = rs.getString("senha");

				if (nome.equals(nomeBanco) && senha.equals(senhaBanco)) {
					Usuario u = new Usuario(nome, senha);
					return u;
				}
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
	
	public static void main(String[] args) {
		System.out.println(new UsuarioDAO().logar("breno", "123").getNome());
	}
}
