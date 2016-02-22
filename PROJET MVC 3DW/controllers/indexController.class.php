<?php
class indexController{

	public function indexAction($args){
		echo "Bonjour indexAction";
		
		$article = new articles();
		$article->setTitle("TITRE");
		$article->setContent("description");
		$article->save();
		
		$v = new view();
		$v->setView("IndexIndex", "template");
		$v->assign("nom_pseudo", "nom pseudo");
	}

	public function testAction($args){
		echo "Bonjour testAction";
	}

}
