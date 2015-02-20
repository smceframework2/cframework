
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"
#include "kernel/hash.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_EventManager) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, EventManager, smce, core_eventmanager, smce_core_eventmanager_method_entry, 0);

	zend_declare_property_null(smce_core_eventmanager_ce, SL("evts"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_EventManager, __callStatic) {

	zend_bool _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *params = NULL;
	zval *key_param = NULL, *params_param = NULL, *es = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5, *_7, *_8, *_9, *_10;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &params_param);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(params, params_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, key, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_2, "get")) {
		ZEPHIR_INIT_VAR(es);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, zephir_fast_strlen_ev(key));
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_3, key, &_0, &_1);
		zephir_check_call_status();
		zephir_fast_strtolower(es, _4);
	} else {
		ZEPHIR_INIT_NVAR(es);
		zephir_fast_strtolower(es, key);
	}
	_5 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	_6 = !zephir_array_isset(_5, es);
	if (!(_6)) {
		_7 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		zephir_array_fetch(&_8, _7, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 33 TSRMLS_CC);
		_6 = !zephir_is_callable(_8 TSRMLS_CC);
	}
	if (_6) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Method Not Found Exception", "smce/core/eventmanager.zep", 36);
		return;
	}
	_9 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_array_fetch(&_10, _9, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 42 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _10, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_EventManager, __call) {

	zend_bool _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *params = NULL;
	zval *key_param = NULL, *params_param = NULL, *es = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5, *_7, *_8, *_9, *_10;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &params_param);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(params, params_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, key, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_2, "get")) {
		ZEPHIR_INIT_VAR(es);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, zephir_fast_strlen_ev(key));
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_3, key, &_0, &_1);
		zephir_check_call_status();
		zephir_fast_strtolower(es, _4);
	} else {
		ZEPHIR_INIT_NVAR(es);
		zephir_fast_strtolower(es, key);
	}
	_5 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	_6 = !zephir_array_isset(_5, es);
	if (!(_6)) {
		_7 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		zephir_array_fetch(&_8, _7, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 61 TSRMLS_CC);
		_6 = !zephir_is_callable(_8 TSRMLS_CC);
	}
	if (_6) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Method Not Found Exception", "smce/core/eventmanager.zep", 64);
		return;
	}
	_9 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_array_fetch(&_10, _9, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _10, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_EventManager, push) {

	zval *key, *class, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &class);



	if (!(zephir_instance_of_ev(class, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'class' must be an instance of 'Closure'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, key);
	zephir_update_static_property_array_multi_ce(smce_core_eventmanager_ce, SL("evts"), &class TSRMLS_CC, SL("z"), 1, _0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_EventManager, pull) {

	zval *key_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		_2 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strtolower(_4, key);
		zephir_array_fetch(&_3, _2, _4, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 90 TSRMLS_CC);
		RETURN_CTOR(_3);
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(Smce_Core_EventManager, bind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *class, *_0 = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &class);

	zephir_get_strval(key, key_param);


	if (!(zephir_instance_of_ev(class, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'class' must be an instance of 'Closure'", "", 0);
		return;
	}
	ZEPHIR_CALL_ZVAL_FUNCTION(&_0, class, NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	zephir_update_static_property_array_multi_ce(smce_core_eventmanager_ce, SL("evts"), &_0 TSRMLS_CC, SL("z"), 1, _1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_EventManager, remove) {

	zval *key_param = NULL, *_0, *_1, *_2, *_3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "", 1);
	} else {
		zephir_get_strval(key, key_param);
	}


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		_2 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		zephir_fast_strtolower(_3, key);
		zephir_array_unset(&_2, _3, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_EventManager, has) {

	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "", 1);
	} else {
		zephir_get_strval(key, key_param);
	}


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_EventManager, reset) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/eventmanager.zep", 153);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		zephir_array_unset(&_4, key, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_EventManager, getKeys) {

	HashTable *_2;
	HashPosition _1;
	int i = 0;
	zval *arr, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);

	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/eventmanager.zep", 167);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_update_long(&arr, i, &key, PH_COPY | PH_SEPARATE, "smce/core/eventmanager.zep", 163);
		i++;
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Smce_Core_EventManager, getAll) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(Smce_Core_EventManager, getCount) {

	zval *_0, *_1;


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		RETURN_LONG(zephir_fast_count_int(_1 TSRMLS_CC));
	} else {
		RETURN_LONG(0);
	}

}

