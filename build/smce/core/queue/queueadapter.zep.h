
extern zend_class_entry *smce_core_queue_queueadapter_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueAdapter);

PHP_METHOD(Smce_Core_Queue_QueueAdapter, set);
PHP_METHOD(Smce_Core_Queue_QueueAdapter, replace);
PHP_METHOD(Smce_Core_Queue_QueueAdapter, get);
PHP_METHOD(Smce_Core_Queue_QueueAdapter, remove);
PHP_METHOD(Smce_Core_Queue_QueueAdapter, removeQue);
PHP_METHOD(Smce_Core_Queue_QueueAdapter, setAdapter);
PHP_METHOD(Smce_Core_Queue_QueueAdapter, isAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queueadapter_set, 0, 0, 5)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, class)
	ZEND_ARG_INFO(0, duration)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queueadapter_replace, 0, 0, 4)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queueadapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queueadapter_remove, 0, 0, 2)
	ZEND_ARG_INFO(0, queKey)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queueadapter_removeque, 0, 0, 1)
	ZEND_ARG_INFO(0, queKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queueadapter_setadapter, 0, 0, 1)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_queueadapter_method_entry) {
	PHP_ME(Smce_Core_Queue_QueueAdapter, set, arginfo_smce_core_queue_queueadapter_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueAdapter, replace, arginfo_smce_core_queue_queueadapter_replace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueAdapter, get, arginfo_smce_core_queue_queueadapter_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueAdapter, remove, arginfo_smce_core_queue_queueadapter_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueAdapter, removeQue, arginfo_smce_core_queue_queueadapter_removeque, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueAdapter, setAdapter, arginfo_smce_core_queue_queueadapter_setadapter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_Queue_QueueAdapter, isAdapter, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
