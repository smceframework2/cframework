<?php


class SiteController
{

	public function  __construct(Loader3Interface $loader3, Loader4Interface $loader4)
	{

		if($loader3->get()!=true){

			throw new Exception("__construct: was not installed loader3");

		}

		if($loader4->get()!=true){

			throw new  Exception("__construct: was not installed loader4");

		}

	}


	public function actionIndex(Loader3Interface $loader3, Loader4Interface $loader4)
	{

		if($loader3->get()!=true){

			throw new  Exception("actionIndex: was not installed loader3");

		}

		if($loader4->get()!=true){

			throw  new Exception("actionIndex: was not installed loader4");

		}

		$loader3=Smce\Core\DI::resolve("loader3");

		if($loader3->get()!=true){

			throw new  Exception("resolve: was not installed loader3");

		}
	}


}