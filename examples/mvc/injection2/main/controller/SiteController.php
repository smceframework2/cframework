<?php


class SiteController
{
	
	public function __construct(PersonInterface $person, CurrentCompany $company)
	{
		echo $company->getCompanyName();

		echo "<br>";

		echo $person->getPersonName()." ".$person->getPersonSurname();

	 	echo "<br>";

	}

	public function actionIndex(CompanyBrand $brand, PersonInterface $person)
	{

		echo "<br>";
		echo $brand->getBrandName();

		echo "<br>";
		echo $person->getPersonName();
		echo "<br>";

		$di=Smce\Core\DI::resolve("brand");
		echo $di->getBrandName();
	}


}