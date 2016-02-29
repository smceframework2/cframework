
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Driver_Adapter) {

	ZEPHIR_REGISTER_CLASS(Smce\\Driver, Adapter, smce, driver_adapter, smce_driver_adapter_method_entry, 0);

	/**
	 * @var prefix
	 */
	zend_declare_property_string(smce_driver_adapter_ce, SL("prefix"), "smceAdapter.", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapter
	 */
	zend_declare_property_null(smce_driver_adapter_ce, SL("adapter"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapterName
	 */
	zend_declare_property_null(smce_driver_adapter_ce, SL("adapterName"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 *@var MAX
	 */
	zend_declare_class_constant_long(smce_driver_adapter_ce, SL("MAX"), 2592000 TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 * @param int
 * @return bool
 */
PHP_METHOD(Smce_Driver_Adapter, set) {

	int duration, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *str, *duration_param = NULL, *_0, *_1, *_2$$3, *_3$$3, *_4$$3, *_5$$3, *_6$$3, *_7$$4, *_8$$4, *_9$$4, *_10$$4;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &str, &duration_param);

	zephir_get_strval(key, key_param);
	duration = zephir_get_intval(duration_param);


	_0 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		_2$$3 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3$$3);
		zephir_read_static_property_ce(&_3$$3, smce_driver_adapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VV(_4$$3, _3$$3, key);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_BOOL(_5$$3, 0);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_LONG(_6$$3, duration);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "set", NULL, 0, _4$$3, str, _5$$3, _6$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_7$$4 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_8$$4);
		zephir_read_static_property_ce(&_8$$4, smce_driver_adapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_VV(_9$$4, _8$$4, key);
		ZEPHIR_INIT_VAR(_10$$4);
		ZVAL_LONG(_10$$4, duration);
		ZEPHIR_CALL_METHOD(NULL, _7$$4, "set", NULL, 0, _9$$4, str, _10$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param string
 * @return function
 */
PHP_METHOD(Smce_Driver_Adapter, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, smce_driver_adapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, key);
	ZEPHIR_RETURN_CALL_METHOD(_0, "get", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @return bool
 */
PHP_METHOD(Smce_Driver_Adapter, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1, *_2$$3, *_3$$3, *_4$$3, *_5$$4, *_6$$4, *_7$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		_2$$3 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3$$3);
		zephir_read_static_property_ce(&_3$$3, smce_driver_adapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VV(_4$$3, _3$$3, key);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "delete", NULL, 0, _4$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_5$$4 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_6$$4);
		zephir_read_static_property_ce(&_6$$4, smce_driver_adapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_VV(_7$$4, _6$$4, key);
		ZEPHIR_CALL_METHOD(NULL, _5$$4, "hdel", NULL, 0, _7$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param adapter
 * @return void
 *
 * @return bool
 */
PHP_METHOD(Smce_Driver_Adapter, setAdapter) {

	zend_bool _1, _6;
	zval *adapter, *_0, *_2, _3, *_4, *_5, *_7, _8, *_9, *_10, *_11$$3, *_12$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &adapter);



	_0 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = Z_TYPE_P(_0) == IS_NULL;
	if (_1) {
		ZEPHIR_INIT_VAR(_2);
		zephir_get_class(_2, adapter, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "Memcache", 0);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strpos(_4, _2, &_3, 0 );
		_1 = zephir_is_true(_4);
	}
	_5 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	_6 = Z_TYPE_P(_5) == IS_NULL;
	if (_6) {
		ZEPHIR_INIT_VAR(_7);
		zephir_get_class(_7, adapter, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "Redis", 0);
		ZEPHIR_INIT_VAR(_9);
		zephir_fast_strpos(_9, _7, &_8, 0 );
		_6 = zephir_is_true(_9);
	}
	_10 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapterName") TSRMLS_CC);
	if (_1) {
		ZEPHIR_INIT_ZVAL_NREF(_11$$3);
		ZEPHIR_INIT_VAR(_11$$3);
		ZVAL_STRING(_11$$3, "Memcache", 1);
		zephir_update_static_property_ce(smce_driver_adapter_ce, SL("adapterName"), &_11$$3 TSRMLS_CC);
	} else if (_6) {
		ZEPHIR_INIT_ZVAL_NREF(_12$$4);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_STRING(_12$$4, "Redis", 1);
		zephir_update_static_property_ce(smce_driver_adapter_ce, SL("adapterName"), &_12$$4 TSRMLS_CC);
	} else if (Z_TYPE_P(_10) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "only Memcache and Redis", "smce/driver/adapter.zep", 124);
		return;
	}
	zephir_update_static_property_ce(smce_driver_adapter_ce, SL("adapter"), &adapter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Smce_Driver_Adapter, isAdapter) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_driver_adapter_ce, SL("adapter") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

