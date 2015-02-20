<?php


$di=new Smce\Core\EventManager;

$di->push("output",function($msg){

	$output= new Smce\Components\Output;

	$output ->setContentType("application/json")
			->put(json_encode(array('message' => $msg)));

});


Smce\Core\EventManager::getOutput("Hello World");
