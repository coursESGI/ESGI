<?php

class articles extends basesql{ // article h�rite de ce qui est dans basesql.class.php
	protected $id;
	protected $title;
	protected $content;
	
	public function __contruct(){
		parent::construct(); // permet d'ex�cuter le contructeur de basesql quand on fera un new article();
	}
	
	public function setId($id){
		$this->id = $id;
	}
	
	public function setTitle($title){
		$this->title = trim($title);
	}
	
	public function setContent($content){
		$this->content = trim($content);
	}
	
	public function getId($id){
		return $this->id;
	}
	
	public function getTitle($title){
		return $this->title;
	}
	
	public function getContent($content){
		return $this->content;
	}
}