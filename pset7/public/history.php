<?php

    // configuration
    require("../includes/config.php"); 

    $history = cs50::query("select * from history where user_id = ? ", $_SESSION["id"]);
   
    render("history_view.php", ["title" => "Transaction History" ,  "history" => $history]);

?>
