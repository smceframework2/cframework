<?php


class SiteController
{

	public function  __construct(Loader1Interface $loader1, Loader2Interface $loader2)
	{

		if($loader1->get()!=true){

			throw Exception("__construct: was not installed loader1")

		}

		if($loader2->get()!=true){

			throw Exception("__construct: was not installed loader2")

		}

	}


	public function actionIndex(Loader1Interface $loader1, Loader2Interface $loader2)
	{

		if($loader1->get()!=true){

			throw Exception("actionIndex: was not installed loader1")

		}

		if($loader2->get()!=true){

			throw Exception("actionIndex: was not installed loader2")

		}
		
	}


}