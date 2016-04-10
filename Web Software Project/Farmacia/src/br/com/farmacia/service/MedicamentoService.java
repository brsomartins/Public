package br.com.farmacia.service;

import br.com.farmacia.dao.MedicamentoDAO;
import br.com.farmacia.entity.Medicamento;

public class MedicamentoService {
	public Medicamento getMedicamento(int id) {
		return new MedicamentoDAO().getMedicamento(id);
	}
	
	public void setMedicamento(int id, String nome, int preco) {
		new MedicamentoDAO().setMedicamento(id, nome, preco);
	}
}