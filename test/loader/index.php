<?php
<?php


class Loader extends PHPUnit_Framework_TestCase
{
	public function test1()
    {	
    	//di
    	$di=new Smce\Core\DI;

    	//bind
		$di->bind("loader",function(){

		    $loader=new Smce\Core\Loader;

		    $loader->setDir(array(
		        dirname(__FILE__)."/main/controller/",
		        dirname(__FILE__)."/main/model/",
		    ));

		    return $loader;
		});

		//resolve
		$loader=Smce\Core\DI::resolve("loader");

		//register
		$loader->register();

		//bind
		$di->bind("router",function()use($baseUrl){

			//router
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

			$this->assertTrue( false);
		    

		}


	}
}
