
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Smce_Components_Collection) {

	ZEPHIR_REGISTER_CLASS(Smce\\Components, Collection, smce, components_collection, smce_components_collection_method_entry, 0);

	zend_declare_property_null(smce_components_collection_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	smce_components_collection_ce->create_object = zephir_init_properties_Smce_Components_Collection;
	return SUCCESS;

}

PHP_METHOD(Smce_Components_Collection, __construct) {

	zval *items = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &items);

	if (!items) {
		ZEPHIR_INIT_VAR(items);
		array_init(items);
	}


	zephir_update_property_this(this_ptr, SL("items"), items TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Collection, each) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "array_map", NULL, 8, callback, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_keys(_1, _2 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 8, callback, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 10, _0, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, pop) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_pop", NULL, 11, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, diff) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *items_param = NULL, *_0, *_1 = NULL;
	zval *items = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &items_param);

	zephir_get_arrval(items, items_param);


	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_diff", NULL, 12, _0, items);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, getAll) {

	

	RETURN_MEMBER(this_ptr, "items");

}

PHP_METHOD(Smce_Components_Collection, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *dt = NULL, *_0 = NULL, *_1$$3, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &dt);

	if (!dt) {
		dt = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "smce/components/collection.zep", 71 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Collection, flip) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 13, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetexists", NULL, 0, key);
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

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_keys(_0, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _0);
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, last) {

	zval *_0 = NULL, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	if (zephir_fast_count_int(_1 TSRMLS_CC) > 0) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		ZEPHIR_MAKE_REF(_2);
		ZEPHIR_CALL_FUNCTION(&_0, "end", NULL, 14, _2);
		ZEPHIR_UNREF(_2);
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
	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 15, _0, value);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Collection, reduce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *initial = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &initial);

	if (!initial) {
		initial = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_reduce", NULL, 16, _0, callback, initial);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, reverse) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_reverse", NULL, 17, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, search) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict;
	zval *value, *strict_param = NULL, *_0, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (strict ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 18, value, _0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, shift) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", NULL, 19, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, sort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "uasort", NULL, 20, _0, callback);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, splice) {

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
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(&_3, "array_splice", NULL, 21, _0, _1, _2, replacement);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, transform) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", NULL, 8, callback, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("items"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Collection, values) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 22, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, unique) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, smce_components_collection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_unique", NULL, 23, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 9, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Collection, shuffle) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "shuffle", NULL, 24, _0);
	ZEPHIR_UNREF(_0);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, _0, value);
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

static zend_object_value zephir_init_properties_Smce_Components_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("items"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

