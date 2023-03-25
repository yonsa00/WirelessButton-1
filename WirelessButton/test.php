<?php
@include 'config.php';
if(isset($_GET["save"])) {
    // $Status = $_GET["Status"];
    $sql = "SELECT Status FROM sub_assy";
    $result1 = mysqli_query($conn, $sql);
    if(mysqli_num_rows($result1) > 0){
        foreach($result1 as $row){
        $rowStatus .= $row['Status']; 
       //$_SESSION['username'] = $row['UserCode'];
       //echo $row;
        }
        echo $rowStatus;
        
    }
}
    if ($conn->connect_error) {
        die("MySQL connection failed: " . $conn->connect_error);
    }
$conn->close();
?>