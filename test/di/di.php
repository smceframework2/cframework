<?php


class Di  extends PHPUnit_Framework_TestCase
{
	public function test1()
    {	
    	$di=new \Smce\Core\DI;

		$di->bind("foo",function(){

		    $foo=new Foo;

		});



    }
}

class Foo{

	public function get()
	{

		return true;
	}
}