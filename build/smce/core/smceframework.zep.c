
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Smceframework) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, Smceframework, smce, core_smceframework, smce_core_smceframework_method_entry, 0);

	/**
	 * @var controller
	 */
	zend_declare_property_null(smce_core_smceframework_ce, SL("controller"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var action
	 */
	zend_declare_property_null(smce_core_smceframework_ce, SL("action"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @return void
 */
PHP_METHOD(Smce_Core_Smceframework, make) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 95);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "router", NULL, 96);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "command", NULL, 97);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", NULL, 98);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return HttpException|void
 */
PHP_METHOD(Smce_Core_Smceframework, router) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *router = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&router, smce_core_di_ce, "resolve", &_0, 60, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(router)) {
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_2, smce_core_di_ce, "resolve", &_0, 60, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, _2, "getcontrollername", NULL, 0);
		zephir_check_call_status();
		zephir_ucfirst(_1, _4);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_VS(_5, _1, "Controller");
		zephir_update_static_property_ce(smce_core_smceframework_ce, SL("controller"), &_5 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_6, smce_core_di_ce, "resolve", &_0, 60, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8, _6, "getactionname", NULL, 0);
		zephir_check_call_status();
		zephir_ucfirst(_3, _8);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SV(_5, "action", _3);
		zephir_update_static_property_ce(smce_core_smceframework_ce, SL("action"), &_5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, smce_http_httpexception_ce);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 404);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "Set DI 'router'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 43, _7, _9);
		zephir_check_temp_parameter(_9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "smce/core/smceframework.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return HttpException|void
 */
PHP_METHOD(Smce_Core_Smceframework, command) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscontroller", NULL, 99);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 404);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "Controller Not Found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 43, _2, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "smce/core/smceframework.zep", 73 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "controlleraction", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return bool
 */
PHP_METHOD(Smce_Core_Smceframework, isController) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	if (zephir_class_exists(_0, 1 TSRMLS_CC)) {
		RETURN_BOOL(1);
	} else {
		RETURN_BOOL(0);
	}

}

/**
 * 
 * @return HttpException|void
 */
PHP_METHOD(Smce_Core_Smceframework, controllerAction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	if ((zephir_method_exists(_0, _1 TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "runaction", NULL, 100);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 404);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Page Not Found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 43, _3, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "smce/core/smceframework.zep", 112 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return void
 */
PHP_METHOD(Smce_Core_Smceframework, runAction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1, *_2;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	_2 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_core_di_disingleton_ce, "make", &_0, 101, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

