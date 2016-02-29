
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
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/hash.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Di) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, Di, smce, core_di, smce_core_di_method_entry, 0);

	/**
	 * @var dis
	 */
	zend_declare_property_null(smce_core_di_ce, SL("dis"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 *@param adapter
 *@return void
 */
PHP_METHOD(Smce_Core_Di, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *adapter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &adapter);

	if (!adapter) {
		adapter = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(adapter) != IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(NULL, smce_core_di_diadapter_ce, "setadapter", &_0, 54, adapter);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *@param string
 *@param Closure
 *
 *@return void|DiCache
 */
PHP_METHOD(Smce_Core_Di, bind) {

	zephir_fcall_cache_entry *_2 = NULL;
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
	zephir_update_static_property_array_multi_ce(smce_core_di_ce, SL("dis"), &_0 TSRMLS_CC, SL("z"), 1, _1);
	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_di_diadapter_ce, "isadapter", &_2, 55);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		object_init_ex(return_value, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 56, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *@param string
 *@return value|false
 */
PHP_METHOD(Smce_Core_Di, resolve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key_param = NULL, *_0 = NULL, *_2, *_3, *diCache$$3 = NULL, *get$$3 = NULL, *_4$$5, *_5$$5, *_6$$5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_di_diadapter_ce, "isadapter", &_1, 55);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		ZEPHIR_INIT_VAR(diCache$$3);
		object_init_ex(diCache$$3, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, diCache$$3, "__construct", NULL, 56, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&get$$3, diCache$$3, "get", NULL, 57);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(get$$3))) {
			RETURN_CCTOR(get$$3);
		}
	}
	_2 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_strtolower(_3, key);
	if (zephir_array_isset(_2, _3)) {
		_4$$5 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$5);
		zephir_fast_strtolower(_6$$5, key);
		zephir_array_fetch(&_5$$5, _4$$5, _6$$5, PH_NOISY | PH_READONLY, "smce/core/di.zep", 89 TSRMLS_CC);
		RETURN_CTOR(_5$$5);
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *@param Closure
 *
 *@return new Di\Singleton
 */
PHP_METHOD(Smce_Core_Di, singleton) {

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
	zephir_update_static_property_array_multi_ce(smce_core_di_ce, SL("dis"), &_0 TSRMLS_CC, SL("z"), 1, _1);
	object_init_ex(return_value, smce_core_di_disingleton_ce);
	ZEPHIR_CALL_ZVAL_FUNCTION(&_0, class, NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 58, key, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *@param string
 *
 *@return bool
 */
PHP_METHOD(Smce_Core_Di, remove) {

	zend_bool bl;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *key_param = NULL, *_0, *_1, *_4 = NULL, *_2$$3, *_3$$3, *diCache$$4 = NULL, *_6$$4 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "", 1);
	} else {
		zephir_get_strval(key, key_param);
	}


	bl = 0;
	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, key);
	if (zephir_array_isset(_0, _1)) {
		_2$$3 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_fast_strtolower(_3$$3, key);
		zephir_array_unset(&_2$$3, _3$$3, PH_SEPARATE);
		bl = 1;
	}
	ZEPHIR_CALL_CE_STATIC(&_4, smce_core_di_diadapter_ce, "isadapter", &_5, 55);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_4)) {
		ZEPHIR_INIT_VAR(diCache$$4);
		object_init_ex(diCache$$4, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, diCache$$4, "__construct", NULL, 56, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, diCache$$4, "remove", NULL, 59);
		zephir_check_call_status();
		if (zephir_is_true(_6$$4)) {
			bl = 1;
		}
	}
	if (bl == 1) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *@param string
 *
 *@return bool
 */
PHP_METHOD(Smce_Core_Di, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key_param = NULL, *_0 = NULL, *_2, *_3, *diCache$$3 = NULL, *get$$3 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "", 1);
	} else {
		zephir_get_strval(key, key_param);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, smce_core_di_diadapter_ce, "isadapter", &_1, 55);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(_0)) {
		ZEPHIR_INIT_VAR(diCache$$3);
		object_init_ex(diCache$$3, smce_core_di_dicache_ce);
		ZEPHIR_CALL_METHOD(NULL, diCache$$3, "__construct", NULL, 56, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&get$$3, diCache$$3, "get", NULL, 57);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(get$$3))) {
			RETURN_MM_BOOL(1);
		}
	}
	_2 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_strtolower(_3, key);
	if (zephir_array_isset(_2, _3)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 *
 *@return void
 */
PHP_METHOD(Smce_Core_Di, reset) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *_0, **_3, *_4$$3, *_5$$3 = NULL, *diCache$$4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/di.zep", 225);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4$$3 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		zephir_array_unset(&_4$$3, key, PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&_5$$3, smce_core_di_diadapter_ce, "isadapter", &_6, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE(_5$$3)) {
			ZEPHIR_INIT_NVAR(diCache$$4);
			object_init_ex(diCache$$4, smce_core_di_dicache_ce);
			ZEPHIR_CALL_METHOD(NULL, diCache$$4, "__construct", &_7, 56, key);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, diCache$$4, "remove", &_8, 59);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 *@return array
 */
PHP_METHOD(Smce_Core_Di, getKeys) {

	HashTable *_2;
	HashPosition _1;
	int i;
	zval *arr = NULL, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	i = 0;
	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/di.zep", 243);
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

/**
 *
 *@return array
 */
PHP_METHOD(Smce_Core_Di, getAll) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 *
 *@return int
 */
PHP_METHOD(Smce_Core_Di, getCount) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_static_property_ce(smce_core_di_ce, SL("dis") TSRMLS_CC);
		RETURN_LONG(zephir_fast_count_int(_1$$3 TSRMLS_CC));
	} else {
		RETURN_LONG(0);
	}

}

