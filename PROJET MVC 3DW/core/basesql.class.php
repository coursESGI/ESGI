<?php

class basesql{
	private $table;
	private $pdo;
	private $columns = [];
	
	public function __contruct(){
		$this->table = get_called_class();
		 echo "<br>" . $this->table;
		$dsn = 'mysql:dbname='.DBNAME.':host='.DBHOST;
		try{
			$this->pdo = new PDO($dsn,DBUSER, BDPWD);
		}catch(Exception $e){
			die("Erreur SQL : ".$e->getMessage());
		}
		
		$all_vars = get_object_vars($this); // retourne toutes les variables de mon objet (table, pdo, colonne)
		$class_vars = get_class_vars(get_class()); // retourne les variables correspondant à la classe (donc table, pdo et colonne et celles de la classe enfant)
		$this->columns = array_keys(array_diff_key($all_vars, $class_vars)); // ne récupère que les clefs de l'enfant (table, pdo et colonne)
		print_r($this->columns);
	}
	
	public function save(){
		if(is_numeric($this->id)){
			// UPDATE
		}
		else{
			$sql = "INSERT INTO".$this->table." (".implode(",", $this->columns).")
			        VALUES (:".implode(",:", $this->columns).")";
					
			echo $sql;
		}
	}
}
