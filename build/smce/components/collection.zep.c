
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
#include "kernel/object.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Smce_Components_Collection) {

	ZEPHIR_REGISTER_CLASS(Smce\\Components, Collection, smce, components_collection, smce_components_collection_method_entry, 0);

	zend_declare_property_null(smce_components_collection_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Components_Collection, __construct) {

	zval *items = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &items);

	if (!items) {
		ZEPHIR_INIT_VAR(items);
		array_init(items);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("items"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("items"), items TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Collection, each) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!(zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'callback' must be an instance of 'Closure'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "array_map", &_1, callback, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *callback, *_0, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!(zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'callback' must be an instance of 'Closure'", "", 0);
		return;
	}
	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_keys(_1, _2 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", &_4, callback, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *callback, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!(zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'callback' must be an instance of 'Closure'", "", 0);
		return;
	}
	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", &_2, _0, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, pull) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *dt = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &dt);

	if (!dt) {
		dt = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_pull", NULL, _0, key, dt);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, pop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_pop", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, diff) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *items_param = NULL, *_0, *_1 = NULL;
	zval *items = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &items_param);

	zephir_get_arrval(items, items_param);


	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_diff", &_2, _0, items);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, getAll) {


	RETURN_MEMBER(this_ptr, "items");

}

PHP_METHOD(Smce_Components_Collection, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *dt = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &dt);

	if (!dt) {
		dt = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, key, PH_NOISY | PH_READONLY, "smce/components/collection.zep", 80 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("value", NULL, dt);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, flip) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", &_2, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetexists", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, isEmpty) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(_0));

}

PHP_METHOD(Smce_Components_Collection, keys) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_keys(_0, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, lists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *key_param = NULL, *_0;
	zval *value = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &key_param);

	zephir_get_strval(value, value_param);
	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_pluck", NULL, _0, value, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, merge) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *items_param = NULL, *_0, *_1;
	zval *items = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &items_param);

	zephir_get_arrval(items, items_param);


	object_init_ex(return_value, smce_components_collection_ce);
	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(items) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, last) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	if (zephir_fast_count_int(_1 TSRMLS_CC) > 0) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		Z_SET_ISREF_P(_2);
		ZEPHIR_CALL_FUNCTION(&_0, "end", &_3, _2);
		Z_UNSET_ISREF_P(_2);
		zephir_check_call_status();
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Smce_Components_Collection, offsetExists) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_key_exists(_0, key TSRMLS_CC));

}

PHP_METHOD(Smce_Components_Collection, prepend) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_1, _0, value);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Collection, reduce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *callback, *initial = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &initial);

	if (!initial) {
		initial = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_reduce", &_1, _0, callback, initial);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, reverse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_reverse", &_2, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, search) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool strict;
	zval *value, *strict_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", &_1, value, _0, (strict ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, shift) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, sort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!(zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'callback' must be an instance of 'Closure'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "uasort", &_1, _0, callback);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, splice) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *offset_param = NULL, *length_param = NULL, *replacement = NULL, *_0, *_1, *_2, *_3 = NULL;
	int offset, length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &offset_param, &length_param, &replacement);

	offset = zephir_get_intval(offset_param);
	if (!length_param) {
		length = 0;
	} else {
		length = zephir_get_intval(length_param);
	}
	if (!replacement) {
		ZEPHIR_INIT_VAR(replacement);
		array_init(replacement);
	}


	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, offset);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, length);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&_3, "array_splice", &_4, _0, _1, _2, replacement);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, transform) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *callback, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!(zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'callback' must be an instance of 'Closure'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", &_2, callback, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("items"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, values) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", &_2, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, unique) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_unique", &_2, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, shuffle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "shuffle", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

PHP_METHOD(Smce_Components_Collection, push) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, _0, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Collection, offsetSet) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	if (Z_TYPE_P(key) == IS_NULL) {
		zephir_update_property_array_append(this_ptr, SL("items"), value TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("items"), key, value TSRMLS_CC);
	}

}

