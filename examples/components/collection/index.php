<?php

$di=new Smce\Core\DI;

$di->bind("EventManager",function(){

	return new Smce\Core\EventManager;

});



/*****************************************/


$event=Smce\Core\DI::resolve("EventManager");


$event->push("Container",function($arr){

	return new Smce\Components\Collection($arr);

});





$arr=array(10, 12, 6, 65, 32);

$container=Smce\Core\EventManager::getContainer($arr);

echo $container->filter(function($a){

	return $a>12;

})->count();

