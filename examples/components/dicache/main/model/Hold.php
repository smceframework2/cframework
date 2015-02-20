<?php


class Hold
{

	private $key;
	
	public function get()
	{

		return $this->key;

	}

	public function set($key)
	{
		$this->key=$key;

	}
}