
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Di_DiAdapter) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Di, DiAdapter, smce, core_di_diadapter, smce_core_di_diadapter_method_entry, 0);

	/**
	 * @var prefix
	 */
	zend_declare_property_string(smce_core_di_diadapter_ce, SL("prefix"), "smceDi.", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapter
	 */
	zend_declare_property_null(smce_core_di_diadapter_ce, SL("adapter"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapterName
	 */
	zend_declare_property_null(smce_core_di_diadapter_ce, SL("adapterName"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 * @param int
 * @return bool
 */
PHP_METHOD(Smce_Core_Di_DiAdapter, set) {

	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *duration, *_0, *_1 = NULL, *_2, *_3, *_4$$3, *_5$$3, *_6$$4, *_7$$4, *_8$$4, *_9$$4 = NULL, *_11$$4 = NULL, *_12$$4, *_13$$5, *_14$$5, *_15$$5, *_16$$5 = NULL, *_17$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &duration);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, key);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _3);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		_4$$3 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
		_5$$3 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_4$$3, "Memcache")) {
			_6$$4 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
			ZEPHIR_OBS_VAR(_7$$4);
			zephir_read_static_property_ce(&_7$$4, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
			ZEPHIR_INIT_VAR(_8$$4);
			ZEPHIR_CONCAT_VV(_8$$4, _7$$4, key);
			ZEPHIR_CALL_CE_STATIC(&_9$$4, smce_core_di_ce, "resolve", &_10, 60, key);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_11$$4, "serialize", NULL, 61, _9$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_12$$4);
			ZVAL_BOOL(_12$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, _6$$4, "set", NULL, 0, _8$$4, _11$$4, _12$$4, duration);
			zephir_check_call_status();
			RETURN_MM_BOOL(1);
		} else if (ZEPHIR_IS_STRING(_5$$3, "Redis")) {
			_13$$5 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
			ZEPHIR_OBS_VAR(_14$$5);
			zephir_read_static_property_ce(&_14$$5, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
			ZEPHIR_INIT_VAR(_15$$5);
			ZEPHIR_CONCAT_VV(_15$$5, _14$$5, key);
			ZEPHIR_CALL_CE_STATIC(&_16$$5, smce_core_di_ce, "resolve", &_10, 60, key);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_17$$5, "serialize", NULL, 61, _16$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _13$$5, "set", NULL, 0, _15$$5, _17$$5, duration);
			zephir_check_call_status();
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param string
 * @return function
 */
PHP_METHOD(Smce_Core_Di_DiAdapter, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, key);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 62, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @return bool
 */
PHP_METHOD(Smce_Core_Di_DiAdapter, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1, *_2$$3, *_3$$3, *_4$$3, *_5$$4, *_6$$4, *_7$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		_2$$3 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3$$3);
		zephir_read_static_property_ce(&_3$$3, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VV(_4$$3, _3$$3, key);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "delete", NULL, 0, _4$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_5$$4 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_6$$4);
		zephir_read_static_property_ce(&_6$$4, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
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
PHP_METHOD(Smce_Core_Di_DiAdapter, setAdapter) {

	zend_bool _1, _6;
	zval *adapter, *_0, *_2, _3, *_4, *_5, *_7, _8, *_9, *_10, *_11$$3, *_12$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &adapter);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
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
	_5 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
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
	_10 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
	if (_1) {
		ZEPHIR_INIT_ZVAL_NREF(_11$$3);
		ZEPHIR_INIT_VAR(_11$$3);
		ZVAL_STRING(_11$$3, "Memcache", 1);
		zephir_update_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName"), &_11$$3 TSRMLS_CC);
	} else if (_6) {
		ZEPHIR_INIT_ZVAL_NREF(_12$$4);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_STRING(_12$$4, "Redis", 1);
		zephir_update_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName"), &_12$$4 TSRMLS_CC);
	} else if (Z_TYPE_P(_10) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "only Memcache and Redis", "smce/core/di/diadapter.zep", 121);
		return;
	}
	zephir_update_static_property_ce(smce_core_di_diadapter_ce, SL("adapter"), &adapter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Smce_Core_Di_DiAdapter, isAdapter) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

