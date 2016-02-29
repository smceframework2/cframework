
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
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
ZEPHIR_INIT_CLASS(Smce_Components_Session) {

	ZEPHIR_REGISTER_CLASS(Smce\\Components, Session, smce, components_session, smce_components_session_method_entry, 0);

	zend_declare_property_null(smce_components_session_ce, SL("security"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(smce_components_session_ce, SL("iv"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Components_Session, setSecurity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *security, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &security);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "sha1", NULL, 47, security);
	zephir_check_call_status();
	zephir_md5(_0, _1);
	zephir_update_property_this(this_ptr, SL("security"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Session, register) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 48);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_0, 1)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 49);
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

	int ZEPHIR_LAST_CALL_STATUS, _5;
	zval *key, *value, *_SESSION, *security = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_6, *_7, *_8 = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &key, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "encrypt", NULL, 50, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "sha1", NULL, 47, key);
	zephir_check_call_status();
	zephir_md5(_2, _3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, security, _2);
	_5 = zephir_maybe_separate_zval(&_SESSION);
	zephir_array_update_zval(&_SESSION, _4, &_1, PH_COPY | PH_SEPARATE);
	if (_5) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SESSION", _SESSION);
	}
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CALL_FUNCTION(&_8, "sha1", NULL, 47, key);
	zephir_check_call_status();
	zephir_md5(_7, _8);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_VV(_9, security, _7);
	zephir_array_fetch(&_6, _SESSION, _9, PH_NOISY | PH_READONLY, "smce/components/session.zep", 54 TSRMLS_CC);
	if (zephir_is_true(_6)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_SESSION, *security = NULL, *_0, *_1, *_2 = NULL, *_3, *_4$$3 = NULL, *_5$$3, *_6$$3, *_7$$3 = NULL, *_8$$3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", NULL, 47, key);
	zephir_check_call_status();
	zephir_md5(_1, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, security, _1);
	if (zephir_array_isset(_SESSION, _3)) {
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "sha1", NULL, 47, key);
		zephir_check_call_status();
		zephir_md5(_6$$3, _7$$3);
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_CONCAT_VV(_8$$3, security, _6$$3);
		zephir_array_fetch(&_5$$3, _SESSION, _8$$3, PH_NOISY | PH_READONLY, "smce/components/session.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "decrypt", NULL, 51, _5$$3);
		zephir_check_call_status();
		zephir_fast_trim(return_value, _4$$3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(Smce_Components_Session, reset) {

	HashTable *_4;
	HashPosition _3;
	zval *_SESSION, *security = NULL, *login = NULL, *key = NULL, *value = NULL, *_0, *_1, *_2 = NULL, **_5, *_9, *_6$$3 = NULL, _7$$3 = zval_used_for_init, *_8$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "SMCE_", _0);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", NULL, 47, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(login);
	zephir_md5(login, _2);
	zephir_is_iterable(_SESSION, &_4, &_3, 1, 0, "smce/components/session.zep", 99);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZEPHIR_SINIT_NVAR(_7$$3);
		ZVAL_STRING(&_7$$3, "", 0);
		zephir_fast_str_replace(&_6$$3, security, &_7$$3, key TSRMLS_CC);
		ZEPHIR_CPY_WRT(key, _6$$3);
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_VV(_8$$3, security, key);
		zephir_array_unset(&_SESSION, _8$$3, PH_SEPARATE);
	}
	zend_hash_destroy(_4);
	FREE_HASHTABLE(_4);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_VV(_9, security, login);
	zephir_array_unset(&_SESSION, _9, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Session, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_SESSION, *security = NULL, *_0, *_1, *_2 = NULL, *_3, *_4$$3, *_5$$3 = NULL, *_6$$3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(security, _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", NULL, 47, key);
	zephir_check_call_status();
	zephir_md5(_1, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, security, _1);
	if (zephir_array_isset(_SESSION, _3)) {
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sha1", NULL, 47, key);
		zephir_check_call_status();
		zephir_md5(_4$$3, _5$$3);
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_VV(_6$$3, security, _4$$3);
		zephir_array_unset(&_SESSION, _6$$3, PH_SEPARATE);
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
	zval *_identity, *duration, *security2 = NULL, *_0, *_1, *_2 = NULL, _3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_identity, &duration);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "SMCE_", _0);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", NULL, 47, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(security2);
	zephir_md5(security2, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "session.gc_maxlifetime", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 52, &_3, duration);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_cookie_params", NULL, 53, duration);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, security2, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Components_Session, getLoginStatus) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "SMCE_", _0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Session, isSessionStart) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 48);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_0, 1)) {
		RETURN_MM_BOOL(0);
	} else {
		RETURN_MM_BOOL(1);
	}

}

PHP_METHOD(Smce_Components_Session, encrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1, *_2, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "MCRYPT_RIJNDAEL_256");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "MCRYPT_MODE_CBC");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_encrypt", NULL, 0, _0, _1, str, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Components_Session, decrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1, *_2, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "MCRYPT_RIJNDAEL_256");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "MCRYPT_MODE_CBC");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_decrypt", NULL, 0, _0, _1, str, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

