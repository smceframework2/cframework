
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Mvc_Url) {

	ZEPHIR_REGISTER_CLASS(Smce\\Mvc, Url, smce, mvc_url, smce_mvc_url_method_entry, 0);

	zend_declare_property_null(smce_mvc_url_ce, SL("baseUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Mvc_Url, setBaseUrl) {

	zval *url_param = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(url, url_param);


	zephir_update_property_this(this_ptr, SL("baseUrl"), url TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Mvc_Url, getBaseUrl) {


	RETURN_MEMBER(this_ptr, "baseUrl");

}

PHP_METHOD(Smce_Mvc_Url, get) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int len, i = 1, ZEPHIR_LAST_CALL_STATUS;
	zval *paramerter_param = NULL, *baseUrl = NULL, *_0, *_1, _2, _3, *_4 = NULL, *_6, *_7;
	zval *paramerter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paramerter_param);

	zephir_get_strval(paramerter, paramerter_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("baseUrl"), PH_NOISY_CC);
	len = zephir_fast_strlen_ev(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("baseUrl"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (len - i));
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, len);
	ZEPHIR_CALL_FUNCTION(&_4, "substr", &_5, _1, &_2, &_3);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(_4, "/")) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("baseUrl"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_VS(_7, _6, "/");
		ZEPHIR_CPY_WRT(baseUrl, _7);
	} else {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("baseUrl"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(baseUrl, _6);
	}
	ZEPHIR_CONCAT_VV(return_value, baseUrl, paramerter);
	RETURN_MM();

}

