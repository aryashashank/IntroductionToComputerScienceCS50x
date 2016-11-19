 <?php
 
 require("../includes/config.php"); 
 
     if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
         $symbols = cs50::query("select symbol from portfolio where user_id = ? ", $_SESSION["id"]);
        render("sell_form.php", ["title" => "Sell", "symbols" => $symbols]);
    }
    else if($_SERVER["REQUEST_METHOD"] =  "POST"){
        if(empty($_POST["symbol"])){
            apologize("Please select the symbol of stocks you want to sell");
        }
        
       $stock = lookup($_POST["symbol"]);
       $symbol = $_POST["symbol"];
       $shares =  cs50::query("select shares from portfolio where user_id = ?  AND symbol =  ?", $_SESSION["id"],  $symbol);
       
       $price = $stock["price"]*$shares[0]["shares"];
        cs50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ? ", $_SESSION["id"] , $_POST["symbol"]);
        cs50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $price , $_SESSION["id"]);
        cs50::query("INSERT INTO history (user_id, transaction, datetime, symbol, shares, price) VALUES (?, ?,NOW(), ?, ?,?)", $_SESSION["id"], "SELL", $_POST["symbol"], $_POST["shares"], $stock["price"]);
        
         redirect("/");
    }
    
 
 ?>