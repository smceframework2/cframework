
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
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
PHP_METHOD(Smce_Mvc_Acl, setRules) {

	zval *rules_param = NULL;
	zval *rules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rules_param);

	zephir_get_arrval(rules, rules_param);


	zephir_update_property_this(this_ptr, SL("rules"), rules TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Mvc_Acl, getRules) {


	RETURN_MEMBER(this_ptr, "rules");

}

PHP_METHOD(Smce_Mvc_Acl, run) {

	zephir_fcall_cache_entry *_18 = NULL;
	zend_bool _12, _27;
	HashTable *_9;
	HashPosition _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_22 = NULL, *_26 = NULL, *_29 = NULL;
	zval *value = NULL, *ip = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5, *_6, *_7, **_10, *_11, *_13, *_14, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_19 = NULL, *_20, *_21, *_23, *_24, *_25, *_28 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, smce_sm_ce, "app", &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("ip"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(ip, _2);
	ZEPHIR_CALL_CE_STATIC(&_3, smce_sm_ce, "app", &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property(&_2, _3, SL("action"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("actions"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 51 TSRMLS_CC);
	if (zephir_fast_in_array(_2, _5 TSRMLS_CC)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		zephir_array_fetch_string(&_7, _6, SL("actions"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 56 TSRMLS_CC);
		zephir_is_iterable(_7, &_9, &_8, 0, 0, "smce/mvc/acl.zep", 93);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(value, _10);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			_12 = zephir_array_isset_string(_11, SS("ip"));
			if (_12) {
				_13 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
				zephir_array_fetch_string(&_14, _13, SL("ip"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 59 TSRMLS_CC);
				_12 = zephir_fast_in_array(ip, _14 TSRMLS_CC) == 1;
			}
			if (_12) {
				ZEPHIR_INIT_NVAR(_15);
				object_init_ex(_15, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_16);
				ZVAL_LONG(_16, 404);
				ZEPHIR_INIT_NVAR(_17);
				ZVAL_STRING(_17, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _15, "__construct", &_18, _16, _17);
				zephir_check_temp_parameter(_17);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15, "smce/mvc/acl.zep", 63 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_20 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			zephir_array_fetch_string(&_21, _20, SL("users"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 69 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_19, this_ptr, "logincontrol", &_22, _21);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_19)) {
				_23 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
				if (zephir_array_isset_string(_23, SS("redirect"))) {
					_24 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
					zephir_array_fetch_string(&_25, _24, SL("redirect"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 76 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", &_26, _25);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_15);
				object_init_ex(_15, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_16);
				ZVAL_LONG(_16, 404);
				ZEPHIR_INIT_NVAR(_17);
				ZVAL_STRING(_17, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _15, "__construct", &_18, _16, _17);
				zephir_check_temp_parameter(_17);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15, "smce/mvc/acl.zep", 79 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
			_27 = zephir_array_isset_string(_23, SS("expression"));
			if (_27) {
				_24 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
				zephir_array_fetch_string(&_25, _24, SL("expression"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 83 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_28, this_ptr, "expressioncontrol", &_29, _25);
				zephir_check_call_status();
				_27 = ZEPHIR_IS_TRUE(_28);
			}
			if (_27) {
				ZEPHIR_INIT_NVAR(_15);
				object_init_ex(_15, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_16);
				ZVAL_LONG(_16, 404);
				ZEPHIR_INIT_NVAR(_17);
				ZVAL_STRING(_17, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _15, "__construct", &_18, _16, _17);
				zephir_check_temp_parameter(_17);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15, "smce/mvc/acl.zep", 86 TSRMLS_CC);
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

