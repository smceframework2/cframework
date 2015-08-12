
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
#include "ext/spl/spl_iterators.h"
#include "ext/spl/spl_directory.h"
#include "kernel/file.h"
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

	zend_declare_property_null(smce_components_i18n_ce, SL("dir_search"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_components_i18n_ce, SL("lang_list"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

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

PHP_METHOD(Smce_Components_I18n, setDirSearch) {

	zval *dir_param = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	zephir_update_static_property_ce(smce_components_i18n_ce, SL("dir_search"), &dir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, setLangList) {

	zval *list_param = NULL;
	zval *list = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &list_param);

	zephir_get_arrval(list, list_param);


	zephir_update_static_property_ce(smce_components_i18n_ce, SL("lang_list"), &list TSRMLS_CC);
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
		zephir_array_fetch(&_4, _3, str, PH_NOISY, "smce/components/i18n.zep", 66 TSRMLS_CC);
		_2 = !(ZEPHIR_IS_EMPTY(_4));
	}
	if (_2) {
		if (zephir_fast_count_int(arr TSRMLS_CC) > 0) {
			zephir_is_iterable(arr, &_6, &_5, 0, 0, "smce/components/i18n.zep", 78);
			for (
			  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_6, &_5)
			) {
				ZEPHIR_GET_HMKEY(key, _6, _5);
				ZEPHIR_GET_HVALUE(value, _7);
				zephir_array_append(&at, key, PH_SEPARATE, "smce/components/i18n.zep", 73);
				zephir_array_append(&at2, value, PH_SEPARATE, "smce/components/i18n.zep", 74);
			}
			ZEPHIR_INIT_VAR(str2);
			_8 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			zephir_array_fetch(&_9, _8, str, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 78 TSRMLS_CC);
			zephir_fast_str_replace(&str2, at, at2, _9 TSRMLS_CC);
			RETURN_CCTOR(str2);
		} else {
			_8 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			zephir_array_fetch(&_9, _8, str, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 83 TSRMLS_CC);
			RETURN_CTOR(_9);
		}
	} else {
		if (zephir_fast_count_int(arr TSRMLS_CC) > 0) {
			zephir_is_iterable(arr, &_11, &_10, 0, 0, "smce/components/i18n.zep", 99);
			for (
			  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
			  ; zephir_hash_move_forward_ex(_11, &_10)
			) {
				ZEPHIR_GET_HMKEY(key, _11, _10);
				ZEPHIR_GET_HVALUE(value, _12);
				zephir_array_append(&at, key, PH_SEPARATE, "smce/components/i18n.zep", 94);
				zephir_array_append(&at2, value, PH_SEPARATE, "smce/components/i18n.zep", 95);
			}
			ZEPHIR_INIT_NVAR(str2);
			zephir_fast_str_replace(&str2, at, at2, str TSRMLS_CC);
			RETURN_CCTOR(str2);
		} else {
			RETURN_CTOR(str);
		}
	}

}

PHP_METHOD(Smce_Components_I18n, search) {

	zval *_9 = NULL;
	HashTable *_7, *_17, *_23;
	HashPosition _6, _16, _22;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_10 = NULL, *_13 = NULL;
	zval *filelist, *strings = NULL, *_0, *_1 = NULL, *rii = NULL, *path = NULL, *xexplode = NULL, *extensionsfile = NULL, *_3 = NULL, *ex = NULL, *ab = NULL, *_4, *_5 = NULL, **_8, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *key = NULL, *value = NULL, *out = NULL, *file = NULL, **_18, _19 = zval_used_for_init, *_20, *_21, **_24;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(filelist);
	array_init(filelist);
	ZEPHIR_INIT_VAR(strings);
	array_init(strings);
	ZEPHIR_INIT_VAR(rii);
	array_init(rii);
	ZEPHIR_INIT_VAR(extensionsfile);
	array_init(extensionsfile);

	_0 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("dir_search") TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", &_2, 24, _0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(extensionsfile);
		zephir_create_array(extensionsfile, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "php", 1);
		zephir_array_fast_append(extensionsfile, _3);
		ZEPHIR_INIT_NVAR(rii);
		object_init_ex(rii, spl_ce_RecursiveIteratorIterator);
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, spl_ce_RecursiveDirectoryIterator);
		_4 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("dir_search") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 25, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, rii, "__construct", NULL, 26, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5, "iterator_to_array", NULL, 27, rii);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(rii, _5);
		zephir_is_iterable(rii, &_7, &_6, 0, 0, "smce/components/i18n.zep", 151);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HVALUE(path, _8);
			ZEPHIR_CALL_FUNCTION(&_5, "is_dir", &_2, 24, path);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_5)) {
				zephir_get_strval(_9, path);
				ZEPHIR_CPY_WRT(ab, _9);
				ZEPHIR_INIT_NVAR(xexplode);
				zephir_fast_explode_str(xexplode, SL("/"), ab, LONG_MAX TSRMLS_CC);
				Z_SET_ISREF_P(xexplode);
				ZEPHIR_CALL_FUNCTION(&ab, "end", &_10, 12, xexplode);
				Z_UNSET_ISREF_P(xexplode);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(xexplode);
				zephir_fast_explode_str(xexplode, SL("."), ab, LONG_MAX TSRMLS_CC);
				Z_SET_ISREF_P(xexplode);
				ZEPHIR_CALL_FUNCTION(&ex, "end", &_10, 12, xexplode);
				Z_UNSET_ISREF_P(xexplode);
				zephir_check_call_status();
				if (zephir_fast_in_array(ex, extensionsfile TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_11, path, "getpathname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_12, "file", &_13, 28, _11);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14, path, "getpathname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, zephir_fast_count_int(_12 TSRMLS_CC));
					zephir_array_update_zval(&filelist, _14, &_15, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_fast_count_int(filelist TSRMLS_CC) > 0) {
			zephir_is_iterable(filelist, &_17, &_16, 0, 0, "smce/components/i18n.zep", 169);
			for (
			  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
			  ; zephir_hash_move_forward_ex(_17, &_16)
			) {
				ZEPHIR_GET_HMKEY(key, _17, _16);
				ZEPHIR_GET_HVALUE(value, _18);
				ZEPHIR_INIT_NVAR(file);
				zephir_file_get_contents(file, key TSRMLS_CC);
				ZEPHIR_INIT_NVAR(out);
				ZEPHIR_INIT_NVAR(_15);
				ZEPHIR_SINIT_NVAR(_19);
				ZVAL_STRING(&_19, "#Sm::t\\(\"(.*?)\"[ ,|, |,|\\)]#", 0);
				zephir_preg_match(_15, &_19, file, out, 1, 0 , 0  TSRMLS_CC);
				zephir_array_fetch_long(&_20, out, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 160 TSRMLS_CC);
				if (zephir_fast_count_int(_20 TSRMLS_CC) > 0) {
					zephir_array_fetch_long(&_21, out, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 163 TSRMLS_CC);
					zephir_is_iterable(_21, &_23, &_22, 0, 0, "smce/components/i18n.zep", 167);
					for (
					  ; zephir_hash_get_current_data_ex(_23, (void**) &_24, &_22) == SUCCESS
					  ; zephir_hash_move_forward_ex(_23, &_22)
					) {
						ZEPHIR_GET_HVALUE(value, _24);
						zephir_array_append(&strings, value, PH_SEPARATE, "smce/components/i18n.zep", 164);
					}
				}
			}
		}
	}
	ZEPHIR_CALL_FUNCTION(&_5, "array_unique", NULL, 21, strings);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(strings, _5);
	Z_SET_ISREF_P(strings);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 29, strings);
	Z_UNSET_ISREF_P(strings);
	zephir_check_call_status();
	RETURN_CCTOR(strings);

}

PHP_METHOD(Smce_Components_I18n, search_replace) {

	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *strings = NULL, *value = NULL, *file = NULL, *file_x = NULL, *arr = NULL, *returnArr, *_0, **_3, *_4 = NULL, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(strings);
	array_init(strings);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_INIT_VAR(returnArr);
	array_init(returnArr);

	ZEPHIR_CALL_METHOD(&strings, this_ptr, "search", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("lang_list") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/components/i18n.zep", 222);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_static_property_ce(&_4, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file_x);
		ZEPHIR_CONCAT_VSVS(file_x, _4, "/", value, ".php");
		ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_6, 30, file_x);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_7);
			if (zephir_require_zval_ret(&_7, file_x TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(file, _7);
			if (Z_TYPE_P(file) == IS_ARRAY) {
				ZEPHIR_CPY_WRT(arr, file);
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "uniquearr", &_8, 31, arr);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _7);
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "addarr", &_9, 32, arr, strings);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _7);
				Z_SET_ISREF_P(arr);
				ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_10, 33, arr);
				Z_UNSET_ISREF_P(arr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "addarr", &_9, 32, arr, strings);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _7);
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "uniquearr", &_8, 31, arr);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _7);
				Z_SET_ISREF_P(arr);
				ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_10, 33, arr);
				Z_UNSET_ISREF_P(arr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_11, 34, file_x);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "addarr", &_9, 32, arr, strings);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(arr, _7);
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "uniquearr", &_8, 31, arr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(arr, _7);
			Z_SET_ISREF_P(arr);
			ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_10, 33, arr);
			Z_UNSET_ISREF_P(arr);
			zephir_check_call_status();
		}
		zephir_array_update_zval(&returnArr, value, &arr, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "writefile", &_12, 35, arr, file_x);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "out", NULL, 36, returnArr);
	zephir_check_call_status();
	RETURN_CCTOR(returnArr);

}

PHP_METHOD(Smce_Components_I18n, out) {

	HashTable *_10, *_14;
	HashPosition _9, _13;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, _5 = zval_used_for_init, *_6, *_7, *key = NULL, *value = NULL, *key2 = NULL, *value2 = NULL, *file_x = NULL, *file = NULL, **_11, **_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/out");
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 24, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_static_property_ce(&_3, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VS(_4, _3, "/out");
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_LONG(&_5, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 37, _4, &_5);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_6);
		zephir_read_static_property_ce(&_6, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_VS(_7, _6, "/out");
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "chmod", &_8, 38, _7, &_5);
		zephir_check_call_status();
	}
	zephir_is_iterable(arr, &_10, &_9, 0, 0, "smce/components/i18n.zep", 263);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(key, _10, _9);
		ZEPHIR_GET_HVALUE(value, _11);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_static_property_ce(&_3, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file_x);
		ZEPHIR_CONCAT_VSVS(file_x, _3, "/out/", key, ".txt");
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "w", 0);
		ZEPHIR_CALL_FUNCTION(&file, "fopen", &_12, 39, file_x, &_5);
		zephir_check_call_status();
		if (zephir_is_true(file)) {
			zephir_is_iterable(value, &_14, &_13, 0, 0, "smce/components/i18n.zep", 256);
			for (
			  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
			  ; zephir_hash_move_forward_ex(_14, &_13)
			) {
				ZEPHIR_GET_HMKEY(key2, _14, _13);
				ZEPHIR_GET_HVALUE(value2, _15);
				if (ZEPHIR_IS_EMPTY(value2)) {
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_VS(_4, key2, "=|!|=\n");
					zephir_fwrite(NULL, file, _4 TSRMLS_CC);
				}
			}
		}
		zephir_fclose(file TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "chmod", &_8, 38, file_x, &_5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, in_replace) {

	zend_bool _12;
	zval *_11 = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *value = NULL, *file_x = NULL, *file_x2 = NULL, *file = NULL, *readArr = NULL, *arr = NULL, *ex = NULL, *line = NULL, *_3, **_6, *_7 = NULL, _8 = zval_used_for_init, *_13 = NULL, *_14, *_15 = NULL, *_16, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_21 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(readArr);
	array_init(readArr);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_INIT_VAR(ex);
	array_init(ex);

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/in");
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 24, _1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		_3 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("lang_list") TSRMLS_CC);
		zephir_is_iterable(_3, &_5, &_4, 0, 0, "smce/components/i18n.zep", 337);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(value, _6);
			ZEPHIR_OBS_NVAR(_7);
			zephir_read_static_property_ce(&_7, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
			ZEPHIR_INIT_NVAR(file_x);
			ZEPHIR_CONCAT_VSVS(file_x, _7, "/in/", value, ".txt");
			if ((zephir_file_exists(file_x TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_NVAR(readArr);
				array_init(readArr);
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_STRING(&_8, "r", 0);
				ZEPHIR_CALL_FUNCTION(&file, "fopen", &_9, 39, file_x, &_8);
				zephir_check_call_status();
				while (1) {
					if (!(!(zephir_feof(file TSRMLS_CC)))) {
						break;
					}
					ZEPHIR_CALL_FUNCTION(&line, "fgets", &_10, 40, file);
					zephir_check_call_status();
					zephir_get_strval(_11, line);
					ZEPHIR_CPY_WRT(line, _11);
					if (!(ZEPHIR_IS_EMPTY(line))) {
						ZEPHIR_INIT_NVAR(ex);
						zephir_fast_explode_str(ex, SL("=|!|="), line, LONG_MAX TSRMLS_CC);
						_12 = zephir_array_isset_long(ex, 0);
						if (_12) {
							_12 = zephir_array_isset_long(ex, 1);
						}
						if (_12) {
							ZEPHIR_INIT_NVAR(_13);
							zephir_array_fetch_long(&_14, ex, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 290 TSRMLS_CC);
							zephir_fast_trim(_13, _14, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
							if (!(ZEPHIR_IS_EMPTY(_13))) {
								ZEPHIR_INIT_NVAR(_15);
								zephir_array_fetch_long(&_16, ex, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 292 TSRMLS_CC);
								zephir_fast_trim(_15, _16, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
								ZEPHIR_OBS_NVAR(_17);
								zephir_array_fetch_long(&_17, ex, 0, PH_NOISY, "smce/components/i18n.zep", 292 TSRMLS_CC);
								zephir_array_update_zval(&readArr, _17, &_15, PH_COPY | PH_SEPARATE);
							}
						} else {
							RETURN_MM_STRING("error", 1);
						}
					}
				}
				zephir_fclose(file TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_18);
				zephir_read_static_property_ce(&_18, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
				ZEPHIR_INIT_NVAR(file_x2);
				ZEPHIR_CONCAT_VSVS(file_x2, _18, "/", value, ".php");
				ZEPHIR_CALL_FUNCTION(&_19, "is_file", &_20, 30, file_x2);
				zephir_check_call_status();
				if (zephir_is_true(_19)) {
					ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_21);
					if (zephir_require_zval_ret(&_21, file_x2 TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
					ZEPHIR_CPY_WRT(file, _21);
					if (Z_TYPE_P(file) == IS_ARRAY) {
						ZEPHIR_CALL_FUNCTION(NULL, "print_r", &_22, 41, readArr);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&arr, this_ptr, "addarr2", &_23, 42, file, readArr);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_21, this_ptr, "uniquearr", &_24, 31, arr);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(arr, _21);
						Z_SET_ISREF_P(arr);
						ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_25, 33, arr);
						Z_UNSET_ISREF_P(arr);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "writefile", &_26, 35, arr, file_x2);
						zephir_check_call_status();
					}
				}
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, uniqueArr) {

	HashTable *_1;
	HashPosition _0;
	zval *arr, *arr2, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr);

	ZEPHIR_INIT_VAR(arr2);
	array_init(arr2);


	zephir_is_iterable(arr, &_1, &_0, 0, 0, "smce/components/i18n.zep", 354);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (!(zephir_array_isset(arr2, key))) {
			zephir_array_update_zval(&arr2, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arr2);

}

PHP_METHOD(Smce_Components_I18n, addArr) {

	HashTable *_1;
	HashPosition _0;
	zval *arr, *arr2, *key = NULL, *value = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr, &arr2);

	ZEPHIR_SEPARATE_PARAM(arr);


	zephir_is_iterable(arr2, &_1, &_0, 0, 0, "smce/components/i18n.zep", 370);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (!(zephir_array_isset(arr, value))) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "", 1);
			zephir_array_update_zval(&arr, value, &_3, PH_COPY | PH_SEPARATE);
		}
	}
	RETVAL_ZVAL(arr, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Smce_Components_I18n, addArr2) {

	HashTable *_1;
	HashPosition _0;
	zval *arr, *arr2, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr, &arr2);

	ZEPHIR_SEPARATE_PARAM(arr);


	zephir_is_iterable(arr2, &_1, &_0, 0, 0, "smce/components/i18n.zep", 386);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_array_isset(arr, key)) {
			zephir_array_update_zval(&arr, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETVAL_ZVAL(arr, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Smce_Components_I18n, writeFile) {

	HashTable *_8;
	HashPosition _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr, *file_x, *file = NULL, *value = NULL, *key = NULL, *_0 = NULL, _1 = zval_used_for_init, _2, _3, _4, _5, _6, **_9, *_10 = NULL, _11 = zval_used_for_init, _12, _13, _14, _15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr, &file_x);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 30, file_x);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 34, file_x);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 39, file_x, &_1);
	zephir_check_call_status();
	if (zephir_is_true(file)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "<?php", 0);
		zephir_fwrite(NULL, file, &_1 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "\n", 0);
		zephir_fwrite(NULL, file, &_2 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "\n", 0);
		zephir_fwrite(NULL, file, &_3 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "\t\treturn array(", 0);
		zephir_fwrite(NULL, file, &_4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "\n", 0);
		zephir_fwrite(NULL, file, &_5 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, "\n", 0);
		zephir_fwrite(NULL, file, &_6 TSRMLS_CC);
		zephir_is_iterable(arr, &_8, &_7, 0, 0, "smce/components/i18n.zep", 427);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HMKEY(key, _8, _7);
			ZEPHIR_GET_HVALUE(value, _9);
			if (!(ZEPHIR_IS_EMPTY(key))) {
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSVS(_10, "\t\t\t\"", key, "\"=>\"", value, "\",");
				zephir_fwrite(NULL, file, _10 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_STRING(&_11, "\n", 0);
				zephir_fwrite(NULL, file, &_11 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_STRING(&_11, "\t\t);", 0);
		zephir_fwrite(NULL, file, &_11 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_12);
		ZVAL_STRING(&_12, "\n", 0);
		zephir_fwrite(NULL, file, &_12 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_STRING(&_13, "\n", 0);
		zephir_fwrite(NULL, file, &_13 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_STRING(&_14, "?>", 0);
		zephir_fwrite(NULL, file, &_14 TSRMLS_CC);
		zephir_fclose(file TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_15);
		ZVAL_LONG(&_15, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "chmod", NULL, 38, file_x, &_15);
		zephir_check_call_status();
	} else {
		php_printf("%s", "Dosya açılamadı!");
	}
	ZEPHIR_MM_RESTORE();

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
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, 43, _2, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "smce/components/i18n.zep", 447 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, 43, _2, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "smce/components/i18n.zep", 454 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

