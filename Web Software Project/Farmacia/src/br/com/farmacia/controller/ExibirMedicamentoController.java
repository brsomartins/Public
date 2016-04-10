package br.com.farmacia.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import br.com.farmacia.entity.Medicamento;
import br.com.farmacia.service.MedicamentoService;

public class ExibirMedicamentoController extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		doPost(req, resp);
	}

	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		int id = Integer.parseInt(req.getParameter("id"));
		Medicamento m = new MedicamentoService().getMedicamento(id);
		req.setAttribute("medicamento", m);
		req.setAttribute("id", id);
		RequestDispatcher rd = req.getRequestDispatcher("medicamento.jsp");
		rd.forward(req, resp);
	}
}