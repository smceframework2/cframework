
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

	zval *dir_param = NULL, *_0, *_1$$3, *_2$$3;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_arrval(dir, dir_param);


	_0 = zephir_fetch_static_property_ce(smce_core_loader_ce, SL("dirs") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_static_property_ce(smce_core_loader_ce, SL("dirs") TSRMLS_CC);
		zephir_fast_array_merge(_1$$3, &(_2$$3), &(dir) TSRMLS_CC);
		zephir_update_static_property_ce(smce_core_loader_ce, SL("dirs"), &_1$$3 TSRMLS_CC);
	} else {
		zephir_update_static_property_ce(smce_core_loader_ce, SL("dirs"), &dir TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Loader, register) {

	zval *_1$$3;
	zval *_0, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "autoLoad", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 73, _1$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_registered"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

PHP_METHOD(Smce_Core_Loader, autoLoad) {

	HashTable *_16;
	HashPosition _15;
	int ZEPHIR_LAST_CALL_STATUS, len$$4 = 0, i$$4;
	zephir_fcall_cache_entry *_4 = NULL, *_24 = NULL;
	zval *className_param = NULL, *fileName = NULL, *namespa = NULL, *lastNsPos = NULL, *value = NULL, *_0, _1, _2 = zval_used_for_init, *_3 = NULL, *_11, _12, *_13, *_14, **_17, _5$$3 = zval_used_for_init, _6$$3, *_7$$3, *_8$$3, _9$$3, _10$$3, _18$$4 = zval_used_for_init, _19$$4 = zval_used_for_init, *_20$$4 = NULL, *_22$$4 = NULL, *_23$$4 = NULL, *_21$$5 = NULL, *_25$$6 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&_3, "strrpos", &_4, 74, className, &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, '\\');
		ZEPHIR_CALL_FUNCTION(&lastNsPos, "strrpos", &_4, 74, className, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_INIT_NVAR(namespa);
		zephir_substr(namespa, className, 0 , zephir_get_intval(lastNsPos), 0);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_LONG(&_6$$3, (zephir_get_numberval(lastNsPos) + 1));
		ZEPHIR_INIT_VAR(_7$$3);
		zephir_substr(_7$$3, className, zephir_get_intval(&_6$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(className, _7$$3);
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_SINIT_VAR(_9$$3);
		ZVAL_STRING(&_9$$3, "\\", 0);
		ZEPHIR_SINIT_VAR(_10$$3);
		ZVAL_STRING(&_10$$3, "/", 0);
		zephir_fast_str_replace(&_8$$3, &_9$$3, &_10$$3, namespa TSRMLS_CC);
		ZEPHIR_INIT_NVAR(fileName);
		ZEPHIR_CONCAT_VS(fileName, _8$$3, "/");
	}
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, '_');
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "/", 0);
	zephir_fast_str_replace(&_11, &_2, &_12, className TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_VS(_13, _11, ".php");
	zephir_concat_self(&fileName, _13 TSRMLS_CC);
	_14 = zephir_fetch_static_property_ce(smce_core_loader_ce, SL("dirs") TSRMLS_CC);
	zephir_is_iterable(_14, &_16, &_15, 0, 0, "smce/core/loader.zep", 87);
	for (
	  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
	  ; zephir_hash_move_forward_ex(_16, &_15)
	) {
		ZEPHIR_GET_HVALUE(value, _17);
		i$$4 = 1;
		len$$4 = zephir_fast_strlen_ev(value);
		ZEPHIR_SINIT_NVAR(_18$$4);
		ZVAL_LONG(&_18$$4, (len$$4 - i$$4));
		ZEPHIR_SINIT_NVAR(_19$$4);
		ZVAL_LONG(&_19$$4, len$$4);
		ZEPHIR_INIT_NVAR(_20$$4);
		zephir_substr(_20$$4, value, zephir_get_intval(&_18$$4), zephir_get_intval(&_19$$4), 0);
		if (!ZEPHIR_IS_STRING(_20$$4, "/")) {
			ZEPHIR_INIT_LNVAR(_21$$5);
			ZEPHIR_CONCAT_VS(_21$$5, value, "/");
			ZEPHIR_CPY_WRT(value, _21$$5);
		}
		ZEPHIR_INIT_LNVAR(_22$$4);
		ZEPHIR_CONCAT_VV(_22$$4, value, fileName);
		ZEPHIR_CALL_FUNCTION(&_23$$4, "is_file", &_24, 32, _22$$4);
		zephir_check_call_status();
		if (zephir_is_true(_23$$4)) {
			ZEPHIR_INIT_LNVAR(_25$$6);
			ZEPHIR_CONCAT_VV(_25$$6, value, fileName);
			if (zephir_require_zval(_25$$6 TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

