
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
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_Di_DiCache) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Di, DiCache, smce, core_di_dicache, smce_core_di_dicache_method_entry, 0);

	zend_declare_property_null(smce_core_di_dicache_ce, SL("adapter"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_core_di_dicache_ce, SL("thisKey"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_core_di_dicache_ce, SL("thisSingletonKey"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

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

PHP_METHOD(Smce_Core_Di_DiCache, cache) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *duration_param = NULL, *_1, *_2;
	int duration, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &duration_param);

	if (!duration_param) {
		duration = 0;
	} else {
		duration = zephir_get_intval(duration_param);
	}


	if (duration == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "duration is not empty", "smce/core/di/dicache.zep", 45);
		return;
	}
	_1 = zephir_fetch_static_property_ce(smce_core_di_dicache_ce, SL("thisKey") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, duration);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_core_di_diadapter_ce, "set", &_0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

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

