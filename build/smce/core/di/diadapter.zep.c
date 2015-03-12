
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
 * @github https://github.com/smceframework22
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

	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *duration, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &duration);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, key);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, _3);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		_4 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
		_5 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_4, "Memcache")) {
			_6 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
			ZEPHIR_OBS_VAR(_7);
			zephir_read_static_property_ce(&_7, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_CONCAT_VV(_8, _7, key);
			ZEPHIR_CALL_CE_STATIC(&_9, smce_core_di_ce, "resolve", &_10, key);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_11, "serialize", &_12, _9);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_13);
			ZVAL_BOOL(_13, 0);
			ZEPHIR_CALL_METHOD(NULL, _6, "set", NULL, _8, _11, _13, duration);
			zephir_check_call_status();
			RETURN_MM_BOOL(1);
		} else if (ZEPHIR_IS_STRING(_5, "Redis")) {
			_6 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_7);
			zephir_read_static_property_ce(&_7, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_VV(_8, _7, key);
			ZEPHIR_CALL_CE_STATIC(&_9, smce_core_di_ce, "resolve", &_10, key);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_11, "serialize", &_12, _9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _6, "set", NULL, _8, _11, duration);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, key);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", &_4, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @return bool
 */
PHP_METHOD(Smce_Core_Di_DiAdapter, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		_2 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_static_property_ce(&_3, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VV(_4, _3, key);
		ZEPHIR_CALL_METHOD(NULL, _2, "delete", NULL, _4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_2 = zephir_fetch_static_property_ce(smce_core_di_diadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_static_property_ce(&_3, smce_core_di_diadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VV(_4, _3, key);
		ZEPHIR_CALL_METHOD(NULL, _2, "hdel", NULL, _4);
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
	zval *adapter, *_0, *_2, _3, *_4, *_5, *_7, _8, *_9, *_10, *_11 = NULL;

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
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_STRING(_11, "Memcache", 1);
		zephir_update_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName"), &_11 TSRMLS_CC);
	} else if (_6) {
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "Redis", 1);
		zephir_update_static_property_ce(smce_core_di_diadapter_ce, SL("adapterName"), &_11 TSRMLS_CC);
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

