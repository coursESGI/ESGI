<?php

class view{
	
	protected $data = []; // protected : accessible seulement depuis la classe où l'on se trouve
	protected $view;
	protected $template;
	
	public function setView($view, $layout="template"){
		
		$path_view = "views/".$view.".php";
		$path_template = "views/".$layout.".php";
		
		if(file_exists($path_view)){
			$this->view = $path_view;
			
			if(file_exists($path_template))
			    $this->template = $path_template;
			else
				die("Le template n'existe pas");
				
		}else{
			die("erreur template, view n'existe pas");
		}
	}
	
	public function assign($key, $value){
		$this->data[$key] = $value;
	}
	
	function __destruct(){ // appelé à la fin
		extract($this->data);
		include $this->template;
	}
}