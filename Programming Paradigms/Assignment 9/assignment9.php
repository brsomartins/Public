<?php
	if ($_REQUEST == null) {
		echo
		"<!DOCTYPE html>
		<html>
			<head>
				<title>Assignment 9: no query string</title>
			</head>
			<body>
				Hello world!<br>
				Breno Martins' assignment 9.<br>
				The query string is null.";
		phpinfo();
		echo
		"	</body>
		</html>";
	} else {
		echo
		"<!DOCTYPE html>
		<html>
			<head>
				<title>Assignment 9: with a query string</title>
			</head>
			<body>
				Hello world!<br>
				Breno Martins' assignment 9.<br>
				The query string is "; var_dump($_REQUEST); echo ".";
		phpinfo();
		echo
		"	</body>
		</html>";
	}
?>