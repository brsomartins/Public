<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Medicamento</title>
</head>
<body>
	<c:choose>
		<c:when test="${!empty medicamento}">
			ID: ${medicamento.id}
			<br> Nome: <a
				href="EditarMedicamentoController.do?id=${medicamento.id}&nome=${medicamento.nome}&preco=${medicamento.preco}&origem=exibir">${medicamento.nome}</a>
			<br> Preço: ${medicamento.preco}
		</c:when>
		<c:otherwise>
			O medicamento com id ${id} não existe.
		</c:otherwise>
	</c:choose>
	<br>
	<form action="index.jsp" method="post">
		<input type="submit" value="Voltar">
	</form>
</body>
</html>