<?php

/**
* A simple parser that extends FeedsSimplePieParser by adding support for a
* couple of iTunes tags.
*/
class SimplePieGeoWKTParser extends FeedsSimplePieParser
{
	/**
	* Add the extra mapping sources provided by this parser.
	*/
	public function getMappingSources()
	{
		return parent::getMappingSources() + array(
			'geolocation_wkt' => array(
				'name' => t('Geo location as WKT'),
				'description' => t('Transforms geo data into WKT'),
			),
		);
	}
	
	/**
	* Parse the extra mapping sources provided by this parser.
	*/
	protected function parseExtensions(&$item, $simplepie_item)
	{
		$latitude = $simplepie_item->get_latitude();
		$longitude = $simplepie_item->get_longitude();
		
		if($latitude && $longitude)
		{
			$item['geolocation_wkt'] = 'GEOMETRYCOLLECTION(POINT('.$longitude.' '.$latitude.'))';
		}
	}
}
