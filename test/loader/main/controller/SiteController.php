<?php


class SiteController extends PHPUnit_Framework_TestCase
{
	
	

	public function actionIndex()
	{
		//loader1
		$loader1=new Loader1;

		//get
		$this->assertTrue( $loader1->get() );

		//loader1
		$loader2=new Loader2;

		//get
		$this->assertTrue( $loader2->get() );

	}


}