<?php

	$di=new Smce\Core\DI;

	$di->bind("app1ses",function(){

	     $session = new Smce\Components\Session;
	     $session->setSecurity(md5("%22AFbsaU"));
	     $session->register();
	     return $session;

	});


	$di->bind("app2ses",function(){

	     $session = new Smce\Components\Session;
	     $session->setSecurity(md5("Ac2385Cs6"));
	     $session->register();
	     return $session;

	});

	

	//set
	Smce\Core\DI::resolve("app1ses")->set("ID",53); //set
	Smce\Core\DI::resolve("app2ses")->set("ID",28); //set
	
	//get
	echo Smce\Core\DI::resolve("app1ses")->get("ID"); //53
	echo "<br>";
	echo Smce\Core\DI::resolve("app2ses")->get("ID"); //28

	//remove
	Smce\Core\DI::resolve("app1ses")->remove("ID"); // app1ses remove ID
	Smce\Core\DI::resolve("app2ses")->remove("ID"); // app2ses remove ID

	//reset
	Smce\Core\DI::resolve("app1ses")->reset(); // reset app1ses
	Smce\Core\DI::resolve("app2ses")->reset(); // reset app2ses