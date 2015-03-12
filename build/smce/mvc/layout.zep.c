
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Smce_Mvc_Layout) {

	ZEPHIR_REGISTER_CLASS(Smce\\Mvc, Layout, smce, mvc_layout, smce_mvc_layout_method_entry, 0);

	/**
	 * @var ContentDirectory
	 */
	zend_declare_property_null(smce_mvc_layout_ce, SL("contentDirectory"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(smce_mvc_layout_ce, SL("content"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 */
PHP_METHOD(Smce_Mvc_Layout, setContentDirectory) {

	zval *contentDirectory_param = NULL;
	zval *contentDirectory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &contentDirectory_param);

	if (!contentDirectory_param) {
		ZEPHIR_INIT_VAR(contentDirectory);
		ZVAL_STRING(contentDirectory, "", 1);
	} else {
		zephir_get_strval(contentDirectory, contentDirectory_param);
	}


	zephir_update_property_this(this_ptr, SL("contentDirectory"), contentDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return string
 */
PHP_METHOD(Smce_Mvc_Layout, getContentDirectory) {


	RETURN_MEMBER(this_ptr, "contentDirectory");

}

/**
 * @param string
 * @param array
 *
 * @return void
 */
PHP_METHOD(Smce_Mvc_Layout, setContent) {

	zval *_0;
	zval *view_param = NULL, *arr = NULL;
	zval *view = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &view_param, &arr);

	zephir_get_strval(view, view_param);
	if (!arr) {
		ZEPHIR_INIT_VAR(arr);
		array_init(arr);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_update_string(&_0, SL("view"), &view, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("array"), &arr, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("content"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * @return HttpException|include
 */
PHP_METHOD(Smce_Mvc_Layout, run) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL;
	zval *contentFile, *_0, *_1, *_3, *_4, *_5, *_6 = NULL, *_8, *_9, *_10;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("array"), PH_NOISY | PH_READONLY, "smce/mvc/layout.zep", 70 TSRMLS_CC);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_2, _1);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("contentDirectory"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("view"), PH_NOISY | PH_READONLY, "smce/mvc/layout.zep", 72 TSRMLS_CC);
	ZEPHIR_INIT_VAR(contentFile);
	ZEPHIR_CONCAT_VSVS(contentFile, _3, "/", _5, ".php");
	ZEPHIR_CALL_FUNCTION(&_6, "is_file", &_7, contentFile);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		if (zephir_require_zval(contentFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	} else {
		ZEPHIR_INIT_VAR(_8);
		object_init_ex(_8, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SV(_9, "Content Not Found ", contentFile);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_LONG(_10, 404);
		ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL, _10, _9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8, "smce/mvc/layout.zep", 83 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Mvc_Layout, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("content"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

