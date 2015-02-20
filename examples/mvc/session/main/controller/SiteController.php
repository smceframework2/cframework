<?php


class SiteController
{
	
	

	

	public function actionIndex1()
	{
		

		Smce\Core\DI::resolve("app1ses")->set("ID",53); //set

		Smce\Core\DI::resolve("app2ses")->set("ID",28); //set
		
	}


	public function actionIndex2()
	{

		
		echo Smce\Core\DI::resolve("app1ses")->get("ID"); //53
		echo "<br>";
		echo Smce\Core\DI::resolve("app2ses")->get("ID"); //28

		Smce\Core\DI::resolve("app1ses")->remove("ID"); // app1ses remove ID
		Smce\Core\DI::resolve("app2ses")->remove("ID"); // app2ses remove ID


		Smce\Core\DI::resolve("app1ses")->reset(); // reset app1ses
		Smce\Core\DI::resolve("app2ses")->reset(); // reset app2ses
	}


	


}