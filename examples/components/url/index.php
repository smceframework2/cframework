<?php


$di=new Smce\Core\DI;


$di->bind("url",function(){

     $url=new Smce\Mvc\Url;
     $url->setBaseUrl("/app");
     return $url;

});


echo Smce\Core\DI::resolve("url")->get("controller/action/13"); //  /app/controller/action/13