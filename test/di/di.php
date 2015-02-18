<?php


class Di  extends PHPUnit_Framework_TestCase
{
	public function test1()
    {	
    	$di=new Smce\Core\DI;

		$di->bind("foo",function(){

		    return new Foo;

		});


		$foo=$di->resolve("foo");
		$foo2=Smce\Core\DI::resolve("foo");

		$this->assertTrue( $foo->get() );
		$this->assertTrue( $foo2->get() );
    }
}

class Foo{

	public function get()
	{

		return true;
	}
}