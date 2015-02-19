
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmceFramework) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmceFramework, smce, core_smceframework, smce_core_smceframework_method_entry, 0);

	zend_declare_property_null(smce_core_smceframework_ce, SL("controller"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_core_smceframework_ce, SL("action"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_SmceFramework, make) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "router", &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "command", &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmceFramework, router) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *router = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&router, smce_core_di_ce, "resolve", &_0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(router)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2, smce_core_di_ce, "resolve", &_0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, _2, "getcontrollername", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4, "ucfirst", &_5, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_VS(_6, _4, "Controller");
		zephir_update_static_property_ce(smce_core_smceframework_ce, SL("controller"), &_6 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7, smce_core_di_ce, "resolve", &_0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8, _7, "getactionname", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9, "ucfirst", &_5, _8);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SV(_6, "action", _9);
		zephir_update_static_property_ce(smce_core_smceframework_ce, SL("action"), &_6 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_LONG(_10, 404);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_STRING(_11, "Set DI 'router'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _10, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "smce/core/smceframework.zep", 47 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmceFramework, command) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscontroller", &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 404);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Controller Not Found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "smce/core/smceframework.zep", 60 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "controlleraction", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmceFramework, isController) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	if (zephir_class_exists(_0, 1 TSRMLS_CC)) {
		RETURN_BOOL(1);
	} else {
		RETURN_BOOL(0);
	}

}

PHP_METHOD(Smce_Core_SmceFramework, controllerAction) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	if ((zephir_method_exists(_0, _1 TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "runaction", &_2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 404);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "Page Not Found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "smce/core/smceframework.zep", 93 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmceFramework, runAction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_2;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	_2 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_core_di_singleton_ce, "make", &_0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

