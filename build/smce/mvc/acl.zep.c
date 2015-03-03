
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

	zephir_fcall_cache_entry *_14 = NULL;
	zend_bool _9, _20;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_17 = NULL, *_19 = NULL, *_22 = NULL;
	zval *value = NULL, *ip = NULL, *_0 = NULL, *_2 = NULL, *_3, **_6, *_7 = NULL, *_8, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_16, *_18, *_21 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, smce_sm_ce, "app", &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("ip"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(ip, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "smce/mvc/acl.zep", 94);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(value, _6);
		ZEPHIR_CALL_CE_STATIC(&_7, smce_sm_ce, "app", &_1);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_2);
		zephir_read_property(&_2, _7, SL("action"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, value, SL("actions"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 54 TSRMLS_CC);
		if (zephir_fast_in_array(_2, _8 TSRMLS_CC)) {
			_9 = zephir_array_isset_string(value, SS("ip"));
			if (_9) {
				zephir_array_fetch_string(&_10, value, SL("ip"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 58 TSRMLS_CC);
				_9 = zephir_fast_in_array(ip, _10 TSRMLS_CC) == 1;
			}
			if (_9) {
				ZEPHIR_INIT_NVAR(_11);
				object_init_ex(_11, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, 404);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_14, _12, _13);
				zephir_check_temp_parameter(_13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11, "smce/mvc/acl.zep", 61 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_string(&_16, value, SL("users"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 67 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "logincontrol", &_17, _16);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_15)) {
				if (zephir_array_isset_string(value, SS("redirect"))) {
					zephir_array_fetch_string(&_18, value, SL("redirect"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 73 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", &_19, _18);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_11);
				object_init_ex(_11, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, 404);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_14, _12, _13);
				zephir_check_temp_parameter(_13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11, "smce/mvc/acl.zep", 76 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_20 = zephir_array_isset_string(value, SS("expression"));
			if (_20) {
				zephir_array_fetch_string(&_18, value, SL("expression"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 80 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_21, this_ptr, "expressioncontrol", &_22, _18);
				zephir_check_call_status();
				_20 = !ZEPHIR_IS_TRUE(_21);
			}
			if (_20) {
				ZEPHIR_INIT_NVAR(_11);
				object_init_ex(_11, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, 404);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_14, _12, _13);
				zephir_check_temp_parameter(_13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11, "smce/mvc/acl.zep", 83 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Smce_Mvc_Acl, redirect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *url_param = NULL;
	zval *url = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(url, url_param);


	if (!(ZEPHIR_IS_EMPTY(url))) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "Location:", url);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, _0);
		zephir_check_call_status();
		zephir_exit_empty();
		ZEPHIR_MM_RESTORE();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $users
 * @param $redirect
 *
 * @redirect url
 */
PHP_METHOD(Smce_Mvc_Acl, loginControl) {

	zend_bool _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *users_param = NULL, *session = NULL, *_1, *_4 = NULL;
	zval *users = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &users_param);

	if (!users_param) {
		ZEPHIR_INIT_VAR(users);
		ZVAL_STRING(users, "", 1);
	} else {
		zephir_get_strval(users, users_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&session, smce_core_eventmanager_ce, "pull", &_0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_STRING(users, "@");
	if (_2) {
		_3 = ZEPHIR_IS_FALSE(session);
		if (!(_3)) {
			ZEPHIR_CALL_METHOD(&_4, session, "getloginstate", NULL);
			zephir_check_call_status();
			_3 = !zephir_is_true(_4);
		}
		_2 = _3;
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	} else {
		RETURN_MM_BOOL(1);
	}

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

