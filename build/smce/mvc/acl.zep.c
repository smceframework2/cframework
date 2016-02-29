
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


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Mvc_Acl) {

	ZEPHIR_REGISTER_CLASS(Smce\\Mvc, Acl, smce, mvc_acl, smce_mvc_acl_method_entry, 0);

	zend_declare_property_null(smce_mvc_acl_ce, SL("rules"), ZEND_ACC_PRIVATE TSRMLS_CC);

	smce_mvc_acl_ce->create_object = zephir_init_properties_Smce_Mvc_Acl;
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
	zend_bool control, _10$$4, _16$$4;
	zval *value = NULL, *ip = NULL, *_0 = NULL, *_2, *_3, **_6, *_7$$3 = NULL, *_8$$3 = NULL, *_9$$3, *_11$$4, *_17$$4 = NULL, *_18$$4, *_12$$5 = NULL, *_13$$5 = NULL, *_14$$5 = NULL, *_20$$6, *_22$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_15 = NULL, *_19 = NULL, *_21 = NULL;

	ZEPHIR_MM_GROW();

	control = 0;
	ZEPHIR_CALL_CE_STATIC(&_0, smce_sm_ce, "app", &_1, 102);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("ip"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(ip, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "smce/mvc/acl.zep", 81);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(value, _6);
		ZEPHIR_CALL_CE_STATIC(&_7$$3, smce_sm_ce, "app", &_1, 102);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_8$$3);
		zephir_read_property(&_8$$3, _7$$3, SL("action"), PH_NOISY_CC);
		zephir_array_fetch_string(&_9$$3, value, SL("actions"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 56 TSRMLS_CC);
		if (zephir_fast_in_array(_8$$3, _9$$3 TSRMLS_CC)) {
			control = 1;
			_10$$4 = zephir_array_isset_string(value, SS("ip"));
			if (_10$$4) {
				zephir_array_fetch_string(&_11$$4, value, SL("ip"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 60 TSRMLS_CC);
				_10$$4 = !(zephir_fast_in_array(ip, _11$$4 TSRMLS_CC)) == 1;
			}
			if (_10$$4) {
				ZEPHIR_INIT_NVAR(_12$$5);
				object_init_ex(_12$$5, smce_http_httpexception_ce);
				ZEPHIR_INIT_NVAR(_13$$5);
				ZVAL_LONG(_13$$5, 403);
				ZEPHIR_INIT_NVAR(_14$$5);
				ZVAL_STRING(_14$$5, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _12$$5, "__construct", &_15, 45, _13$$5, _14$$5);
				zephir_check_temp_parameter(_14$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_12$$5, "smce/mvc/acl.zep", 63 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_16$$4 = zephir_array_isset_string(value, SS("expression"));
			if (_16$$4) {
				zephir_array_fetch_string(&_18$$4, value, SL("expression"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 69 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_17$$4, this_ptr, "expressioncontrol", &_19, 103, _18$$4);
				zephir_check_call_status();
				_16$$4 = !ZEPHIR_IS_TRUE(_17$$4);
			}
			if (_16$$4) {
				zephir_array_fetch_string(&_20$$6, value, SL("redirect"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 71 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", &_21, 104, _20$$6);
				zephir_check_call_status();
			}
		}
	}
	if (control == 0) {
		zephir_array_fetch_string(&_22$$7, value, SL("redirect"), PH_NOISY | PH_READONLY, "smce/mvc/acl.zep", 83 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", &_21, 104, _22$$7);
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


	ZEPHIR_CALL_CE_STATIC(&_0, smce_sm_ce, "app", &_1, 102);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, _0, SL("baseUrl"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "refresh:4;url=", _2, "/", url);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 3, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, smce_http_httpexception_ce);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 404);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "You do not have authority to allow", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 45, _5, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(_4, "smce/mvc/acl.zep", 98 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
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

static zend_object_value zephir_init_properties_Smce_Mvc_Acl(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("rules"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("rules"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

