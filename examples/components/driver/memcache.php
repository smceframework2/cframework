
<?php


$di=new Smce\Core\DI;

$di->bind("memcache",function(){

	$mem=new Smce\Driver\Memcache;
	$mem->setConfig(array(
			"host"=>"127.0.0.1",
			"port"=>"11211"
		));
	$mem->connect();

	return $mem;
});



Smce\Core\DI::resolve("memcache")->set("key","Hello world!",false,300);

echo Smce\Core\DI::resolve("memcache")->get("key");  // Hello world! 