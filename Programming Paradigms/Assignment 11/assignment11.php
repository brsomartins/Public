<?php
	function login($user, $pass) {
		$file = fopen("assignment11-account-info.txt", "r") or exit("Unable to open file!");
		
		while (!feof($file)) {
			$line = fgets($file);
			$line = trim($line);

			if (strlen($line) > 0) {
				$arr = explode(";", $line);

				if ($user == $arr[0]) {
					if ($pass == $arr[1]) {
						return $arr;
					} else {
						return "pass";
					}
				}
			}
		}

		return "user";
	}

	function change($old, $new) {
		$file = file_get_contents("assignment11-account-info.txt");
		$file = str_replace($old, $new, $file);
		file_put_contents("assignment11-account-info.txt", $file);
	}

	function exists($user) {
		$file = fopen("assignment11-account-info.txt", "r") or exit("Unable to open file!");
		
		while (!feof($file)) {
			$line = fgets($file);
			$line = trim($line);

			if (strlen($line) > 0) {
				$arr = explode(";", $line);

				if ($user == $arr[0]) {
					return true;
				}
			}
		}

		return false;
	}

	function create($info) {
		$file = file_get_contents("assignment11-account-info.txt");
		$file = $file . $info . "\n";
		file_put_contents("assignment11-account-info.txt", $file);
	}
?>

<?php
	$user;

	session_start();

	if (isset($_GET["logout"])) {
		$user = $_SESSION["user"];
		session_unset();
		session_destroy();
		session_start();
	}

	if (!isset($_GET["user"]) && !isset($_SESSION["user"])) {
		echo
		"<html>
			<head>
				<title>Welcome to Breno Martins' Assignment 11 PHP page!</title>
			</head>
			<body bgcolor='white'>
				<h1>Welcome to Breno Martins' Assignment 11 PHP page!</h1><br>
				<hr>";
				if (isset($_GET["logout"])) {
					echo $user, " has logged out.<br>";
				} else {
					echo "No login attempted.<br>";
				}
				echo
				"<hr><br>
				If you have an existing account, log in here:<br>
				<form name='loginForm' action='assignment11.php' method='get'>
					User name: <input type='text' name='user'><br>
					Password: <input type='password' name='pass'></br>
					<input type='submit' value='Login'>
				</form><br>
				<hr><br>
				Otherwise, if you'd like to create an account, please fill out the following form:<br>
				<form name='createAccountForm' action='assignment11.php' method='get'>
					User name: <input type='text' name='user'><br>
					Password: <input type='password' name='pass'><br>
					First name: <input type='text' name='fname'><br>
					Last name: <input type='text' name='lname'><br>
					<input type='hidden' name='create' value='true'>
					<input type='submit' value='Create Account'>
				</form>
			</body>
		</html>";
	} else {
		if ((isset($_GET["user"]) && !(isset($_GET["create"]))) || (isset($_GET["create"]) && ($_GET["user"] == "" || $_GET["pass"] == "" || $_GET["fname"] == "" || $_GET["lname"] == "" || exists($_GET["user"])))) {
			$arr = login($_GET["user"], $_GET["pass"]);

			if ($arr != "pass" && $arr != "user" && !(isset($_GET["create"]) && exists($_GET["user"]))) {
				$_SESSION["user"] = $arr[0];
				$_SESSION["pass"] = $arr[1];
				$_SESSION["fname"] = $arr[2];
				$_SESSION["lname"] = $arr[3];
				$_SESSION["color"] = $arr[4];
				$_SESSION["title"] = $arr[5];
				$_SESSION["image"] = $arr[6];
			} else {
				echo
				"<html>
					<head>
						<title>Welcome to Breno Martins' Assignment 11 PHP page!</title>
					</head>
					<body bgcolor='white'>
						<h1>Welcome to Breno Martins' Assignment 11 PHP page!</h1><br>
						<hr>";
						if (isset($_GET["create"])) {
							if ($_GET["user"] == "") {
								echo "<font color='red'>Please enter a user name.</font>";
							} else if ($_GET["pass"] == "") {
								echo "<font color='red'>Please enter a password.</font>";
							} else if ($_GET["fname"] == "") {
								echo "<font color='red'>Please enter a first name.</font>";
							} else if ($_GET["lname"] == "") {
								echo "<font color='red'>Please enter a last name.</font>";
							} else if (exists($_GET["user"])) {
								echo "<font color='red'>Can't create account. User '", $_GET["user"], "' already exists.</font>";
							}
						} else if ($_GET["user"] == "" || $_GET["pass"] == "") {
							echo "No login attempted.<br>";
						} else {
							if ($arr == "pass") {
								echo "<font color='red'>Incorrect password!</font>";
							} else if ($arr == "user") {
								echo "<font color='red'>User account not found.</font>";
							}
						}
						echo
						"<hr><br>
						If you have an existing account, log in here:<br>
						<form name='loginForm' action='assignment11.php' method='get'>
							User name: <input type='text' name='user'><br>
							Password: <input type='password' name='pass'></br>
							<input type='submit' value='Login'>
						</form><br>
						<hr><br>
						Otherwise, if you'd like to create an account, please fill out the following form:<br>
						<form name='createAccountForm' action='assignment11.php' method='get'>
							User name: <input type='text' name='user'><br>
							Password: <input type='password' name='pass'><br>
							First name: <input type='text' name='fname'><br>
							Last name: <input type='text' name='lname'><br>
							<input type='hidden' name='create' value='true'>
							<input type='submit' value='Create Account'>
						</form>
					</body>
				</html>";
			}
		}
		
		if (isset($_SESSION["user"]) || (isset($_GET["create"]) && ($_GET["user"] != "" && $_GET["pass"] != "" && $_GET["fname"] != "" && $_GET["lname"] != "" && !exists($_GET["user"])))) {
			if (isset($_GET["edit"])) {
				$old = $_SESSION["user"] . ";" . $_SESSION["pass"] . ";" . $_SESSION["fname"] . ";" . $_SESSION["lname"] . ";" . $_SESSION["color"] . ";" . $_SESSION["title"] . ";" . $_SESSION["image"];
				$new = $_SESSION["user"] . ";" . $_SESSION["pass"] . ";" . $_GET["fname"] . ";" . $_GET["lname"] . ";" . $_GET["color"] . ";" . $_GET["title"] . ";" . $_GET["image"];
				change($old, $new);
				$_SESSION["fname"] = $_GET["fname"];
				$_SESSION["lname"] = $_GET["lname"];
				$_SESSION["color"] = $_GET["color"];
				$_SESSION["title"] = $_GET["title"];
				$_SESSION["image"] = $_GET["image"];
			}

			if (isset($_GET["create"])) {
				$info = $_GET["user"] . ";" . $_GET["pass"] . ";" . $_GET["fname"] . ";" . $_GET["lname"] . ";white;Welcome to Breno Martins' Assignment 11 PHP page!;http://upload.wikimedia.org/wikipedia/commons/thumb/9/94/Stick_Figure.svg/170px-Stick_Figure.svg.png";
				create($info);
				$_SESSION["user"] = $_GET["user"];
				$_SESSION["pass"] = $_GET["pass"];
				$_SESSION["fname"] = $_GET["fname"];
				$_SESSION["lname"] = $_GET["lname"];
				$_SESSION["color"] = "white";
				$_SESSION["title"] = "Welcome to Breno Martins' Assignment 11 PHP page!";
				$_SESSION["image"] = "http://upload.wikimedia.org/wikipedia/commons/thumb/9/94/Stick_Figure.svg/170px-Stick_Figure.svg.png";
			}

			echo
			"<html>
				<head>
					<title>", $_SESSION['title'], "</title>
				</head>
				<body bgcolor='", $_SESSION['color'], "'>
					<h1>", $_SESSION['title'], "</h1><br>
					Welcome, ", $_SESSION['user'], "!<br>
					<hr>";

					if (isset($_GET["create"])) {
						echo "Account for user '", $_SESSION['user'], "' successfully created.<br>";
					} else if (isset($_GET["edit"])) {
						echo "Account information successfully edited.";
					} else if (isset($_GET["user"])) {
						echo "User ", $_SESSION['user'], " successfully logged in.<br>";
					} else {
						echo $_SESSION['user'], " is logged in.<br>";
					}
					
					echo
					"<hr><br>
					<img src='", $_SESSION['image'], "' width='200px' height='200px'><br><br>
					<form name='logoutForm' action='assignment11.php' method='get'>
						<input type='hidden' name='logout' value='doLogout'><br>
						<input type='submit' value='Logout'>
					</form><br>
					<hr><br>
					<form name='editAccountForm' action='assignment11.php' method='get'>
						<table>
							<tr>
								<td>First name:</td>
								<td><input type='text' name='fname' value='", $_SESSION['fname'], "'></td>
							</tr>
							<tr>
								<td>Last name:</td>
								<td><input type='text' name='lname' value='", $_SESSION['lname'], "'></td>
							</tr>
							<tr>
								<td>Background color:</td>
								<td><input type='text' name='color' value='", $_SESSION['color'], "'></td>
							</tr>
							<tr>
								<td>Title:</td>
								<td><input type='text' name='title' value='", str_replace("'", "&#39;", $_SESSION['title']), "'></td>
							</tr>
							<tr>
								<td>Image:</td>
								<td><input type='text' name='image' size='100' value='", $_SESSION['image'], "'></td>
							</tr>
						</table>
						<input type='hidden' name='edit' value='true'>
						<input type='submit' value='Edit Account Information'>
				</body>
			</html>";
		}
	}
?>