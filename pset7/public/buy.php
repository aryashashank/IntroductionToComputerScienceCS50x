<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide the company symbol.");
        }
        else if (empty($_POST["shares"]))
        {
            apologize("You must provide number of shares.");
        }
        else if (!preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Number of shares should be a whole number.");
        }
        
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        $stock = lookup($_POST["symbol"]);
        if ($stock == false)
        {
            apologize("Invalid symbol");
        }
        
        if($stock["price"] * $_POST["shares"]>$cash[0]["cash"]){
            $message = "You cannot afford ".$_POST["shares"]." shares.";
              render("apology_cannotAfford.php", ["message" => $message]);
        }
        else{
        $shares = (int)$_POST["shares"];
            cs50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], $_POST["symbol"], $shares, $shares);
            cs50::query("UPDATE users set cash = cash - ? where id = ?", $stock["price"] * $_POST["shares"], $_SESSION["id"]);
            cs50::query("INSERT INTO history (user_id, transaction, datetime, symbol, shares, price) VALUES (?, ?,NOW(), ?, ?,?)", $_SESSION["id"], "BUY", $_POST["symbol"], $_POST["shares"], $stock["price"]);
        }
          redirect("/");
          
    }

?>
