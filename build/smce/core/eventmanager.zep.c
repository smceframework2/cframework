
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_EventManager) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, EventManager, smce, core_eventmanager, smce_core_eventmanager_method_entry, 0);

	zend_declare_property_null(smce_core_eventmanager_ce, SL("evts"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_EventManager, __callStatic) {

	zend_bool _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *key_param = NULL, *params_param = NULL, *es = NULL, _0, _1, *_2, *_6, *_8, *_9, *_10, *_11, _3$$3, _4$$3, *_5$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &params_param);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(params, params_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, key, 0 , 3 , 0);
	if (ZEPHIR_IS_STRING(_2, "get")) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 3);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, zephir_fast_strlen_ev(key));
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_substr(_5$$3, key, 3 , zephir_get_intval(&_4$$3), 0);
		ZEPHIR_INIT_VAR(es);
		zephir_fast_strtolower(es, _5$$3);
	} else {
		ZEPHIR_INIT_NVAR(es);
		zephir_fast_strtolower(es, key);
	}
	_6 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	_7 = !(zephir_array_isset(_6, es));
	if (!(_7)) {
		_8 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		zephir_array_fetch(&_9, _8, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 33 TSRMLS_CC);
		_7 = !(zephir_is_callable(_9 TSRMLS_CC));
	}
	if (_7) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Method Not Found Exception", "smce/core/eventmanager.zep", 36);
		return;
	}
	_10 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_array_fetch(&_11, _10, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 42 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _11, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_EventManager, __call) {

	zend_bool _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *key_param = NULL, *params_param = NULL, *es = NULL, _0, _1, *_2, *_6, *_8, *_9, *_10, *_11, _3$$3, _4$$3, *_5$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &params_param);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(params, params_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, key, 0 , 3 , 0);
	if (ZEPHIR_IS_STRING(_2, "get")) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 3);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, zephir_fast_strlen_ev(key));
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_substr(_5$$3, key, 3 , zephir_get_intval(&_4$$3), 0);
		ZEPHIR_INIT_VAR(es);
		zephir_fast_strtolower(es, _5$$3);
	} else {
		ZEPHIR_INIT_NVAR(es);
		zephir_fast_strtolower(es, key);
	}
	_6 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	_7 = !(zephir_array_isset(_6, es));
	if (!(_7)) {
		_8 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		zephir_array_fetch(&_9, _8, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 61 TSRMLS_CC);
		_7 = !(zephir_is_callable(_9 TSRMLS_CC));
	}
	if (_7) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Method Not Found Exception", "smce/core/eventmanager.zep", 64);
		return;
	}
	_10 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_array_fetch(&_11, _10, es, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _11, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_EventManager, push) {

	zval *key, *class, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &class);



	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, key);
	zephir_update_static_property_array_multi_ce(smce_core_eventmanager_ce, SL("evts"), &class TSRMLS_CC, SL("z"), 1, _0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_EventManager, pull) {

	zval *key_param = NULL, *_0, *_1, *_2$$3, *_3$$3, *_4$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		_2$$3 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_fast_strtolower(_4$$3, key);
		zephir_array_fetch(&_3$$3, _2$$3, _4$$3, PH_NOISY | PH_READONLY, "smce/core/eventmanager.zep", 90 TSRMLS_CC);
		RETURN_CTOR(_3$$3);
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


	ZEPHIR_CALL_ZVAL_FUNCTION(&_0, class, NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	zephir_update_static_property_array_multi_ce(smce_core_eventmanager_ce, SL("evts"), &_0 TSRMLS_CC, SL("z"), 1, _1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_EventManager, remove) {

	zval *key_param = NULL, *_0, *_1, *_2$$3, *_3$$3;
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
		_2$$3 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_fast_strtolower(_3$$3, key);
		zephir_array_unset(&_2$$3, _3$$3, PH_SEPARATE);
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
	zval *key = NULL, *value = NULL, *_0, **_3, *_4$$3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/eventmanager.zep", 153);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4$$3 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		zephir_array_unset(&_4$$3, key, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_EventManager, getKeys) {

	HashTable *_2;
	HashPosition _1;
	int i;
	zval *arr = NULL, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	i = 0;
	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/eventmanager.zep", 167);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_update_long(&arr, i, &key, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
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

	zval *_0, *_1$$3;


	_0 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_static_property_ce(smce_core_eventmanager_ce, SL("evts") TSRMLS_CC);
		RETURN_LONG(zephir_fast_count_int(_1$$3 TSRMLS_CC));
	} else {
		RETURN_LONG(0);
	}

}

