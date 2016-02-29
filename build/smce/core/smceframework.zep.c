
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

	zval *router = NULL, *_1, *_2$$3, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_7$$3 = NULL, *_8$$3, *_9$$3 = NULL, *_10$$4, *_11$$4, *_12$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&router, smce_core_di_ce, "resolve", &_0, 60, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(router)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, smce_core_di_ce, "resolve", &_0, 60, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, _3$$3, "getcontrollername", NULL, 0);
		zephir_check_call_status();
		zephir_ucfirst(_2$$3, _5$$3);
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_VS(_6$$3, _2$$3, "Controller");
		zephir_update_static_property_ce(smce_core_smceframework_ce, SL("controller"), &_6$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_STRING(_8$$3, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7$$3, smce_core_di_ce, "resolve", &_0, 60, _8$$3);
		zephir_check_temp_parameter(_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_9$$3, _7$$3, "getactionname", NULL, 0);
		zephir_check_call_status();
		zephir_ucfirst(_4$$3, _9$$3);
		ZEPHIR_INIT_LNVAR(_6$$3);
		ZEPHIR_CONCAT_SV(_6$$3, "action", _4$$3);
		zephir_update_static_property_ce(smce_core_smceframework_ce, SL("action"), &_6$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_10$$4);
		object_init_ex(_10$$4, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_11$$4);
		ZVAL_LONG(_11$$4, 404);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_STRING(_12$$4, "Set DI 'router'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "__construct", NULL, 45, _11$$4, _12$$4);
		zephir_check_temp_parameter(_12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$4, "smce/core/smceframework.zep", 57 TSRMLS_CC);
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

	zval *_0 = NULL, *_1$$3, *_2$$3, *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscontroller", NULL, 99);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 404);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "Controller Not Found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 45, _2$$3, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "smce/core/smceframework.zep", 73 TSRMLS_CC);
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

	zval *_0, *_1, *_2$$4, *_3$$4, *_4$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	if ((zephir_method_exists(_0, _1 TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "runaction", NULL, 100);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, 404);
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "Page Not Found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 45, _3$$4, _4$$4);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "smce/core/smceframework.zep", 112 TSRMLS_CC);
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

	zval *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("controller") TSRMLS_CC);
	_2 = zephir_fetch_static_property_ce(smce_core_smceframework_ce, SL("action") TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, smce_core_di_disingleton_ce, "make", &_0, 101, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

