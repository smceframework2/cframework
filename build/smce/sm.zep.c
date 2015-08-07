
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Smce_Sm) {

	ZEPHIR_REGISTER_CLASS(Smce, Sm, smce, sm, smce_sm_method_entry, 0);

	zend_declare_property_null(smce_sm_ce, SL("app"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_sm_ce, SL("t"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Sm, app) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_sm_ce, SL("app") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, smce_app_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 113);
		zephir_check_call_status();
		zephir_update_static_property_ce(smce_sm_ce, SL("app"), &_1 TSRMLS_CC);
	}
	_2 = zephir_fetch_static_property_ce(smce_sm_ce, SL("app") TSRMLS_CC);
	RETURN_CTOR(_2);

}

PHP_METHOD(Smce_Sm, t) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *arr = NULL;
	zval *str_param = NULL, *arr_param = NULL;
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


	ZEPHIR_RETURN_CALL_CE_STATIC(smce_components_i18n_ce, "t", &_0, 114, str, arr);
	zephir_check_call_status();
	RETURN_MM();

}

