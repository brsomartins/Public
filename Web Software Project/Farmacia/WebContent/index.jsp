<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Buscar</title>
</head>
<body>
	<c:choose>
		<c:when test="${!empty usuarioLogado}">
			Seja bem-vindo, ${usuarioLogado.nome}!<br>
			<form action="LogoutController.do" method="post">
				<input type="submit" value="Sair">
			</form>
		</c:when>
		<c:otherwise>
			Você não está logado.<br>
			<form action="login.html" method="post">
				<input type="submit" value="Logar">
			</form>
		</c:otherwise>
	</c:choose>
	<form action="ExibirMedicamentoController.do" method="post">
		<br> <br>ID: <input type="text" name="id"><br>
		<input type="submit" value="Buscar">
	</form>
</body>
</html>