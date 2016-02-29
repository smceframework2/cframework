
extern zend_class_entry *smce_core_queue_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue);

PHP_METHOD(Smce_Core_Queue, __construct);
PHP_METHOD(Smce_Core_Queue, bind);
PHP_METHOD(Smce_Core_Queue, resolve);
PHP_METHOD(Smce_Core_Queue, remove);
PHP_METHOD(Smce_Core_Queue, removeQue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_bind, 0, 0, 3)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, class, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_remove, 0, 0, 2)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_removeque, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_method_entry) {
	PHP_ME(Smce_Core_Queue, __construct, arginfo_smce_core_queue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Queue, bind, arginfo_smce_core_queue_bind, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue, resolve, arginfo_smce_core_queue_resolve, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue, remove, arginfo_smce_core_queue_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue, removeQue, arginfo_smce_core_queue_removeque, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
