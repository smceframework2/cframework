
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueAdapter) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Queue, QueueAdapter, smce, core_queue_queueadapter, smce_core_queue_queueadapter_method_entry, 0);

	/**
	 * @var prefix
	 */
	zend_declare_property_string(smce_core_queue_queueadapter_ce, SL("prefix"), "smceQueue.", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapterName
	 */
	zend_declare_property_string(smce_core_queue_queueadapter_ce, SL("queKey"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapter
	 */
	zend_declare_property_null(smce_core_queue_queueadapter_ce, SL("adapter"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var adapterName
	 */
	zend_declare_property_null(smce_core_queue_queueadapter_ce, SL("adapterName"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 * @param int
 * @return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueAdapter, set) {

	zval *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *queKey, *key, *class, *duration, *time, *arr = NULL, *newArr = NULL, *_0, *_1, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &queKey, &key, &class, &duration, &time);

	ZEPHIR_INIT_VAR(newArr);
	array_init(newArr);


	zephir_update_static_property_ce(smce_core_queue_queueadapter_ce, SL("queKey"), &queKey TSRMLS_CC);
	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		ZEPHIR_CALL_SELF(&arr, "get", NULL, 0, queKey);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(arr))) {
			ZEPHIR_INIT_VAR(_2);
			zephir_create_array(_2, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_2, SL("class"), &class, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2, SL("time"), &time, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2, SL("duration"), &duration, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&newArr, key, &_2, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_3);
			zephir_fast_array_merge(_3, &(arr), &(newArr) TSRMLS_CC);
			ZEPHIR_CPY_WRT(newArr, _3);
		} else {
			ZEPHIR_INIT_NVAR(_2);
			zephir_create_array(_2, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_2, SL("class"), &class, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2, SL("time"), &time, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2, SL("duration"), &duration, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&newArr, key, &_2, PH_COPY | PH_SEPARATE);
		}
		_4 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_5);
		zephir_read_static_property_ce(&_5, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_6);
		zephir_read_static_property_ce(&_6, smce_core_queue_queueadapter_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_VV(_7, _5, _6);
		ZEPHIR_CALL_FUNCTION(&_8, "serialize", NULL, 43, newArr);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_BOOL(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, _4, "set", NULL, 0, _7, _8, _3, duration);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_4 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_5);
		zephir_read_static_property_ce(&_5, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_static_property_ce(&_6, smce_core_queue_queueadapter_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_VV(_7, _5, _6);
		ZEPHIR_CALL_FUNCTION(&_8, "serialize", NULL, 43, newArr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4, "set", NULL, 0, _7, _8, duration);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param string
 * @param int
 * @return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueAdapter, replace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queKey, *key, *arr, *duration, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &queKey, &key, &arr, &duration);



	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		_2 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_static_property_ce(&_3, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VV(_4, _3, queKey);
		ZEPHIR_CALL_FUNCTION(&_5, "serialize", NULL, 43, arr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZVAL_BOOL(_6, 0);
		ZEPHIR_CALL_METHOD(NULL, _2, "set", NULL, 0, _4, _5, _6, duration);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_2 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_static_property_ce(&_3, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VV(_4, _3, queKey);
		ZEPHIR_CALL_FUNCTION(&_5, "serialize", NULL, 43, arr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "set", NULL, 0, _4, _5, duration);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param string
 * @return function
 */
PHP_METHOD(Smce_Core_Queue_QueueAdapter, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queKey_param = NULL, *_0, *_1 = NULL, *_2, *_3;
	zval *queKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey_param);

	zephir_get_strval(queKey, queKey_param);


	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, queKey);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 44, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string
 * @param string
 * @return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueAdapter, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queKey_param = NULL, *key_param = NULL, *arr = NULL, *duration, *_0, *_1 = NULL, *_2, *_3, *_4;
	zval *queKey = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queKey_param, &key_param);

	zephir_get_strval(queKey, queKey_param);
	zephir_get_strval(key, key_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, queKey);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&arr, "unserialize", NULL, 44, _1);
	zephir_check_call_status();
	zephir_array_fetch(&_4, arr, key, PH_NOISY | PH_READONLY, "smce/core/queue/queueadapter.zep", 143 TSRMLS_CC);
	ZEPHIR_OBS_VAR(duration);
	zephir_array_fetch_string(&duration, _4, SL("duration"), PH_NOISY, "smce/core/queue/queueadapter.zep", 143 TSRMLS_CC);
	zephir_array_unset(&arr, key, PH_SEPARATE);
	ZEPHIR_CALL_SELF(NULL, "replace", NULL, 0, queKey, key, arr, duration);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string
 * @return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueAdapter, removeQue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queKey_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL;
	zval *queKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey_param);

	zephir_get_strval(queKey, queKey_param);


	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "Memcache")) {
		_2 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_static_property_ce(&_3, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VV(_4, _3, queKey);
		ZEPHIR_CALL_METHOD(NULL, _2, "delete", NULL, 0, _4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(_1, "Redis")) {
		_2 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_static_property_ce(&_3, smce_core_queue_queueadapter_ce, SL("prefix") TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VV(_4, _3, queKey);
		ZEPHIR_CALL_METHOD(NULL, _2, "hdel", NULL, 0, _4);
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
PHP_METHOD(Smce_Core_Queue_QueueAdapter, setAdapter) {

	zend_bool _1, _6;
	zval *adapter, *_0, *_2, _3, *_4, *_5, *_7, _8, *_9, *_10, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &adapter);



	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
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
	_5 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	_6 = Z_TYPE_P(_5) == IS_NULL;
	if (_6) {
		ZEPHIR_INIT_VAR(_7);
		zephir_get_class(_7, adapter, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "ReQueues", 0);
		ZEPHIR_INIT_VAR(_9);
		zephir_fast_strpos(_9, _7, &_8, 0 );
		_6 = zephir_is_true(_9);
	}
	_10 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName") TSRMLS_CC);
	if (_1) {
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_STRING(_11, "Memcache", 1);
		zephir_update_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName"), &_11 TSRMLS_CC);
	} else if (_6) {
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "ReQueues", 1);
		zephir_update_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapterName"), &_11 TSRMLS_CC);
	} else if (Z_TYPE_P(_10) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "only Memcache and ReQueues", "smce/core/queue/queueadapter.zep", 196);
		return;
	}
	zephir_update_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter"), &adapter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueAdapter, isAdapter) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_queue_queueadapter_ce, SL("adapter") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

