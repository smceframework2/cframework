<?php


class SiteController
{


	public function actionIndex(CurPerson $person)
	{

		echo $person->getPersonName(). " ". $person->getPersonSurname();

	}


}