<?php


$di=new Smce\Core\DI;

$di->bind("redis",function(){

	$red=new Smce\Driver\Redis;
	$red->setConfig(array(
			"host"=>"127.0.0.1",
			"port"=>"6379"
		));
	$red->connect();

	return $red;
});



Smce\Core\DI::resolve("redis")->set("key","Hello world!",300);

echo Smce\Core\DI::resolve("redis")->get("key"); // Hello world! 