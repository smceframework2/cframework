<?php


$di=new Smce\Core\DI;


$di->bind("loader",function(){

    $loader=new Smce\Core\Loader;

    $loader->setDir(array(
        dirname(__FILE__)."/main/controller/",
    ));

    return $loader;
});


$loader=Smce\Core\DI::resolve("loader");
$loader->register();


$di->bind("EventManager",function(){

    return new Smce\Core\EventManager;

});


function baseUrl()
{
        
    $uri=str_replace("/index.php", "", $_SERVER["SCRIPT_NAME"]);
    
    return str_replace($uri, "", $_SERVER['REQUEST_URI']);
}

$baseUrl=baseUrl();



$di->bind("router",function()use($baseUrl){

    $router = new Smce\Mvc\Router;
    $router->setDefaultController('site');
    $router->setDefaultAction('index');
    $router->handle($baseUrl);

    return $router;
});


try{

	$smce=new Smce\Core\SmceFramework;
	$smce->make();

}catch(Smce\Http\HttpException $e){


    echo $e->getHttpCode(). " - ".$e->getMsg(); 

}
