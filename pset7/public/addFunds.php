<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("addFunds_form.php", ["title" => "Add Funds"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["amount"]))
        {
            apologize("You must provide the amount");
        }
        else if (!preg_match("/^\d+(\.(\d{2}))?$/", $_POST["amount"]))
        {
            apologize("Amount should be a positive decimal upto 2 decimal places.");
        }
        $amount = floatval($_POST["amount"]);
        cs50::query("UPDATE users set cash = cash + ? where id = ?", $amount, $_SESSION["id"]);
        
        redirect("/");
        
    }

?>