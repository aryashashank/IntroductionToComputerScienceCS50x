<div>
    <table class="table table-striped">
        <tr>
            <th>Serial no.</th>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
        <?php
            $i=1;
            
        foreach ($history as $row)
        {
            print("<tr>");
            print("<td>{$i}</td>");
            print("<td>" . $row["transaction"] . "</td>");
            print("<td>" . $row["datetime"] . "</td>");
            print("<td>" . $row["symbol"] . "</td>");
            print("<td>" . $row["shares"] . "</td>");
            print("<td>$" . number_format((float)$row["price"], 2, '.', ''). "</td>");
            print("</tr>");
            $i++;
        }
    ?>
    </table>


</div>