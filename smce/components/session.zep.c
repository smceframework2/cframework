
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework 2
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Components_Session) {

	ZEPHIR_REGISTER_CLASS(Smce\\Components, Session, smce, components_session, smce_components_session_method_entry, 0);

	zend_declare_property_null(smce_components_session_ce, SL("security"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Components_Session, setSecurity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *security, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &security);



	ZEPHIR_CALL_FUNCTION(&_0, "sha1", &_1, security);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "md5", &_3, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("security"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Session, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_0, 1)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $key
 * @param $value
 *
 * @return bool
 */
PHP_METHOD(Smce_Components_Session, set) {

	int _2;
	zval *key, *value, *security = NULL, *_0, *_SESSION, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, security, key);
	_2 = zephir_maybe_separate_zval(&_SESSION);
	zephir_array_update_zval(&_SESSION, _1, &value, PH_COPY | PH_SEPARATE);
	if (_2) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SESSION", _SESSION);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, security, key);
	zephir_array_fetch(&_3, _SESSION, _4, PH_NOISY | PH_READONLY, "smce/components/session.zep", 51 TSRMLS_CC);
	if (zephir_is_true(_3)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * @param $key
 *
 * @return session or false
 */
PHP_METHOD(Smce_Components_Session, get) {

	zval *key, *security = NULL, *_0, *_SESSION, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, security, key);
	if (zephir_array_isset(_SESSION, _1)) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VV(_3, security, key);
		zephir_array_fetch(&_2, _SESSION, _3, PH_NOISY | PH_READONLY, "smce/components/session.zep", 75 TSRMLS_CC);
		RETURN_CTOR(_2);
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(Smce_Components_Session, reset) {

	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zval *security = NULL, *login = NULL, *key = NULL, *value = NULL, *_0, *_1, *_2 = NULL, *_SESSION, **_7, *_8 = NULL, _9 = zval_used_for_init, *_10 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "SMCE_", _0);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", &_3, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&login, "md5", &_4, _2);
	zephir_check_call_status();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_is_iterable(_SESSION, &_6, &_5, 1, 0, "smce/components/session.zep", 96);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(key, _6, _5);
		ZEPHIR_GET_HVALUE(value, _7);
		ZEPHIR_INIT_NVAR(_8);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "", 0);
		zephir_fast_str_replace(_8, security, &_9, key TSRMLS_CC);
		ZEPHIR_CPY_WRT(key, _8);
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_VV(_10, security, key);
		zephir_array_unset(&_SESSION, _10, PH_SEPARATE);
	}
	ZEPHIR_INIT_LNVAR(_10);
	ZEPHIR_CONCAT_VV(_10, security, login);
	zephir_array_unset(&_SESSION, _10, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Session, remove) {

	zval *key, *security = NULL, *_0, *_SESSION, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, security, key);
	if (zephir_array_isset(_SESSION, _1)) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VV(_2, security, key);
		zephir_array_unset(&_SESSION, _2, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param $_identity
 * @param $duration
 *
 * session_set_cookie_params
 */
PHP_METHOD(Smce_Components_Session, login) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_6 = NULL;
	zval *_identity, *duration, *security2 = NULL, *_0, *_1, *_2 = NULL, _5, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_identity, &duration);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "SMCE_", _0);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", &_3, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&security2, "md5", &_4, _2);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "session.gc_maxlifetime", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_6, &_5, duration);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_cookie_params", NULL, duration);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZVAL_BOOL(_7, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, security2, _7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Session, getLoginStatus) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "SMCE_", _0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

