
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/exit.h"

ZEPHIR_INIT_CLASS(Smce_Mvc_Acl) {

	ZEPHIR_REGISTER_CLASS(Smce\\Mvc, Acl, smce, mvc_acl, smce_mvc_acl_method_entry, 0);

	zend_declare_property_null(smce_mvc_acl_ce, SL("rules"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $accessRules
 * @param $view
 *
 * @return bool
 */
PHP_METHOD(Smce_Mvc_Acl, setRule) {

	zval *rule_param = NULL, *_0, *_1;
	zval *rule = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rule_param);

	zephir_get_arrval(rule, rule_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, zephir_fast_count_int(_0 TSRMLS_CC));
	zephir_update_property_array(this_ptr, SL("rules"), _1, rule TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Mvc_Acl, getRules) {


	RETURN_MEMBER(this_ptr, "rules");

}

PHP_METHOD(Smce_Mvc_Acl, run) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_14 = NULL, *_18 = NULL, *_20 = NULL;
	zend_bool control = 0, _9, _15;
	zval *value = NULL, *ip = NULL, *_0 = NULL, *_2 = NULL, *_3, **_6, *_7 = NULL, *_8, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_16 = NULL, *_17, *_19;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, smce_sm_ce, "app", &_1, 87);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("ip"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(ip, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "smce/mvc/acl.zep", 82);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(value, _6);
		ZEPHIR_CALL_CE_STATIC(&_7, smce_sm_ce, "app", &_1, 87);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_2);
		zephir_read_property(&_2, _7, SL("action"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, value, SL("actions"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 56 TSRMLS_CC);
		if (zephir_fast_in_array(_2, _8 TSRMLS_CC)) {
			control = 1;
			_9 = zephir_array_isset_string(value, SS("ip"));
			if (_9) {
				zephir_array_fetch_string(&_10, value, SL("ip"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 60 TSRMLS_CC);
				_9 = zephir_fast_in_array(ip, _10 TSRMLS_CC) == 1;
			}
			if (_9) {
				ZEPHIR_INIT_NVAR(_11);
				object_init_ex(_11, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, 404);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_14, 25, _12, _13);
				zephir_check_temp_parameter(_13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11, "smce/mvc/acl.zep", 63 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_15 = zephir_array_isset_string(value, SS("expression"));
			if (_15) {
				zephir_array_fetch_string(&_17, value, SL("expression"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 70 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_16, this_ptr, "expressioncontrol", &_18, 88, _17);
				zephir_check_call_status();
				_15 = !ZEPHIR_IS_TRUE(_16);
			}
			if (_15) {
				zephir_array_fetch_string(&_19, value, SL("redirect"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 72 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", &_20, 89, _19);
				zephir_check_call_status();
			}
		}
	}
	if (control == 0) {
		zephir_array_fetch_string(&_8, value, SL("redirect"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 84 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", &_20, 89, _8);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Smce_Mvc_Acl, redirect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *url_param = NULL, *_0 = NULL, *_2, *_3, *_4, *_5, *_6;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(url, url_param);


	ZEPHIR_CALL_CE_STATIC(&_0, smce_sm_ce, "app", &_1, 87);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("baseUrl"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "refresh:4;url=", _2, "/", url);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 5, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, smce_http_httpexception_ce);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 404);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 25, _5, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(_4, "smce/mvc/acl.zep", 99 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $expression
 *
 * @return bool
 */
PHP_METHOD(Smce_Mvc_Acl, expressionControl) {

	zval *expression_param = NULL;
	zend_bool expression;

	zephir_fetch_params(0, 1, 0, &expression_param);

	expression = zephir_get_boolval(expression_param);


	if (expression == 1) {
		RETURN_BOOL(1);
	}

}

PHP_METHOD(Smce_Mvc_Acl, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("rules"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

