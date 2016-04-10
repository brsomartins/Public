package br.com.farmacia.service;

import br.com.farmacia.dao.UsuarioDAO;
import br.com.farmacia.entity.Usuario;

public class UsuarioService {
	public Usuario logar(String nome, String senha) {
		return new UsuarioDAO().logar(nome, senha);
	}
}