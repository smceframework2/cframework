
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
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Di_DiCache) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Di, DiCache, smce, core_di_dicache, smce_core_di_dicache_method_entry, 0);

	/**
	 * @var adapter
	 */
	zend_declare_property_null(smce_core_di_dicache_ce, SL("adapter"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var key
	 */
	zend_declare_property_null(smce_core_di_dicache_ce, SL("thisKey"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var singletonKey
	 */
	zend_declare_property_null(smce_core_di_dicache_ce, SL("thisSingletonKey"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 * @param string
 * @return void
 */
PHP_METHOD(Smce_Core_Di_DiCache, __construct) {

	zval *key, *singletonKey = NULL;

	zephir_fetch_params(0, 1, 1, &key, &singletonKey);

	if (!singletonKey) {
		singletonKey = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_static_property_ce(smce_core_di_dicache_ce, SL("thisKey"), &key TSRMLS_CC);
	if (Z_TYPE_P(singletonKey) != IS_NULL) {
		zephir_update_static_property_ce(smce_core_di_dicache_ce, SL("thisSingletonKey"), &singletonKey TSRMLS_CC);
	}

}

/**
 * @param int
 * @return void
 */
PHP_METHOD(Smce_Core_Di_DiCache, cache) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *duration_param = NULL, *_0 = NULL, *_2, *_3;
	int duration, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &duration_param);

	if (!duration_param) {
		duration = 0;
	} else {
		duration = zephir_get_intval(duration_param);
	}


	if (duration == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "duration is not empty", "smce/core/di/dicache.zep", 63);
		return;
	}
	_2 = zephir_fetch_static_property_ce(smce_core_di_dicache_ce, SL("thisKey") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, duration);
	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_di_diadapter_ce, "set", &_1, _2, _3);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @return bool
 */
PHP_METHOD(Smce_Core_Di_DiCache, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_di_dicache_ce, SL("thisKey") TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_core_di_diadapter_ce, "get", &_0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Smce_Core_Di_DiCache, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_di_dicache_ce, SL("thisKey") TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(smce_core_di_diadapter_ce, "remove", &_0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

