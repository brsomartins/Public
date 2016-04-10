package br.com.farmacia.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import br.com.farmacia.entity.Medicamento;
import br.com.farmacia.service.MedicamentoService;

public class EditarMedicamentoController extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		doPost(req, resp);
	}

	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		int id = Integer.parseInt(req.getParameter("id"));
		String nome = req.getParameter("nome");
		int preco = Integer.parseInt(req.getParameter("preco"));
		String origem = req.getParameter("origem");
		Medicamento m = new Medicamento(id, nome, preco);
		req.setAttribute("medicamento", m);

		if (origem.equals("exibir")) {
			RequestDispatcher rd = req.getRequestDispatcher("editar.jsp");
			rd.forward(req, resp);
		} else if (origem.equals("editar")) {
			new MedicamentoService().setMedicamento(m.getId(), m.getNome(),
					m.getPreco());
			RequestDispatcher rd = req.getRequestDispatcher("medicamento.jsp");
			rd.forward(req, resp);
		}
	}

}