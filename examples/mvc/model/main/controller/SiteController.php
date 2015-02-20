<?php

class SiteController
{

	public function actionIndex()
	{

		
		$person= new Person;
		
		echo $person->get();

		echo "<br>";
		
		$personSub= new Person\Sub;
		
		echo $personSub->get();
		
	}



}