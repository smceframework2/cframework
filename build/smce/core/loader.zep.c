
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/require.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Loader) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, Loader, smce, core_loader, smce_core_loader_method_entry, 0);

	zend_declare_property_null(smce_core_loader_ce, SL("dirs"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(smce_core_loader_ce, SL("_registered"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_Loader, setDir) {

	zval *dir_param = NULL, *_0, *_1, *_2;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_arrval(dir, dir_param);


	_0 = zephir_fetch_static_property_ce(smce_core_loader_ce, SL("dirs") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zephir_fetch_static_property_ce(smce_core_loader_ce, SL("dirs") TSRMLS_CC);
		zephir_fast_array_merge(_1, &(_2), &(dir) TSRMLS_CC);
		zephir_update_static_property_ce(smce_core_loader_ce, SL("dirs"), &_1 TSRMLS_CC);
	} else {
		zephir_update_static_property_ce(smce_core_loader_ce, SL("dirs"), &dir TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Loader, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 3);
		zephir_array_fast_append(_1, this_ptr);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "autoLoad", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_registered"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Smce_Core_Loader, autoLoad) {

	HashTable *_13;
	HashPosition _12;
	int ZEPHIR_LAST_CALL_STATUS, len, i = 1;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_19 = NULL;
	zval *className_param = NULL, *fileName = NULL, *namespa = NULL, *lastNsPos = NULL, *value = NULL, *_0, _1, _2 = zval_used_for_init, *_3 = NULL, *_6 = NULL, *_7 = NULL, _8 = zval_used_for_init, _9, *_10, *_11, **_14, _15 = zval_used_for_init, _16 = zval_used_for_init, *_17 = NULL, *_18 = NULL, *_20 = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);
	ZEPHIR_INIT_VAR(fileName);
	ZVAL_STRING(fileName, "", 1);
	ZEPHIR_INIT_VAR(namespa);
	ZVAL_STRING(namespa, "", 1);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, '\\');
	zephir_fast_trim(_0, className, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(className, _0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, '\\');
	ZEPHIR_CALL_FUNCTION(&_3, "strrpos", &_4, className, &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, '\\');
		ZEPHIR_CALL_FUNCTION(&lastNsPos, "strrpos", &_4, className, &_2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 0);
		ZEPHIR_CALL_FUNCTION(&namespa, "substr", &_5, className, &_2, lastNsPos);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, (zephir_get_numberval(lastNsPos) + 1));
		ZEPHIR_CALL_FUNCTION(&_6, "substr", &_5, className, &_2);
		zephir_check_call_status();
		zephir_get_strval(className, _6);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "\\", 0);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_str_replace(_7, &_2, &_8, namespa TSRMLS_CC);
		ZEPHIR_INIT_NVAR(fileName);
		ZEPHIR_CONCAT_VS(fileName, _7, "/");
	}
	ZEPHIR_INIT_NVAR(_7);
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_LONG(&_8, '_');
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "/", 0);
	zephir_fast_str_replace(_7, &_8, &_9, className TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_VS(_10, _7, ".php");
	zephir_concat_self(&fileName, _10 TSRMLS_CC);
	_11 = zephir_fetch_static_property_ce(smce_core_loader_ce, SL("dirs") TSRMLS_CC);
	zephir_is_iterable(_11, &_13, &_12, 0, 0, "smce/core/loader.zep", 87);
	for (
	  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zephir_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HVALUE(value, _14);
		len = zephir_fast_strlen_ev(value);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, (len - i));
		ZEPHIR_SINIT_NVAR(_16);
		ZVAL_LONG(&_16, len);
		ZEPHIR_CALL_FUNCTION(&_6, "substr", &_5, value, &_15, &_16);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(_6, "/")) {
			ZEPHIR_INIT_LNVAR(_17);
			ZEPHIR_CONCAT_VS(_17, value, "/");
			ZEPHIR_CPY_WRT(value, _17);
		}
		ZEPHIR_INIT_LNVAR(_17);
		ZEPHIR_CONCAT_VV(_17, value, fileName);
		ZEPHIR_CALL_FUNCTION(&_18, "is_file", &_19, _17);
		zephir_check_call_status();
		if (zephir_is_true(_18)) {
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VV(_20, value, fileName);
			if (zephir_require_zval(_20 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

