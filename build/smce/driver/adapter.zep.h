
extern zend_class_entry *smce_driver_adapter_ce;

ZEPHIR_INIT_CLASS(Smce_Driver_Adapter);

PHP_METHOD(Smce_Driver_Adapter, set);
PHP_METHOD(Smce_Driver_Adapter, get);
PHP_METHOD(Smce_Driver_Adapter, remove);
PHP_METHOD(Smce_Driver_Adapter, setAdapter);
PHP_METHOD(Smce_Driver_Adapter, isAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_adapter_set, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_adapter_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_adapter_setadapter, 0, 0, 1)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_driver_adapter_method_entry) {
	PHP_ME(Smce_Driver_Adapter, set, arginfo_smce_driver_adapter_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_Adapter, get, arginfo_smce_driver_adapter_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_Adapter, remove, arginfo_smce_driver_adapter_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_Adapter, setAdapter, arginfo_smce_driver_adapter_setadapter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_Adapter, isAdapter, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
