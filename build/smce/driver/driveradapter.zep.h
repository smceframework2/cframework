
extern zend_class_entry *smce_driver_driveradapter_ce;

ZEPHIR_INIT_CLASS(Smce_Driver_DriverAdapter);

PHP_METHOD(Smce_Driver_DriverAdapter, set);
PHP_METHOD(Smce_Driver_DriverAdapter, get);
PHP_METHOD(Smce_Driver_DriverAdapter, remove);
PHP_METHOD(Smce_Driver_DriverAdapter, setAdapter);
PHP_METHOD(Smce_Driver_DriverAdapter, isAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_driveradapter_set, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, duration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_driveradapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_driveradapter_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_driver_driveradapter_setadapter, 0, 0, 1)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_driver_driveradapter_method_entry) {
	PHP_ME(Smce_Driver_DriverAdapter, set, arginfo_smce_driver_driveradapter_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_DriverAdapter, get, arginfo_smce_driver_driveradapter_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_DriverAdapter, remove, arginfo_smce_driver_driveradapter_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_DriverAdapter, setAdapter, arginfo_smce_driver_driveradapter_setadapter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Driver_DriverAdapter, isAdapter, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
