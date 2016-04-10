<?php
	$rand = rand(1, 5);

	if (!isset($_GET["fname"]) && !isset($_POST["guess"])) {
		echo
		"<html>
			<head>
				<title>Assignment 10</title>
				<script>
					function submitted() {
						var fname = document.getElementById('fname').value;
						var lname = document.getElementById('lname').value;
						var email = document.getElementById('email').value;
						var msg = document.getElementById('msg');
						var errors = 0;

						msg.innerHTML = '';

						if (fname == '') {
							msg.innerHTML += 'First name must be filled out.<br>';
							errors++;
						}

						if (lname == '') {
							msg.innerHTML += 'Last name must be filled out.<br>';
							errors++;
						}

						if (email == '') {
							msg.innerHTML += 'Email must be filled out.<br>';
							errors++;
						} else {
							if (email.indexOf('@') == -1) {
								msg.innerHTML += 'Email must contain a \'@\' character.<br>';
								errors++;
							}

							if (email.indexOf('.') == -1) {
								msg.innerHTML += 'Email must contain a \'.\' character.';
								errors++;
							}
						}

						if (errors == 0) {
							return true;
						} else {
							return false;
						}
					}
				</script>
			</head>
			<body>
				<h1>Welcome to CSCE 3193 Assignment 10!</h1>
				<p>Please fill out the form below to begin a super fun game.</p>
				<form method='get' action='assignment10.php' onsubmit='return submitted()'>
					Your first name: <input type='text' name='fname' id='fname' value='Breno'><br>
					Your last name: <input type='text' name='lname' id='lname' value='Martins'><br>
					Your email address:  <input type='text' name='email' id='email' value='bsoaresm@uark.edu'><br>
					<input type='submit' value='Submit'>
				</form>
				<div id='msg'></div>
			</body>
		</html>";
	} else if (!isset($_POST["guess"])) {
		echo
		"<html>
			<head>
				<title>Assignment 10</title>
			</head>
			<body>
				<p>Hi ", $_GET["fname"], " ", $_GET["lname"], "!  Let's play a super fun game!</p>
				<p>I'm thinking of a number between 1 and 5. See if you can guess it!</p>
				<form method='post' action='assignment10.php'>
					Your guess: <input type='text' name='guess'>
					<input type='hidden' name='answer' value='", $rand, "'>
					<input type='submit' value='Guess!'>
				</form>
			</body>
		</html>";
	} else {
		if ($_POST["guess"] != $_POST["answer"]) {
			echo
			"<html>
				<head>
					<title>Assignment 10</title>
				</head>
				<body>
					<p>Oops!  Your guess, ", $_POST["guess"], ", was wrong.  Please try again!</p>
					<form method='post' action='assignment10.php'>
						Your guess: <input type='text' name='guess'>
						<input type='hidden' name='answer' value='", $_POST["answer"], "'>
						<input type='submit' value='Guess!'>
					</form>
				</body>
			</html>";
		} else {
			echo
			"<html>
				<head>
					<title>Assignment 10</title>
				</head>
				<body>
					Oh boy! You got it! See how much fun that was!?!?
				</body>
			</html>";
		}
	}
?>