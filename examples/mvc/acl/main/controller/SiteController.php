<?php


class SiteController
{
	
	public function  __construct()
	{

		$event=Smce\Core\DI::resolve("EventManager");

		$event->bind("acl",function(){

			$acl= new Smce\Mvc\Acl;
			$acl->setRules(array(
	                'actions'=>array('index','page'), // Actions. is array
	                'users'=>'@',  // Only * or @ values ​​are
	                'redirect'=>"site/login",
	                'expression'=>true,    //True is allowed only. Only TRUE or FALSE values ​​are.
	                //'ip'=>array('127.0.0.1'), //IP is allowed only. is array
            ))->run();
		});

	}

	public function actionIndex()
	{

		echo "Hello world";

	}

	public function actionPage()
	{

		echo "Page";

	}


	public function actionLogin()
	{

		echo "Login Page";

	}


}