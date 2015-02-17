
extern zend_class_entry *smce_components_session_ce;

ZEPHIR_INIT_CLASS(Smce_Components_Session);

PHP_METHOD(Smce_Components_Session, setSecurity);
PHP_METHOD(Smce_Components_Session, register);
PHP_METHOD(Smce_Components_Session, set);
PHP_METHOD(Smce_Components_Session, get);
PHP_METHOD(Smce_Components_Session, reset);
PHP_METHOD(Smce_Components_Session, remove);
PHP_METHOD(Smce_Components_Session, login);
PHP_METHOD(Smce_Components_Session, getLoginStatus);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_session_setsecurity, 0, 0, 1)
	ZEND_ARG_INFO(0, security)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_session_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_session_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_session_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_components_session_login, 0, 0, 2)
	ZEND_ARG_INFO(0, _identity)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_components_session_method_entry) {
	PHP_ME(Smce_Components_Session, setSecurity, arginfo_smce_components_session_setsecurity, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, set, arginfo_smce_components_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, get, arginfo_smce_components_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, remove, arginfo_smce_components_session_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, login, arginfo_smce_components_session_login, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Components_Session, getLoginStatus, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
