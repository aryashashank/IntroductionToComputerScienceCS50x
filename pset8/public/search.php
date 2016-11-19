<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    $geo = $_GET["geo"];
    $places =CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST (?)", $geo);
    if($places===[]){
    if(is_numeric($geo)){
        $places = CS50::query("SELECT * FROM places WHERE postal_code LIKE ?", $geo . "%");
    }
    else{
         $places = CS50::query("SELECT * FROM places WHERE place_name LIKE ?", $geo . "%");
    }
    }

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>