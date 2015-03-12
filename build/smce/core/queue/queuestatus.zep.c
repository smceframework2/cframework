
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueStatus) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Queue, QueueStatus, smce, core_queue_queuestatus, smce_core_queue_queuestatus_method_entry, 0);

	/**
	 *@var sleep
	 */
	zend_declare_property_null(smce_core_queue_queuestatus_ce, SL("sleep"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 *@var stop
	 */
	zend_declare_property_null(smce_core_queue_queuestatus_ce, SL("stop"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 *@var queKey
	 */
	zend_declare_property_null(smce_core_queue_queuestatus_ce, SL("queKey"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 *@param adapter
 *@return void
 */
PHP_METHOD(Smce_Core_Queue_QueueStatus, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *queKey = NULL;
	zval *adapter = NULL, *queKey_param = NULL;

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
		ZEPHIR_CALL_CE_STATIC(NULL, smce_driver_adapter_ce, "setadapter", &_0, adapter);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Adapter is not empty", "smce/core/queue/queuestatus.zep", 47);
		return;
	}
	if (!ZEPHIR_IS_STRING(queKey, "")) {
		zephir_update_static_property_ce(smce_core_queue_queuestatus_ce, SL("queKey"), &queKey TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Queue Key is not empty", "smce/core/queue/queuestatus.zep", 59);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Queue_QueueStatus, getStatus) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *queKey, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey);



	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "QueueStatus.", queKey);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_driver_adapter_ce, "get", &_0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_Queue_QueueStatus, status) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *arr = NULL, *reArr = NULL, *que = NULL, *status = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_INIT_VAR(reArr);
	array_init(reArr);

	ZEPHIR_INIT_NVAR(arr);
	array_init_size(arr, 6);
	add_index_stringl(arr, 0, SL("Uninitialized"), 1);
	add_index_stringl(arr, 1, SL("Working"), 1);
	add_index_stringl(arr, 2, SL("Not Working"), 1);
	add_index_stringl(arr, 3, SL("Sleep"), 1);
	_1 = zephir_fetch_static_property_ce(smce_core_queue_queuestatus_ce, SL("queKey") TSRMLS_CC);
	ZEPHIR_CALL_SELF(&status, "getstatus", &_0, _1);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(status))) {
		ZEPHIR_CPY_WRT(que, status);
	} else {
		ZEPHIR_INIT_NVAR(que);
		ZVAL_LONG(que, 0);
	}
	ZEPHIR_INIT_NVAR(reArr);
	array_init_size(reArr, 3);
	zephir_array_update_string(&reArr, SL("status"), &que, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch(&_2, arr, que, PH_NOISY, "smce/core/queue/queuestatus.zep", 101 TSRMLS_CC);
	zephir_array_update_string(&reArr, SL("msg"), &_2, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(reArr);

}

