
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

	HashTable *_7$$4, *_14$$8;
	HashPosition _6$$4, _13$$8;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *arr = NULL;
	zval *str_param = NULL, *arr_param = NULL, *at = NULL, *at2 = NULL, *key = NULL, *value = NULL, *str2 = NULL, *_1, *_3, *_4, *_5$$4, **_8$$4, *_9$$4, *_10$$4, *_11$$6, *_12$$6, **_15$$8, *_16$$9 = NULL;
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
	ZEPHIR_CALL_SELF(NULL, "is", &_0, 25);
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
			_5$$4 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			ZEPHIR_OBS_VAR(str2);
			zephir_array_fetch(&str2, _5$$4, str, PH_NOISY, "smce/components/i18n.zep", 72 TSRMLS_CC);
			zephir_is_iterable(arr, &_7$$4, &_6$$4, 0, 0, "smce/components/i18n.zep", 82);
			for (
			  ; zephir_hash_get_current_data_ex(_7$$4, (void**) &_8$$4, &_6$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7$$4, &_6$$4)
			) {
				ZEPHIR_GET_HMKEY(key, _7$$4, _6$$4);
				ZEPHIR_GET_HVALUE(value, _8$$4);
				zephir_array_append(&at, key, PH_SEPARATE, "smce/components/i18n.zep", 77);
				zephir_array_append(&at2, value, PH_SEPARATE, "smce/components/i18n.zep", 78);
			}
			_9$$4 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			zephir_array_fetch(&_10$$4, _9$$4, str, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 82 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(str2);
			zephir_fast_str_replace(&str2, at, at2, _10$$4 TSRMLS_CC);
			RETURN_CCTOR(str2);
		} else {
			_11$$6 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("langArr") TSRMLS_CC);
			zephir_array_fetch(&_12$$6, _11$$6, str, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 87 TSRMLS_CC);
			RETURN_CTOR(_12$$6);
		}
	} else {
		if (zephir_fast_count_int(arr TSRMLS_CC) > 0) {
			ZEPHIR_CPY_WRT(str2, str);
			zephir_is_iterable(arr, &_14$$8, &_13$$8, 0, 0, "smce/components/i18n.zep", 115);
			for (
			  ; zephir_hash_get_current_data_ex(_14$$8, (void**) &_15$$8, &_13$$8) == SUCCESS
			  ; zephir_hash_move_forward_ex(_14$$8, &_13$$8)
			) {
				ZEPHIR_GET_HMKEY(key, _14$$8, _13$$8);
				ZEPHIR_GET_HVALUE(value, _15$$8);
				ZEPHIR_INIT_NVAR(_16$$9);
				zephir_fast_str_replace(&_16$$9, key, value, str2 TSRMLS_CC);
				ZEPHIR_CPY_WRT(str2, _16$$9);
			}
			RETURN_CCTOR(str2);
		} else {
			RETURN_CTOR(str);
		}
	}

}

PHP_METHOD(Smce_Components_I18n, search) {

	zval *_10$$5 = NULL;
	HashTable *_7$$3, *_20$$7, *_27$$9;
	HashPosition _6$$3, _19$$7, _26$$9;
	zval *filelist = NULL, *strings = NULL, *_0, *_1 = NULL, *_29 = NULL, *rii$$3 = NULL, *path$$3 = NULL, *xexplode$$3 = NULL, *extensionsfile$$3 = NULL, *_3$$3 = NULL, *ex$$3 = NULL, *ab$$3 = NULL, *_4$$3, *_5$$3 = NULL, **_8$$3, *_9$$4 = NULL, *_12$$6 = NULL, *_14$$6 = NULL, *_16$$6 = NULL, *_18$$6 = NULL, *key$$7 = NULL, *value$$7 = NULL, *out$$7 = NULL, *file$$7 = NULL, **_21$$7, *_22$$8 = NULL, _23$$8 = zval_used_for_init, *_24$$8, *_25$$9, **_28$$9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(filelist);
	array_init(filelist);
	ZEPHIR_INIT_VAR(strings);
	array_init(strings);
	_0 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("dir_search") TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", &_2, 26, _0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(rii$$3);
		array_init(rii$$3);
		ZEPHIR_INIT_VAR(extensionsfile$$3);
		zephir_create_array(extensionsfile$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "php", 1);
		zephir_array_fast_append(extensionsfile$$3, _3$$3);
		ZEPHIR_INIT_NVAR(rii$$3);
		object_init_ex(rii$$3, spl_ce_RecursiveIteratorIterator);
		ZEPHIR_INIT_NVAR(_3$$3);
		object_init_ex(_3$$3, spl_ce_RecursiveDirectoryIterator);
		_4$$3 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("dir_search") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 27, _4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, rii$$3, "__construct", NULL, 28, _3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$3, "iterator_to_array", NULL, 29, rii$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(rii$$3, _5$$3);
		zephir_is_iterable(rii$$3, &_7$$3, &_6$$3, 0, 0, "smce/components/i18n.zep", 166);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$3, (void**) &_8$$3, &_6$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$3, &_6$$3)
		) {
			ZEPHIR_GET_HVALUE(path$$3, _8$$3);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "is_dir", &_2, 26, path$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(_9$$4)) {
				zephir_get_strval(_10$$5, path$$3);
				ZEPHIR_CPY_WRT(ab$$3, _10$$5);
				ZEPHIR_INIT_NVAR(xexplode$$3);
				zephir_fast_explode_str(xexplode$$3, SL("/"), ab$$3, LONG_MAX TSRMLS_CC);
				ZEPHIR_MAKE_REF(xexplode$$3);
				ZEPHIR_CALL_FUNCTION(&ab$$3, "end", &_11, 14, xexplode$$3);
				ZEPHIR_UNREF(xexplode$$3);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(xexplode$$3);
				zephir_fast_explode_str(xexplode$$3, SL("."), ab$$3, LONG_MAX TSRMLS_CC);
				ZEPHIR_MAKE_REF(xexplode$$3);
				ZEPHIR_CALL_FUNCTION(&ex$$3, "end", &_11, 14, xexplode$$3);
				ZEPHIR_UNREF(xexplode$$3);
				zephir_check_call_status();
				if (zephir_fast_in_array(ex$$3, extensionsfile$$3 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&_12$$6, path$$3, "getpathname", &_13, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_14$$6, "file", &_15, 30, _12$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_16$$6, path$$3, "getpathname", &_17, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_18$$6);
					ZVAL_LONG(_18$$6, zephir_fast_count_int(_14$$6 TSRMLS_CC));
					zephir_array_update_zval(&filelist, _16$$6, &_18$$6, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_fast_count_int(filelist TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(out$$7);
			array_init(out$$7);
			zephir_is_iterable(filelist, &_20$$7, &_19$$7, 0, 0, "smce/components/i18n.zep", 184);
			for (
			  ; zephir_hash_get_current_data_ex(_20$$7, (void**) &_21$$7, &_19$$7) == SUCCESS
			  ; zephir_hash_move_forward_ex(_20$$7, &_19$$7)
			) {
				ZEPHIR_GET_HMKEY(key$$7, _20$$7, _19$$7);
				ZEPHIR_GET_HVALUE(value$$7, _21$$7);
				ZEPHIR_INIT_NVAR(file$$7);
				zephir_file_get_contents(file$$7, key$$7 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_22$$8);
				ZEPHIR_SINIT_NVAR(_23$$8);
				ZVAL_STRING(&_23$$8, "#Sm::t\\(\"(.*?)\"[ ,|, |,|\\)]#", 0);
				zephir_preg_match(_22$$8, &_23$$8, file$$7, out$$7, 1, 0 , 0  TSRMLS_CC);
				zephir_array_fetch_long(&_24$$8, out$$7, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 175 TSRMLS_CC);
				if (zephir_fast_count_int(_24$$8 TSRMLS_CC) > 0) {
					zephir_array_fetch_long(&_25$$9, out$$7, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 178 TSRMLS_CC);
					zephir_is_iterable(_25$$9, &_27$$9, &_26$$9, 0, 0, "smce/components/i18n.zep", 182);
					for (
					  ; zephir_hash_get_current_data_ex(_27$$9, (void**) &_28$$9, &_26$$9) == SUCCESS
					  ; zephir_hash_move_forward_ex(_27$$9, &_26$$9)
					) {
						ZEPHIR_GET_HVALUE(value$$7, _28$$9);
						zephir_array_append(&strings, value$$7, PH_SEPARATE, "smce/components/i18n.zep", 179);
					}
				}
			}
		}
	}
	ZEPHIR_CALL_FUNCTION(&_29, "array_unique", NULL, 23, strings);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(strings, _29);
	ZEPHIR_MAKE_REF(strings);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 31, strings);
	ZEPHIR_UNREF(strings);
	zephir_check_call_status();
	RETURN_CCTOR(strings);

}

PHP_METHOD(Smce_Components_I18n, search_replace) {

	HashTable *_2;
	HashPosition _1;
	zval *strings = NULL, *value = NULL, *file = NULL, *file_x = NULL, *arr = NULL, *returnArr = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3 = NULL, *_7$$4 = NULL, *_8$$5 = NULL, *_12$$6 = NULL, *_14$$7 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/components/i18n.zep", 237);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_OBS_NVAR(_4$$3);
		zephir_read_static_property_ce(&_4$$3, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file_x);
		ZEPHIR_CONCAT_VSVS(file_x, _4$$3, "/", value, ".php");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_file", &_6, 32, file_x);
		zephir_check_call_status();
		if (zephir_is_true(_5$$3)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_7$$4);
			if (zephir_require_zval_ret(&_7$$4, file_x TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			ZEPHIR_CPY_WRT(file, _7$$4);
			if (Z_TYPE_P(file) == IS_ARRAY) {
				ZEPHIR_CPY_WRT(arr, file);
				ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "uniquearr", &_9, 33, arr);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _8$$5);
				ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "addarr", &_10, 34, arr, strings);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _8$$5);
				ZEPHIR_MAKE_REF(arr);
				ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_11, 35, arr);
				ZEPHIR_UNREF(arr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "addarr", &_10, 34, arr, strings);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _12$$6);
				ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "uniquearr", &_9, 33, arr);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(arr, _12$$6);
				ZEPHIR_MAKE_REF(arr);
				ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_11, 35, arr);
				ZEPHIR_UNREF(arr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_13, 36, file_x);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "addarr", &_10, 34, arr, strings);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(arr, _14$$7);
			ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "uniquearr", &_9, 33, arr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(arr, _14$$7);
			ZEPHIR_MAKE_REF(arr);
			ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_11, 35, arr);
			ZEPHIR_UNREF(arr);
			zephir_check_call_status();
		}
		zephir_array_update_zval(&returnArr, value, &arr, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "writefile", &_15, 37, arr, file_x);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "out", NULL, 38, returnArr);
	zephir_check_call_status();
	RETURN_CCTOR(returnArr);

}

PHP_METHOD(Smce_Components_I18n, out) {

	HashTable *_10, *_16$$5;
	HashPosition _9, _15$$5;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr, *_0, *_1, *_2 = NULL, *key = NULL, *value = NULL, *key2 = NULL, *value2 = NULL, *file_x = NULL, *file = NULL, **_11, *_3$$3, *_4$$3, _5$$3 = zval_used_for_init, *_6$$3, *_7$$3, *_12$$4 = NULL, _13$$4 = zval_used_for_init, **_17$$5, *_18$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/out");
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 26, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_OBS_VAR(_3$$3);
		zephir_read_static_property_ce(&_3$$3, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VS(_4$$3, _3$$3, "/out");
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 39, _4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_6$$3);
		zephir_read_static_property_ce(&_6$$3, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_VS(_7$$3, _6$$3, "/out");
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_LONG(&_5$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "chmod", &_8, 40, _7$$3, &_5$$3);
		zephir_check_call_status();
	}
	zephir_is_iterable(arr, &_10, &_9, 0, 0, "smce/components/i18n.zep", 278);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(key, _10, _9);
		ZEPHIR_GET_HVALUE(value, _11);
		ZEPHIR_OBS_NVAR(_12$$4);
		zephir_read_static_property_ce(&_12$$4, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(file_x);
		ZEPHIR_CONCAT_VSVS(file_x, _12$$4, "/out/", key, ".txt");
		ZEPHIR_SINIT_NVAR(_13$$4);
		ZVAL_STRING(&_13$$4, "w", 0);
		ZEPHIR_CALL_FUNCTION(&file, "fopen", &_14, 41, file_x, &_13$$4);
		zephir_check_call_status();
		if (zephir_is_true(file)) {
			zephir_is_iterable(value, &_16$$5, &_15$$5, 0, 0, "smce/components/i18n.zep", 271);
			for (
			  ; zephir_hash_get_current_data_ex(_16$$5, (void**) &_17$$5, &_15$$5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_16$$5, &_15$$5)
			) {
				ZEPHIR_GET_HMKEY(key2, _16$$5, _15$$5);
				ZEPHIR_GET_HVALUE(value2, _17$$5);
				if (ZEPHIR_IS_EMPTY(value2)) {
					ZEPHIR_INIT_LNVAR(_18$$7);
					ZEPHIR_CONCAT_VS(_18$$7, key2, "=|!|=\n");
					zephir_fwrite(NULL, file, _18$$7 TSRMLS_CC);
				}
			}
		}
		zephir_fclose(file TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_13$$4);
		ZVAL_LONG(&_13$$4, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "chmod", &_8, 40, file_x, &_13$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, in_replace) {

	zend_bool _12$$7;
	zval *_11$$6 = NULL;
	HashTable *_5$$3;
	HashPosition _4$$3;
	zval *_0, *_1, *_2 = NULL, *value$$3 = NULL, *file_x$$3 = NULL, *file_x2$$3 = NULL, *file$$3 = NULL, *readArr$$3 = NULL, *arr$$3 = NULL, *ex$$3 = NULL, *line$$3 = NULL, *_3$$3, **_6$$3, *_7$$4 = NULL, _8$$5 = zval_used_for_init, *_18$$5 = NULL, *_19$$5 = NULL, *_13$$8 = NULL, *_14$$8, *_15$$9 = NULL, *_16$$9, *_17$$9 = NULL, *_21$$11 = NULL, *_24$$12 = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL, *_25 = NULL, *_26 = NULL, *_27 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/in");
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 26, _1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(readArr$$3);
		array_init(readArr$$3);
		ZEPHIR_INIT_VAR(arr$$3);
		array_init(arr$$3);
		ZEPHIR_INIT_VAR(ex$$3);
		array_init(ex$$3);
		_3$$3 = zephir_fetch_static_property_ce(smce_components_i18n_ce, SL("lang_list") TSRMLS_CC);
		zephir_is_iterable(_3$$3, &_5$$3, &_4$$3, 0, 0, "smce/components/i18n.zep", 352);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$3, (void**) &_6$$3, &_4$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$3, &_4$$3)
		) {
			ZEPHIR_GET_HVALUE(value$$3, _6$$3);
			ZEPHIR_OBS_NVAR(_7$$4);
			zephir_read_static_property_ce(&_7$$4, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
			ZEPHIR_INIT_NVAR(file_x$$3);
			ZEPHIR_CONCAT_VSVS(file_x$$3, _7$$4, "/in/", value$$3, ".txt");
			if ((zephir_file_exists(file_x$$3 TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_NVAR(readArr$$3);
				array_init(readArr$$3);
				ZEPHIR_SINIT_NVAR(_8$$5);
				ZVAL_STRING(&_8$$5, "r", 0);
				ZEPHIR_CALL_FUNCTION(&file$$3, "fopen", &_9, 41, file_x$$3, &_8$$5);
				zephir_check_call_status();
				while (1) {
					if (!(!(zephir_feof(file$$3 TSRMLS_CC)))) {
						break;
					}
					ZEPHIR_CALL_FUNCTION(&line$$3, "fgets", &_10, 42, file$$3);
					zephir_check_call_status();
					zephir_get_strval(_11$$6, line$$3);
					ZEPHIR_CPY_WRT(line$$3, _11$$6);
					if (!(ZEPHIR_IS_EMPTY(line$$3))) {
						ZEPHIR_INIT_NVAR(ex$$3);
						zephir_fast_explode_str(ex$$3, SL("=|!|="), line$$3, LONG_MAX TSRMLS_CC);
						_12$$7 = zephir_array_isset_long(ex$$3, 0);
						if (_12$$7) {
							_12$$7 = zephir_array_isset_long(ex$$3, 1);
						}
						if (_12$$7) {
							ZEPHIR_INIT_NVAR(_13$$8);
							zephir_array_fetch_long(&_14$$8, ex$$3, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 305 TSRMLS_CC);
							zephir_fast_trim(_13$$8, _14$$8, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
							if (!(ZEPHIR_IS_EMPTY(_13$$8))) {
								ZEPHIR_INIT_NVAR(_15$$9);
								zephir_array_fetch_long(&_16$$9, ex$$3, 1, PH_NOISY | PH_READONLY, "smce/components/i18n.zep", 307 TSRMLS_CC);
								zephir_fast_trim(_15$$9, _16$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
								ZEPHIR_OBS_NVAR(_17$$9);
								zephir_array_fetch_long(&_17$$9, ex$$3, 0, PH_NOISY, "smce/components/i18n.zep", 307 TSRMLS_CC);
								zephir_array_update_zval(&readArr$$3, _17$$9, &_15$$9, PH_COPY | PH_SEPARATE);
							}
						} else {
							RETURN_MM_STRING("error", 1);
						}
					}
				}
				zephir_fclose(file$$3 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_18$$5);
				zephir_read_static_property_ce(&_18$$5, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
				ZEPHIR_INIT_NVAR(file_x2$$3);
				ZEPHIR_CONCAT_VSVS(file_x2$$3, _18$$5, "/", value$$3, ".php");
				ZEPHIR_CALL_FUNCTION(&_19$$5, "is_file", &_20, 32, file_x2$$3);
				zephir_check_call_status();
				if (zephir_is_true(_19$$5)) {
					ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_21$$11);
					if (zephir_require_zval_ret(&_21$$11, file_x2$$3 TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
					ZEPHIR_CPY_WRT(file$$3, _21$$11);
					if (Z_TYPE_P(file$$3) == IS_ARRAY) {
						ZEPHIR_CALL_FUNCTION(NULL, "print_r", &_22, 43, readArr$$3);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&arr$$3, this_ptr, "addarr2", &_23, 44, file$$3, readArr$$3);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_24$$12, this_ptr, "uniquearr", &_25, 33, arr$$3);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(arr$$3, _24$$12);
						ZEPHIR_MAKE_REF(arr$$3);
						ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_26, 35, arr$$3);
						ZEPHIR_UNREF(arr$$3);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "writefile", &_27, 37, arr$$3, file_x2$$3);
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
	zval *arr, *arr2 = NULL, *key = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr);



	ZEPHIR_INIT_VAR(arr2);
	array_init(arr2);
	zephir_is_iterable(arr, &_1, &_0, 0, 0, "smce/components/i18n.zep", 369);
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
	zval *arr, *arr2, *key = NULL, *value = NULL, **_2, *_3$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr, &arr2);

	ZEPHIR_SEPARATE_PARAM(arr);


	zephir_is_iterable(arr2, &_1, &_0, 0, 0, "smce/components/i18n.zep", 385);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (!(zephir_array_isset(arr, value))) {
			ZEPHIR_INIT_NVAR(_3$$4);
			ZVAL_STRING(_3$$4, "", 1);
			zephir_array_update_zval(&arr, value, &_3$$4, PH_COPY | PH_SEPARATE);
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


	zephir_is_iterable(arr2, &_1, &_0, 0, 0, "smce/components/i18n.zep", 401);
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

	HashTable *_9$$4;
	HashPosition _8$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr, *file_x, *file = NULL, *value = NULL, *key = NULL, *_0 = NULL, _1, _2$$4, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, **_10$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$4, *_11$$6 = NULL, _12$$6 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr, &file_x);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 32, file_x);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 36, file_x);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "w", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 41, file_x, &_1);
	zephir_check_call_status();
	if (zephir_is_true(file)) {
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_STRING(&_2$$4, "<?php", 0);
		zephir_fwrite(NULL, file, &_2$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_STRING(&_3$$4, "\n", 0);
		zephir_fwrite(NULL, file, &_3$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_STRING(&_4$$4, "\n", 0);
		zephir_fwrite(NULL, file, &_4$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "\t\treturn array(", 0);
		zephir_fwrite(NULL, file, &_5$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_STRING(&_6$$4, "\n", 0);
		zephir_fwrite(NULL, file, &_6$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_7$$4);
		ZVAL_STRING(&_7$$4, "\n", 0);
		zephir_fwrite(NULL, file, &_7$$4 TSRMLS_CC);
		zephir_is_iterable(arr, &_9$$4, &_8$$4, 0, 0, "smce/components/i18n.zep", 442);
		for (
		  ; zephir_hash_get_current_data_ex(_9$$4, (void**) &_10$$4, &_8$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9$$4, &_8$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _9$$4, _8$$4);
			ZEPHIR_GET_HVALUE(value, _10$$4);
			if (!(ZEPHIR_IS_EMPTY(key))) {
				ZEPHIR_INIT_LNVAR(_11$$6);
				ZEPHIR_CONCAT_SVSVS(_11$$6, "\t\t\t\"", key, "\"=>\"", value, "\",");
				zephir_fwrite(NULL, file, _11$$6 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_12$$6);
				ZVAL_STRING(&_12$$6, "\n", 0);
				zephir_fwrite(NULL, file, &_12$$6 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_VAR(_13$$4);
		ZVAL_STRING(&_13$$4, "\t\t);", 0);
		zephir_fwrite(NULL, file, &_13$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_14$$4);
		ZVAL_STRING(&_14$$4, "\n", 0);
		zephir_fwrite(NULL, file, &_14$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_15$$4);
		ZVAL_STRING(&_15$$4, "\n", 0);
		zephir_fwrite(NULL, file, &_15$$4 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_16$$4);
		ZVAL_STRING(&_16$$4, "?>", 0);
		zephir_fwrite(NULL, file, &_16$$4 TSRMLS_CC);
		zephir_fclose(file TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_17$$4);
		ZVAL_LONG(&_17$$4, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "chmod", NULL, 40, file_x, &_17$$4);
		zephir_check_call_status();
	} else {
		php_printf("%s", "Dosya açılamadı!");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_I18n, is) {

	zval *_0, *_5, *_1$$3, *_2$$3, *_3$$3, *_6$$4, *_7$$4, *_8$$4;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, smce_components_i18n_ce, SL("lang") TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 403);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "Set I18n 'setLang()'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", &_4, 45, _2$$3, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "smce/components/i18n.zep", 462 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(_5);
	zephir_read_static_property_ce(&_5, smce_components_i18n_ce, SL("dir") TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_5)) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_7$$4);
		ZVAL_LONG(_7$$4, 403);
		ZEPHIR_INIT_VAR(_8$$4);
		ZVAL_STRING(_8$$4, "Set I18n 'setDir()'", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", &_4, 45, _7$$4, _8$$4);
		zephir_check_temp_parameter(_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "smce/components/i18n.zep", 469 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

