
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


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Mvc_Layout) {

	ZEPHIR_REGISTER_CLASS(Smce\\Mvc, Layout, smce, mvc_layout, smce_mvc_layout_method_entry, 0);

	/**
	 * @var ContentDirectory
	 */
	zend_declare_property_null(smce_mvc_layout_ce, SL("contentDirectory"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(smce_mvc_layout_ce, SL("content"), ZEND_ACC_PRIVATE TSRMLS_CC);

	smce_mvc_layout_ce->create_object = zephir_init_properties_Smce_Mvc_Layout;
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
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
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

	zval *contentFile = NULL, *_0, *_1, *_2, *_3, *_4, *_5 = NULL, *_6$$4, *_7$$4, *_8$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("array"), PH_NOISY | PH_READONLY, "smce/mvc/layout.zep", 70 TSRMLS_CC);
	ZEPHIR_MAKE_REF(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 105, _1);
	ZEPHIR_UNREF(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("contentDirectory"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	zephir_array_fetch_string(&_4, _3, SL("view"), PH_NOISY | PH_READONLY, "smce/mvc/layout.zep", 72 TSRMLS_CC);
	ZEPHIR_INIT_VAR(contentFile);
	ZEPHIR_CONCAT_VSVS(contentFile, _2, "/", _4, ".php");
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", NULL, 32, contentFile);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		if (zephir_require_zval(contentFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	} else {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SV(_7$$4, "Content Not Found ", contentFile);
		ZEPHIR_INIT_VAR(_8$$4);
		ZVAL_LONG(_8$$4, 404);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 45, _8$$4, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "smce/mvc/layout.zep", 83 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Mvc_Layout, content) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *url, *arr = NULL, *contentFile = NULL, *_0 = NULL, *_1$$4, *_2$$4, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url, &arr);

	if (!arr) {
		ZEPHIR_INIT_VAR(arr);
		array_init(arr);
	}


	ZEPHIR_MAKE_REF(arr);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 105, arr);
	ZEPHIR_UNREF(arr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(contentFile);
	ZEPHIR_CONCAT_VS(contentFile, url, ".php");
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 32, contentFile);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		if (zephir_require_zval(contentFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SV(_2$$4, "Content Not Found ", contentFile);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, 404);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 45, _3$$4, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "smce/mvc/layout.zep", 102 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Smce_Mvc_Layout(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("content"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

