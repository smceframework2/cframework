<?php


class Eventmanager extends PHPUnit_Framework_TestCase
{
	public function test1()
    {	

		//new di    	
		$di=new Smce\Core\DI;

		//bind
		$di->bind("EventManager",function(){

			return new Smce\Core\EventManager;

		});

		//resolve
		$event=Smce\Core\DI::resolve("EventManager");


		//push
		$event->push("sum",function($a,$b){

			return $a+$b;

		});


		//__get
		$this->assertTrue( is_int( Smce\Core\EventManager::getSum(3,5) ) );

		//pull
		$sum=Smce\Core\EventManager::pull("sum");

		$this->assertTrue( is_int( $sum(3,5) ) );

		//has
		$this->assertTrue( Smce\Core\EventManager::has("sum") );

		//getKeys
		$this->assertTrue( is_array(Smce\Core\EventManager::getKeys()) );

		//getAll
		$this->assertTrue( is_array(Smce\Core\EventManager::getAll()) );

		//getCount
		$this->assertInternalType("int", Smce\Core\EventManager::getCount() );


		//remove
		$this->assertTrue( Smce\Core\EventManager::remove("sum") );


		//push
		$event->bind("foo",function(){

			return new EFoo;

		});


		//resolve
		$foo=$event->pull("foo");

		//get
		$this->assertTrue( $foo->get() );

		//reset
		if(Smce\Core\Eventmanager::reset())
		{

			$this->assertTrue(true);

		}
   
    }
}


class EFoo{

	public function get()
	{

		return true;
	}
}
