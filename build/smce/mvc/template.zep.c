
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/require.h"

ZEPHIR_INIT_CLASS(Smce_Mvc_Template) {

	ZEPHIR_REGISTER_CLASS(Smce\\Mvc, Template, smce, mvc_template, smce_mvc_template_method_entry, 0);

	/**
	 * @var layout
	 */
	zend_declare_property_null(smce_mvc_template_ce, SL("layout"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var layoutDirectory
	 */
	zend_declare_property_null(smce_mvc_template_ce, SL("layoutDirectory"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var view
	 */
	zend_declare_property_null(smce_mvc_template_ce, SL("view"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var viewDirectory
	 */
	zend_declare_property_null(smce_mvc_template_ce, SL("viewDirectory"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var error
	 */
	zend_declare_property_null(smce_mvc_template_ce, SL("error"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var content
	 */
	zend_declare_property_string(smce_mvc_template_ce, SL("content"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string
 * @return void
 */
PHP_METHOD(Smce_Mvc_Template, setLayout) {

	zval *layout_param = NULL;
	zval *layout = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &layout_param);

	if (!layout_param) {
		ZEPHIR_INIT_VAR(layout);
		ZVAL_STRING(layout, "", 1);
	} else {
		zephir_get_strval(layout, layout_param);
	}


	zephir_update_property_this(this_ptr, SL("layout"), layout TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string
 * @return void
 */
PHP_METHOD(Smce_Mvc_Template, setLayoutDirectory) {

	zval *layoutDirectory_param = NULL;
	zval *layoutDirectory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &layoutDirectory_param);

	if (!layoutDirectory_param) {
		ZEPHIR_INIT_VAR(layoutDirectory);
		ZVAL_STRING(layoutDirectory, "", 1);
	} else {
		zephir_get_strval(layoutDirectory, layoutDirectory_param);
	}


	zephir_update_property_this(this_ptr, SL("layoutDirectory"), layoutDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return string
 */
PHP_METHOD(Smce_Mvc_Template, getLayout) {


	RETURN_MEMBER(this_ptr, "layout");

}

/**
 * 
 * @return string
 */
PHP_METHOD(Smce_Mvc_Template, getLayoutDirectory) {


	RETURN_MEMBER(this_ptr, "layoutDirectory");

}

/**
 * @param string
 * @param array
 * @return void
 */
PHP_METHOD(Smce_Mvc_Template, setView) {

	zval *view_param = NULL, *arr = NULL, *_0, *_1;
	zval *view = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &view_param, &arr);

	if (!view_param) {
		ZEPHIR_INIT_VAR(view);
		ZVAL_STRING(view, "", 1);
	} else {
		zephir_get_strval(view, view_param);
	}
	if (!arr) {
		ZEPHIR_INIT_VAR(arr);
		array_init(arr);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "view", 1);
	zephir_update_property_array(this_ptr, SL("view"), _0, view TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "array", 1);
	zephir_update_property_array(this_ptr, SL("view"), _1, arr TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string
 * @return void
 */
PHP_METHOD(Smce_Mvc_Template, setViewDirectory) {

	zval *viewDirectory_param = NULL;
	zval *viewDirectory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &viewDirectory_param);

	if (!viewDirectory_param) {
		ZEPHIR_INIT_VAR(viewDirectory);
		ZVAL_STRING(viewDirectory, "", 1);
	} else {
		zephir_get_strval(viewDirectory, viewDirectory_param);
	}


	zephir_update_property_this(this_ptr, SL("viewDirectory"), viewDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return string
 */
PHP_METHOD(Smce_Mvc_Template, getView) {


	RETURN_MEMBER(this_ptr, "view");

}

/**
 * 
 * @return string
 */
PHP_METHOD(Smce_Mvc_Template, getViewDirectory) {


	RETURN_MEMBER(this_ptr, "viewDirectory");

}

/**
 * 
 *@return void
 */
PHP_METHOD(Smce_Mvc_Template, run) {

	zephir_fcall_cache_entry *_9 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *viewFile, *layoutFile, *_0, *_1, *_2, *_3, *_4, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("layoutDirectory"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("layout"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(layoutFile);
	ZEPHIR_CONCAT_VSVS(layoutFile, _0, "/", _1, ".php");
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("viewDirectory"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
	zephir_array_fetch_string(&_4, _3, SL("view"), PH_NOISY | PH_READONLY, "smce/mvc/template.zep", 159 TSRMLS_CC);
	ZEPHIR_INIT_VAR(viewFile);
	ZEPHIR_CONCAT_VSVS(viewFile, _2, "/", _4, ".php");
	if ((zephir_file_exists(viewFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adjustmentview", &_5, viewFile);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, "View Not Found ", viewFile);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_LONG(_8, 404);
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_9, _8, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "smce/mvc/template.zep", 169 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_file_exists(layoutFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adjustmentlayout", &_10, layoutFile);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_6);
		object_init_ex(_6, smce_http_httpexception_ce);
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, "Layout Not Found ", layoutFile);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 404);
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_9, _8, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "smce/mvc/template.zep", 183 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return void
 */
PHP_METHOD(Smce_Mvc_Template, adjustmentLayout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	zval *layoutFile_param = NULL, *_1;
	zval *layoutFile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layoutFile_param);

	zephir_get_strval(layoutFile, layoutFile_param);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("content"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("content"), &_1, PH_COPY | PH_SEPARATE);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_2, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	if (zephir_require_zval(layoutFile TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 
 * @return void
 */
PHP_METHOD(Smce_Mvc_Template, adjustmentView) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL;
	zval *viewFile_param = NULL, *_1, *_2, *_4 = NULL;
	zval *viewFile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewFile_param);

	zephir_get_strval(viewFile, viewFile_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("array"), PH_NOISY | PH_READONLY, "smce/mvc/template.zep", 212 TSRMLS_CC);
	Z_SET_ISREF_P(_2);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_3, _2);
	Z_UNSET_ISREF_P(_2);
	zephir_check_call_status();
	if (zephir_require_zval(viewFile TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&_4, "ob_get_contents", &_5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("content"), _4 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Mvc_Template, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("view"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

