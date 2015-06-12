
extern zend_class_entry *smce_mvc_acl_ce;

ZEPHIR_INIT_CLASS(Smce_Mvc_Acl);

PHP_METHOD(Smce_Mvc_Acl, setRule);
PHP_METHOD(Smce_Mvc_Acl, getRules);
PHP_METHOD(Smce_Mvc_Acl, run);
PHP_METHOD(Smce_Mvc_Acl, redirect);
PHP_METHOD(Smce_Mvc_Acl, expressionControl);
PHP_METHOD(Smce_Mvc_Acl, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_acl_setrule, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_acl_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_mvc_acl_expressioncontrol, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_mvc_acl_method_entry) {
	PHP_ME(Smce_Mvc_Acl, setRule, arginfo_smce_mvc_acl_setrule, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Acl, getRules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Acl, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Mvc_Acl, redirect, arginfo_smce_mvc_acl_redirect, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Mvc_Acl, expressionControl, arginfo_smce_mvc_acl_expressioncontrol, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Mvc_Acl, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
