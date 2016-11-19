<div>
    <table class="table table-striped">
        <tr>
            <th>Serial no.</th>
            <th>Symbol</th>
            <th>Shares</th>
        </tr>
        <?php
            $i=1;
            
        foreach ($portfolio as $row)
        {
            print("<tr>");
            print("<td>{$i}</td>");
            print("<td>" . $row["symbol"] . "</td>");
            print("<td>" . $row["shares"] . "</td>");
            print("</tr>");
            $i++;
        }
        print("<tr>");
            print("<td>Cash</td>");
            print("<td></td>");
            print("<td> $".number_format((float)$cash[0]["cash"], 2, '.', '')."</td>");
            print("</tr>");
    ?>
    </table>


</div>
