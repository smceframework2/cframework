<?php


class Di  extends PHPUnit_Framework_TestCase
{
	public function test1()
    {	

    	//new di
    	$di=new Smce\Core\DI;

    	//bind
		$di->bind("foo",function(){

		    return new Foo;

		});

		//resolve
		$foo=$di->resolve("foo");


		//get
		$this->assertTrue( $foo->get() );

		//has
		$this->assertTrue( Smce\Core\DI::has("foo") );

		//getKeys
		$this->assertTrue( is_array(Smce\Core\DI::getKeys()) );

		//getAll
		$this->assertTrue( is_array(Smce\Core\DI::getAll()) );

		//getCount
		$this->assertInternalType("int", Smce\Core\DI::getCount() );


		//reset
		if(Smce\Core\DI::reset())
		{

			$this->assertTrue(true);

		}

    }
}

