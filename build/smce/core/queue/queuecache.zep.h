
extern zend_class_entry *smce_core_queue_queuecache_ce;

ZEPHIR_INIT_CLASS(Smce_Core_Queue_QueueCache);

PHP_METHOD(Smce_Core_Queue_QueueCache, __construct);
PHP_METHOD(Smce_Core_Queue_QueueCache, cache);
PHP_METHOD(Smce_Core_Queue_QueueCache, get);
PHP_METHOD(Smce_Core_Queue_QueueCache, remove);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuecache___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_queue_queuecache_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, duration)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_queue_queuecache_method_entry) {
	PHP_ME(Smce_Core_Queue_QueueCache, __construct, arginfo_smce_core_queue_queuecache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_Queue_QueueCache, cache, arginfo_smce_core_queue_queuecache_cache, ZEND_ACC_PRIVATE)
	PHP_ME(Smce_Core_Queue_QueueCache, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_Queue_QueueCache, remove, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
