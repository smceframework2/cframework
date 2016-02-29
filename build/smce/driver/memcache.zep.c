
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Driver_Memcache) {

	ZEPHIR_REGISTER_CLASS(Smce\\Driver, Memcache, smce, driver_memcache, smce_driver_memcache_method_entry, 0);

	/**
	 * @var array memcache config
	 */
	zend_declare_property_null(smce_driver_memcache_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var memcache instance
	 */
	zend_declare_property_null(smce_driver_memcache_ce, SL("memcache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	smce_driver_memcache_ce->create_object = zephir_init_properties_Smce_Driver_Memcache;
	return SUCCESS;

}

PHP_METHOD(Smce_Driver_Memcache, getMemcache) {

	

	RETURN_MEMBER(this_ptr, "memcache");

}

PHP_METHOD(Smce_Driver_Memcache, setConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);

}

PHP_METHOD(Smce_Driver_Memcache, getConfig) {

	

	RETURN_MEMBER(this_ptr, "config");

}

/**
 * @return void
 */
PHP_METHOD(Smce_Driver_Memcache, connect) {

	zend_bool _2;
	zval *_0, *_1, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9, *_10, *_11, *_12$$5, *_13$$5, *_14$$5, *_15$$5, *_16$$5, *_17$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	if (!(zephir_isset_property(this_ptr, SS("config") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "MemCache server configuration must have \"host\" and \"port\" values in array.", "smce/driver/memcache.zep", 61);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch_string(&_1, _0, SL("host"), PH_NOISY, "smce/driver/memcache.zep", 64 TSRMLS_CC);
	_2 = ZEPHIR_IS_EMPTY(_1);
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch_string(&_4, _3, SL("port"), PH_NOISY, "smce/driver/memcache.zep", 64 TSRMLS_CC);
		_2 = !(ZEPHIR_IS_EMPTY(_4));
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "MemCache server configuration must have \"host\" and \"port\" not empty", "smce/driver/memcache.zep", 67);
		return;
	}
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, zephir_get_internal_ce(SS("memcache") TSRMLS_CC));
	if (zephir_has_constructor(_5 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("memcache"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_9, _8, SL("host"), PH_NOISY | PH_READONLY, "smce/driver/memcache.zep", 74 TSRMLS_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_11, _10, SL("port"), PH_NOISY | PH_READONLY, "smce/driver/memcache.zep", 74 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "connect", NULL, 0, _9, _11);
	zephir_check_call_status();
	if (!zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_12$$5);
		object_init_ex(_12$$5, zend_exception_get_default(TSRMLS_C));
		_13$$5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_14$$5, _13$$5, SL("host"), PH_NOISY | PH_READONLY, "smce/driver/memcache.zep", 76 TSRMLS_CC);
		_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_16$$5, _15$$5, SL("port"), PH_NOISY | PH_READONLY, "smce/driver/memcache.zep", 76 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_17$$5);
		ZEPHIR_CONCAT_SVSV(_17$$5, "Failed on connecting to memcache server at ", _14$$5, ":", _16$$5);
		ZEPHIR_CALL_METHOD(NULL, _12$$5, "__construct", NULL, 66, _17$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$5, "smce/driver/memcache.zep", 76 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string
 *
 * @return string
 */
PHP_METHOD(Smce_Driver_Memcache, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 * @param bool
 * @param int
 *
 * @return set
 */
PHP_METHOD(Smce_Driver_Memcache, set) {

	int duration, ZEPHIR_LAST_CALL_STATUS;
	zend_bool bolen;
	zval *key_param = NULL, *value_param = NULL, *bolen_param = NULL, *duration_param = NULL, *_0, *_1, *_2;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &key_param, &value_param, &bolen_param, &duration_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(value, value_param);
	bolen = zephir_get_boolval(bolen_param);
	duration = zephir_get_intval(duration_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (bolen) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, duration);
	ZEPHIR_RETURN_CALL_METHOD(_0, "set", NULL, 0, key, value, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 * @param bool
 * @param int
 *
 * @return add
 */
PHP_METHOD(Smce_Driver_Memcache, add) {

	int duration, ZEPHIR_LAST_CALL_STATUS;
	zend_bool bolen;
	zval *key_param = NULL, *value_param = NULL, *bolen_param = NULL, *duration_param = NULL, *_0, *_1, *_2;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &key_param, &value_param, &bolen_param, &duration_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(value, value_param);
	bolen = zephir_get_boolval(bolen_param);
	if (!duration_param) {
		duration = 10;
	} else {
		duration = zephir_get_intval(duration_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (bolen) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, duration);
	ZEPHIR_RETURN_CALL_METHOD(_0, "add", NULL, 0, key, value, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 *
 * @return addServer
 */
PHP_METHOD(Smce_Driver_Memcache, addServer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *host, *port, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host, &port);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addserver", NULL, 0, host, port);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 
 *
 * @return  $get
 *
 */
PHP_METHOD(Smce_Driver_Memcache, close) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "close", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return  close
 *
 */
PHP_METHOD(Smce_Driver_Memcache, decrement) {

	int item, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *item_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &item_param);

	zephir_get_strval(key, key_param);
	item = zephir_get_intval(item_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, item);
	ZEPHIR_RETURN_CALL_METHOD(_0, "decrement", NULL, 0, key, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 *
 * @return delete
 */
PHP_METHOD(Smce_Driver_Memcache, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "delete", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * @return flush
 */
PHP_METHOD(Smce_Driver_Memcache, flush) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "flush", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 
 * @return getExtendedStats
 */
PHP_METHOD(Smce_Driver_Memcache, getExtendedStats) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getextendedstats", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 *
 * @return getServerStatus
 */
PHP_METHOD(Smce_Driver_Memcache, getServerStatus) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *host_param = NULL, *port, *_0;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host_param, &port);

	zephir_get_strval(host, host_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getserverstatus", NULL, 0, host, port);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * @return getStats
 */
PHP_METHOD(Smce_Driver_Memcache, getStats) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getstats", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 
 *
 * @return getVersion
 */
PHP_METHOD(Smce_Driver_Memcache, getVersion) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getversion", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param int
 *
 * @return increment
 */
PHP_METHOD(Smce_Driver_Memcache, increment) {

	int item, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *item_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &item_param);

	zephir_get_strval(key, key_param);
	item = zephir_get_intval(item_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, item);
	ZEPHIR_RETURN_CALL_METHOD(_0, "increment", NULL, 0, key, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 *
 * @return pconnect
 */
PHP_METHOD(Smce_Driver_Memcache, pconnect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *host_param = NULL, *port, *_0;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host_param, &port);

	zephir_get_strval(host, host_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "pconnect", NULL, 0, host, port);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 * @param bool
 * @param int
 *
 * @return replace
 */
PHP_METHOD(Smce_Driver_Memcache, replace) {

	int duration, ZEPHIR_LAST_CALL_STATUS;
	zend_bool bol;
	zval *key_param = NULL, *value_param = NULL, *bol_param = NULL, *duration_param = NULL, *_0, *_1, *_2;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &key_param, &value_param, &bol_param, &duration_param);

	zephir_get_strval(key, key_param);
	zephir_get_strval(value, value_param);
	bol = zephir_get_boolval(bol_param);
	duration = zephir_get_intval(duration_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (bol) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, duration);
	ZEPHIR_RETURN_CALL_METHOD(_0, "replace", NULL, 0, key, value, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int
 * @param float
 *
 * @return setCompressThreshold
 */
PHP_METHOD(Smce_Driver_Memcache, setCompressThreshold) {

	double d;
	zval *i_param = NULL, *d_param = NULL, *_0, *_1, *_2;
	int i, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &i_param, &d_param);

	i = zephir_get_intval(i_param);
	d = zephir_get_doubleval(d_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, i);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_DOUBLE(_2, d);
	ZEPHIR_RETURN_CALL_METHOD(_0, "setcompressthreshold", NULL, 0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

static zend_object_value zephir_init_properties_Smce_Driver_Memcache(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("config"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

