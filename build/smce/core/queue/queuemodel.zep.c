
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueModel) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Queue, QueueModel, smce, core_queue_queuemodel, smce_core_queue_queuemodel_method_entry, 0);

	/**
	 * @var key
	 */
	zend_declare_property_null(smce_core_queue_queuemodel_ce, SL("key"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var queKey
	 */
	zend_declare_property_null(smce_core_queue_queuemodel_ce, SL("queKey"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var class
	 */
	zend_declare_property_null(smce_core_queue_queuemodel_ce, SL("class"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var minute
	 */
	zend_declare_property_long(smce_core_queue_queuemodel_ce, SL("minute"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 * @param string
 * @return void
 */
PHP_METHOD(Smce_Core_Queue_QueueModel, __construct) {

	zval *queKey_param = NULL, *key_param = NULL, *class;
	zval *queKey = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &queKey_param, &key_param, &class);

	zephir_get_strval(queKey, queKey_param);
	zephir_get_strval(key, key_param);


	zephir_update_property_this(this_ptr, SL("key"), key TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("queKey"), queKey TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("class"), class TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 *@param int
 *@return this
 */
PHP_METHOD(Smce_Core_Queue_QueueModel, addMinutes) {

	zval *minute_param = NULL, *_0, *_1;
	int minute;

	zephir_fetch_params(0, 0, 1, &minute_param);

	if (!minute_param) {
		minute = 0;
	} else {
		minute = zephir_get_intval(minute_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("minute"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + ((minute * 60))));
	zephir_update_property_this(this_ptr, SL("minute"), _1 TSRMLS_CC);
	RETURN_THISW();

}

/**
 *@param int
 *@return bool|exception
 */
PHP_METHOD(Smce_Core_Queue_QueueModel, register) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *duration_param = NULL, *time = NULL, *_0, *_1, *_2 = NULL, *_4, *_5, *_6;
	int duration, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &duration_param);

	if (!duration_param) {
		duration = 0;
	} else {
		duration = zephir_get_intval(duration_param);
	}


	if (duration != 0) {
		ZEPHIR_CALL_FUNCTION(&time, "time", NULL);
		zephir_check_call_status();
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("minute"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1);
		zephir_add_function_ex(_1, time, _0 TSRMLS_CC);
		ZEPHIR_CPY_WRT(time, _1);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("queKey"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("key"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("class"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, duration);
		ZEPHIR_CALL_CE_STATIC(&_2, smce_core_queue_queueadapter_ce, "set", &_3, _0, _4, _5, _6, time);
		zephir_check_call_status();
		if (zephir_is_true(_2)) {
			RETURN_MM_BOOL(1);
		}
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Duration is not empty", "smce/core/queue/queuemodel.zep", 92);
		return;
	}
	RETURN_MM_BOOL(0);

}

