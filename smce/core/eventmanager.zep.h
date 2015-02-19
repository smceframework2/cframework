
extern zend_class_entry *smce_core_eventmanager_ce;

ZEPHIR_INIT_CLASS(Smce_Core_EventManager);

PHP_METHOD(Smce_Core_EventManager, __callStatic);
PHP_METHOD(Smce_Core_EventManager, __call);
PHP_METHOD(Smce_Core_EventManager, push);
PHP_METHOD(Smce_Core_EventManager, pull);
PHP_METHOD(Smce_Core_EventManager, bind);
PHP_METHOD(Smce_Core_EventManager, remove);
PHP_METHOD(Smce_Core_EventManager, has);
PHP_METHOD(Smce_Core_EventManager, reset);
PHP_METHOD(Smce_Core_EventManager, getKeys);
PHP_METHOD(Smce_Core_EventManager, getAll);
PHP_METHOD(Smce_Core_EventManager, getCount);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager___call, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, class, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager_pull, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, class, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager_remove, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_eventmanager_has, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_eventmanager_method_entry) {
	PHP_ME(Smce_Core_EventManager, __callStatic, arginfo_smce_core_eventmanager___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, __call, arginfo_smce_core_eventmanager___call, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_EventManager, push, arginfo_smce_core_eventmanager_push, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_EventManager, pull, arginfo_smce_core_eventmanager_pull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, bind, arginfo_smce_core_eventmanager_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_EventManager, remove, arginfo_smce_core_eventmanager_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, has, arginfo_smce_core_eventmanager_has, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, getKeys, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, getAll, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_EventManager, getCount, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
