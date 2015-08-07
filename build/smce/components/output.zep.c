
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Components_Output) {

	ZEPHIR_REGISTER_CLASS(Smce\\Components, Output, smce, components_output, smce_components_output_method_entry, 0);

	zend_declare_property_null(smce_components_output_ce, SL("header"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(smce_components_output_ce, SL("fileName"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Components_Output, setContentType) {

	zval *mimeType = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mimeType);

	if (!mimeType) {
		ZEPHIR_INIT_VAR(mimeType);
		ZVAL_STRING(mimeType, "", 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "Content-Type: ", mimeType);
	zephir_update_property_this(this_ptr, SL("header"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Smce_Components_Output, setFileName) {

	zval *fileName;

	zephir_fetch_params(0, 1, 0, &fileName);



	zephir_update_property_this(this_ptr, SL("fileName"), fileName TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Smce_Components_Output, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *data, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("fileName"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("fileName"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Content-disposition: attachment; filename=", _1);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 5, _2);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 5, _1);
	zephir_check_call_status();
	zend_print_zval(data, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Output, putFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *file, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("fileName"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("fileName"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Content-disposition: attachment; filename=", _1);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 5, _2);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 5, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "readfile", NULL, 44, file);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Output, getHeader) {


	RETURN_MEMBER(this_ptr, "header");

}

