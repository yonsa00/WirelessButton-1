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
        $conf = include('./config.php');

        $hostname = $conf['hostname'];
        $username = $conf['username'];
        $password = $conf['password'];
        $database = $conf['database'];

        $conn = new mysqli($hostname, $username, $password, $database) or die("Failed connect: %s\n" . $conn->error);
        return $conn;
    }
    function get_url(){
        if ($this->is_url_query('mode')) {
            switch ($this->get_url_query_value('mode')) {
                default:
                    $this->read_data($this->get_url_query_value('Device'));
                
                    case 'save':
                        if ($this->is_url_query('Status'))
                        {
                            $Status = $this->get_url_query_value('Status');
                            $this->create_data($this->get_url_query_value('Device'), $Status);
                        }   
                        else {
                            $error = [
                                'Sensor'=> 'required'
                            ];
                            echo $this->error_handler($error);
                        }
                    break;
        
            }   
        }
    }

    function create_data($Dev, $Status)
    {
        $get_query = "SELECT Status FROM {$Dev}";
        echo $this->execute_query($get_query, null, 1);
        // echo $get;

        echo nl2br("\r\r");
        $arrayStatus['data'] = $Status;
        $arrayStatus = json_encode($arrayStatus);
        echo $arrayStatus;

        // $sql_query = "INSERT INTO {$Dev} (Sensor, Stat, Volume, Temperature_Panel, Humidity, Temperature_Motor, Pressure1, Pressure2, Pressure3, Temperature_Oil) 
        // VALUES ('".$Sen."','".$Stat."','".$Vol."','".$Temp."','".$Hum."','".$Tempmtr."','".$Prs1."','".$Prs2."','".$Prs3."','".$Tempoil."')";
        // echo $this->execute_query($sql_query);
    }

    private function execute_query($sql, $data = [], $is_read = null)
    {
        $executed = $this->connection->query($sql);
        if ($executed == TRUE)
        {
            if($is_read == null){
            $data['status'] = true;
            $data['message'] = 'data operation success';
            

            if (!is_null($is_read) && $is_read)
            {
                // $data['data'] = [];
                // if($executed->num_rows != 0)
                // {
                //     while($row = $executed->fetch_all())
                //     {
                //         $data['data'] = $row;
                //     }
                // }
            }
            // $data['payload'] = $row;
            
            }else
            $row = $executed->fetch_all();
            $data = $row;
            return json_encode($data);

        }

        $data['status'] = false;
        $data['message'] = 'data operation failed';
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