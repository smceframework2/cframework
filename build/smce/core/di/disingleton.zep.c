
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/hash.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework2
 */
ZEPHIR_INIT_CLASS(Smce_Core_Di_DiSingleton) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core\\Di, DiSingleton, smce, core_di_disingleton, smce_core_di_disingleton_method_entry, 0);

	zend_declare_property_null(smce_core_di_disingleton_ce, SL("disSingleton"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_core_di_disingleton_ce, SL("cs"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(smce_core_di_disingleton_ce, SL("reflection"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_core_di_disingleton_ce, SL("reflectionClassArr"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_core_di_disingleton_ce, SL("istance"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_Di_DiSingleton, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *class, *_0, *_1$$4;
	zval *key = NULL, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &class);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, class, 0 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_0, "")) {
		zephir_update_property_this(this_ptr, SL("cs"), class TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_VS(_2$$4, key, " is not recycled class");
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 66, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "smce/core/di/disingleton.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Di_DiSingleton, resolveWhen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1, *_2, *_3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cs"), PH_NOISY_CC);
	zephir_update_static_property_array_multi_ce(smce_core_di_disingleton_ce, SL("disSingleton"), &_0 TSRMLS_CC, SL("z"), 1, key);
	ZEPHIR_INIT_VAR(_1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cs"), PH_NOISY_CC);
	zephir_get_class(_1, _0, 0 TSRMLS_CC);
	zephir_update_static_property_array_multi_ce(smce_core_di_disingleton_ce, SL("reflectionClassArr"), &key TSRMLS_CC, SL("z"), 1, _1);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("cs"), PH_NOISY_CC);
	zephir_get_class(_2, _3, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "class_alias", NULL, 67, _2, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_Di_DiSingleton, getSingleton) {

	zval *key_param = NULL, *_0, *_1$$3, *_2$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
	if (zephir_array_isset(_0, key)) {
		_1$$3 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "smce/core/di/disingleton.zep", 57 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_Di_DiSingleton, getKeys) {

	HashTable *_2;
	HashPosition _1;
	int i;
	zval *arr = NULL, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	i = 0;
	_0 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/di/disingleton.zep", 78);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_update_long(&arr, i, &key, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		i++;
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Smce_Core_Di_DiSingleton, getAll) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(Smce_Core_Di_DiSingleton, getCount) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
		RETURN_LONG(zephir_fast_count_int(_1$$3 TSRMLS_CC));
	} else {
		RETURN_LONG(0);
	}

}

PHP_METHOD(Smce_Core_Di_DiSingleton, controllerConstructorParamerters) {

	HashTable *_6$$3;
	HashPosition _5$$3;
	zephir_fcall_cache_entry *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *controller, *params = NULL, *value = NULL, *paramerter = NULL, *class = NULL, *_0, *_1, *_2 = NULL, *_3$$3, *_4$$3 = NULL, **_7$$3, *_8$$4 = NULL, *_9$$5, *_10$$5, *_11$$5 = NULL, *_12$$5 = NULL, *_13$$5 = NULL, *_14$$6 = NULL, *_15$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controller);



	ZEPHIR_INIT_VAR(paramerter);
	array_init(paramerter);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 68, controller);
	zephir_check_call_status();
	zephir_update_static_property_ce(smce_core_di_disingleton_ce, SL("reflection"), &_0 TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflection") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getconstructor", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(_2)) {
		_3$$3 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflection") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "getconstructor", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&params, _4$$3, "getparameters", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(params, &_6$$3, &_5$$3, 0, 0, "smce/core/di/disingleton.zep", 134);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HVALUE(value, _7$$3);
			ZEPHIR_CALL_METHOD(&_8$$4, value, "getclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_isset_property(_8$$4, SS("name") TSRMLS_CC)) {
				_9$$5 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
				ZEPHIR_OBS_NVAR(class);
				_10$$5 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflectionClassArr") TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_11$$5);
				ZEPHIR_CALL_METHOD(&_12$$5, value, "getclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(_13$$5);
				zephir_read_property(&_13$$5, _12$$5, SL("name"), PH_NOISY_CC);
				zephir_array_fetch(&_11$$5, _10$$5, _13$$5, PH_NOISY, "smce/core/di/disingleton.zep", 124 TSRMLS_CC);
				zephir_array_fetch(&class, _9$$5, _11$$5, PH_NOISY, "smce/core/di/disingleton.zep", 124 TSRMLS_CC);
				zephir_array_append(&paramerter, class, PH_SEPARATE, "smce/core/di/disingleton.zep", 125);
			} else {
				ZEPHIR_INIT_NVAR(_14$$6);
				object_init_ex(_14$$6, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_LNVAR(_15$$6);
				ZEPHIR_CONCAT_VS(_15$$6, value, " class not found");
				ZEPHIR_CALL_METHOD(NULL, _14$$6, "__construct", &_16, 66, _15$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_14$$6, "smce/core/di/disingleton.zep", 129 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		RETURN_CCTOR(paramerter);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_Di_DiSingleton, controllerMethodParamerters) {

	HashTable *_6$$3;
	HashPosition _5$$3;
	zephir_fcall_cache_entry *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *controller, *action, *params = NULL, *value = NULL, *paramerter = NULL, *class = NULL, *_0, *_1, *_2 = NULL, *_3$$3, *_4$$3 = NULL, **_7$$3, *_8$$4 = NULL, *_9$$5, *_10$$5, *_11$$5 = NULL, *_12$$5 = NULL, *_13$$5 = NULL, *_14$$6 = NULL, *_15$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &controller, &action);



	ZEPHIR_INIT_VAR(paramerter);
	array_init(paramerter);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 68, controller);
	zephir_check_call_status();
	zephir_update_static_property_ce(smce_core_di_disingleton_ce, SL("reflection"), &_0 TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflection") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getmethod", NULL, 0, action);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(_2)) {
		_3$$3 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflection") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "getmethod", NULL, 0, action);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&params, _4$$3, "getparameters", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(params, &_6$$3, &_5$$3, 0, 0, "smce/core/di/disingleton.zep", 172);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HVALUE(value, _7$$3);
			ZEPHIR_CALL_METHOD(&_8$$4, value, "getclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_isset_property(_8$$4, SS("name") TSRMLS_CC)) {
				_9$$5 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("disSingleton") TSRMLS_CC);
				ZEPHIR_OBS_NVAR(class);
				_10$$5 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflectionClassArr") TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_11$$5);
				ZEPHIR_CALL_METHOD(&_12$$5, value, "getclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(_13$$5);
				zephir_read_property(&_13$$5, _12$$5, SL("name"), PH_NOISY_CC);
				zephir_array_fetch(&_11$$5, _10$$5, _13$$5, PH_NOISY, "smce/core/di/disingleton.zep", 162 TSRMLS_CC);
				zephir_array_fetch(&class, _9$$5, _11$$5, PH_NOISY, "smce/core/di/disingleton.zep", 162 TSRMLS_CC);
				zephir_array_append(&paramerter, class, PH_SEPARATE, "smce/core/di/disingleton.zep", 163);
			} else {
				ZEPHIR_INIT_NVAR(_14$$6);
				object_init_ex(_14$$6, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_LNVAR(_15$$6);
				ZEPHIR_CONCAT_VS(_15$$6, value, " class not found");
				ZEPHIR_CALL_METHOD(NULL, _14$$6, "__construct", &_16, 66, _15$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_14$$6, "smce/core/di/disingleton.zep", 167 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		RETURN_CCTOR(paramerter);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Smce_Core_Di_DiSingleton, make) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL;
	zval *controller, *action, *refMethod = NULL, *constructorParamerter = NULL, *actionParamerter = NULL, *_2$$3, *_3$$3 = NULL, *_4$$4, *_5$$4 = NULL, *_7$$5, *_8$$5, *_9$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &controller, &action);



	ZEPHIR_CALL_SELF(&constructorParamerter, "controllerconstructorparamerters", &_0, 69, controller);
	zephir_check_call_status();
	_1 = !ZEPHIR_IS_FALSE(constructorParamerter);
	if (_1) {
		_1 = zephir_fast_count_int(constructorParamerter TSRMLS_CC) > 0;
	}
	if (_1) {
		_2$$3 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflection") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, _2$$3, "newinstanceargs", NULL, 0, constructorParamerter);
		zephir_check_call_status();
		zephir_update_static_property_ce(smce_core_di_disingleton_ce, SL("istance"), &_3$$3 TSRMLS_CC);
	} else {
		_4$$4 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("reflection") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5$$4, _4$$4, "newinstanceargs", NULL, 0);
		zephir_check_call_status();
		zephir_update_static_property_ce(smce_core_di_disingleton_ce, SL("istance"), &_5$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_SELF(&actionParamerter, "controllermethodparamerters", &_6, 70, controller, action);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(refMethod);
	object_init_ex(refMethod, zephir_get_internal_ce(SS("reflectionmethod") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, refMethod, "__construct", NULL, 71, controller, action);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(actionParamerter)) {
		_7$$5 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("istance") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$5);
		array_init(_8$$5);
		ZEPHIR_CALL_METHOD(NULL, refMethod, "invokeargs", NULL, 72, _7$$5, _8$$5);
		zephir_check_call_status();
	} else {
		_9$$6 = zephir_fetch_static_property_ce(smce_core_di_disingleton_ce, SL("istance") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, refMethod, "invokeargs", NULL, 72, _9$$6, actionParamerter);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

