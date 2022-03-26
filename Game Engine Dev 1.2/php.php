<?php

function generateRandomString($length = 10) {
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $charactersLength = strlen($characters);
    $randomString = '';
    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, $charactersLength - 1)];
    }
    $randomString = $randomString . "@greggdaegg.co.uk";
    return $randomString;
}
	$name = $_POST["name"];
	$email_to = $_POST["toemail"]; 			
	$email_from = generateRandomString(); 
	$email_subject = "Subject"; 
	$thankyou_url = $_SERVER['HTTP_REFERER'];


	$reply_to = $_POST["email"];
	$note = $_POST["message"];
	if(!filter_var($email_from, FILTER_VALIDATE_EMAIL)) {
		die("The email address entered is invalid.");
	}

	$headers  = "From: " . $email_from . "\r\n" . "Reply-To: " . $reply_to;
	
	$message = "Name: " . $name . "\n" . "Note: " . $note . "\n";
;
	ini_set("sendmail_from", $email_from);
	$sent = mail($email_to, $email_subject, $message, $headers, "-f" . $email_from);

	if($sent) {
      date_default_timezone_set("GMT");
$today = date("D M j H:i:s T Y");
$myfile = fopen("log.txt", "a") or die("Unable to open file!");
fwrite($myfile, "Sent To " . $email_to . "(" . $name . ")" . " on: " . $today . "| Note: ". $note . "\n");
fclose($myfile);
		header("Location: " . $thankyou_url);
	} else {
		echo "There has been an error sending your message. Please try later.";
	}
?>

