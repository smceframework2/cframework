<?php

$di=new Smce\Core\DI;

$di->bind("memcache",function(){
    $memcache=new Smce\Driver\Memcache;
    $memcache->setConfig(array(
        "host"=>"127.0.0.1",
        "port"=>"11211"
    ));
    $memcache->connect();
    return $memcache;

});

$di->bind("loader",function(){

    $loader=new Smce\Core\Loader;

    $loader->setDir(array(
        dirname(__FILE__)."/main/model/",
    ));

    return $loader;
});


$loader=Smce\Core\DI::resolve("loader");
$loader->register();


// CACHE

$di2=new Smce\Core\DI(Smce\Core\DI::resolve("memcache"));

 
if(Smce\Core\DI::has("hold")==false) {

     $di2->bind("hold",function(){

        $a=1;
        for($i=0;$i<100000;$i++){
          $a++;
        }

         $hold=new Hold;
         $hold->set($a);

        
        return $hold;

    })->cache(3000);

} 



$hold=Smce\Core\DI::resolve("hold");

echo $hold->get();


/******************************************/

// NONCACHE

$di->bind("hold2",function(){

        $a=1;
        for($i=0;$i<100000;$i++){
          $a++;
        }

         $hold=new Hold;
         $hold->set($a);
        
        return $hold;

});

$hold=Smce\Core\DI::resolve("hold2");

echo $hold->get();