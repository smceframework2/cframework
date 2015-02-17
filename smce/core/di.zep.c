
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/hash.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_Di) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, Di, smce, core_di, smce_core_di_method_entry, 0);

	zend_declare_property_null(smce_core_di_ce, SL("dis"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_Di, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *adapter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &adapter);

	if (!adapter) {
		adapter = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(adapter) != IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(NULL, smce_core_di_diadapter_ce, "setadapter", &_0, adapter);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Di, bind) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
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
	zephir_update_static_property_array_multi_ce(smce_core_di_ce, SL("dis"), &_0 TSRMLS_CC, SL("z"), 1, _1);
	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_di_diadapter_ce, "isadapter", &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		object_init_ex(return_value, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Di, resolve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	zval *key_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5 = NULL, *diCache, *get = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		_2 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strtolower(_4, key);
		zephir_array_fetch(&_3, _2, _4, PH_NOISY | PH_READONLY, "smce/core/di.zep", 59 TSRMLS_CC);
		RETURN_CTOR(_3);
	}
	ZEPHIR_CALL_CE_STATIC(&_5, smce_core_di_diadapter_ce, "isadapter", &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_5)) {
		ZEPHIR_INIT_VAR(diCache);
		object_init_ex(diCache, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, diCache, "__construct", NULL, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&get, diCache, "get", NULL);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(get))) {
			RETURN_CCTOR(get);
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_Di, singleton) {

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
	zephir_update_static_property_array_multi_ce(smce_core_di_ce, SL("dis"), &_0 TSRMLS_CC, SL("z"), 1, _1);
	object_init_ex(return_value, smce_core_di_singleton_ce);
	ZEPHIR_CALL_ZVAL_FUNCTION(&_0, class, NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, key, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_Di, remove) {

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


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		_2 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		zephir_fast_strtolower(_3, key);
		zephir_array_unset(&_2, _3, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_Di, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *key_param = NULL, *_0, *_1, *_2 = NULL, *diCache, *get = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "", 1);
	} else {
		zephir_get_strval(key, key_param);
	}


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_CE_STATIC(&_2, smce_core_di_diadapter_ce, "isadapter", &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_2)) {
		ZEPHIR_INIT_VAR(diCache);
		object_init_ex(diCache, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, diCache, "__construct", NULL, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&get, diCache, "get", NULL);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(get))) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_Di, reset) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/di.zep", 159);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		zephir_array_unset(&_4, key, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Di, getKeys) {

	HashTable *_2;
	HashPosition _1;
	int i = 0;
	zval *arr, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);

	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/di.zep", 173);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_update_long(&arr, i, &key, PH_COPY | PH_SEPARATE, "smce/core/di.zep", 169);
		i++;
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Smce_Core_Di, getAll) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(Smce_Core_Di, getCount) {

	zval *_0, *_1;


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		RETURN_LONG(zephir_fast_count_int(_1 TSRMLS_CC));
	} else {
		RETURN_LONG(0);
	}

}

