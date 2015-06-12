
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/time.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/array.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueListen) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Queue, QueueListen, smce, core_queue_queuelisten, smce_core_queue_queuelisten_method_entry, 0);

	/**
	 *@var sleep
	 */
	zend_declare_property_null(smce_core_queue_queuelisten_ce, SL("sleep"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 *@var stop
	 */
	zend_declare_property_null(smce_core_queue_queuelisten_ce, SL("stop"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 *@var queKey
	 */
	zend_declare_property_null(smce_core_queue_queuelisten_ce, SL("queKey"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 *@var adapter
	 */
	zend_declare_property_null(smce_core_queue_queuelisten_ce, SL("adapter"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 *@param adapter
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zval *queKey = NULL;
	zval *adapter = NULL, *queKey_param = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &adapter, &queKey_param);

	if (!adapter) {
		adapter = ZEPHIR_GLOBAL(global_null);
	}
	if (!queKey_param) {
		ZEPHIR_INIT_VAR(queKey);
		ZVAL_EMPTY_STRING(queKey);
	} else {
		zephir_get_strval(queKey, queKey_param);
	}


	if (Z_TYPE_P(adapter) != IS_NULL) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "max_execution_time", 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, -1);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 32, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "memory_limit", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, -1);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 32, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(NULL, smce_core_queue_queueadapter_ce, "setadapter", &_3, 58, adapter);
		zephir_check_call_status();
		zephir_update_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter"), &adapter TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Adapter is not empty", "smce/core/queue/queuelisten.zep", 56);
		return;
	}
	if (!ZEPHIR_IS_STRING(queKey, "")) {
		zephir_update_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey"), &queKey TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Queue Key is not empty", "smce/core/queue/queuelisten.zep", 68);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, start) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL;
	zval *status = NULL, *statusInt = NULL, sleepInt = zval_used_for_init, *_1, *_2 = NULL, *_4, _5 = zval_used_for_init, _6 = zval_used_for_init, _7 = zval_used_for_init, _8 = zval_used_for_init, *_11 = NULL, *_14, *_15 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_SELF(NULL, "changestatus", &_0, 64, _1, _2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		_4 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_CALL_SELF(&status, "getstatus", &_3, 65, _4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 1);
		ZEPHIR_INIT_NVAR(statusInt);
		zephir_substr(statusInt, status, 0 , 1 , 0);
		if (ZEPHIR_IS_LONG(statusInt, 2)) {
			break;
		} else if (ZEPHIR_IS_LONG(statusInt, 3)) {
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, 2);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, zephir_fast_strlen_ev(status));
			ZEPHIR_INIT_NVAR(_2);
			zephir_substr(_2, status, 2 , zephir_get_intval(&_8), 0);
			ZEPHIR_SINIT_NVAR(sleepInt);
			ZVAL_LONG(&sleepInt, zephir_get_intval(_2));
			ZEPHIR_CALL_FUNCTION(NULL, "sleep", &_9, 66, &sleepInt);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "on", &_10, 67);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_11);
		zephir_time(_11);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "transactions", &_12, 68, _11);
		zephir_check_call_status();
		_14 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_15);
		zephir_time(_15);
		ZEPHIR_CALL_SELF(NULL, "onpoint", &_13, 69, _14, _15);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Queue_QueueListen, on) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *on = NULL, *_0, *_1, *_3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&on, this_ptr, "geton", NULL, 70, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_time(_1);
	if (ZEPHIR_GT_LONG(_1, (zephir_get_numberval(on) + 300))) {
		_3 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 1);
		ZEPHIR_CALL_SELF(NULL, "changestatus", &_2, 64, _3, _4);
		zephir_check_call_status();
		_5 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seton", NULL, 71, _5);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_EMPTY(on)) {
		_3 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 1);
		ZEPHIR_CALL_SELF(NULL, "changestatus", &_2, 64, _3, _4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *@param string
 *@param int
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, setOn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *queKey, *_1, *_2 = NULL, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "QueueOn.", queKey);
	ZEPHIR_INIT_VAR(_5);
	zephir_time(_5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 3600);
	ZEPHIR_CALL_CE_STATIC(&_2, smce_driver_adapter_ce, "set", &_3, 73, _4, _5, _6);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *@return string
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, getOn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *queKey, *_1, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "QueueOn.", queKey);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_driver_adapter_ce, "get", &_2, 74, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *@param time
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, transactions) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL, *_9 = NULL, *_12 = NULL;
	zval *time, *arr = NULL, *key = NULL, *value = NULL, *cs = NULL, *_1, **_4, *_6, *_7 = NULL, *_8, *_10, *_11 = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &time);

	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&arr, smce_core_queue_queueadapter_ce, "get", &_0, 61, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(arr) == IS_ARRAY) {
		zephir_is_iterable(arr, &_3, &_2, 0, 0, "smce/core/queue/queuelisten.zep", 213);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(key, _3, _2);
			ZEPHIR_GET_HVALUE(value, _4);
			_6 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_7);
			zephir_time(_7);
			ZEPHIR_CALL_SELF(NULL, "onpoint", &_5, 69, _6, _7);
			zephir_check_call_status();
			zephir_array_fetch_string(&_8, value, SL("time"), PH_NOISY | PH_READONLY, "smce/core/queue/queuelisten.zep", 195 TSRMLS_CC);
			if (ZEPHIR_GE(time, _8)) {
				ZEPHIR_OBS_NVAR(cs);
				zephir_array_fetch_string(&cs, value, SL("class"), PH_NOISY, "smce/core/queue/queuelisten.zep", 197 TSRMLS_CC);
				if ((zephir_method_exists_ex(cs, SS("fire") TSRMLS_CC) == SUCCESS)) {
					_10 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_11);
					zephir_time(_11);
					ZEPHIR_CALL_SELF(NULL, "lasttransactiontime", &_9, 75, _10, _11);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, cs, "fire", NULL, 0);
					zephir_check_call_status();
					_13 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
					ZEPHIR_CALL_CE_STATIC(NULL, smce_core_queue_queueadapter_ce, "remove", &_12, 0, _13, key);
					zephir_check_call_status();
				}
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, stop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_2;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_SELF(NULL, "changestatus", &_0, 64, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 *@param int
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, sleep) {

	zval *_3;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *duration_param = NULL, *_1, _2;
	int duration, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &duration_param);

	if (!duration_param) {
		duration = 0;
	} else {
		duration = zephir_get_intval(duration_param);
	}


	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, duration);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "3:", &_2);
	ZEPHIR_CALL_SELF(NULL, "changestatus", &_0, 64, _1, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 *@param string
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, isQue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *queKey_param = NULL, *arr = NULL;
	zval *queKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey_param);

	zephir_get_strval(queKey, queKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	ZEPHIR_CALL_CE_STATIC(&arr, smce_core_queue_queueadapter_ce, "get", &_0, 61, queKey);
	zephir_check_call_status();
	if (zephir_fast_count_int(arr TSRMLS_CC) > 1) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 *@param string
 *@param int
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, onPoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *queKey, *time, *_1, *_2 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queKey, &time);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "QueueOnPoint.", queKey);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 600);
	ZEPHIR_CALL_CE_STATIC(&_2, smce_driver_adapter_ce, "set", &_3, 73, _4, time, _5);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *@return string
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, getOnPoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *queKey, *_1, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "QueueOnPoint.", queKey);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_driver_adapter_ce, "get", &_2, 74, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *@param string
 *@param int
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, lastTransactionTime) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *queKey, *time, *_1, *_2 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queKey, &time);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "QueueLastTransactionTime.", queKey);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, ((3600 * 24) * 30));
	ZEPHIR_CALL_CE_STATIC(&_2, smce_driver_adapter_ce, "set", &_3, 73, _4, time, _5);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *@return string
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, getLastTransactionTime) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_3, *_4;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_static_property_ce(&_3, smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "QueueLastTransactionTime.", _3);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_driver_adapter_ce, "get", &_2, 74, _4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *@param string
 *@param int
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, changeStatus) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval *queKey, *status, *_1, *_2 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queKey, &status);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "QueueStatus.", queKey);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, (3600 * 24));
	ZEPHIR_CALL_CE_STATIC(&_2, smce_driver_adapter_ce, "set", &_3, 73, _4, status, _5);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *@return string
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, getStatus) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *queKey, *_1, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey);



	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("adapter") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, 72, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "QueueStatus.", queKey);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_driver_adapter_ce, "get", &_2, 74, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *@return array
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, status) {

	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	int onPointTime, onlineMin, ZEPHIR_LAST_CALL_STATUS;
	zval *arr = NULL, *reArr = NULL, *que = NULL, *status = NULL, *statusInt, *_1, _2, _3, *_4 = NULL, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_INIT_VAR(reArr);
	array_init(reArr);

	ZEPHIR_INIT_NVAR(arr);
	zephir_create_array(arr, 4, 0 TSRMLS_CC);
	add_index_stringl(arr, 0, SL("Uninitialized"), 1);
	add_index_stringl(arr, 1, SL("Working"), 1);
	add_index_stringl(arr, 2, SL("Not Working"), 1);
	add_index_stringl(arr, 3, SL("Sleep"), 1);
	onlineMin = 300;
	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_CALL_SELF(&status, "getstatus", &_0, 65, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_INIT_VAR(statusInt);
	zephir_substr(statusInt, status, 0 , 1 , 0);
	if (!(ZEPHIR_IS_EMPTY(status))) {
		ZEPHIR_CPY_WRT(que, statusInt);
	} else {
		ZEPHIR_INIT_NVAR(que);
		ZVAL_LONG(que, 0);
	}
	if (ZEPHIR_IS_LONG(statusInt, 1)) {
		_6 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_CALL_SELF(&_4, "getonpoint", &_5, 76, _6);
		zephir_check_call_status();
		onPointTime = zephir_get_intval(_4);
		ZEPHIR_INIT_VAR(_7);
		zephir_time(_7);
		if (ZEPHIR_GT_LONG(_7, ((onPointTime + onlineMin)))) {
			ZEPHIR_INIT_NVAR(que);
			ZVAL_LONG(que, 2);
		}
	}
	ZEPHIR_INIT_NVAR(reArr);
	zephir_create_array(reArr, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&reArr, SL("status"), &que, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_8);
	zephir_array_fetch(&_8, arr, que, PH_NOISY, "smce/core/queue/queuelisten.zep", 415 TSRMLS_CC);
	zephir_array_update_string(&reArr, SL("msg"), &_8, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(reArr);

}

/**
 *
 *@return false|array
 */
PHP_METHOD(Smce_Core_Queue_QueueListen, getAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *_0 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_queue_queueadapter_ce, "isadapter", &_1, 59);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		_3 = zephir_fetch_static_property_ce(smce_core_queue_queuelisten_ce, SL("queKey") TSRMLS_CC);
		ZEPHIR_RETURN_CALL_CE_STATIC(smce_core_queue_queueadapter_ce, "get", &_2, 61, _3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

