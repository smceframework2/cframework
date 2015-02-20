
<?php


function baseUrl()
{
	    
	$uri=str_replace("/index.php", "", $_SERVER["SCRIPT_NAME"]);
	
	return str_replace($uri, "", $_SERVER['REQUEST_URI']);
}

$baseUrl=baseUrl();

$di=new Smce\Core\DI;

$di->bind("router",function()use($baseUrl){

	$router = new Smce\Mvc\Router;
	$router->setDefaultController('site');
	$router->setDefaultAction('index');
	$router->handle($baseUrl);

	return $router;
});



 echo 'Controller = ', Smce\Core\DI::resolve("router")->getControllerName(), '<br>';
 echo 'Action = ', Smce\Core\DI::resolve("router")->getActionName(), '<br>';
  

  


