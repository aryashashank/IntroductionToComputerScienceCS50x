<?php

    // configuration
    require("../includes/config.php"); 

    $portfolio = cs50::query("select portfolio.symbol, portfolio.shares from portfolio where user_id = ? ", $_SESSION["id"]);
    $cash = cs50::query("select cash from users where id = ? ", $_SESSION["id"]);
    render("portfolio.php", ["title" => "Portfolio" ,  "portfolio" => $portfolio , "cash" => $cash]);

?>
