<?php
class routing{


	public static function setRouting(){
		
		$uri = $_SERVER['REQUEST_URI'];
		$explode_uri = explode("?", $uri);
		$uri = $explode_uri[0];

		$uri = trim( str_replace("PROJET%20MVC%203DW", "", $uri) , "/");

		$explode_uri = explode("/", $uri);
		
		$c = (!empty($explode_uri[0]))?$explode_uri[0]:"index"; // si contrôleur existe, sinon index pour contrôleur
		$a = (!empty($explode_uri[1]))?$explode_uri[1]:"index"; // si action existe, sinon index pour action
		unset($explode_uri[0]);
		unset($explode_uri[1]);
		$args = array_merge($explode_uri, $_REQUEST);

		return ["c" => $c, "a" => $a, "args" => $args];

	}


}
