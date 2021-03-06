
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Queue) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, Queue, smce, core_queue, smce_core_queue_method_entry, 0);

	/**
	 *@var MAX
	 */
	zend_declare_class_constant_long(smce_core_queue_ce, SL("MAX"), 2592000 TSRMLS_CC);

	return SUCCESS;

}

/**
 *@param adapter
 *@return void
 */
PHP_METHOD(Smce_Core_Queue, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *adapter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &adapter);

	if (!adapter) {
		adapter = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(adapter) != IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(NULL, smce_core_queue_queueadapter_ce, "setadapter", &_0, adapter);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Adapter is not empty", "smce/core/queue.zep", 36);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *@param string
 *@param Closure
 *
 *@return false|DiCache
 */
PHP_METHOD(Smce_Core_Queue, bind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *queKey_param = NULL, *key_param = NULL, *class, *_0 = NULL, *_2 = NULL;
	zval *queKey = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &queKey_param, &key_param, &class);

	zephir_get_strval(queKey, queKey_param);
	zephir_get_strval(key, key_param);


	if (!(zephir_instance_of_ev(class, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'class' must be an instance of 'Closure'", "", 0);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_queue_queueadapter_ce, "isadapter", &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		object_init_ex(return_value, smce_core_queue_queuemodel_ce);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_2, class, NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, queKey, key, _2);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *
 *@return false|array
 */
PHP_METHOD(Smce_Core_Queue, resolve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *queKey_param = NULL, *_0 = NULL;
	zval *queKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey_param);

	zephir_get_strval(queKey, queKey_param);


	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_queue_queueadapter_ce, "isadapter", &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		ZEPHIR_RETURN_CALL_CE_STATIC(smce_core_queue_queueadapter_ce, "get", &_2, queKey);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *@param string
 *
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *queKey_param = NULL, *key_param = NULL, *_0 = NULL;
	zval *queKey = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queKey_param, &key_param);

	zephir_get_strval(queKey, queKey_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_queue_queueadapter_ce, "isadapter", &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		ZEPHIR_RETURN_CALL_CE_STATIC(smce_core_queue_queueadapter_ce, "remove", &_2, queKey, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *@param string
 *
 *@return bool
 */
PHP_METHOD(Smce_Core_Queue, removeQue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *queKey_param = NULL, *_0 = NULL;
	zval *queKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queKey_param);

	zephir_get_strval(queKey, queKey_param);


	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_queue_queueadapter_ce, "isadapter", &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		ZEPHIR_RETURN_CALL_CE_STATIC(smce_core_queue_queueadapter_ce, "removeque", &_2, queKey);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

