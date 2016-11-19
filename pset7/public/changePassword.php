<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("changePassword_form.php", ["title" => "ChangePassword"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["oldPassword"]))
        {
            apologize("You must provide your old password.");
        }
        else if (empty($_POST["newPassword"]))
        {
            apologize("You must provide a new password.");
        }
        else if (empty($_POST["confirmPassword"]))
        {
            apologize("You must confirm your password.");
        }
        if($_POST["newPassword"]!=$_POST["confirmPassword"]){
            apologize("You have entered different values in the new and old Password");
        }
        
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        
        // if we found user, check password
        if (count($rows) == 1)
        {
            $row = $rows[0];

            // compare hash of user's input against hash that's in database
            if (!(password_verify($_POST["oldPassword"], $row["hash"])))
            {
                apologize("Wrong old password");
                
            }
            CS50::query("UPDATE users set hash = ?",password_hash($_POST["newPassword"], PASSWORD_DEFAULT));
            render("passwordChangeSuccess.php", ["title" => "Success"]);
        }
    }

?>