
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


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
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

	smce_mvc_template_ce->create_object = zephir_init_properties_Smce_Mvc_Template;
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

	zval *viewFile = NULL, *layoutFile = NULL, *_0, *_1, *_2, *_3, *_4, *_5$$4, *_6$$4, *_7$$4, *_9$$6, *_10$$6, *_11$$6;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adjustmentview", NULL, 107, viewFile);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_5$$4);
		object_init_ex(_5$$4, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_6$$4);
		ZEPHIR_CONCAT_SV(_6$$4, "View Not Found ", viewFile);
		ZEPHIR_INIT_VAR(_7$$4);
		ZVAL_LONG(_7$$4, 404);
		ZEPHIR_CALL_METHOD(NULL, _5$$4, "__construct", &_8, 45, _7$$4, _6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$4, "smce/mvc/template.zep", 169 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_file_exists(layoutFile TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "adjustmentlayout", NULL, 108, layoutFile);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_9$$6);
		object_init_ex(_9$$6, smce_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_10$$6);
		ZEPHIR_CONCAT_SV(_10$$6, "Layout Not Found ", layoutFile);
		ZEPHIR_INIT_VAR(_11$$6);
		ZVAL_LONG(_11$$6, 404);
		ZEPHIR_CALL_METHOD(NULL, _9$$6, "__construct", &_8, 45, _11$$6, _10$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$6, "smce/mvc/template.zep", 183 TSRMLS_CC);
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

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *layoutFile_param = NULL, *_1;
	zval *layoutFile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layoutFile_param);

	zephir_get_strval(layoutFile, layoutFile_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("content"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("content"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 105, _0);
	ZEPHIR_UNREF(_0);
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
	zval *viewFile_param = NULL, *_0, *_1, *_2 = NULL;
	zval *viewFile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewFile_param);

	zephir_get_strval(viewFile, viewFile_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 95);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("array"), PH_NOISY | PH_READONLY, "smce/mvc/template.zep", 212 TSRMLS_CC);
	ZEPHIR_MAKE_REF(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 105, _1);
	ZEPHIR_UNREF(_1);
	zephir_check_call_status();
	if (zephir_require_zval(viewFile TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "ob_get_contents", NULL, 109);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("content"), _2 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 110);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Smce_Mvc_Template(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("error"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("view"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

