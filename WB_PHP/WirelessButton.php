<?php

class WirelessButton
{

    private $connection;
    public $query_string; 

    function __construct() 
    {
        $this->cors();
        $this->connection = $this->open_connection();
    }

    private function open_connection()
    {
            $conf = include('./config_wirelessbutton.php');

            $servername = $conf['servername'];
            $username = $conf['username'];
            $password = $conf['password'];
            $dbname = $conf['dbname'];
        $conn = new mysqli($servername, $username, $password, $dbname) or die("Failed connect: %s\n" . $conn->error);
        return $conn;
    }

    function get_url(){
        if ($this->is_url_query('mode')) {
            switch ($this->get_url_query_value('mode')) {
                default:
                    $this->read_data($this->get_url_query_value('Line'));

                    case 'read':
                        if ($this->is_url_query('Line') 
                        && $this->is_url_query('Machine'))
                        {
                            $Machine = $this->get_url_query_value('Machine');
                            $Line = $this->get_url_query_value('Line');
                            $this->read_data($Line, $Machine);
                        }   
                        else {
                            $error = [
                                'Line'=> 'required',
                                'Machine'=> 'required'
                            ];
                            echo $this->error_handler($error);
                        }
                    break;

                    case 'update':
                        if ($this->is_url_query('Line') 
                        && $this->is_url_query('Status') 
                        && $this->is_url_query('Machine'))
                        {
                            $Status = $this->get_url_query_value('Status');
                            $Machine = $this->get_url_query_value('Machine');
                            $Line = $this->get_url_query_value('Line');
                            $this->create_data($Line, $Status, $Machine);
                        }   
                        else {
                            $error = [
                                'Line'=> 'required',
                                'Status'=> 'required',
                                'Machine'=> 'required'
                            ];
                            echo $this->error_handler($error);
                        }
                    break;
        
            }   
        }
    }

    function read_data($Line,$Machine)
    {
        $sql_query = "SELECT Departement,status FROM {$Line} WHERE Machine_Name = '".$Machine."' ORDER BY id DESC";
        echo $this->execute_query($sql_query, [], true);
    }

    function create_data($Line, $Status, $Machine)
    {
        $InputArrayStatus = str_split($Status);
        print_r($InputArrayStatus);
        $sp_query = "Call UPDATEMONITORING('".$Line."','Maintenance','".$Machine."',{$InputArrayStatus[0]})";
        echo $this->execute_sp($sp_query);
        $sp_query = "Call UPDATEMONITORING('".$Line."','QC','".$Machine."',{$InputArrayStatus[1]})";
        echo $this->execute_sp($sp_query);
        $sp_query = "Call UPDATEMONITORING('".$Line."','Supply','".$Machine."',{$InputArrayStatus[2]})";
        echo $this->execute_sp($sp_query);
        $sql_query = "UPDATE {$Line} SET Status = {$InputArrayStatus[0]} WHERE Machine_Name = '".$Machine."' AND Departement = 'Maintenance' ";
        echo $this->execute_query($sql_query);
        $sql_query = "UPDATE {$Line} SET Status = {$InputArrayStatus[1]} WHERE Machine_Name = '".$Machine."' AND Departement = 'QC' ";
        echo $this->execute_query($sql_query);
        $sql_query = "UPDATE {$Line} SET Status = {$InputArrayStatus[2]} WHERE Machine_Name = '".$Machine."' AND Departement = 'Supply' ";
        echo $this->execute_query($sql_query);


    }

       private function execute_query($sql, $data = [], $is_read = null)
    {
        $executed = $this->connection->query($sql);
        if ($executed == TRUE)
        {
            $data['status'] = true;
            $data['message'] = 'data operation success';

            if (!is_null($is_read) && $is_read)
            {
                $data['data'] = [];
                if($executed->num_rows != 0)
                {
                    while($row = $executed->fetch_assoc())
                    {
                        $data['data'][] = $row;
                    }
                }
            }

            return json_encode($data);
        }

        $data['status'] = false;
        $data['message'] = 'data operation failed';
        return json_encode($data);
    }

    private function execute_sp($sql, $data = [])
    {
        $executed = $this->connection->query($sql);
        if ($executed == TRUE)
        {
            $data['status'] = true;
            $data['message'] = 'stored procedure execute success';
            $data['data'] = [];
                if($executed->num_rows != 0)
                {
                    while($row = $executed->fetch_assoc())
                    {
                        $data['data'][] = $row;
                    }
                }
                $this->close_connection();
        $this->connection = $this->open_connection();
            return json_encode($data);
        }

        $data['status'] = false;
        $data['message'] = 'stored procedure execute failed';
        $this->close_connection();
        $this->connection = $this->open_connection();
        return json_encode($data);
    }

    function error_handler($params = [])
    {
        $data = [];
        foreach($params as $param => $rules) {
            $data[$param] = $rules;
        }
        $data['status'] = false;
        $data['message'] = 'error on operation';
        return json_encode($data);
    }

    function is_url_query($string_value)
    {
        $query = array();
        parse_str($this->query_string, $query);
        if (array_key_exists($string_value, $query)) {
            return true;
        }
        return false;
    }

    function get_url_query_value($string_value)
    {
        $query = array();
        parse_str($this->query_string, $query);
        return $query[$string_value];
    }

    private function close_connection()
    {
        $this->connection->close();
    }

    private function cors() {
        // Allow from any origin
        if (isset($_SERVER['HTTP_ORIGIN'])) {
            // Decide if the origin in $_SERVER['HTTP_ORIGIN'] is one
            // you want to allow, and if so:
            header("Access-Control-Allow-Origin: {$_SERVER['HTTP_ORIGIN']}");
            header('Access-Control-Allow-Credentials: true');
            header('Access-Control-Max-Age: 86400');    // cache for 1 day
        }
    
        // Access-Control headers are received during OPTIONS requests
        if ($_SERVER['REQUEST_METHOD'] == 'OPTIONS') {
    
            if (isset($_SERVER['HTTP_ACCESS_CONTROL_REQUEST_METHOD']))
                // may also be using PUT, PATCH, HEAD etc
                header("Access-Control-Allow-Methods: GET, POST, OPTIONS");         
    
            if (isset($_SERVER['HTTP_ACCESS_CONTROL_REQUEST_HEADERS']))
                header("Access-Control-Allow-Headers: {$_SERVER['HTTP_ACCESS_CONTROL_REQUEST_HEADERS']}");
    
            exit(0);
        }
    }
}
$app = new WirelessButton;

$app->query_string = $_SERVER['QUERY_STRING'];
echo $app->get_url();
?>