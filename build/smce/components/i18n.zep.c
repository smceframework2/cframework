
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
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Components_I18n) {

	ZEPHIR_REGISTER_CLASS(Smce\\Components, I18n, smce, components_i18n, smce_components_i18n_method_entry, 0);

	zend_declare_property_null(smce_components_i18n_ce, SL("dir"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_components_i18n_ce, SL("lang"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_components_i18n_ce, SL("langArr"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Components_I18n, setDir) {

	zval *dir_param = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	zephir_update_static_property_ce(smce_components_i18n_ce, SL("dir"), &dir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, setLang) {

	zval *lang_param = NULL, *_0, *_1, *_2, *_3 = NULL;
	zval *lang = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &lang_param);

	zephir_get_strval(lang, lang_param);


	zephir_update_static_property_ce(smce_components_i18n_ce, SL("lang"), &lang TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, smce_components_i18n_ce, SL("lang") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSVS(_2, _0, "/", _1, ".php");
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3);
	if (zephir_require_zval_ret(&_3, _2 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(smce_components_i18n_ce, SL("langArr"), &_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, t) {

	HashTable *_6, *_11;
	HashPosition _5, _10;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *arr = NULL;
	zval *str_param = NULL, *arr_param = NULL, *at, *at2, *key = NULL, *value = NULL, *str2 = NULL, *_1, *_3, *_4, **_7, *_8, *_9, **_12;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &arr_param);

	zephir_get_strval(str, str_param);
	if (!arr_param) {
		ZEPHIR_INIT_VAR(arr);
		array_init(arr);
	} else {
		zephir_get_arrval(arr, arr_param);
	}
	ZEPHIR_INIT_VAR(at);
	array_init(at);
	ZEPHIR_INIT_VAR(at2);
	array_init(at2);


	ZEPHIR_CALL_SELF(NULL, "is", &_0, 23);
	zephir_check_call_status();
	_1 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
	_2 = zephir_array_isset(_1, str);
	if (_2) {
		_3 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch(&_4, _3, str, PH_NOISY, "smce/components/i18n.zep", 48 TSRMLS_CC);
		_2 = !(ZEPHIR_IS_EMPTY(_4));
	}
	if (_2) {
		if (zephir_fast_count_int(arr TSRMLS_CC) > 0) {
			zephir_is_iterable(arr, &_6, &_5, 0, 0, "smce/components/i18n.zep", 60);
			for (
			  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_6, &_5)
			) {
				ZEPHIR_GET_HMKEY(key, _6, _5);
				ZEPHIR_GET_HVALUE(value, _7);
				zephir_array_append(&at, key, PH_SEPARATE, "smce/components/i18n.zep", 55);
				zephir_array_append(&at2, value, PH_SEPARATE, "smce/components/i18n.zep", 56);
			}
			ZEPHIR_INIT_VAR(str2);
			_8 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			zephir_array_fetch(&_9, _8, str, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 60 TSRMLS_CC);
			zephir_fast_str_replace(&str2, at, at2, _9 TSRMLS_CC);
			RETURN_CCTOR(str2);
		} else {
			_8 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			zephir_array_fetch(&_9, _8, str, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 65 TSRMLS_CC);
			RETURN_CTOR(_9);
		}
	} else {
		if (zephir_fast_count_int(arr TSRMLS_CC) > 0) {
			zephir_is_iterable(arr, &_11, &_10, 0, 0, "smce/components/i18n.zep", 81);
			for (
			  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
			  ; zephir_hash_move_forward_ex(_11, &_10)
			) {
				ZEPHIR_GET_HMKEY(key, _11, _10);
				ZEPHIR_GET_HVALUE(value, _12);
				zephir_array_append(&at, key, PH_SEPARATE, "smce/components/i18n.zep", 76);
				zephir_array_append(&at2, value, PH_SEPARATE, "smce/components/i18n.zep", 77);
			}
			ZEPHIR_INIT_NVAR(str2);
			zephir_fast_str_replace(&str2, at, at2, str TSRMLS_CC);
			RETURN_CCTOR(str2);
		} else {
			RETURN_CTOR(str);
		}
	}

}

PHP_METHOD(Smce_Components_I18n, is) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("lang") TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 403);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "Set I18n 'setLang()'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, 24, _2, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "smce/components/i18n.zep", 101 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(_5);
	zephir_read_static_property_ce(&_5, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_5)) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, smce_http_httpexception_ce);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 403);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Set I18n 'setDir()'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, 24, _2, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "smce/components/i18n.zep", 108 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

