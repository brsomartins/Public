<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Editar</title>
</head>
<body>
	<form action="EditarMedicamentoController.do" method="post">
		<input type="hidden" name="id" value="${medicamento.id}"> ID:
		${medicamento.id}<br> Nome: <input type="text" name="nome"
			value="${medicamento.nome}"><br> Preço: <input
			type="text" name="preco" value="${medicamento.preco}"><br>
		<input type="hidden" name="origem" value="editar"> <input
			type="submit" value="Salvar">
	</form>
</body>
</html>